#include "OrdList.h"



void OrdList::addItem(T value) {
    Node* newNode = new Node(value);

    if (isEmpty() || value < head->data) {
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next
        }
    
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    if(!tail || value > tail->data) {
        tail = newNode;
    }    
}

OrdList::OrdList() {
    head = nullptr;
    tail = nullptr;
}

OrdList::~OrdList();

T OrdList::getItem(T value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (tail == temp) { tail = temp->prev; }
            if (head == temp) { head = temp->next; }
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

bool OrdList::inList(T value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool OrdList::isEmpty() {
    return head == nullptr;
}

int OrdList::size() {
    int i = 0;
    Node* temp = head;
    while (temp != nullptr) {
        i++;
        temp = temp->next;
    }
    return i;
}

T OrdList::seeNext() {
    if (isEmpty()) {
        throw listUnderflow();
    }

    Node* current = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }

    result = current->data;
    delete current;
    return result;
};

T OrdList::seePrev() {
    if (isEmpty()) {
        throw listUnderflow();
    }

    Node* current = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    
    result = current->data;
    delete current;
    return result;
};

T OrdList::seeAt(int location) { //first loc is 1
    Node* temp = head;
    while (location >= 1) {
        if (temp == nullptr) { throw listUnderflow(); }
        location--;
        temp = temp->next;
    }
    return temp->data;
}

void OrdList::reset() {
    Node* temp = head->next;
    while (temp != nullptr) {
        delete temp->prev;
        temp = temp->next;
    }
    delete head;
    tail = nullptr;
}