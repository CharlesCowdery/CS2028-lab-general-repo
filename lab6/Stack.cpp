#include "Stack.h"
#include <stdexcept>

/* Exception Classes */
class stackOverflow : public std::exception {
public:
    const char* what() {
        return "stackOverflow Exception";
    }
}

class stackUnderflow : public std::exception {
public:
    const char* what() {
        return "stackUnderflow Exception";
    }
}

/* Implementation of Stack Class */
void Stack::push(T* top) {
    if (num >= size) { throw stackOverflow(); }
    items[num] = top;
    num++;
}

T* Stack::pop(){
    if(num <= 0) { throw stackUnderflow()}
    num--;
    return items[num+1];
}

T* Stack::top() {
    if (num == 0) { throw stackUnderflow(); }
    return items[num-1]
}

int Stack::length() {
    return num;
}

void Stack::empty() {
    for (int i = num - 1; i >= 0; i--) {
        delete items[i];
    }
    num = 0;
}



/* Initialization to prevent linker errors with header */
template class Stack<int>;
