#include "Queue.h"
#include <stdexcept>

/* Exception Classes */
class queueOverflow : public std::exception {
public:
    const char* what() {
        return "queueOverflow Exception";
    }
}

class queueUnderflow : public std::exception {
public:
    const char* what() {
        return "queueUnderflow Exception";
    }
}

/* Implementation of Queue Class */
Queue::Queue(int _size){
    size = _size;
    items = new T*[size];
}

Queue::~Queue(){
    delete[] data;
}

bool Queue::isEmpty() {
    return num == 0;
}

void Queue::enqueue(T* item){
    if(num >= size) throw queueOverflow();
    data[num] = item;
    num++;
}

T* Queue::dequeue(){
    if(num <= 0) throw queueUnderflow();
    T* out = data[0];
    for(int i = 0; i < num; i++){
        data[i] = data[i+1];
    }
    return out;
}

int Queue::sizeQueue(){
    return num;
}

T* Queue::peek() {
    if (num == 0) { throw queueUnderflow(); }
    return items[0];
}

/* Initialization to prevent linker errors with header */
template class Queue<int>;
