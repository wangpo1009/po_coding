#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Section;
class Course;
class Person;
class Transcript;
class Student;
class Professor;
class TranscriptEntry;
//==================== Môn học ===========================
// Một khóa học có nhiều section
// Mỗi section có thể được giảng dạy bởi một giảng viên và 
// được tham gia bởi nhiều sinh viên và một số section chỉ được tham gia 
// khi sinh viên đã tham gia một số các môn học nhất định trước đó

class Course{
    string courseName;
    int courseNo;
    int credits;
    vector <Section*> SectionList;
    vector <Course*> prerequisites;

    public:
    Course(string name, int no, int cre) {
        this->setName(name);
        this->setCourseNo(no);
        this->setCredits(cre);
    }
    Course() : Course("Phong", 10, 9) {}
    ~Course() {
        for(Section* i : SectionList) {
            delete i;
        }
    }

    //Setters
    void setName(string name) {
        this->courseName = name;
    }
    void setCourseNo(int no) {
        this->courseNo = no;
    }
    void setCredits(int c) {
        this->credits = c;
    }
    void addPrerequisite(Course* course) {
        prerequisites.push_back(course);
    }

    //Getters
    string getName() {
        return this->courseName;
    }
    int getCourseNo() {
        return this->courseNo;
    }
    int getCredits() {
        return this->credits;
    }
    vector<Course*>& getPrerequisites() {
        return this->prerequisites;
    }
    vector <Section*>& getSectionList() {
        return this->SectionList;
    }

    void scheduleSection(int no, string day, string time, string room, int seatCap) {
        for(auto i : this->getSectionList()) {
            if(i->getSectionNo() == no) {
                cout << "Section no exsisted!\n";
                return;
            }

            if(i->getRoom() == room && i->getTimeOfDay() == time && i->getDayOfWeek() == day) {
                cout << "Room occupied!\n";
                return;
            }
        }
        Section* Phong = new Section(no, day, time, room, seatCap, this);
        SectionList.push_back(Phong);

        cout << "Section created!\n";
    }

    bool hasPrerequisite() {
        if(this->getPrerequisites().empty()) {
            return false; //Khong co mon tien quyet
        }
        return true;
    }

    void addPrerequisite(Course* course) {
        if(this->getName() == course->getName()) {
            cout << "Cant!\n";
            return;
        }
        this->getPrerequisites().push_back(course);
    }

    void display() {
    cout << "===== COURSE =====\n";
    cout << "Course Name : " << this->getName() << endl;
    cout << "Course No   : " << this->getCourseNo() << endl;
    cout << "Credits     : " << this->getCredits() << endl;
    }
    


};


class Section {
    private:
    int sectionNo;
    string dayOfWeek;
    string timeOfDay;
    string room;
    int seatingCapacity;
    Course* course;
    Professor* Phofessor;
    vector <Student*> studentList;

    public:
    Section(int no, string day, string time, string room, int cap, Course* coursePtr) {
        this->setSectionNo(no);
        this->setDayOfWeek(day);
        this->setTimeOfDay(time);
        this->setRoom(room);
        this->setSeatingCapacity(cap);
        this->setCourse(coursePtr);
    } 

    // Setters
    void setSectionNo(int no) {
        this->sectionNo = no;
    }
    void setDayOfWeek(string d) {
        this->dayOfWeek = d;
    }
    void setTimeOfDay(string t) {
        this->timeOfDay = t;
    }
    void setRoom(string room) {
        this->room = room;
    }
    void setSeatingCapacity(int cap) {
        this->seatingCapacity = cap;
    }
    void setCourse(Course* A) {
        this->course = A;
    }
    void setProfessor(Professor* Professor) {
        if(this->getProfessor() == nullptr) {
            this->Phofessor = Professor;
        }
        else cout << "Da co giang vien!\n";
    }

    // Getters
    int getSectionNo() {
        return this->sectionNo;
    }
    string getDayOfWeek() {
        return this->dayOfWeek;
    }
    string getTimeOfDay() {
        return this->timeOfDay;
    }
    string getRoom() {
        return this->room;
    }
    int getSeatingCapacity() {
        return this->seatingCapacity;
    }
    Course* getCourse() {
        return this->course;
    }
    Professor* getProfessor() {
        return this->Phofessor;
    }
    vector <Student*>& getStudentList() {
        return this->studentList;
    }

    bool confirmSeatAvailbality() {
        if(studentList.size() < this->getSeatingCapacity()) {
            return true;
        }
        return false;
    }
    // trong ham enroll nay can thoa ma 3 dieu kien
    // Sinh vien khong dang tham gia section nay (da kiem tra trong ham addSection)
    // So ghe con du
    // Sinh vien da tham gia cac mon tien quyet neu co

    void enroll(Student* student) {
        if(!this->confirmSeatAvailbality()) {
            cout << "Full!\n";
            return;
        }

        if(!this->getCourse()->hasPrerequisite()) {
            student->addSection(this);
            this->getStudentList().push_back(student);
            cout << "Succeed!\n";
            return;
        }

        for(auto i : this->getCourse()->getPrerequisites()){
            if(!student->isEnrolledIn(i)) {
                cout << "Haven't finished prerequistie!\n";
                return;
            }
        }

        student->addSection(this);
        this->getStudentList().push_back(student);
        cout << "Succeed!\n";
    }

