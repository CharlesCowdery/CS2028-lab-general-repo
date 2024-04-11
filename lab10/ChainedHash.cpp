#include "ChainedHash.h"

/* Link Implementation */
template <typename T>
Link<T>::Link(T* val) {
    data = *val;
    next = nullptr;
}

/* Chain Implementation */
template <typename T>
Chain<T>::Chain() {
    head = nullptr;
}

template <typename T>
void Chain<T>::addLink(T* val) {
    if (head == nullptr) {
        head = val;
        return;
    }
    T* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = val;
}

template<typename T>
void Chain<T>::removeLink(T* val) {
    if (head == nullptr) {throw NotFound();}
    T* temp = head;
    while (temp->next != nullptr) {
        if (*temp->next == *val) {
            temp2 = temp->next;
            temp->next = temp->next->next
            delete temp2;
            return;
        }
        temp = temp->next;
    }
    throw NotFound();
}

template<typename T>
T* Chain<T>::findLink(T* val) {
    if (head == nullptr) {throw NotFound();}
    T* temp = head;
    T* temp2 = nullptr;
    while (temp->next != nullptr) {
        if (*temp->next == *val) {
            return temp->next;
        }
        temp = temp->next;
    }
    throw NotFound();
}

/* Hash Table Implementation */
template <typename T>
ChainedHash<T>::ChainedHash() {
    data = new Chain*[size];
}

template <typename T>
ChainedHash<T>::ChainedHash(int s) {
    size = s;
    data = new Chain*[size];
}

template <typename T>
ChainedHash<T>::~ChainedHash();

template <typename T>
void ChainedHash<T>::AddItem(T* val);

template <typename T>
T* ChainedHash<T>::RemoveItem(T* val);

template <typename T>
T* ChainedHash<T>::GetItem(T* val);

template <typename T>
int ChainedHash<T>::GetLength() {
    return size;
}
