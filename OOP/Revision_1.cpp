#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//===================================================
class Node {
    private:
    int val;

    public:
    Node(int val) {
        this->setVal(val);
    }
    void setVal(int val) {
        this->val = val;
    }

    int getVal() {
        return this->val;
    }

    virtual void display() {
        cout << "NodeVal:" << this->getVal() << "\n";
    }

    virtual int sumTree() {
        return this->getVal();
    }

    virtual bool addLeaf(int val) = 0;

    virtual ~Node() {}
};


// =================================================
class Leaf : public Node {
    public:
    Leaf(int val) : Node (val) {}

    bool addLeaf(int val) override {
        return false;
    }

};


// =================================================
class Tree : public Node {
    private:
    Node* left;
    Node* right;

    public:
    Tree(int val) : Node(val) {
        this->setLeftLeaf(nullptr);
        this->setRightLeaf(nullptr);
    }
    ~Tree() {
        delete left;
        delete right;
    }

    void setLeftLeaf(Node* leaf) {
        this->left = leaf;
    }
    void setRightLeaf(Node* leaf) {
        this->right = leaf;
    }

    Node* getLeftLeaf() {
        return this->left;
    }

    Node* getRightLeaf() {
        return this->right;
    }


    bool addLeaf(int val){
        if(this->getLeftLeaf() == nullptr) {
            Leaf* left_l = new Leaf(val);
            this->setLeftLeaf(left_l);
            return true;
        }

        if(this->getRightLeaf() == nullptr) {
            Leaf* right_r = new Leaf(val);
            this->setRightLeaf(right_r);
            return true;
        }

        if(this->getLeftLeaf() != nullptr && this->getLeftLeaf()->addLeaf(val)) return true;
        if(this->getRightLeaf() != nullptr && this->getRightLeaf()->addLeaf(val)) return true;

        return false;
    }

    void addTree(int val) {
        if(this->getLeftLeaf() == nullptr) {
            Tree* tree_left = new Tree(val);
            this->setLeftLeaf(tree_left);
            return;
        }

        if(this->getRightLeaf() == nullptr) {
            Tree* tree_right = new Tree(val);
            this->setRightLeaf(tree_right);
            return;
        }

        cout << "Full tree, cant add!\n";
        return;
    }

    bool containLeaf() {
        if(this->getLeftLeaf() == nullptr && this->getRightLeaf() == nullptr) {
            return false;
        }
        return true;
    }

    int sumTree() override {
        int sum = this->getVal();

        if(this->getLeftLeaf() != nullptr) {
            sum += this->getLeftLeaf()->sumTree();
        }
        if(this->getRightLeaf() != nullptr) {
            sum += this->getRightLeaf()->sumTree();
        }

        return sum;
    }
};

int main() {

    Tree root = Tree(10);
    root.addTree(5);
    root.addLeaf(15);
    root.addLeaf(2);
    root.addLeaf(7);
    cout << "Sum tree:" << root.sumTree() << "\n";

    return 0;
}
