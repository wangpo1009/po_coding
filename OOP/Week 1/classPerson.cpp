#include <iostream>
#include <string>
#include <stdlib.h>

#define CUR_YEAR 2026
#define CUR_MONTH 3 
using namespace std;

class Person{
  private:
  string name;
  string dateOfBirth;
  
  public:
  Person(string name, string dateOfBirth) {
    this->setName(name);
    this->setDateOfBirth(dateOfBirth);
  }
  
  void setName(string name) {
    this->name = name;
  }
  
  void setDateOfBirth(string dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
  }
  
  string getName() {
    return name;
  }
  
  string getDateOfBirth() {
    return dateOfBirth;
  }
  
  int getAge(){
    if(stoi(getDateOfBirth().substr(4,2)) > CUR_MONTH){
      return CUR_YEAR - stoi(getDateOfBirth().substr(6,4)) - 1;
    }
    return CUR_YEAR - stoi(getDateOfBirth().substr(6,4));
  }
  
  void displayInfo(){
    cout << "Name: " << getName() << "\n";
    cout << "Age: " << getAge() << "\n";
  }
};

int main(){
  Person A = Person("Phong","10/09/2006");
  A.displayInfo();
  return 0;
  /*output:
  
  Name: Phong
  Age: 19
  */
  
  
  return 0;
}
