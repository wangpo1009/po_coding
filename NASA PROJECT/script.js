// -------------------------------
// 🌍 Khởi tạo bản đồ
// -------------------------------
var map = L.map("map").setView([16, 107], 5);
L.tileLayer("https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png", {
  attribution: "© OpenStreetMap"
}).addTo(map);

// -------------------------------
// 🔧 Biến toàn cục
// -------------------------------
let currentUnit = "C"; // "C" hoặc "F"
let currentCity = "Hanoi";
let userContext = "general"; // "general", "travel", "sports", "work", "outdoor"


const cities = {
  "Hanoi": [21.0285, 105.8542],
  "Ho Chi Minh": [10.7769, 106.7009],
  "Da Nang": [16.0471, 108.2068],
  "Can Tho": [10.0452, 105.7469]
};

// -------------------------------
// 📡 Fetch dữ liệu từ API
// -------------------------------
async function fetchNASAData(lat, lon) {
  const today = new Date();
  const end = today.toISOString().split("T")[0].replace(/-/g, "");
  const startDate = new Date();
  startDate.setDate(today.getDate() - 5);
  const start = startDate.toISOString().split("T")[0].replace(/-/g, "");

  const url = `https://power.larc.nasa.gov/api/temporal/daily/point?parameters=T2M,RH2M,WS2M&community=RE&longitude=${lon}&latitude=${lat}&start=${start}&end=${end}&format=JSON`;

  const res = await fetch(url);
  const data = await res.json();
  return data.properties.parameter; // { T2M, RH2M, WS2M }
}

async function fetchMeteoData(lat, lon) {
  const url = `https://api.open-meteo.com/v1/forecast?latitude=${lat}&longitude=${lon}&hourly=precipitation_probability,temperature_2m,cloud_cover,visibility,wind_speed_10m,relative_humidity_2m&timezone=auto`;
  const res = await fetch(url);
  const data = await res.json();
  return data.hourly;
}
//chuẩn hóa dữ liệu thời tiết hàng giờ thành hàng ngày
function normalizeForecast(hourly) {
  const result = {};
  const times = hourly.time;

  times.forEach((t, i) => {
    const day = t.split("T")[0]; // lấy YYYY-MM-DD
    if (!result[day]) {
      result[day] = {
        temp: [],
        humidity: [],
        wind: [],
        rainProb: [],
        cloud: [],
        visibility: []
      };
    }
    result[day].temp.push(hourly.temperature_2m[i]);
    result[day].humidity.push(hourly.relative_humidity_2m[i]);
    result[day].wind.push(hourly.wind_speed_10m[i]);
    result[day].rainProb.push(hourly.precipitation_probability[i]);
    result[day].cloud.push(hourly.cloud_cover[i]);
    result[day].visibility.push(hourly.visibility[i]);
  });

  // Tính trung bình mỗi ngày
  const daily = {};
  Object.keys(result).forEach(day => {
    daily[day] = {
      avgTemp: avg(result[day].temp),
      avgHumidity: avg(result[day].humidity),
      avgWind: avg(result[day].wind),
      maxRainProb: Math.max(...result[day].rainProb),
      avgCloud: avg(result[day].cloud),
      avgVisibility: avg(result[day].visibility)
    };
  });

  return daily;
}

function avg(arr) {
  return arr.reduce((a,b) => a+b, 0) / arr.length;
}

