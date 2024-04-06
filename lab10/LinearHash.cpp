#include "LinearHash.h"

void LinearHash::empty() {
	for (int i = 0; i < size; i++) {
		data[i] = NULL;
	}
}

LinearHash::LinearHash() {
	size = 100;
	data = new T [max_size]();
	empty();
}

LinearHash::LinearHash(int s) {
	size = s;
	data = new T data[size];
	empty();
}

int LinearHash::hash(std::string val) {
	int total = 0;
	for (char i : val) {
		total += int(i);
	}
	return total % size;
}

void LinearHash::AddItem(T* val) {
    int index = hash(val);
    int original_index = index;
    while (status[index] == 2) {
        index = (index + 1) % max_size;
        if (index == original_index) {
            return;
        }
    }
    data[index] = val;
    status[index] = 1;
}

int LinearHash::GetLength() {
	return size;
}

T* LinearHash::GetItem(T* val) {
	if (data[hash(*val)] == *val) {
		return &data[hash(*val)];
	}
	for (int i = 1; data[hash(*val) + i] != NULL; i++) {
		if (data[hash(*val) + i] == *val) {
			return &data[hash(*val) + i];
		}
	}
	return nullptr;
}