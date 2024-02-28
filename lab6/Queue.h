
#pragma once

#include <exception>


class queueOverflow : public std::exception {
public:
    const char* what() {
        return "queueOverflow Exception";
    }
};

class queueUnderflow : public std::exception {
public:
    const char* what() {
        return "queueUnderflow Exception";
    }
};

template <typename T> 
class Queue{
    private:
        T** data;
        int size;
        int num = 0;

    public:
        Queue(int _size) {
            size = _size;
            data = new T * [size];
        }
        ~Queue() {
            delete[] data;
        }

        void enqueue(T* item) { //adds item to queue
            if (num >= size) throw queueOverflow();
            data[num] = item;
            num++;
        }
        T* dequeue() { //removes and returns first item from queue
            if (num <= 0) throw queueUnderflow();
            T* out = data[0];
            for (int i = 0; i < num; i++) { //shuffling data after popping front. 
                data[i] = data[i + 1];
            }
            num--;
            return out;
        }
        T* peek() { //returns first spot in queue
            if (num == 0) { throw queueUnderflow(); }
            return items[0];
        }
        bool isEmpty() { //returns true if empty
            return num == 0;
        }
        void empty() { //clears queue
            num = 0;
        }
        int sizeQueue() {//returns queue size
            return num;
        }
};