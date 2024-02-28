#pragma once

template <typename T>
class Queue{
    private:
        T** data;
        int size;
        int num;

    public:
        Queue(int size);
        ~Queue();

        void enqueue(T* item);
        T* dequeue();
        T* peek();
        bool isEmpty();
        int sizeQueue();
};