#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Forward Declaration
class BorrowerRecord;

class Book {
private:
    string CatalogueNumber;
    string Author;
    string Title;
    BorrowerRecord* borrower;

public:
    Book(string CatalogueNumber, string Author, string Title) {
        this->CatalogueNumber = CatalogueNumber;
        this->Author = Author;
        this->Title = Title;
        this->borrower = nullptr; // Cực kỳ quan trọng: Khởi tạo giá trị rỗng
    }

    Book() : Book("", "", "") {}

    void setCatalogueNumber(string cn) { CatalogueNumber = cn; }
    void setAuthor(string a) { Author = a; }
    void setTitle(string t) { Title = t; }

    string getCatalogueNumber() { return CatalogueNumber; }
    string getAuthor() { return Author; }
    string getTitle() { return Title; }
    BorrowerRecord* getBorrower() { return borrower; }
    
    void attachBorrower(BorrowerRecord* b) { this->borrower = b; }

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

int main() {
    Book b1("B001", "To Hoai", "De Men Phieu Luu Ky");
    Book b2("B002", "Nam Cao", "Chi Pheo");
    BorrowerRecord user("Nguyen Van A");

    // 1. Mượn sách
    user.attachBook(&b1);
    user.attachBook(&b2);
    
    cout << "SAU KHI MUON:\n";
    b1.display();
    user.displayBorrowedBooks();

    // 2. Trả sách
    user.detachBook(&b1);
    
    cout << "SAU KHI TRA SACH B001:\n";
    b1.display();
    user.displayBorrowedBooks();

    return 0;
}
