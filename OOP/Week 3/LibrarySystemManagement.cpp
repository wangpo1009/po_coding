#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Employee;
class SoftwareHouse;
class Programmer;
class ProjectLeader;


//=============== Employee ==================
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

//================== Programmer ==================
class Programmer : public Employee{
  private:
  string language;
  ProjectLeader* leader;
  
  public:
  Programmer(string number, double salary, string name, string language) : Employee(number, salary, name){
    this->setLanguage(language);
    this->leader = nullptr;
  }
  Programmer() : Programmer("000", 0, " ", "cpp"){}
  
  void setLanguage(string language){
    this->language = language;
  }
  void setLeader(ProjectLeader* A){
    this->leader = A;
  }
  
  string getLanguage(){
    return language;
  }
  ProjectLeader* getProjectLeader(){
    return leader;
  }
};

//================ ProjectLeader =======================
class ProjectLeader : public Programmer{
  private:
  string projectName;
  vector <Programmer*> team;
  
  public:
  ProjectLeader(string number, double salary, string name, string language, string projectName) : Programmer(number, salary, name, language){
    this->setProjectName(projectName);
  } 
  ProjectLeader() : ProjectLeader("000", 0, " ", "cpp", "OOP"){}
  
  void setProjectName(string projectName){
    this->projectName = projectName;
  }
  
  string getProjectName(){
    return projectName;
  }
  
  void addProgrammer(Programmer* A){
    team.push_back(A);
    A->setLeader(this);
  }
  
  
};

//================= SoftwareHouse ======================
class SoftwareHouse{
  private:
  string name;
  vector <Programmer*> programmerList;
  vector <ProjectLeader*> leaderList;
  
  public:
  SoftwareHouse(string name){
    this->setName(name);
  }
  SoftwareHouse() : SoftwareHouse("NhoNguoiCanQuen"){}
  
  void setName(string name){
    this->name = name;
  }
  
  string getName(){
    return name;
  }
  
  void addProgrammer(Programmer* A){
    programmerList.push_back(A);
  }
  
  void addProjectLeader(ProjectLeader* A){
    leaderList.push_back(A);
  }
  
};



int main(){
  cout << "No hope";
  return 0;
}
