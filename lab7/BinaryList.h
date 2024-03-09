#pragma once
#include "Exceptions.h"
#include "OrderedList.h"
template<typename U>

class BinaryList : public OrderedList<U> {
public:
    int searchValue(U* value) {
        int high = num;
        int low = 0;
        if (high == low)return 0;
        int mid;
        while (true) {
            mid = (high + low) / 2;
            U* v = arr[mid];
            numCompare++;
            if (*v < *value) {
                if (low == mid) return mid;
                low = mid;
                continue;
            }
            numCompare++;
            if (*v > *value) {
                if (high == mid) return mid;
                high = mid;
                continue;
            }
            return mid;
        }
    }
    void addItem(U* item) {
        if (isFull()) { throw listOverflow(); }
        int index = searchValue(item);
        for (int i = num; i > index; i--) {
            arr[i] = arr[i - 1];
            numMove++;
        }
        if (num != 0) {
            //if(index!=num)index++;
            numCompare++;
            if (*arr[index] < *item)index++;
        }
        arr[index] = item;
        num++;
    }
    void removeItem(U* item) {
        if (this->isEmpty()) {
            throw listUnderflow();
        }
        int index = searchValue(item);
        if (*arr[index] != *item) throw valueDNE();
        delete arr[index];
        num--;
        for (int i = index; i < num; i++) {
            arr[i] = arr[i + 1];
            numMove++;
        }

    }

};