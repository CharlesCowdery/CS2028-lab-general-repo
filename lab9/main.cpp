#include <iostream>
#include "BinaryTree.h"

int main(){
    std::string userInput;
    BinaryTree<int> t = BinaryTree<int>();
    t.insert(7);
    t.insert(6);
    t.insert(5);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.rebalance(&t.root);
    t.insert(8);
    return 0;
}
