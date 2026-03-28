#include <iostream>
#include <string>

using namespace std;


class House{
  private:
  string address;
  int theNumberOfRoom;
  
  public:
  House(string address, int theNumberOfRoom){
    this->setAddress(address);
    this->setTheNumberOfRoom(theNumberOfRoom);
  }
House(string address) : House(address, theNumberOfRoom = 0){}
  
  void setTheNumberOfRoom(int theNumberOfRoom){
    this->theNumberOfRoom = theNumberOfRoom;
  }
  
  void setAddress(string address){
    this->address = address;
  }
  
  string getAddress(){
    return address;
  }
  
  int getTheNumberOfRoom(){
    return theNumberOfRoom;
  }
  
  void extendRoom(int amountOfRoom){
    if(-amountOfRoom > this->getTheNumberOfRoom() && amountOfRoom < 0){
      cout << "INVALID AMOUNT OF ROOM!" << "\n";
      return;
    }
    
    this->setTheNumberOfRoom(this->getTheNumberOfRoom() + amountOfRoom);
    cout << "SUCCESS!" << "\n";
  }
  
};
  
  
  
