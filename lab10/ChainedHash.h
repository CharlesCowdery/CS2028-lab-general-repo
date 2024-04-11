#include "LinearHash.h"
#include <stdexcept>

class NotFound : public std::exception {
public:
  const char *what() { return "NotFound Exception"; }
};


template <typename T>
class Link {
public:
    T data;
    Link* next;

    Link(T* val);
};

template <typename U>
class Chain {
public:
    Link*<U> head;

    Chain();
    void addLink(U* val);
    void removeLink(U* val);
    U* findLink(U* val);
};

template <typename W>
class ChainedHash:LinearHash<W> {
private:
    Chain** data;
    int size = 100;
    int hash(); //keep hash func from Linear???
public:

    ChainedHash();
    ChainedHash(int s);
    ~ChainedHash();

    void AddItem(W* val);
    W* RemoveItem(W* val);
    W* GetItem(W* val);
    int GetLength();
};