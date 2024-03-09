#pragma once
#include <stdexcept>

/* Exception Classes */
class listOverflow : public std::exception {
public:
    const char* what() {
        return "listOverflow Exception";
    }
};

class listUnderflow : public std::exception {
public:
    const char* what() {
        return "listUnderflow Exception";
    }
};

class valueDNE : public std::exception {
public:
    const char* what() {
        return "valueDoesNotExist Exception";
    }
};