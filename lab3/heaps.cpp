#include "heaps.h"
#include <iostream>

int Measure::getLittle() { return little; }; //getters
int Measure::getLot() { return lot; };
int Measure::getHeap() { return heap; };

void Measure::setLittle(int v) { little = v; reflow(); } //setters. recalculates values after setting to maintain coherance to measurement
void Measure::setLot(int v) { lot = v; reflow(); }
void Measure::setHeap(int v) { heap = v; }

Measure::Measure() : 
    little(0), lot(0), heap(0) {};
Measure::Measure(int littles) :
    little(littles), lot(0), heap(0) { reflow(); };
Measure::Measure(int littles, int lots, int heaps) :
    little(littles), lot(lots), heap(heaps) { reflow(); };


void Measure::reflow(){ //recalculates values, such that if there is enough of one to convert it to a larger format, it does.
    lot  += little/7;
    heap += lot/23;

    little %= 7;
    lot %= 23;
};

int Measure::allLittles(){ //converts all values to littles, essentially, convering them to decimal
    return (heap*23+lot)*7+little;
};

Measure::operator std::string() const { //converts measure to a string organized (l/L/H)
    return std::to_string(little) + "/" + std::to_string(lot) + "/" + std::to_string(heap);
}; // operator -> string


//mathematical operators.
//performs the operations without modifying the original values,
//returning a new object with the resulting value

Measure Measure::operator +(Measure& right) {
    return Measure(
        little + right.little,
        lot    + right.lot,
        heap   + right.heap
    );
    
};
Measure Measure::operator-(Measure& right) {
    return Measure(
            little - right.little,
            lot    - right.lot,
            heap   - right.heap
        );
};
Measure Measure::operator *(Measure& right) {
    return Measure(
        allLittles()*right.allLittles()
    );
};
Measure Measure::operator /(Measure& right) {
    int left_l = allLittles();
    int right_l = right.allLittles();
    return Measure(
        left_l/right_l
    );
};
bool Measure::operator ==(Measure& right) {
    return allLittles()==right.allLittles();
};

#hi




