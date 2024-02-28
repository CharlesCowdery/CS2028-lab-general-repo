#pragma once
template<typename T>
class Stack {
private:
	T** items;
	const int size;
	int num = 0;
	
public:
	Stack(int sz) { items = new T*[sz]; size = sz; }
	~Stack();
	void push(T* top);
	T* pop();
	T* top();
	int length();
	void empty();
};