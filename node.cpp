#include "node.h"

Node::Node()
{
    number = 0;
    right = nullptr;
    left = nullptr;
}
//Node::Node(int n, Node* l, Node* r)
//{
//    number = n;
//    right = r;
//    left = l;
//}
int Node::getNumber()
{
    return number;
}
Node* Node::getRight()
{
    return right;
}
Node* Node::getLeft()
{
    return left;
}
void Node::setNumber(int n)
{
    number = n;
}
void Node::setRight(Node* node)
{
    right = node;
}
void Node::setLeft(Node* node)
{
    left = node;
}
ostream& operator << (ostream &out, Node &node)
{
    int n = node.getNumber();
    out << n;
    Node* right_node = node.getRight();
    if (right_node != nullptr){
        out << " -> " << *right_node;
    }
    Node* left_node = node.getLeft();
    if (left_node != nullptr){
        out << endl << n << " -> " << *left_node;
    }
    return out;
}
