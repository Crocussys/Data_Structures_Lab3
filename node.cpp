#include "node.h"

Node::Node()
{
    id = -1;
    number = 0;
    right = nullptr;
    left = nullptr;
}
int Node::getId()
{
    return id;
}
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
void Node::setId(int ind)
{
    id = ind;
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
void Node::print(int step)
{
    int new_step = step + 4;  // Вычисляем отступ
    float n = number;
    while (n >= 1){
        new_step++;
        n /= 10;
    }
    cout << number;
    if (right != nullptr){                // Правый потомок
        cout << " -> ";
        right->print(new_step);
    }
    if (left != nullptr){                 // Левый потомок
        cout << endl;
        for (int i = 0; i < step; i++){
            cout << " ";
        }
        cout << number << " -> ";
        left->print(new_step);
    }
}