// -------------------------------
// 🎨 UI Update
// -------------------------------
async function updateWeather(city) {
  currentCity = city;
  const [lat, lon] = cities[city];

  try {
    const forecast = await fetchForecastData(lat, lon);
    const nasaData = await fetchNASAData(lat, lon);

    // --- Lấy dữ liệu NASA ---
    const tempToday = nasaData.T2M 
      ? toNumber(Object.values(nasaData.T2M)[0]) 
      : null;

    const humidityToday = nasaData.RH2M 
      ? toNumber(Object.values(nasaData.RH2M)[0]) 
      : null;

    const windToday = nasaData.WS2M 
      ? toNumber((Object.values(nasaData.WS2M)[0] * 3.6).toFixed(1)) 
      : null;

    // --- Lấy forecast từ Open-Meteo ---
    const avgTemp = (forecast.temperature_2m_max && forecast.temperature_2m_min)
      ? (forecast.temperature_2m_max[0] + forecast.temperature_2m_min[0]) / 2
      : tempToday;

    const rainProb = forecast.precipitation_probability_max 
      ? forecast.precipitation_probability_max[0] 
      : 0;

    const cloudCover = forecast.cloudcover_mean 
      ? forecast.cloudcover_mean[0] 
      : 0;

    const visibility = forecast.visibility_mean 
      ? (forecast.visibility_mean[0] / 1000).toFixed(1) 
      : "--";

    // --- Cập nhật UI ---
    document.getElementById("city-name").innerText = city;
    document.getElementById("desc").innerText = "Data from Open-Meteo & NASA";
    document.getElementById("temp").innerText = avgTemp !== null ? formatTemp(avgTemp) : "--";
    document.getElementById("humidity").innerText = humidityToday !== null ? humidityToday + "%" : "--";
    document.getElementById("wind").innerText = windToday !== null ? windToday + " km/h" : "--";
    document.getElementById("visibility").innerText = visibility;

    // --- Hiển thị forecast 5 ngày ---
    const forecastContainer = document.getElementById("forecast-container");
    forecastContainer.innerHTML = "";
    for (let i = 0; i < 5; i++) {
      const div = document.createElement("div");
      div.className = "forecast-day";
      div.innerHTML = `
        <span>${forecast.time[i]}</span>
        <span>${Math.round((forecast.temperature_2m_max[i] + forecast.temperature_2m_min[i]) / 2)}°C</span>
        <span>☁️ ${forecast.cloudcover_mean ? forecast.cloudcover_mean[i] : 0}%</span>
        <span>💧 ${forecast.precipitation_probability_max ? forecast.precipitation_probability_max[i] : 0}%</span>
      `;
      forecastContainer.appendChild(div);
    }

    // --- Sinh lời khuyên ---
    const adviceList = generateAdvice(
      avgTemp,
      "Weather data",
      humidityToday,
      windToday,
      userContext,
      rainProb,
      cloudCover,
      visibility
    );

    const adviceUl = document.getElementById("advice-list");
    adviceUl.innerHTML = "";
    adviceList.forEach(advice => {
      const li = document.createElement("li");
      li.textContent = advice;
      adviceUl.appendChild(li);
    });

  } catch (err) {
    console.error(err);
    document.getElementById("city-name").innerText = city;
    document.getElementById("desc").innerText = "⚠️ Data unavailable";
  }
}
// -------------------------------
// 📅 Lấy thời tiết theo ngày chọn
// -------------------------------
async function fetchWeatherForDate() {
  const dateInput = document.getElementById("date-picker").value;
  if (!dateInput) {
    alert("Please select a date first!");
    return;
  }

  const [lat, lon] = cities[currentCity];
  const day = dateInput.replace(/-/g, "");

  try {
    // 1️⃣ Lấy dữ liệu NASA POWER (nhiệt độ, độ ẩm, gió)
    const nasaUrl = `https://power.larc.nasa.gov/api/temporal/daily/point?parameters=T2M,T2M_MIN,T2M_MAX,RH2M,WS2M&community=RE&longitude=${lon}&latitude=${lat}&start=${day}&end=${day}&format=JSON`;

    const nasaRes = await fetch(nasaUrl);
    const nasaData = await nasaRes.json();

    if (!nasaData.properties || !nasaData.properties.parameter) {
      throw new Error("NASA POWER: dữ liệu rỗng hoặc sai cấu trúc");
    }

    const weather = nasaData.properties.parameter;

    const safeGet = (param) =>
      weather[param] && weather[param][day] !== undefined
        ? weather[param][day]
        : "--";

    // 2️⃣ Lấy thêm dữ liệu Open-Meteo (mây, mưa, tầm nhìn)
    const omUrl = `https://api.open-meteo.com/v1/forecast?latitude=${lat}&longitude=${lon}&hourly=precipitation_probability,cloud_cover,visibility&timezone=auto&start_date=${dateInput}&end_date=${dateInput}`;
    const omRes = await fetch(omUrl);
    const omData = await omRes.json();

    // Lấy giá trị trung bình trong ngày từ dữ liệu hourly
    function dailyAvg(arr) {
      return arr && arr.length > 0
        ? (arr.reduce((a, b) => a + b, 0) / arr.length).toFixed(1)
        : "--";
    }

    const cityData = {
      current: {
        temp: safeGet("T2M"),
        tempMin: safeGet("T2M_MIN"),
        tempMax: safeGet("T2M_MAX"),
        desc: "NASA + OpenMeteo",
        humidity: safeGet("RH2M"),
        wind:
          safeGet("WS2M") !== "--"
            ? (safeGet("WS2M") * 3.6).toFixed(1) // m/s → km/h
            : "--",
        cloud: dailyAvg(omData.hourly?.cloud_cover || []),
        rainProb: dailyAvg(
          omData.hourly?.precipitation_probability || []
        ),
        visibility: dailyAvg(omData.hourly?.visibility || []),
      },
    };

    updateWeatherFromAPI(currentCity, cityData);

  } catch (err) {
    console.error("API fetch error:", err);
    document.getElementById("desc").innerText = "⚠️ Data unavailable";
  }
}

