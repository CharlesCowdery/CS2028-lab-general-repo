#include "LinearHash.h"

template<typename T>
void LinearHash<T>::empty() {
    for (int i = 0; i < size; i++) {
        data[i] = nullptr;
        status[i] = 0;
    }
}

template<typename T>
LinearHash<T>::LinearHash() {
    data = new T * [size];
    status = new int[size];
    empty();
}

template<typename T>
LinearHash<T>::LinearHash(int s) {
    size = s;
    data = new T * [size];
    status = new int[size];
    empty();
}

template<typename T>
LinearHash<T>::~LinearHash() {
    delete[] data;
    delete[] status;
}

template<typename T>
int LinearHash<T>::hash(std::string val) {
    int total = 0;
    for (char i : val) {
        total += int(i);
    }
    return total % size;
}

template<typename T>
void LinearHash<T>::AddItem(T* val) {
    int index = hash(val->getSKU());
    int original_index = index;
    while (status[index] != 0) {
        index = (index + 1) % size;
        if (index == original_index) {
            throw std::runtime_error("Hash table is full");
        }
    }
    data[index] = val;
    status[index] = 1;
}

template<typename T>
T* LinearHash<T>::RemoveItem(T* val) {
    int index = hash(val->getSKU());
    int original_index = index;
    while (status[index] != 0) {
        if (status[index] == 1 && *data[index] == *val) {
            T* item = data[index];
            data[index] = nullptr;
            status[index] = 2;
            return item;
        }
        index = (index + 1) % size;
        if (index == original_index) {
            return nullptr;
        }
    }
    return nullptr;
}

template<typename T>
T* LinearHash<T>::GetItem(T* val) {
    int index = hash(val->getSKU());
    int original_index = index;
    while (status[index] != 0) {
        if (status[index] == 1 && *data[index] == *val) {
            return data[index];
        }
        index = (index + 1) % size;
        if (index == original_index) {
            return nullptr;
        }
    }
    return nullptr;
}

template<typename T>
int LinearHash<T>::GetLength() {
    return size;
}

template class LinearHash<ItemStock>;