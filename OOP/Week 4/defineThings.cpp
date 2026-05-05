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
};

class ProjectLeader : public Programmer{
  private:
  string projectName;
  
  public:
  ProjectLeader(string number, double salary, string name, string language, string projectName) : Programmer(number, salary, name, language){
    this->setProjectName(projectName);
  } 
  ProjectLeader() : ProjectLeader("000", 0, " ", "cpp", "OOP"){}
}

class SoftwareHouse{
  private:
  string name;
  vector <Programmer> programmerList;
  
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
  
  void addProgrammer(Programmer A){
    programmerList.push_back(A);
  }
};



int main(){
  cout << "No hope";
  return 0;
}
