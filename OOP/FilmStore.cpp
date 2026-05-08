#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

//============================================================
//                        Some Func
//============================================================
int calculateDaysGap(string startDateStr, string endDateStr) {
    struct tm start_tm = {0}, end_tm = {0};
    istringstream ssStart(startDateStr), ssEnd(endDateStr);

    // Chuyển string sang struct tm
    ssStart >> get_time(&start_tm, "%d/%m/%Y");
    ssEnd >> get_time(&end_tm, "%d/%m/%Y");

    // Chuyển sang time_t (giây kể từ 1970)
    time_t start = mktime(&start_tm);
    time_t end = mktime(&end_tm);

    // Tính số giây chênh lệch và đổi sang ngày (1 ngày = 86400 giây)
    double seconds = difftime(end, start);
    return (int)(seconds / 86400);
}

string getCurrentDate() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&t);
    
    ostringstream oss;
    oss << setfill('0') << setw(2) << now_tm->tm_mday << "/"
        << setw(2) << (now_tm->tm_mon + 1) << "/"
        << (now_tm->tm_year + 1900);
    return oss.str();
}

//============================================================
//                        Class
//============================================================
class Customer;
class Film;
class FilmStore;
//======================== Film ==============================

class Film {
  private:
  string id;
  string title;
  double basePrice;
  int status; // 0 rented, 1 available
  string borrowDate; // dd/mm/yyyy
  Customer* curCustomer;
  
  public:
  Film(string id, string title, double basePrice) {
    this->setId(id);
    this->setTitle(title);
    this->setBasePrice(basePrice);
    this->setStatus(1);
    this->setBorrowDate("");
    this->curCustomer = nullptr;
  }
  Film(string id, string title) : Film(id, title, 10) {}
  Film() : Film("","",0) {}
  
  // Setters
  void setId(string id){
    this->id = id;
  }
  void setTitle(string title){
    this->title = title;
  }
  void setBasePrice(double basePrice){
    this->basePrice = basePrice;
  }
  void setStatus(int s){
    this->status = s;
  }
  void setBorrowDate(string d){
    this->borrowDate = d;
  }
  void setBorrower(Customer* cus){
    this->curCustomer = cus;
  }
  
  // Getters
  string getId() {
    return this->id;
  }
  string getTitle() {
    return this->title;
  }
  double getBasePrice() {
    return this->basePrice;
  }
  int getStatus() {
    return this->status;
  }
  string getBorrowDate() {
    return this->borrowingTime;
  }
  Customer* getBorrower() {
    return this->curCustomer;
  }
  
  
  // Methods
  void displayInfo() {
    cout << "Title: " << this->getTitle() << "\n";
    cout << "Id: " << this->getId() << "\n";
    cout << "Base Price: " << this->getBasePrice() << "\n";
  }
  
  void attachBorrower (Customer* cus){
    if(this->getStatus() == 1) {
      cout << "Film is being rented!\n";
      return;
    }
    
    this->setBorrower(cus);
    this->setBorrowDate(getCurrentDate());
    this->setStatus(0);
    cout << "Success!\n";
  }
  
  void dettachBorrower() {
    if(this->getStatus() == 0) {
      cout << "Film is not rented!\n";
      return;
    }
    
    int date = calculateDaysGap(this->getBorrowDate(), getCurrentDate());
    if(date == 0) date = 1;
    double totalFee = (double)date * this->getBasePrice();
    cout << "Fee for renting: " << totalFee << "\n";
    
    this->setStatus(1);
    this->setBorrowDate("");
    this->setBorrower(nullptr);
  }
};

//===================== Customer ==================================
class Customer {
  private:
  string customerId;
  string name;
  int membershipPoint;
  vector <Film*> rentedFilm;
  
  public:
  Customer(string customerId, string name, int membershipPoint) {
    this->setCusId(customerId);
    this->setName(name);
    this->setMembershipPoint(membershipPoint);
  }
  Customer(string customerId, string name) : Customer(customerId, name, 0) {}
  Customer() : Customer("", "", 0) {}
  
  // Setters
  void setCusId(string id) {
    this->customerId = id;
  }
  void setName(string name){
    this->name = name;
  }
  void setMembershipPoint(int p){
    this->membershipPoint = p;
  }
  
  //Getters
  string getCusId() {
    return this->customerId;
  }
  string getName() {
    return this->name;
  }
  int getMembershipPoint() {
    return this->membershipPoint;
  }
  
  // Methods
  void attachFilm(Film* film){
    rentedFilm.push_back(film);
    film->attachBorrower(this);
  }
  
  void returnFilm(Film* film){
    for(auto f = rentedFilm.begin(); f != rentedFilm.end(); ++f) {
      if((*f)->getId() == film->getId()){
        (*f)->dettachBorrower();
        rentedFilm.erase(f);
        cout << "Success!\n";
        return;
      }
    }
    cout << "Error!\n";
  }
};

//======================== FilmStore ============================

class FilmStore {
  
};


