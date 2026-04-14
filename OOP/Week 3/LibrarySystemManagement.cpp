#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BorrowerRecord;
class Book;
class Library;

class Book {
private:
    string CatalogueNumber;
    string Author;
    string Title;
    BorrowerRecord* borrower;

public:
    Book(string CatalogueNumber, string Author, string Title) {
        this->setCatalogueNumber(CatalogueNumber);
        this->setAuthor(Author);
        this->setTitle(Title);
        this->setBorrower(nullptr); 
    }

    Book() : Book("", "", "") {}

    void setCatalogueNumber(string cn) { this->CatalogueNumber = cn; }
    void setAuthor(string a) { this->Author = a; }
    void setTitle(string t) { this->Title = t; }
    void setBorrower(BorrowerRecord *borrower){ this->borrower = borrower; }

    string getCatalogueNumber() { return CatalogueNumber; }
    string getAuthor() { return Author; }
    string getTitle() { return Title; }
    BorrowerRecord* getBorrower() { return borrower; }
    
    void attachBorrower(BorrowerRecord* b) { this->borrower = b; }
    void dettachBorrower(){ this->borrower = nullptr; }

    // Chỉ khai báo, định nghĩa ở cuối file
    void display();
}; 

class BorrowerRecord {
private:
    string name;
    vector<Book*> books;

public:
    BorrowerRecord(string name) { this->name = name; }

    void setName(string name) { this->name = name; }
    string getName() { return name; }

    // Cập nhật 2 chiều để dữ liệu đồng bộ
    void attachBook(Book* b) {
        if (b != nullptr && b->getBorrower() == nullptr) {
            books.push_back(b);
            b->attachBorrower(this);
        }
    }
    
    // Trả sách
    void detachBook(Book* b) {
        auto it = find(books.begin(), books.end(), b); // So sánh con trỏ trực tiếp
        if (it != books.end()) {
            books.erase(it);
            b->attachBorrower(nullptr); // Sách không còn người mượn
        }
    }

    void displayBorrowedBooks() {
        cout << "--- Danh sach muon cua: " << name << " ---\n";
        if (books.empty()) {
            cout << "(Trong)\n";
        } else {
            for (Book* b : books) {
                cout << "+ " << b->getTitle() << " [" << b->getCatalogueNumber() << "]\n";
            }
        }
        cout << "--------------------------\n";
    }
};

class Library{
  string name;
  vector <BorrowerRecord*> BorrowerList;
  vector <Book*> Stock;
  
  public:
  Library(string name) { this->setName(name); }
  
  void setName(string name) { this->name = name; }
  
  string getName() { return name; }
  vector <Book*> getStock() { return Stock; }
  vector <BorrowerRecord*> getBorrowerRecord() { return BorrowerList; }
  
  void registerOneBorrower(string borrowerName) {
    BorrowerList.push_back(new BorrowerRecord(borrowerName));
    printf("SUCCESS!\n");
  }
  
  void addOneBook(string CatalogueNumber, string Author, string Title) {
    Stock.push_back(new Book(CatalogueNumber, Author, Title));
    printf("SUCCESS!\n");
  }
  
  void displayBooksAvailable(){
    for(auto i : this->getStock()){
      if(i->getBorrower() == nullptr){
        i->display();
      }
    }
  }
  
  void displayBookOnLoan(){
    for(auto i : this->getStock()){
      if(i->getBorrower() != nullptr){
        i->display();
      }
    }
  }
  
  
  void lendOneBook(string CatalogueNumber, string BorrowerName){
    Book* b = nullptr;
    BorrowerRecord* borrower = nullptr;

    for(auto i : this->getStock()){
        if(i->getCatalogueNumber() == CatalogueNumber){
            b = i;
            break;
        }
    }

    for(auto i : this->getBorrowerRecord()){
        if(i->getName() == BorrowerName){
            borrower = i;
            break;
        }
    }

    if(b != nullptr && borrower != nullptr && b->getBorrower() == nullptr){
        borrower->attachBook(b);
    }
}
  
  void returnOneBook(string CatalogueNumber) {
    for(auto i : this->getStock()){
      if(i->getCatalogueNumber() == CatalogueNumber){
        i->dettachBorrower();
      }
    }
  }
  
};

// 2. Định nghĩa display() sau khi BorrowerRecord đã hoàn tất
void Book::display() {
    cout << "Ten sach: " << Title << "\n";
    cout << "Tac gia:  " << Author << "\n";
    cout << "Ma so:    " << CatalogueNumber << "\n";
    
    if (borrower != nullptr) {
        cout << "Trang thai: Dang muon boi [" << borrower->getName() << "]\n";
    } else {
        cout << "Trang thai: San sang cho muon\n";
    }
    cout << "--------------------------\n";
}

int main(){
  hcmus.display();
  hcmus.registerOneBorrower("Chris");
  hcmus.registerOneBorrower("Elton");
  
  return 0;
}