// -------------------------------
// 🎯 Render từ NASA cho 1 ngày cụ thể
// -------------------------------
function updateWeatherFromAPI(city, cityData) {
  const current = cityData.current;

  // Chuyển dữ liệu sang dạng số an toàn
  const temp = toNumber(current.temp);
  const tempMin = toNumber(current.tempMin);
  const tempMax = toNumber(current.tempMax);
  const humidity = toNumber(current.humidity);
  const wind = toNumber(current.wind); // km/h
  const cloud = toNumber(current.cloud);
  const rainProb = toNumber(current.rainProb);
  const visibility = toNumber(current.visibility);

  // Cập nhật thông tin cơ bản
  document.getElementById("city-name").innerText = city;
  document.getElementById("desc").innerText = current.desc;
  document.getElementById("temp").innerText = formatTemp(temp);
  document.getElementById("humidity").innerText = 
    humidity !== null ? humidity + "%" : "--";
  document.getElementById("wind").innerText = 
    wind !== null ? wind + " km/h" : "--";

  if (cloud !== null && document.getElementById("cloud")) {
    document.getElementById("cloud").innerText = cloud + "%";
  }
  if (rainProb !== null && document.getElementById("rainProb")) {
    document.getElementById("rainProb").innerText = rainProb + "%";
  }
  if (visibility !== null && document.getElementById("visibility")) {
    document.getElementById("visibility").innerText = visibility + " m";
  }

  // Xóa forecast khi chỉ hiển thị 1 ngày
  document.getElementById("forecast-container").innerHTML = "";

  // Tính avgTemp
  const avgTemp = (tempMax !== null && tempMin !== null)
    ? (tempMax + tempMin) / 2
    : temp;

  // Sinh lời khuyên
  const adviceList = generateAdvice(
    avgTemp,
    current.desc,
    humidity,
    wind,
    userContext,
    rainProb,
    cloud,
    visibility
  );

  const adviceUl = document.getElementById("advice-list");
  adviceUl.innerHTML = "";
  adviceList.forEach((advice) => {
    const li = document.createElement("li");
    li.textContent = advice;
    adviceUl.appendChild(li);
  });
}

// -------------------------------
// 🧾 Các hàm tiện ích
// -------------------------------

// Định dạng nhiệt độ theo đơn vị hiện tại
function formatTemp(celsiusValue) {
  if (celsiusValue === "--") return "--";
  if (currentUnit === "C") {
    return Math.round(celsiusValue) + "°C";
  } else {
    return Math.round((celsiusValue * 9 / 5) + 32) + "°F";
  }
}

function toggleUnit() {
  currentUnit = currentUnit === "C" ? "F" : "C";
  updateWeather(currentCity);
}

