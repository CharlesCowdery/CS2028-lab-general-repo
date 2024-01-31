#include "heaps.h";

int Measure::getLittle() { return little; };
int Measure::getLot() { return lot; };
int Measure::getHeap() { return heap; };

Measure::Measure() :
    little(0), lot(0), heap(0) {};
Measure::Measure(int littles) :
    little(littles), lot(0), heap(0) { reflow(); };
Measure::Measure(int littles, int lots, int heaps) :
    little(littles), lot(lots), heap(heaps) { reflow(); };


void Measure::reflow(){
    lot  += little/7;
    heap += lot/23;

    little %= 7;
    lot %= 23;
};

int Measure::allLittles(){
    return (heap*23+lot)*7+little;
};

Measure Measure::operator +(Measure right) {
    return Measure(
        little + right.little,
        lot    + right.lot,
        heap   + right.heap
    );
    
};
Measure Measure::operator-(Measure right) {
    return Measure(
            little - right.little,
            lot    - right.lot,
            heap   - right.heap
        );
};
Measure operator *(Measure right) {
    return Measure(
        allLittles()*right.allLittles()
    );
};
Measure operator /(Measure right) {
    return Measure(
        allLittles()/right.allLittles()
    );
};
bool operator ==(Measure right) {
    return allLittles()==right.allLittles();
};
std::string Measure operator <<() {
    return little.to_string() + "/" + lot.to_string() + "/" + heap.to_string();
}; // operator -> string

