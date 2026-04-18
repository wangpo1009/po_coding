#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BorrowerRecord;
class Book;
class Library;


//======================= BOOK ==========================
class Book {
private:
    string CatalogueNumber;
    string Author;
    string Title;
    BorrowerRecord* borrower;

public:
// Constructor
    Book(string CatalogueNumber, string Author, string Title) {
        this->setCatalogueNumber(CatalogueNumber);
        this->setAuthor(Author);
        this->setTitle(Title);
        this->setBorrower(nullptr); 
    }

    Book() : Book("", "", "") {}

// Setter
    void setCatalogueNumber(string cn) { this->CatalogueNumber = cn; }
    void setAuthor(string a) { this->Author = a; }
    void setTitle(string t) { this->Title = t; }
    void setBorrower(BorrowerRecord *borrower){ this->borrower = borrower; }

// Getter
    string getCatalogueNumber() { return CatalogueNumber; }
    string getAuthor() { return Author; }
    string getTitle() { return Title; }
    BorrowerRecord* getBorrower() { return borrower; }
    
// Inner Function
    void attachBorrower(BorrowerRecord* b) { setBorrower(b); }
    void dettachBorrower(){ this->borrower = nullptr; }

// Chỉ khai báo, định nghĩa ở cuối file
    void display();
}; 

//===================== BORROWER RECORD =============================
class BorrowerRecord {
private:
    string name;
    vector<Book*> books;

public:
// Constructor
    BorrowerRecord(string name) { this->name = name; }
    BorrowerRecord() : BorrowerRecord(" "){}

// Getter & Setter
    void setName(string name) { this->name = name; }
    string getName() { return name; }

// Inner Func
    void attachBook(Book* b) {
        if (b != nullptr && b->getBorrower() == nullptr) {
            books.push_back(b);
            b->attachBorrower(this);
        }
    }
    
    void detachBook(Book* b) {
        auto it = find(books.begin(), books.end(), b); // So sánh con trỏ trực tiếp
        if (it != books.end()) {
            books.erase(it);
            b->attachBorrower(nullptr); // Sách không còn người mượn
        }
    }

    void displayBorrowedBooks() {
        cout << "--- Danh sach muon cua: " << this->getName() << " ---\n";
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


//======================== LIBRARY ============================
class Library{
  string name;
  vector <BorrowerRecord*> BorrowerList;
  vector <Book*> Stock;
  
  public:
// Constructor
  Library(string name) { this->setName(name); }
  
// Destructor
  ~Library(){
    this->Stock.clear();
    for(auto i : this->getBorrowerList()) {
      delete(i);
    }
    this->BorrowerList.clear();
  }
  
// Getter & Setter
  void setName(string name) { this->name = name; }
  
  string getName() { return name; }
  vector <Book*> getStock() { return Stock; }
  vector <BorrowerRecord*> getBorrowerList() { return BorrowerList; }

// Inner Func
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

    for(auto i : this->getBorrowerList()){
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
    cout << "Ten sach: " << this->getTitle() << "\n";
    cout << "Tac gia:  " << this->getAuthor() << "\n";
    cout << "Ma so:    " << this->getCatalogueNumber() << "\n";
    
    if (borrower != nullptr) {
        cout << "Trang thai: Dang muon boi [" << borrower->getName() << "]\n";
    } else {
        cout << "Trang thai: San sang cho muon\n";
    }
    cout << "--------------------------\n";
}

int main(){
  Library hcmus("HCMUS Library");


    hcmus.addOneBook("B01", "J.K. Rowling", "Harry Potter");
    hcmus.addOneBook("B02", "J.R.R. Tolkien", "The Hobbit");
    hcmus.registerOneBorrower("Chris");
    hcmus.registerOneBorrower("Elton");
  printf("\n");
 
    hcmus.displayBooksAvailable();
    hcmus.lendOneBook("B01", "Chris");
    
  printf("\n");
  
    hcmus.displayBooksAvailable();
    
  printf("\n");
    
    hcmus.returnOneBook("B01");
    hcmus.displayBooksAvailable();
  
  return 0;
}
