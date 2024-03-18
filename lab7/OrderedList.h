#pragma once
#define SIZE 75
template<typename T>

class OrderedList {
protected:
	int numCompare;
	int numMove;
	int num;
public:
	/* Variables */
	T* arr[SIZE];
	

	/* Methods */
	OrderedList() {
		numCompare = 0;
		numMove = 0;
		num = 0;
	}
	void addItem(T* item) {
		if (isFull()) { throw listOverflow(); }
		int pos = 0;
		for (; pos < num; pos++) { //find pos
			numCompare++;
			if (*arr[pos] > *item) break;
		}
		if (pos == num) { //add if at end
			arr[pos] = item;
		}
		else { //shift otherwise
			for (int i = num; i > pos; i--) {
				arr[i] = arr[i - 1];
				numMove++;
			}
			arr[pos] = item;
		}
		num++;
	}
	void removeItem(T* item) {
		if (isEmpty()) throw listUnderflow();

		int pos = 0; 
		for (;pos < num; pos++) { // find item
			numCompare++;
			if (*arr[pos] == *item) break;
		}
		if (pos == num) throw valueDNE();

		delete arr[pos];
		for (int i = pos; i < num - 1; ++i) {
			arr[i] = arr[i + 1];
			numMove++;
		}
		num--;
	}
	bool isEmpty() {
		return num == 0;
	}
	bool isFull() {
		return num == SIZE;
	}
	int size() {
		return num;
	}
	void makeEmpty() {
		num = 0;
		numMove = 0;
		numCompare = 0;
	}
	void print() {
		for (int i = 0; i < num; i++) {
			std::cout << *arr[i] << " ";
		}
		cout << endl;
	} // Useful for outputting current list
	void printStats() {
		cout << "comparisons: " << numCompare << " | moves: " << numMove << endl;
	}
};
