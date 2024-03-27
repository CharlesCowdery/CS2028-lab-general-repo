#include <iostream>
#include "BinaryTree.h"

int main(){
    std::string userInput;
    BinaryTree<int> t = BinaryTree<int>();
    t.insert(10);
    t.insert(13);
    t.insert(8);
    t.insert(12);
    t.insert(11);
    t.insert(9);
    t.insert(7);
    std::cout << t.find(11) << std::endl;
    std::cout << t.find(0) << std::endl;
    int size = t.size();
    std::cout << size << std::endl;
    Node<int>** asc = t.getAllAscending();
    Node<int>** dsc = t.getAllDescending();
    for (int i = 0; i < size; i++) {
        std::cout << asc[i]->to_string() << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << dsc[i]->to_string() << " ";
    }
    std::cout << std::endl;
    //std::cout << t.remove(12).to_string();
    //std::cout << t.remove(9).to_string();
    //std::cout << t.getAllDecending();
    t.emptyTree();
    //std::cout << t.getAllAscending();
    return 0;
}
