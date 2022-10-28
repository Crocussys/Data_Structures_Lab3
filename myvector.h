#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "node.h"


/* Самописный вектор для узлов */
class MyVector
{
private:
    int size;
    Node* array;
public:
    MyVector();
    void push_back(Node node);  // Вставить в конец
    Node get_element(int i);    // Получить элемент по индексу
    int get_size();             // Получить размер
};

#endif // MYVECTOR_H
