#include "BinaryTree.h"

/* Letter Frequency Class */
std::string Word::lowercase(std::string w) { //lowercase(Kite) return kite
    for (c = 0; c < w.size(); c++) {
        if (int(w[c]) <= 90 && int(w[c]) >= 65) { //65:A,90:Z
            w[c] = char(int(w[c]) + 32);
        }
    }
    return w;
}

Word::Word(std::string w) {
    word = lowercase(w);
    count = 1;
}

void Word::add() {
    count += 1;
}

bool Word::operator >(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return true; } // >
        else { return false; } // <
        c++; // increment
    }
    return word.size() > c; // left is longer: return true
}

bool Word::operator <(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return false; } // >
        else { return true; } // <
        c++; // increment
    }
    return word.size() < c; // right is longer: return true
}

bool Word::operator ==(Word& right) {
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) != int(right.word[c])) { return false; } // >
        c++; // increment
    }
    return word.size() == right.word.size();
}

bool Word::operator <=(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return false; } // >
        else { return true; } // <
        c++; // increment
    }
    return (word.size() < c || word.size() == right.word.size()); // right is longer: return true
}

bool Word::operator >(Word& right) {
    c = 0;
    while (word.size() > c && right.word.size() > c) {
        if (int(word[c]) == int(right.word[c])) { continue; } // =
        else if (int(word[c]) > int(right.word[c])) { return true; } // >
        else { return false; } // <
        c++; // increment
    }
    return (word.size() > c || word.size() == right.word.size()); // left is longer: return true
}


/* Node Class */


