#include "BinaryTree.h"

/* Letter Frequency Class */
std::string Word::lowercase(std::string w) { //lowercase(Kite) return kite
    for (c = 0; c < w.size(); c++) {
        if (int(w[c]) <= 90 && int(w[c]) >= 65) { //65:A,90:Z
            w[c] = char(int(w[c]) + 32);
        }
    }
    return w;
}

Word::Word(std::string w) {
    word = lowercase(w);
    count = 1;
}

void Word::add() {
    count += 1;
}

bool Word::operator >(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return true; } // >
        else { return false; } // <
        c++; // increment
    }
    return word.size() > c; // left is longer: return true
}

bool Word::operator <(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return false; } // >
        else { return true; } // <
        c++; // increment
    }
    return word.size() < c; // right is longer: return true
}

bool Word::operator ==(Word& right) {
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) != int(right.word[c])) { return false; } // >
        c++; // increment
    }
    return word.size() == right.word.size();
}

bool Word::operator <=(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return false; } // >
        else { return true; } // <
        c++; // increment
    }
    return (word.size() < c || word.size() == right.word.size()); // right is longer: return true
}

bool Word::operator >(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return true; } // >
        else { return false; } // <
        c++; // increment
    }
    return (word.size() > c || word.size() == right.word.size()); // left is longer: return true
}


/* Node Class */
Node::Node(Word Data) {
    left = nullptr;
    right = nullptr;
    data = Data;
}

/* Tree Class */



Node* BinaryTree::getAllAscending(){
    Node<T> arr[] = new Node<T>[size()];
    int position = 0;
    return getAllAscending(root, arr, position)
    ;
}

Node* BinaryTree::getAllAscending(Node<T>* N, Node[]& arr, int& position){
    if(N->left!=nullptr){
        getAllAscending(N->left,arr,position);
    }
    arr[position] = N;
    if(N->right!=nullptr){
        getAllAscending(N->right,arr,position);
    }
}

Node* BinaryTree::find(T v, node* N = root){
    if(N->data == v) return N;
    node* left = N->left;
    node* right = N->right;
    if(left->data>=v){
        return find(V,N->left);
    }
    else if(right->data<=v){
        return find(V,N->right);
    }
    T* R_return = find(V,N->right);
    if(R_return != nullptr) return R_return;
    T* L_return = find(V,N->left);
    if(L_return != nullptr) return L_return;
    return nullptr;
}

