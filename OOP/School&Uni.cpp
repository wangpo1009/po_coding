#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class University;

class School {
private:
    string name;
    string address;
    University* university;

public:
    School(string name, string address) : name(name), address(address), university(nullptr) {}

    void setName(string name) { this->name = name; }
    void setAddress(string address) { this->address = address; }
    
    string getName() const { return name; }
    string getAddress() const { return address; }

    void attachUniversity(University* u) { this->university = u; }
    void detachUniversity() { this->university = nullptr; }
    
    void display(){
      cout << "Ten Truong: " << this->getName() << "\n";
      cout << "Dia chi: " << this->getAddress() << "\n";
      cout << "=======================================\n";
    }
};

class University {
private:
    string name;
    vector<School*> schoolList;

public:
    University(string name) : name(name) {}
    University() : University("VNU") {}

    ~University() {
        for (auto s : schoolList) delete s;
        schoolList.clear();
    }

    void setName(string name) { this->name = name; }
    string getName() const { return name; }

    void attachSchool(School* newSchool) {
        schoolList.push_back(newSchool);
        newSchool->attachUniversity(this);
    }

    void detachSchool(School* school) {
        auto it = find(schoolList.begin(), schoolList.end(), school);
        
        if (it != schoolList.end()) {
            (*it)->detachUniversity(); // Gọi phương thức detach của School
            schoolList.erase(it);      
            cout << "Da xoa truong: " << school->getName() << endl;
        } else {
            cout << "Khong tim thay truong!" << endl;
        }
    }
    
    void display(){
      cout << "Dai hoc: " << this->getName() << "\n";
      for(auto i : schoolList){
        i->display();
      }
    }
};
int main() {
    // 1. Tạo 1 đại học
    University vnu("Dai hoc Quoc Gia");

    // 2. Tạo 3 trường
    School* s1 = new School("Truong Dai hoc Cong nghe", "TPHCM");
    School* s2 = new School("Truong Dai hoc Khoa hoc Tu nhien", "TPHCM");
    School* s3 = new School("Truong Dai hoc Kinh te", "Ha Noi");

    // 3. Cho 3 trường trở thành thành viên
    vnu.attachSchool(s1);
    vnu.attachSchool(s2);
    vnu.attachSchool(s3);

    // 4. Hiển thị thông tin
    cout << "--- Sau khi them 3 truong ---\n";
    vnu.display();

    // 5. Cho trường thứ 3 rời khỏi đại học
    cout << "\nDang thuc hien: Cho truong Kinh te roi khoi..." << endl;
    vnu.detachSchool(s3);

    // 6. Hiển thị lại thông tin
    cout << "--- Sau khi truong 3 roi khoi ---";
    vnu.display();

    // Dọn dẹp bộ nhớ
    delete s1; delete s2; delete s3;

    return 0;
}
