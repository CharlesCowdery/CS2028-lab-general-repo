#pragma once

#include <stdexcept>

/* Exception Classes */
class ListUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "ListUnderflow Exception";
    }
};

/* Node Class */
template <typename T>
class Node {
public:
    /* Variables */
    Node<T>* next;
    Node<T>* prev;
    T data;

    /* Constructor */
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

/* Ordered Doubly Linked List */
template <typename T>
class OrdList {
    /* Variables */
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current; // Current position pointer for seeNext and seePrev

public:
    /* Methods */
    OrdList();
    ~OrdList();
    void addItem(T value);
    Node<T>* getItem(T value);
    bool inList(T value);
    bool isEmpty();
    int size();
    T seeNext();
    T seePrev();
    T seeAt(int location);
    void reset();
    void removeNext();
    void removePrev();
};