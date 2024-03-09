#include "SparseList.h"
#include "Exceptions.h"

SparseList::SparseList() {
	for (int i = 0; i <= size(); i++) {
		*arr[i] = NULL;
	}
}

SparseList::addItem(U* item){
    
}

template class SparseList<int>;