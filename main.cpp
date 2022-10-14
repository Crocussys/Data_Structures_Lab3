#include <iostream>
#include <fstream>
#include "node.h"

const int SIZE_NODE_ARRAY = 3;

using namespace std;

void usage()
{
    cout << "Lab3 [path]" << endl << endl;
    cout << "path - Файл бинарного дерева" << endl;
    cout << endl << "Error: Not enough arguments" << endl;
}

Node* newNode(int** array, int nodeID)
{
    Node* node = new Node;
    node->setNumber(array[nodeID - 1][0]);
    int leftId = array[nodeID - 1][1];
    int rightId = array[nodeID - 1][2];
    if (leftId != 0){
        Node* left_node = newNode(array, leftId);
        node->setLeft(left_node);
    }else
        node->setLeft(nullptr);
    if (rightId != 0){
        Node* right_node = newNode(array, rightId);
        node->setRight(right_node);
    }else
        node->setRight(nullptr);
    return node;
}

int searchRoot(int** array, int size, int rootId = 1)
{
    for (int i = 0; i < size; i++){
        if (array[i][1] == rootId or array[i][2] == rootId){
            return searchRoot(array, size, i + 1);
        }
    }
    return rootId;
}

Node* inFile(fstream& file)
{
    int size;
    file >> size;
    int** array = new int* [size];
    for (int i = 0; i < size; i++){
        array[i] = new int [SIZE_NODE_ARRAY];
        for (int j = 0; j < SIZE_NODE_ARRAY; j++){
            file >> array[i][j];
        }
    }
    Node* root = newNode(array, searchRoot(array, size));
    delete [] array;
    return root;
}

Node** search(Node* node, int depth = 1)
{
    Node** left_array;
    Node** right_array;
    Node* left_node = node->getLeft();
    if (left_node != nullptr){
        left_array = search(left_node, depth + 1);
    }else{
        left_array = new Node*[depth]; // <- ошибка
    }
    Node* right_node = node->getRight();
    if (right_node != nullptr){
        right_array = search(right_node, depth + 1);
    }else{
        right_array = new Node*[depth];
    }
    size_t size_left = (&left_array)[1] - left_array;
    size_t size_right = (&right_array)[1] - right_array;
    Node** ans_array;
    if (size_left >= size_right){
        ans_array = left_array;
    }else{
        ans_array = right_array;
    }
    ans_array[depth] = node;
    return ans_array;
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
    Node* tree = inFile(file);
    file.close();
    cout << *tree << endl;
    Node** ans = search(tree);
    size_t size = (&ans)[1] - ans;
    if (size != 0)
        cout << ans[0]->getNumber();
    for (size_t i = 1; i < size; i++){
        cout << " -> " << ans[i]->getNumber();
    }
    delete [] ans;
    cout << endl << "Длина максимального пути: " << size << endl;
    return 0;
}
