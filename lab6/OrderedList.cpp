#include "Exceptions.h"
#include "OrderedList.h"

OrderedList::OrderedList() {
	numCompare = 0;
	numMove = 0;
	num = 0;
}

virtual void OrderedList::addItem(T* item) {
	if (isFull()) { throw listOverflow(); }
	int pos = 0;
	while(pos <= num && *arr[i] < *item) {
		numCompare += 2;
		pos += 1;
	}
	numCompare += 1;
	if (pos == num) {
		arr[pos] = item;
	}
	else {
		T* temp1 = arr[i];
		T* temp2;
		arr[pos] = item;
		while (pos <= num) {
			pos += 1;
			temp2 = arr[pos];
			arr[pos] = temp1;
			numCompare += 1;
			numMove += 1;
			temp1 = temp2;
		}
	}
}

virtual T OrderedList::removeItem() {
    if (isEmpty()) {throw listUnderflow();}
    
    T* removeItem = arr[0];
    for (int i = 0; i < num - 1; ++i ) {
        arr[i] = arr[i+1];
        numMove++;
    }
    num--;

    return *removeItem;
    
}

int OrderedList::size(){
    return num;
}

int OrderedList::getComparisons(){
    return numCompare;
}

int OrderedList::getMoves(){
    return numMove;
}

bool OrderedList::isEmpty() {
    return num == 0;
}

bool OrderedList::isFull() {
    return num == size;
}

void OrderedList::makeEmpty() {
    num = 0;
	numMove = 0;
	numCompare = 0;
}

void print() {
	for (int i = 0; i <= size; i++) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	for (int i = 0; i <= size; i++) {
		if (arr[i] == nullptr) { std::cout << "X"; }
		else { std::cout << *arr[i]; }
		std::cout << " ";
	}
}

/* Prevents Linker Errors */
template class OrderedList<int>;