#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Employee;
class SoftwareHouse;
class Programmer;

class Employee{
  private:
  string number;
  double salary;
  string name;
  
  public:
  Employee(string number, double salary, string name){
    this->setNumber(number);
    this->setSalary(salary);
    this->setName(name);
  }
  Employee() : Employee("000", 0, " "){}
  
  //===== Setter =====
  void setName(string name){
    this->name = name;
  }
  void setNumber(string number){
    this->number = number;
  }
  void setSalary(double salary){
    this->salary = salary;
  }
  
  //===== Getter =====
  string getName(){
    return name;
  }
  double getSalary(){
    return salary;
  }
  string getNumber(){
    return number;
  }
  
  virtual void displayInfo() {
    cout << "Name: " << this->getName() << "\n";
    cout << "Number: " << this->getNumber() << "\n";
    cout << "Salary: " << this->getSalary() << "\n";
  }
  
};

class Programmer : public Employee{
  private:
  string language;
  
  public:
  Programmer(string number, double salary, string name, string language) : Employee(number, salary, name){
    this->setLanguage(language);
  }
  Programmer() : Programmer("000", 0, " ", "cpp"){}
  
  void setLanguage(string language){
    this->language = language;
  }
  
  string getLanguage(){
    return language;
  }
  
  void displayInfo() override {
    cout << "Name: " << this->getName() << "\n";
    cout << "Number: " << this->getNumber() << "\n";
    cout << "Salary: " << this->getSalary() << "\n";
    cout << "Language: " << this->getLanguage() << " \n";
  }
};

class ProjectLeader : public Programmer{
  private:
  string projectName;
  vector <Employee*> member;
  
  public:
  ProjectLeader(string number, double salary, string name, string language, string projectName) : Programmer(number, salary, name, language){
    this->setProjectName(projectName);
  } 
  ProjectLeader() : ProjectLeader("000", 0, " ", "cpp", "OOP"){}
  
  void setProjectName(string s) {
    this->projectName = s;
  }
  
  string getProjectName() {
    return this->projectName;
  }
  
  void displayProjectMember() {
    cout << "Member: "
  }
};

class SoftwareHouse{
  private:
  string name;
  vector <Employee*> programmerList;
  
  public:
  SoftwareHouse(string name){
    this->setName(name);
  }
  SoftwareHouse() : SoftwareHouse("May Thg Kho"){}
  
  void setName(string name){
    this->name = name;
  }
  
  string getName(){
    return name;
  }
  
  void addEmployee(Employee* A){
    programmerList.push_back(A);
  }
  
  void displayAllEmployees() {
    cout << "--- Software House: " << this->getName() << " ---\n";
    for (Employee* emp : programmerList) {
        emp->displayInfo(); // Nhờ virtual, nó sẽ tự gọi đúng hàm của Programmer/Employee
        cout << "--------------------------\n";
    }
  }
};



int main() {
    // 1. Khởi tạo Software House
    SoftwareHouse myCompany("C++ Warriors");

    // 2. Tạo các loại nhân viên khác nhau
    // Nhân viên bình thường
    Employee* emp1 = new Employee("E001", 1000, "Nguyen Van A");

    // Lập trình viên (Kế thừa từ Employee)
    Programmer* pro1 = new Programmer("P002", 2000, "Tran Thi B", "C++");

    // Trưởng dự án (Kế thừa từ Programmer)
    // Lưu ý: Bạn chưa override displayInfo cho ProjectLeader nên nó sẽ dùng displayInfo của Programmer
    ProjectLeader* lead1 = new ProjectLeader("L003", 3500, "Le Van C", "Python", "AI System");

    // 3. Thêm vào danh sách quản lý
    myCompany.addEmployee(emp1);
    myCompany.addEmployee(pro1);
    myCompany.addEmployee(lead1);

    // 4. Hiển thị kết quả
    myCompany.displayAllEmployees();

    // Giải phóng bộ nhớ (Rất quan trọng khi dùng con trỏ)
    delete emp1;
    delete pro1;
    delete lead1;

    return 0;
}
