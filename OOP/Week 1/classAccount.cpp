#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Account{
  private:
  string number;
  int balance;
  
  public:
  Account(string number, int balance){
    this->setNumber(number);
    this->setBalance(balance);
  }
  Account(string number) : Account(number, 0){}
  
  void setNumber(string number){
    this->number = number;
  }
  
  void setBalance(int balance){
    this->balance = balance;
  }
  
  string getNumber(){
    return number;
  }
  
  int getBalance(){
    return balance;
  }
  
  void credit(int amount){
    if(amount < 0) {
      cout << "Invalid Amount!\n";
      return ;
    }
     
    this->setBalance(this->getBalance() + amount);
    cout << "Success!\n";
  }
  
  void debit(int amount){
    if(amount > getBalance()){
      cout << "Not Enough Money In Balance!\n";
      return ;
    }
    
    this->setBalance(this->getBalance() - amount);
    cout << "Success!\n";
  }
  
  void displayInfo(){
    cout << "Number: " << getNumber() << "\n";
    cout << "Balance: " << getBalance() << "\n";
  }
};

int main(){
  Account A = Account("Phong",1000);
  A.displayInfo();
  
  A.credit(100);
  A.displayInfo();
  
  A.debit(10000);
  A.displayInfo();
  return 0;
  /*output:
  
  Number: Phong
Balance: 1000
Success!
Number: Phong
Balance: 1100
Not Enough Money In Balance!
Number: Phong
Balance: 1100
  */
  
  
  return 0;
}
