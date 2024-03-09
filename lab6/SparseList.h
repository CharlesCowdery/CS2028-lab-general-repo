#pragma once
#include "OrderedList.h"

class SparseList : public OrderedList {
    private:
        int[size] up_jumplist;
        int[size] down_jumplist;
    public:
	SparseList();
};