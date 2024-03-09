#pragma once

#include <utility>
#include <math.h>
#include "OrderedList.h"


template <typename t>
class SparseList : public OrderedList {
	std::pair<int,int> place(t* item) {
		if (num == 0) return std::pair<int,int>(0,0);
		int low = 0;
		int high = 0;
		for (; high < size; high++) {
			t* at = arr[high];
			if (at != NULL) {
				numComparison++;
				if (*at >= *item) {
					break;
				}
				low = at;
			}
		}
		return std::pair<int, int>(low,high);
	}
	int probe(int index, int dir) {
		while (arr[index] != null) {
			index += dir;
			if (index == -1) return -1;
			if (index == size) return -1;
		}
		return index;
	}
	void addItem(t* item) {
		if (isFull()) { throw listOverflow(); }
		auto indexes = place(item);
		int avg = ceil((float)(indexes.first + indexes.second) / 2.0);
		if (arr[avg] == NULL) {
			arr[avg] = item;
		}
		else {
			T* at = arr[avg];
			int right_shiftable = probe(avg, 1);
			int left_shiftable = probe(avg, -1);
			int use = 0;
			int offset = 0;
			if (*at > *item) {
				if (right_shiftable == -1) {
					offset = -1;
					use = 0;
				}
			}
			if (*at < *item) {
				if (left_shiftable == -1) {
					offset = 1;
					use = 1;
				}
			}
		}
	}
};