// Tạo lời khuyên dựa trên nhiệt độ, mô tả thời tiết, độ ẩm và gió
function generateAdvice(temp, desc, humidity, wind, context, rainProb, cloud, visibility) {
  const rules = [
    // --- Nhiệt độ ---
    { condition: d => d.temp !== null && d.temp < 0, advice: "🥶 Rất lạnh, mặc nhiều lớp." },
    { condition: d => d.temp !== null && d.temp < 10, advice: "🧥 Lạnh, nên mặc áo khoác." },
    { condition: d => d.temp !== null && d.temp > 30, advice: "🔥 Nóng, mặc đồ mỏng và uống đủ nước." },
    { condition: d => d.temp !== null && d.temp > 25 && d.temp <= 30, advice: "😎 Thời tiết dễ chịu, mặc đồ nhẹ." },

    // --- Mưa ---
    { condition: d => d.rainProb !== null && (d.rainProb > 70), advice: "☔ Khả năng mưa cao, nên mang ô hoặc áo mưa." },
    { condition: d => d.rainProb !== null && d.rainProb > 40 && d.rainProb <= 70, advice: "🌦️ Có thể có mưa rào, chú ý khi ra ngoài." },

    // --- Tuyết ---
    { condition: d => /Snow|❄️/.test(d.desc), advice: "❄️ Có tuyết, cẩn thận trơn trượt." },

    // --- Mây ---
    { condition: d => d.cloud !== null && d.cloud > 70, advice: "☁️ Trời nhiều mây, ánh sáng yếu." },
    { condition: d => d.cloud !== null && d.cloud < 30, advice: "🌞 Trời quang, có thể có nắng gắt." },

    // --- Tầm nhìn ---
    { condition: d => d.visibility !== null && d.visibility < 2000, advice: "🌫️ Tầm nhìn kém, lái xe cần chú ý." },
    { condition: d => d.visibility !== null && d.visibility < 500, advice: "🚨 Sương mù dày, hạn chế lái xe đường dài." },

    // --- Gió (theo km/h) ---
    { condition: d => d.wind !== null && d.wind > 50, advice: "💨 Gió rất mạnh, hạn chế ra ngoài." },
    { condition: d => d.wind !== null && d.wind > 25 && d.wind <= 50, advice: "🍃 Gió khá mạnh, cần chú ý." },

    // --- Độ ẩm ---
    { condition: d => d.humidity !== null && d.humidity > 80, advice: "💧 Độ ẩm cao, dễ cảm thấy oi bức." },

    // --- Ngữ cảnh cá nhân ---
    { condition: d => d.context === "travel" && d.rainProb !== null && d.rainProb > 50, advice: "🚗 Trời mưa, đường trơn trượt khi lái xe." },
    { condition: d => d.context === "travel" && d.temp !== null && d.temp > 32, advice: "🧳 Mang thêm nước uống khi đi du lịch." },

    { condition: d => d.context === "work" && d.temp !== null && d.temp < 15, advice: "💼 Trời lạnh, mặc gọn gàng khi đi làm." },
    { condition: d => d.context === "work" && d.cloud !== null && d.cloud < 40, advice: "☀️ Ngày đẹp, đi làm sẽ dễ chịu hơn." },

    { condition: d => d.context === "sport" && d.temp !== null && d.temp > 30, advice: "🏃 Tránh tập ngoài trời lúc trưa." },
    { condition: d => d.context === "sport" && d.wind !== null && d.wind > 30, advice: "⚽ Gió to, hạn chế các môn ngoài trời." },

    { condition: d => d.context === "outdoor" && d.rainProb !== null && d.rainProb > 50, advice: "🌧️ Mưa, không nên tổ chức hoạt động ngoài trời." },
    { condition: d => d.context === "outdoor" && d.temp !== null && d.temp < 10, advice: "🧥 Trời lạnh, nếu ra ngoài nên mang áo ấm." },
  ];

  const input = { temp, desc, humidity, wind, context, rainProb, cloud, visibility };
  return rules.filter(rule => rule.condition(input)).map(rule => rule.advice);
}

  // Gom dữ liệu lại để truyền vào rule
  const input = { temp, desc, humidity, wind, context, rainProb, cloud, visibility };

  return rules.filter(rule => rule.condition(input)).map(rule => rule.advice);


function updateDate() {
  const now = new Date();
  const options = { day: '2-digit', month: '2-digit', year: 'numeric' };
  document.getElementById("date-display").textContent = now.toLocaleDateString('en-GB', options);
}

function changeContext() {
  // Cập nhật ngữ cảnh người dùng
  userContext = document.getElementById("context-select").value;
  updateWeather(currentCity); 
}

function toNumber(val) {
  if (val === "--" || val === undefined || val === null) return null;
  return Number(val);
}

// -------------------------------
// 🚀 Khởi động mặc định
// -------------------------------
for (let city in cities) {
  L.marker(cities[city]).addTo(map).on("click", () => {
    updateWeather(city);
    map.flyTo(cities[city], 10, { animate: true, duration: 1.5 });
  });
}

updateWeather("Hanoi");
updateDate();