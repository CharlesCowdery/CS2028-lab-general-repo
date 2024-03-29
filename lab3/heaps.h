#pragma once

#include <string>

class Measure {
    private:
        int little = 0;
        int lot = 0; // 7 littles
        int heap = 0; // 23 lots, 161 littles
        void reflow();
    public:
        int allLittles();
        Measure();
        Measure(int littles);
        Measure(int littles, int lots, int heaps);

        int getLittle();
        int getLot();
        int getHeap();

        void setLittle(int v);
        void setLot(int v);
        void setHeap(int v);

        Measure operator+(Measure& right);
        Measure operator-(Measure& right);
        Measure operator*(Measure& right);
        Measure operator/(Measure& right);
        bool operator==(Measure& right);
        operator std::string() const; // operator -> string
};
