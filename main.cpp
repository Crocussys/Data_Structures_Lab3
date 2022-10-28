#include <iostream>
#include <fstream>
#include "node.h"
#include "myvector.h"

const int SIZE_NODE_ARRAY = 3;

using namespace std;

void usage()
{
    cout << "Lab3 [path]" << endl << endl;
    cout << "path - Файл бинарного дерева" << endl;
    cout << endl << "Error: Not enough arguments" << endl;
}

Node* newNode(int** array, int nodeID)  // Перенос информации из массива в объект
{
    Node* node = new Node;
    node->setId(nodeID);
    node->setNumber(array[nodeID][0]);
    int leftId = array[nodeID][1];
    int rightId = array[nodeID][2];
    if (leftId != -1){
        Node* left_node = newNode(array, leftId);
        node->setLeft(left_node);
    }else
        node->setLeft(nullptr);
    if (rightId != -1){
        Node* right_node = newNode(array, rightId);
        node->setRight(right_node);
    }else
        node->setRight(nullptr);
    return node;
}

int searchRoot(int** array, int size, int rootId = 0)
{
    for (int i = 0; i < size; i++){                           // Проходимся по таблице
        if (array[i][1] == rootId or array[i][2] == rootId){  // И проверяем что предполагамый корень
            return searchRoot(array, size, i);                // не является чьим-то потомком
        }                                                     // Иначе прдполагаемым корнем становится этот потомок
    }                                                         // И повторяем проход по таблице
    return rootId;
}

Node* inFile(fstream& file)
{
    int size;
    file >> size;
    int** array = new int* [size];                 // Переносим таблицу из файла в массив
    for (int i = 0; i < size; i++){
        array[i] = new int [SIZE_NODE_ARRAY];
        for (int j = 0; j < SIZE_NODE_ARRAY; j++){
            file >> array[i][j];
        }
    }
    Node* root = newNode(array, searchRoot(array, size));  // Создаём объект дерева
    delete [] array;
    return root;                                   // И возвращаем ссылку на корень
}

MyVector search(Node node)
{
    Node* left_node = node.getLeft();
    Node* right_node = node.getRight();
    MyVector left_path = MyVector();
    MyVector right_path = MyVector();
    MyVector ans = MyVector();
    if (node.getNumber() % 2 == 0){        // Проверка на нечётность по заданию
        return ans;
    }
    if (left_node != nullptr){             // Рекурсивный поиск вглубь слева
        left_path = search(*left_node);
    }
    if (right_node != nullptr){            // и справа
        right_path = search(*right_node);
    }
    if (left_path.get_size() >= right_path.get_size()){  // Выбираем длинный путь
        ans = left_path;
    }else{
        ans = right_path;
    }
    ans.push_back(node);  // Добавляем себя
    return ans;           // Передаём этот путь вверх по дереву
}

int main(int argc, char* argv[])
{
    if (argc < 2){
        usage();
        return -1;
    }
    fstream file(argv[1], ios::in);
    if (!file){
        cout << "File open error" << endl;
        return -2;
    }
    Node* tree = inFile(file);       // Считываем дерево из файла
    file.close();
    tree->print();                   // Выведем для проверки
    cout << endl << endl;
    MyVector path = search(*tree);   // Ищем нужный путь
    cout << "root";                  // Далее вывод результатов на экран
    int len = path.get_size() - 1;
    for (int i = len; i >= 0; i--){
        cout << " -> " << path.get_element(i).getNumber();
    }
    cout << endl << "Длина максимального пути: " << len << endl;
    return 0;
}
