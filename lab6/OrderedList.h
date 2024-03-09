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
	OrderedList();
	virtual void addItem(T* item);
	virtual T removeItem();
	bool isEmpty();
	bool isFull();
	int size();
	void makeEmpty();
	void print(); // Useful for outputting current list
};
