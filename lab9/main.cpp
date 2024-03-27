#include <iostream>
#include "BinaryTree.h"

int main(){
    std::string userInput;
    template class Node<int>;
    template class BinaryTree<int>;
    BinaryTree t = new BinaryTree();
    t.insert(10);
    t.insert(13);
    t.insert(8);
    t.insert(12);
    t.insert(11);
    t.insert(9);
    t.insert(7);
    t.find(11);
    t.find(0);
    t.size();
    std::cout << t.getAllAscending();
    std::cout << t.remove(12);
    std::cout << t.remove(9);
    std::cout << t.getAllDecending();
    t.emptyTree();
    std::cout << t.getAllAscending();
    return 0;
}
