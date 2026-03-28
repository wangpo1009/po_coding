#include <iostream>
#include <string>

using namespace std;


class Point{
  private:
  int x, y;

  public:
  Point(int x, int y){
    this->setX(x);
    this->setY(y);
  }
  Point() : Point(0,0){}
  
  void setX(int x){
    this->x = x;
  }
  
  void setY(int y){
    this->y = y;
  }
  
  int getX(){
    return x;
  }
  
  int getY(){
    return y;
  }
  
  void moveBy(int x, int y){
    this->setX(this->getX() + x);
    this->setY(this->getY() + y);
  }
};

class Line{
  private:
  Point Start;
  Point End;
  
  public:
  Line(Point A, Point B){
    this->setStart(A);
    this->setEnd(B);
  }
  Line(Point A) : Line(A, Point(0,0)){}
  
  void setStart(Point A){
    this->Start = A;
  }
  
  void setEnd(Point B){
    this->End = B;
  }
  
  Point getStart(){
    return this->Start;
  }
  
  Point getEnd(){
    return this->End;
  }
  
  bool isHorizontal(){
    if( this->getStart().getX() == this->getEnd().getX() ) return true;
    return false;
  }
  
  bool isVertical(){
    if( this->getStart().getY() == this->getEnd().getY() ) return true;
    return false;
  }
  
  void moveBy(int x, int y){
    Point C = Point(this->getStart().getX() + x,  this->getStart().getY() + y);
    Point D = Point(this->getEnd().getX() + x,  this->getEnd().getY() + y);
    this->setEnd(D);
    this->setStart(C);
  }
    
  
  void display(){
    cout << "From: (" << this->getStart().getX() << "," << this->getStart().getY() << ") \n";
    cout << "To: (" << this->getEnd().getX() << "," << this->getEnd().getY() << ") \n";
    
  }
  
};

int main() {
    // 1. Khởi tạo các điểm
    Point p1(10, 5);
    Point p2(20, 5);
    Point p3(10, 15);

    cout << "--- TEST CASE 1: Doan thang Ngang (Horizontal) ---" << endl;
    Line ngang(p1, p2); 
    ngang.display();
    cout << "Co phai duong ngang? " << (ngang.isHorizontal() ? "Co" : "Khong") << endl;
    cout << "Co phai duong doc? " << (ngang.isVertical() ? "Co" : "Khong") << endl;

    cout << "\n--- TEST CASE 2: Doan thang Doc (Vertical) ---" << endl;
    Line doc(p1, p3);
    doc.display();
    cout << "Co phai duong ngang? " << (doc.isHorizontal() ? "Co" : "Khong") << endl;
    cout << "Co phai duong doc? " << (doc.isVertical() ? "Co" : "Khong") << endl;

    cout << "\n--- TEST CASE 3: Di chuyen (moveBy) ---" << endl;
    cout << "Truoc khi di chuyen (Line ngang):" << endl;
    ngang.display();
    
    // Di chuyển toàn bộ đoạn thẳng thêm x=5, y=10
    ngang.moveBy(5, 10);
    
    cout << "Sau khi di chuyen (x+5, y+10):" << endl;
    ngang.display();

    cout << "\n--- TEST CASE 4: Constructor mac dinh ---" << endl;
    Line macDinh(p1); // Ket thuc tai (0,0) theo logic code cua ban
    macDinh.display();

    return 0;
}








