#include <iostream>
#include <string>

class Student{
  private:
  string name;
  string address;
  string matriculationNumber;
  
  public:
  Student(string name, string address, string matriculationNumber){
    this->setName(name);
    this->setAddress(address);
    this->setMatriculationNumber(matriculationNumber);
  }
  Student(string name, string matriculationNumber) : Student(name, address = NULL, matriculationNumber){};
  Student(string matriculationNumber) : Student(name = NULL, address = NULL, matriculationNumber){};
  
  void setName(string name){
    this->name = name;
  }
  
  void setAddress(string address){
    this->address = address;
  }
  
  void setMatriculationNumber(string matriculationNumber){
    this->matriculationNumber = matriculationNumber;
  }
  
  string getName(){
    return this->name;
  }
  
  string getAddress(){
    return this->address;
  }
  
  string getMatriculationNumber(){
    return this->mmatriculationNumber;
  }
}
