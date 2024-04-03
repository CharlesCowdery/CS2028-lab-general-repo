#pragma once
#include <string>
#include <math.h>
#include <ostream>
#include <ctype.h>
/* Exception Classes */
class valueDNE : public std::exception {
public:
    const char* what() {
        return "Value Not In Tree";
    }
};

class repeatValue : public std::exception {
public:
    const char* what() {
        return "Value already in Tree";
    }
};

/* Word Frequency Class */
class Word {  
public:
    std::string word;
    int size;
    int count;

    Word(std::string w) {
        for (int i = 0; i < w.size(); i++) {
            w[i] = tolower(w[i]);
        }
        word = w;
        size = w.size();
        count = 1;
    }

    void inc() {
        count++;
    }

    char operator[](int v) {
        return word[v];
    }
    bool operator >(Word& right) {
        int index = 0;
        int min = std::min(right.size, size);
        while (index < min) {
            char c1 = word[index];
            char c2 = right[index];
            if (c1 > c2) return true;
            if (c2 > c1) return false;
        }
        return false;
    }
    bool operator <(Word& right) {
        int index = 0;
        int min = std::min(right.size, size);
        while (index < min) {
            char c1 = word[index];
            char c2 = right[index];
            if (c1 < c2) return true;
            if (c2 < c1) return false;
        }
        return false;
    }
    bool operator ==(Word& right) {
        int index = 0;
        if (size != right.size) return false;
        while (index < size) {
            char c1 = word[index];
            char c2 = right[index];
            if (c2 != c1) return false;
        }
        return true;
    }
};

/* Node Class */
template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T _data) {
        left = nullptr;
        right = nullptr;
        data = _data;
    };
    std::string to_string() {
        return std::to_string(data);
    }
};

/* Tree Class */
template <typename T>
class BinaryTree {
public:
    Node<T>* root = nullptr;
    BinaryTree() {}
    ~BinaryTree() {
        emptyTree();
    }

    void insert(T w) { //inserts a node starting at tree root
        Node<T>* w_node = new Node<T>(w);
        if (root == nullptr) {
            root = w_node;
            return;
        }
        else {
            insert(w_node, root);
        }
        rebalance(&root);
    }
    void insert(Node<T>* w, Node<T>* N) {
        //checks which node path is appropriate, if it exists, it propogates the function down that path.
        //Otherwise, it sets that child pointer to the node
        //if it finds a node with value equal to the node were trying to insert, it errors out
        if (w->data > N->data) { 
            if (N->right != nullptr) insert(w, N->right);
            else N->right = w;
        }
        if (w->data < N->data) {
            if (N->left != nullptr) insert(w, N->left);
            else N->left = w;
        }
        if (w->data == N->data) {
            delete w;
            throw repeatValue();
        }
    }
    Node<T>* find(T v) {
        return find(v, root);
    }
    Node<T>* find(T v, Node<T>* N) {
        if (N->data == v) return N; //if node is value return
        if (v > N->data && N->right != nullptr) return find(v, N->right);   //checks if child exists and searches down it if appropriate
        if (v < N->data && N->left != nullptr) return find(v, N->left);     
        return nullptr;
    };
    Node<T>* findParent(T v) {
        return findParent(root);
    }
    Node<T>* findParent(T v, Node<T>* N) {
        if (N->right != nullptr && N->right->data == v) return N; //checks if child has value, and returns self if so
        if (N->left  != nullptr && N->left->data  == v) return N; 
        if (v > N->data && N->right != nullptr) return findParent(v, N->right); //otherwise search down appropriate childs tree if it exists
        if (v < N->data && N->left  != nullptr) return findParent(v, N->left);
        return nullptr;
    };
    int size() {
        return size(root);
    }
    int size(Node<T>* N) {
        if (N == nullptr) return 0;
        return 1 + size(N->left) + size(N->right); //recurses down the tree, with each node adding one to size
    }
    Node<T>** getAllAscending() {
        return getAllAscending(root);
    }
    Node<T>** getAllAscending(Node<T>* N) {
        Node<T>** arr = (Node<T>**) malloc(sizeof(Node<T>*)*size()); //init array
        int position = 0; //init position increment variable
        getAllAscending(N, arr, position);
        return arr;
    }
    void getAllAscending(Node<T>* N, Node<T>** arr, int& position) {
        if (N->left != nullptr) { //if left exists, add all nodes on left first
            getAllAscending(N->left, arr, position);
        }
        arr[position] = N; //then add self and increment
        position++;
        if (N->right != nullptr) { //if right exists add all nodes on right last
            getAllAscending(N->right, arr, position);
        }
    };
    Node<T>** getAllDescending() {
        return getAllDescending(root);

    }
    Node<T>** getAllDescending(Node<T>* N) {
        Node<T>** arr = (Node<T>**) malloc(sizeof(Node<T>*) * size()); //refer to ascending. Order of child traversal is reversed.
        int position = 0;
        getAllDescending(N, arr, position);
        return arr;
    }
    void getAllDescending(Node<T>* N, Node<T>** arr, int& position) {
        if (N->right != nullptr) {
            getAllDescending(N->right, arr, position);
        }
        arr[position] = N;
        position++;
        if (N->left != nullptr) {
            getAllAscending(N->left, arr, position);
        }
    };
    int nodeHeight() {
        return nodeHeight(root);
    }
    int nodeHeight(Node<T>* N) {
        int height = 0;
        if (N->left != nullptr) height = std::max(height, nodeHeight(N->left) + 1); 
        if (N->right != nullptr) height = std::max(height, nodeHeight(N->right) + 1); // if right has more height it will override left
        return height;
    }
    void emptyTree() {
        emptyTree(root);
    }
    void emptyTree(Node<T>* N) {
        if (N == nullptr) return; //ensures repeat calls will not crash due to trying to deallocate a nullptr root
        if (N->left  != nullptr) emptyTree(N->left);//empty children if they exists
        if (N->right != nullptr) emptyTree(N->right);
        delete N;
    }
    Node<T>* remove(T w) {
        remove(T, &root);
    }
    Node<T>* remove(T w, Node<T>** socket) {

    }

    void rebalance(Node<T>** socket) {
        bool cont = true;
        while (cont == true) {
            cont = false;
            Node<T>* node = *socket;
            bool l_exist = node->left != nullptr;
            bool r_exist = node->right != nullptr;
            int dl = -1;
            int dr = -1;

            if (l_exist) rebalance(&(node->left));
            if (r_exist) rebalance(&(node->right));
            if (l_exist) dl = nodeHeight(node->left);
            if (r_exist) dr = nodeHeight(node->right);
            while (dr - dl > 1) {
                rotateLeft(node, socket);
                dl++;
                dr--;
                cont = true;
            }
            while (dl - dr > 1) {
                rotateRight(node, socket);
                dl--;
                dr++;
                cont = true;
            }
        }
    }
    void rotateRight(Node<T>* N, Node<T>** socket) {
        (*socket) = N->left;
        N->left = N->left->right;
        (*socket)->right = N;
    }
    void rotateLeft(Node<T>* N, Node<T>** socket) {
        (*socket) = N->right;
        N->right = N->right->left;
        (*socket)->left = N;
    }

};
