#pragma once
#include <stdexcept>
#include <string>

class ItemStock;

template<typename T>
class LinearHash {
private:
    T** data;
    int* status;
    int size = 10;

    void empty();


public:
    LinearHash();
    LinearHash(int s);
    ~LinearHash();

    int hash(std::string val);

    void AddItem(T* val);
    T* RemoveItem(T* val);
    T* GetItem(T* val);
    int GetLength();
};

#include "LinearHash.cpp"
