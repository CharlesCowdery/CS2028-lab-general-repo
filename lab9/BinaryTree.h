#pragma once
#include <string>
#include <math.h>
/* Exception Classes */
class valueDNE : public std::exception {
public:
    const char* what() {
        return "Value Not In Tree";
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

    Node(T data) {
        left = nullptr;
        right = nullptr;
        data = data;
    };
};

/* Tree Class */
template <typename T>
class BinaryTree {
public:
    Node* root;
    BinaryTree() {}
    ~BinaryTree() {
        emptyTree();
    }

    void insert(T w) {
        if (root == nullptr) {
            root = new Node<T>(w);
            return;
        }
        else {
            insert(w, root);
        }
    }
    void insert(T w, Node<T>* N) {
        if (w > N->data) {
            if (N->right != nullptr) insert(w, N->right);
            else N->right = new Node<T>(w);
        }
        if (w < N->data) {
            if (N->left != nullptr) insert(w, N->left);
            else N->left = new Node<T>(w);
        }
    }
    Node<T>* BinaryTree::find(T v, Node<T>* N = root) {
        if (N->data == v) return N;
        if (v > N->data && N->right != nullptr) return find(v, N->right);
        if (v < N->data && N->left != nullptr) return find(v, N->left);
        return nullptr;
    };
    Node<T>* BinaryTree::findParent(T v, Node<T>* N = root) {
        if (N->right != nullptr && N->right->data == v) return N;
        if (N->left  != nullptr && N->left->data  == v) return N;
        if (v > N->data && N->right != nullptr) return findParent(v, N->right);
        if (v < N->data && N->left  != nullptr) return findParent(v, N->left);
        return nullptr;
    };
    int size(Node<T>* N = root) {
        if (N == nullptr) return 0;
        return 1 + size(N->left) + size(N->right);
    }
    Node<T>[] getAllAscending() {
        Node<T> arr[] = new Node<T>[size()];
        int position = 0;
        return getAllAscending(root, arr, position);
    }
    void getAllAscending(Node<T>* N, Node[] & arr, int& position) {
        if (N->left != nullptr) {
            getAllAscending(N->left, arr, position);
        }
        arr[position] = N;
        position++;
        if (N->right != nullptr) {
            getAllAscending(N->right, arr, position);
        }
    };
    Node<T>[] getAllDescending() {
        Node<T> arr[] = new Node<T>[size()];
        int position = 0;
        return getAllAscending(root, arr, position);
    }
    void getAllDescending(Node<T>* N, Node[] & arr, int& position) {
        if (N->right != nullptr) {
            getAllDescending(N->right, arr, position);
        }
        arr[position] = N;
        position++;
        if (N->left != nullptr) {
            getAllAscending(N->left, arr, position);
        }
    };
    void emptyTree(Node<T>* N = root) {
        if (N->left  != nullptr) emptyTree(N->left);
        if (N->right != nullptr) emptyTree(N->right);
        delete N;
    }
    Node* remove(T w) {
        Node<T>* parent = findParent(w); //get parent of value
        Node<T>** p_node_ptr;
        Node<T>* node;
        Node<T>* n_left;
        Node<T>* n_right;
        if (parent == nullptr) { //root value edge case
            if (root->data == w) {
                node = root;
                p_node_ptr = &root;
            }
            else throw valueDNE();
        }
        else {
            if (parent->left != nullptr && parent->left->data == w) {
                node = parent->left;
                p_node_ptr = &(parent->left);
            }
            if (parent->right != nullptr && parent->right->data == w) {
                node = parent->right;
                p_node_ptr = &(parent->right);
            }
        }
        n_left = node->left;
        n_right = node->right;
        if (n_left == nullptr && n_right == nullptr) {
           (*p_node_ptr) = nullptr;
        }
        if (n_left == nullptr && n_right != nullptr) {
            (*p_node_ptr) = n_right;
        }
        if (n_left != nullptr && n_right == nullptr) {
            (*p_node_ptr) = n_left;
        }
        if (n_left != nullptr && n_right != nullptr) {
            Node<T>* target;
            Node<T>* 
        }


    }
    int nodeHeight(Node<T>* N = root) {
        int height = 0;
        if (N->left != nullptr) height = std::max(height, nodeHeight(N->left) + 1);
        if (N->right != nullptr) height = std::max(height, nodeHeight(N->right) + 1);
        return height;
    }
    void rebalance();
    void rotateRight(Node* N, Node* P);
    void rotateLeft(Node* N, Node* P);

};
