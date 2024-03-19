#include "OrdList.h"

template <typename T>
OrdList<T>::OrdList() : head(nullptr), tail(nullptr), current(nullptr) {}

template <typename T>
OrdList<T>::~OrdList() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
    }
}

template <typename T>
void OrdList<T>::addItem(T value) {
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

template <typename T>
Node<T>* OrdList<T>::getItem(T value) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr; // Return null pointer if the item is not found
}

template <typename T>
bool OrdList<T>::inList(T value) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
bool OrdList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
int OrdList<T>::size() {
    int count = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
T OrdList<T>::seeNext() {
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

template <typename T>
T OrdList<T>::seePrev() {
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

template <typename T>
T OrdList<T>::seeAt(int location) {
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

template <typename T>
void OrdList<T>::reset() {
    current = head;
}

template <typename T>
void OrdList<T>::removeNext() {
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

template <typename T>
void OrdList<T>::removePrev() {
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