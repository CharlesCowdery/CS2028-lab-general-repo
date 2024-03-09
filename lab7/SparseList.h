#pragma once

#include <utility>
#include <math.h>
#include "OrderedList.h"


template <typename t>
class SparseList : public OrderedList<t> {
public:
	SparseList() {
		for (int i = 0; i < SIZE; i++) {
			arr[i] = NULL;
		}
	}
	std::pair<int,int> place(t* item) {
		if (num == 0) return std::pair<int,int>(0,0);
		int low = 0;
		int high = 0;
		for (; high < SIZE; high++) {
			t* at = arr[high];
			if (at != NULL) {
				numCompare++;
				if (*at >= *item) {
					break;
				}
				low = high;
			}
		}
		if (high == SIZE) high--;
		return std::pair<int, int>(low,high);
	}
	int probe(int index, int dir) {
		while (arr[index] != NULL) {
			index += dir;
			if (index == -1) return -1;
			if (index == SIZE) return -1;
		}
		return index;
	}
	void removeItem(t* item) {
		if (isEmpty()) throw listUnderflow();
		for (int i = 0; i < SIZE; i++) {
			if (arr[i] == NULL) continue;
			if (*arr[i] == *item) {
				delete arr[i];
				arr[i] = NULL;
				return;
			}
		}
		throw valueDNE();
	}
	void addItem(t* item) {
		if (isFull()) { throw listOverflow(); }
		auto indexes = place(item);
		int avg = ceil((float)(indexes.first + indexes.second) / 2.0);
		if (arr[avg] == NULL) {
			arr[avg] = item;
			num++;
		}
		else {
			t* at = arr[avg];
			int right_shiftable = probe(avg, 1);
			int left_shiftable = probe(avg, -1);
			numCompare++;
			if (*at >= *item) {
				if (right_shiftable != -1) { // 0ax
					for (int i = right_shiftable; i > avg; i--) {
						numMove++;
						arr[i] = arr[i - 1];
					}
					arr[avg] = item;
				}
				else {
					for (int i = left_shiftable; i < avg; i++) {
						numMove++;
						arr[i] = arr[i + 1];
					}
					arr[avg+1] = item;
				}
			}
			numCompare++;
			if (*at < *item) { //
				if (left_shiftable != -1) { // xa0
					for (int i = left_shiftable; i < avg; i++) {
						numMove++;
						arr[i] = arr[i + 1];
					}
					arr[avg] = item;
				}
				else {
					for (int i = right_shiftable; i > avg; i--) {
						numMove++;
						arr[i] = arr[i - 1];
					}
					arr[avg] = item;
				}
			}
			num++;
		}
	}
	void makeEmpty() {
		num = 0;
		for (int i = 0; i < SIZE; i++) {
			arr[i] = NULL;
		}
	}
	void print(bool verbose) {
		bool first = true;
		for (int i = 0; i < SIZE; i++) {
			if (arr[i] == NULL) {
				if (verbose) {
					if (!first) {
						cout << " ";
					}
					cout << "X";
					first = false;
				}
				continue;
			}
			if (!first) {
				cout << " ";
			}
			cout << *arr[i];
			first = false;
		}
		cout << endl;
	}
};