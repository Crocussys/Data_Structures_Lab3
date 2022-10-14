#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
private:
    int number;
    Node* right;
    Node* left;
public:
    Node();
    //Node(int number, Node* left, Node* right);
    int getNumber();
    Node* getRight();
    Node* getLeft();
    void setNumber(int number);
    void setRight(Node* node);
    void setLeft(Node* node);

    friend ostream& operator << (ostream &out, Node &node);
};

#endif // NODE_H
