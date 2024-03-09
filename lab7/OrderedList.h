#pragma once
const int size = 25;
template<typename T>

class OrderedList {
protected:
	int numCompare;
	int numMove;
	int num;
public:
	/* Variables */
	T* arr[size];
	

	/* Methods */
	OrderedList() {
		numCompare = 0;
		numMove = 0;
		num = 0;
	}
	void addItem(T* item) {
		if (isFull()) { throw listOverflow(); }
		int pos = 0;
		for (; pos < num; pos++) {
			numCompare++;
			if (*arr[pos] < *item) break;
		}
		if (pos == num) {
			arr[pos] = item;
		}
		else {
			for (int i = num; i > pos; i--) {
				arr[i] = arr[i - 1];
				numMove++;
			}
			arr[pos] = item;
		}
	}
	void removeItem(T* item) {
		if (isEmpty()) throw listUnderflow();

		int pos = 0;
		for (;pos < num; pos++) {
			numCompare++;
			if (*arr[pos] == *item) break;
		}
		if (pos == num) throw valueDNE();


		for (int i = pos; i < num - 1; ++i) {
			arr[i] = arr[i + 1];
			numMove++;
		}
		num--;
	}
	bool isEmpty() {
		return num;
	}
	bool isFull() {
		return num == size;
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
		for (int i = 0; i <= size; i++) {
			std::cout << i << " ";
		}
		std::cout << "\n";
		for (int i = 0; i <= size; i++) {
			if (arr[i] == nullptr) { std::cout << "X"; }
			else { std::cout << *arr[i]; }
			std::cout << " ";
		}
	} // Useful for outputting current list
};
