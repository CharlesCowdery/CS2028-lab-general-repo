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

    int hash(std::string val);

public:
    LinearHash();
    LinearHash(int s);
    ~LinearHash();

    void AddItem(T* val);
    T* RemoveItem(T* val);
    T* GetItem(T* val);
    int GetLength();
};

#include "LinearHash.cpp"