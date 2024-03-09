#pragma once
#include "Exceptions.h"
#include <malloc.h>

#define CA_LINE_SIZE 64

const unsigned int init_size = 25;

template<typename t>
 class SparseList {
    private:
        struct address_pair {
            unsigned int high;
            unsigned int low;
        }

        t* contents;
        int* down_indexer;
        int* up_indexer;

        unsigned int allocated_size;
        unsigned int count = 0;

        unsigned int numCompare = 0;
        unsigned int numMove = 0;
    public:
        SparseList():SparseList(init_size) {}
        SparseList(unsigned int size) {
            _self_alloc(size);
        }
        ~SparseList() {
            free(contents);
            free(up_indexer);
            free(down_indexer);
        }
        void addItem(t item);
        void removeItem(t item);
        int size();
        void clear();
    private:
        void targeted_indexer() {
            int abs_low = 
        }
        void self_alloc(unsigned int size) {
            contents = malloc(sizeof(t) * size);
            indexer   = aligned_alloc(sizeof(int) * size,CA_LINE_SIZE);
            addressor = aligned_alloc(sizeof(address_pair) * size,CA_LINE_SIZE);
            allocated_size = new_size;

            initialize_indexer();
        }
        unsigned int get_primary_indexer(unsigned int starting_index) {
            unsigned int index = starting_index;
            while (true) {
                if (up_indexer[index] ) break;
            }

        }
        void rebalance() {
            
        }
        void remap_indexer() {

        }

        void resize(unsigned int new_size) {
            if (new_size < allocated_size) throw exception("Illegal Resize: Cannot downsize");
            realloc(contents, new_size);
            unsigned int* new_indexer   = aligned_alloc(sizeof(int) * new_size, CA_LINE_SIZE);
            unsigned int* new_addressor = aligned_alloc(sizeof(int) * new_size, CA_LINE_SIZE);
            std::copy(indexer,indexer + allocated_size, new_indexer);
            std::copy(addressor, addressor + allocated_size, new_addressor);
            free(indexer);
            free(addressor);
            indexer   = new_indexer;
            addressor = new_addressor;
            allocated_size = new_size;
        }


};  

 template <typename t>
 void SparseList<t>::alloc(int size) }