    void display() {
    cout << "\n===== SECTION =====\n";

    cout << "Section No  : " << this->getSectionNo() << endl;
    cout << "Day         : " << this->getDayOfWeek() << endl;
    cout << "Time        : " << this->getTimeOfDay() << endl;
    cout << "Room        : " << this->getRoom() << endl;
    cout << "Capacity    : " << this->getSeatingCapacity() << endl;

    if(course != nullptr) {
        cout << "Course      : "
             << course->getName()
             << endl;
    }

    if(Phofessor != nullptr) {
        cout << "Professor   : "
             << Phofessor->getName()
             << endl;
    }
    }
};
// ================== Người ========================
class Person {
    private:
    string ssn;
    string name;

    public:
    Person(string ssn, string name) {
        this->setSsn(ssn);
        this->setName(name);
    }
    ~Person() {}

    void setSsn(string ssn) {
        this->ssn = ssn;
    }
    void setName(string name) {
        this->name = name;
    }


    string getSsn() {
        return this->ssn;
    }
    string getName() {
        return this->name;
    }

    virtual void display() {
    cout << "SSN  : " << this->getSsn() << endl;
    cout << "Name : " << this->getName() << endl;
    }

};

class Student : public Person {
    private:
    string major;
    string degree;
    vector <Section*> currentSections;
    Transcript* transcript = new Transcript();

    public:
    Student(string ssn, string name, string major, string degree) : Person(ssn, name) {
        this->setDegree(degree);
        this->setMajor(major);
    }
    ~Student() {
        delete transcript;
    }


    void setMajor(string major) {
        this->major = major;
    }
    void setDegree(string degree) {
        this->degree = degree;
    }

    string getMajor() {
        return this->major;
    }
    string getDegree() {
        return this->degree;
    }
    Transcript* getTranscript() {
        return this->transcript;
    }
    vector <Section*>& getSectionRec() {
        return this->currentSections;
    }

    void addSection(Section* section) {
        for(auto i : this->getSectionRec()) {
            if(i == section) {
                cout << "Already in!\n";
                return;
            }
        }
        // Day vao Danh sach section dang tham du
        this->getSectionRec().push_back(section);

        // Tao transcriptEntry khoi diem = 0;
        this->getTranscript()->completeVerify(section, 0);


        cout << "Succeed!\n";
    }

    bool isEnrolledIn(Course* course) {
        if(this->getTranscript()->findCompletedCourse(course)) return true;
        return false;
    }

    void display() override {
    cout << "\n===== STUDENT =====\n";

    Person::display();

    cout << "Major  : " << major << endl;
    cout << "Degree : " << degree << endl;
    }

    
};

class Professor : public Person {
    private:
    string title;
    string department;
    vector <Section*> SectionList;

    public:
    Professor(string ssn, string name, string title, string department) : Person(ssn, name){
        this->setTitle(title);
        this->setDepartment(department);
    }

    void setTitle(string title) {
        this->title = title;
    }
    void setDepartment(string department) {
        this->department = department;
    }

    string getTitle() {
        return this->title;
    }
    string getDepartment() {
        return this->department;
    }

    void agreeToTeach(Section* Phong){
        if(Phong->getProfessor() == nullptr) {
            Phong->setProfessor(this);
            SectionList.push_back(Phong);
            cout << "Giang vien: "<< this->getName() <<" - Lop:"<<Phong->getSectionNo();
        }
    } 
    void display() override {

    cout << "\n===== PROFESSOR =====\n";

    Person::display();

    cout << "Title      : " << this->getTitle() << endl;
    cout << "Department : " << this->getDepartment() << endl;
    }
}; 

// Điểm số
class TranscriptEntry {
    private:
    int grade;
    Section* section;


    public:
    void setGrade(int grade) {
        this->grade = grade;
    }
    void setSectionRec(Section* section) {
        this->section = section;
    }

    int getGrade() {
        return this->grade;
    }
    Section* getSectionRec() {
        return this->section;
    }

    void display() {

    cout << "\n===== TRANSCRIPT ENTRY =====\n";

    cout << "Grade : " << this->getGrade() << endl;

    if(section != nullptr) {

        cout << "Course : "
             << this->getSectionRec()->getCourse()->getName()
             << endl;

        cout << "Section : "
             << this->getSectionRec()->getSectionNo()
             << endl;
    }
    }
};

// Một học sinh khi đăng kí học sẽ sinh ra một bảng điểm
// Trong bảng điểm này sẽ lưu lại nhiều record tên là transcriptEntry

class Transcript {
    private:
    vector <TranscriptEntry*> Entries;

    public:
    //Trong ham nay ta can phai xem diem so cua sinh vien sau khi 
    //tham gia section, giong nhu mot ham add entry vao entries
    void completeVerify(Section* section, int grade) {
        for(auto &i : Entries) {
            if(i->getSectionRec()->getCourse() == section->getCourse()) {
                i->setGrade(grade);
                i->setSectionRec(section);
                return;
            }
        }
    
        TranscriptEntry* newEntries = new TranscriptEntry();
        newEntries->setGrade(grade);
        newEntries->setSectionRec(section);
        
        Entries.push_back(newEntries);
    }

    bool findCompletedCourse(Course* course) {
        for(auto i : Entries) {
            if(i->getSectionRec()->getCourse() == course && i->getGrade() >= 5) {
                return true;
            }
        }
        return false;
    }
    
};
