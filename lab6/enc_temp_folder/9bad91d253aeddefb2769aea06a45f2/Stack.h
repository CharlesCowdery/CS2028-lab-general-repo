#pragma once

#include <exception>


class stackOverflow : public std::exception {
public:
	const char* what() {
		return "stackOverflow Exception";
	}
};

class stackUnderflow : public std::exception {
public:
	const char* what() {
		return "stackUnderflow Exception";
	}
};

template<typename T>
class Stack {
private:
	T** items;
	const int size;
	int num = 0;
	
public:
	Stack(int sz) : size(sz) { items = new T*[size];  }
	~Stack() {
		delete[] items;
	}
	void push(T* top) {
		if (num >= size) { throw stackOverflow(); }
		items[num] = top;
		num++;
	}
	T* pop() {
		if (num <= 0) { throw stackUnderflow(); }
		num--;
		return items[num];
	}
	T* top() {
		if (num == 0) { throw stackUnderflow(); }
		return items[num - 1]
	}
	int length() {
		return num;
	}
	bool isEmpty() {
		return num == 0;
	}
	void empty() {
		for (int i = num - 1; i >= 0; i--) {
			delete items[i];
		}
		num = 0;
	}
};