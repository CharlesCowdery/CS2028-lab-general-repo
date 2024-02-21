
#include <stdexcept>

#define SIZE 5 //using a preprocessor directive for constant c type array size.
//its what ive been taught personally, dunno how standard it is.

using namespace std;

class ShelfFull : public std::exception {
public:
    const char* what() {
        return "Error, shelf is full.";
    }
};

class ShelfEmpty : public std::exception {
public:
    const char* what() {
        return "Error, shelf is empty.";
    }
};

template <typename t>
class EntertainmentCollection {
private:
    t collection[SIZE];
    int num = 0;
public:
    EntertainmentCollection() {}
    t remove() {
        if (num <= 0) { throw ShelfEmpty(); }
        num -= 1;
        return collection[num];
    }
    void add(t item) {
        if (num >= SIZE) { throw ShelfFull(); }
        for (int i = num; i > 0; i--) {
            collection[i] = collection[i - 1];
        }
        collection[0] = item;
        num += 1;
    }
    int count() { 
        return num;
    }
};
