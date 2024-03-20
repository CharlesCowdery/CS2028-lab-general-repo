#pragma once

#include <stdexcept>

using namespace std;

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
    OrdList() : head(nullptr), tail(nullptr), current(nullptr) {}
    ~OrdList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }
    void printList() {
        cout << "=====Displaying List======" << endl;
        auto* cur = head;
        for (int i = 0; i < size(); i++) { //iterates across the list
            cout << cur->data.getFancyInfo() << endl;
            cur = cur->next;
        }
        cout << "==========================" << endl;
    }
    void addItem(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty() || value < head->data) { 
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            else {
                tail = newNode; // Update tail if the list was empty
            }
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next && current->next->data < value) {
                current = current->next;
            }

            newNode->next = current->next;
            if (current->next) {
                current->next->prev = newNode;
            }
            else {
                tail = newNode; // Update tail if newNode is the new last node
            }
            newNode->prev = current;
            current->next = newNode;
        }
    }
    Node<T>* getItem(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; // Return null pointer if the item is not found
    }
    bool inList(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    int size() {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    T seeNext() {
        if (isEmpty()) {
            throw ListUnderflowException();
        }

        if (current == nullptr) {
            current = head;
        }
        else {
            current = current->next;
        }

        if (current == nullptr) {
            throw ListUnderflowException();
        }

        return current->data;
    }
    T seePrev() {
        if (isEmpty()) {
            throw ListUnderflowException();
        }

        if (current == nullptr) {
            current = tail;
        }
        else {
            current = current->prev;
        }

        if (current == nullptr) {
            throw ListUnderflowException();
        }

        return current->data;
    }
    T seeAt(int location) {
        if (location < 1) {
            throw std::out_of_range("Invalid location");
        }

        Node<T>* temp = head;
        for (int i = 1; i < location; i++) {
            if (temp == nullptr) {
                throw ListUnderflowException();
            }
            temp = temp->next;
        }

        if (temp == nullptr) {
            throw ListUnderflowException();
        }

        current = temp;
        return temp->data;
    }
    void reset() {

    }
    void removeNext() {
        if (isEmpty()) {
            throw ListUnderflowException();
        }

        if (current == nullptr) {
            current = head;
        }

        if (current == nullptr) {
            throw ListUnderflowException();
        }

        Node<T>* temp = current->next;
        if (temp == nullptr) {
            throw ListUnderflowException();
        }

        if (temp == tail) {
            tail = current;
        }

        current->next = temp->next;
        if (temp->next) {
            temp->next->prev = current;
        }

        delete temp;
    }
    void removePrev() {
        if (isEmpty()) {
            throw ListUnderflowException();
        }

        if (current == nullptr) {
            current = tail;
        }

        if (current == nullptr) {
            throw ListUnderflowException();
        }

        Node<T>* temp = current->prev;
        if (temp == nullptr) {
            throw ListUnderflowException();
        }

        if (temp == head) {
            head = current;
        }

        current->prev = temp->prev;
        if (temp->prev) {
            temp->prev->next = current;
        }

        delete temp;
    }
};
