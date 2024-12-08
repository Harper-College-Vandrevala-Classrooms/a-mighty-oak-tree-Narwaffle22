#include <iostream>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel() {}
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

class Tree {
private:
    Squirrel thisItem;
    Tree* leftItem;
    Tree* rightItem;

public:
    Tree() : leftItem(nullptr), rightItem(nullptr) {}
    Tree(Squirrel squirrel) : thisItem(squirrel), leftItem(nullptr), rightItem(nullptr) {}

    void setLeft(Tree* leftNode) {
        leftItem = leftNode;
    }
    void setRight(Tree* rightNode) {
        rightItem = rightNode;
    }
    Tree* getLeft() {
        return leftItem;
    }
    Tree* getRight() {
        return rightItem;
    }

    Squirrel getSquirrel() {
        return thisItem;
    }
};

int main() {
    Squirrel cheeks("Cheeks");
    Tree node_one(cheeks);

    Squirrel squeaks("Squeaks");
    Tree node_two(squeaks);

    Squirrel fluffybutt("Mr. Fluffy Butt");
    Tree node_three(fluffybutt);

    node_one.setLeft(&node_two);
    node_one.setRight(&node_three);

    Tree* retrieved_node_one = node_one.getLeft();  // Retrieves the left node
    Tree* retrieved_node_two = node_one.getRight(); // Retrieves the right node

    cout << "Left node contains squirrel: " << retrieved_node_one->getSquirrel().get_name() << endl;

    cout << "Right node contains squirrel: " << retrieved_node_two->getSquirrel().get_name() << endl;
}