#pragma once

#include <string>

class Measure {
    private:
        int little = 0;
        int lot = 0; // 7 littles
        int heap = 0; // 23 lots
        void reflow();
    public:
        int allLittles();
        Measure();
        Measure(int littles);
        Measure(int littles, int lots, int heaps);

        int getLittle();
        int getLot();
        int getHeap();

        Measure operator+(Measure& right);
        Measure operator-(Measure& right);
        Measure operator*(Measure& right);
        Measure operator/(Measure& right);
        bool operator==(Measure& right);
        operator std::string() const; // operator -> string
};
