#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkForbidden(char a) {
    string forbidden = "\\/:*?\"<>|";
    for(int i = 0; i < (int)forbidden.length(); i++) {
        if(a == forbidden[i]) return true;
    }
    return false;
}

bool checkTail(string name, string val) {
    if(name.length() < val.length()) return false;

    return name.substr(name.length() - val.length()) == val;
}

bool validFileName(string name, string val = "") {
    string forbidden = "\\/:*?\"<>|";
    
    if(!checkTail(name, val)) return false;
    
    
    for(int i = 0; i < name.length() - val.length(); i++) {
        if( checkForbidden(name[i]) ) return false;
        if( name[i] == '.') return false;
    }
    return true;
}

class Object{
    private:
    string name;

    public:
    Object(string name) {
        this->setName(name);
    }

    virtual void setName(string name) {
        if(!validFileName(name)) {
            cout << "File name no good!\n";
            return;
        } 
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    virtual void display() {
        cout << "Name:" << this->getName() << "\n";
    }
};

class Image : public Object {
    public:
    Image(string name) : Object(""){
        setName(name);
    }

    void setName(string name) override {
        if(!validFileName(name, ".png")) {
            cout << "File name not good!\n";
            return;
        }
        Object :: setName(name);
    }

};

class Audio : public Object {
    public:
    Audio(string name) : Object(""){
        setName(name);
    }

    void setName(string name) override {
        if(!validFileName(name, ".mp3")) {
            cout << "File name not good!\n";
            return;
        }
        Object :: setName(name);
    }
};

class HTMLFile : public Object {
    private:
    vector <Object*> InnerObjects;

    public:
    HTMLFile(string name) : Object(""){
        setName(name);
    }
    ~HTMLFile() {}

    void setName(string name) override {
        if(!validFileName(name, ".html")) {
            cout << "File name not good!\n";
            return;
        }
        Object :: setName(name);
    }

    void addObject(Object* obj) {
        InnerObjects.push_back(obj);
    }

    void deleteObject(Object* obj) {
        auto pos = find(InnerObjects.begin(), InnerObjects.end(), obj);
        if(pos == InnerObjects.end()) {
            cout << "Object not found!\n";
            return;
        }
        InnerObjects.erase(pos);
    }

    int countObject() {
        int count = 0;
        for(auto i : InnerObjects) {
            count++;
        }
        return count;
    }

    void display() override {
        cout << "Name:" << getName() << "\n";
        cout << "Number of Object containing: " << this->countObject() << "\n";
        for (auto i : InnerObjects) {
            cout << "\t";
            i->display();
        }
    }
};


int main() {
    HTMLFile home = HTMLFile("home.html");
    HTMLFile header = HTMLFile("header.html");
    HTMLFile main = HTMLFile("main.html");
    HTMLFile footer = HTMLFile("footer.html");
    Image pic1 = Image("header.png");
    Image pic2 = Image("main.png");
    Audio au1 = Audio("audio.mp3");

    home.addObject(&header);
    home.addObject(&main);
    home.addObject(&footer);

    header.addObject(&pic1);
    main.addObject(&pic2);
    main.addObject(&au1);

    home.display();


}

