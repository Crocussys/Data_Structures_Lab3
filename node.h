#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

/* Класс узла дерева */
class Node
{
private:
    int id;
    int number;
    Node* right;
    Node* left;
public:
    Node();
    int getId();
    int getNumber();
    Node* getRight();
    Node* getLeft();
    void setId(int ind);
    void setNumber(int number);
    void setRight(Node* node);
    void setLeft(Node* node);
    void print(int step = 0);   // Вывести дерево на экран
};

#endif // NODE_H
