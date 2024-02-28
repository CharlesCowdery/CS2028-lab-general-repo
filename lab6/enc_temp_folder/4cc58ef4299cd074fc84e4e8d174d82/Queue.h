
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

        void enqueue(T* item) {
            if (num >= size) throw queueOverflow();
            data[num] = item;
            num++;
        }
        T* dequeue() {
            if (num <= 0) throw queueUnderflow();
            T* out = data[0];
            for (int i = 0; i < num; i++) {
                data[i] = data[i + 1];
            }
            num--;
            return out;
        }
        T* peek() {
            if (num == 0) { throw queueUnderflow(); }
            return items[0];
        }
        bool isEmpty() {
            return num == 0;
        }
        int sizeQueue() {
            return num;
        }
};