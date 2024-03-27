#pragma once
#include <string>

/* Exception Classes */
class NotFound : public std::exception {
public:
    const char* what() {
        return "NotFound Exception";
    }
};

/* Word Frequency Class */
class Word {
private:
    std::string word;
    int count;
public:
    Word(std::string w);
    void add();

    std::string lowercase(std::string w);

    bool operator >(Word& right);
    bool operator <(Word& right);
    bool operator ==(Word& right);
    bool operator >=(Word& right);
    bool operator <=(Word& right);
};

/* Node Class */
template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T Data);
};

/* Tree Class */
template <typename T>
class BinaryTree {
public:
    Node* root;
    BinaryTree(); //Constructor
    ~BianryTree(); //Destructor

    void insert(T w);
    Node* find(T w);
    int size();
    Node[] getAscending();
    Node[] getDescending();
    void emptyTree();   
    Node* remove(T w);

    void rebalance();
    void rotateRight(Node* N, Node* P);
    void rotateLeft(Node* N, Node* P);
    int nodeHeight();
};