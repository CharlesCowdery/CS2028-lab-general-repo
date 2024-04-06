#pragma once
#include <string>
template class<typename T>

class LinearHash {
private:
	static int size;
	T** data[];
	int hash(std::string val);
public:
	LinearHash();
	LinearHash(int s);
	~LinearHash();
	void AddItem(T* val);
	T* RemoveItem(T* val);
	T* GetItem(T* val);
	int GetLength();
	void empty();
}; 