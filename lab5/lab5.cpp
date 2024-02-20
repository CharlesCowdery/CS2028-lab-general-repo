// Exception Classes
#include <stdexcept>

class shelf_full : public std::exception {
public:
    const char* what() {
        return "Error, shelf is full.";
    }
}

class shelf_empty : public std::exception {
public:
    const char* what() {
        return "Error, shelf is empty.";
    }
}


// Header for Shelf
const int size = 5;
class Shelf {
private:
    Movie movies[size];
    int numMovies;
public:
    Shelf() { numMovies = 0; }
    Movie remove();
    void add(Movie movie);
    int movieCount() { return numMovies; }
};

// Implementation for Shelf
Shelf::remove() {
    if (numMovies <= 0) { throw shelf_empty; }
    numMovies -= 1;
    return movies[numMovies];
}
Shelf::add(Movie movie) {
    if (numMovies >= size) { throw shelf_full; }
    movies[numMovies] = movie;
    numMovies += 1;
}

// Tester
using namespace std;
int main() {
    bool cont = true;
    char userInput;
    while (cont) {
        Shelf s1;
        cout << "Which method would you like to invoke?:" << endl;
        cout << "Add movie to shelf(1)";
        cout << "Remove movie from shelf(2)";
        cout << "See how many movies are in shelf(3)";
        cout << "quit(4)";
        if (userInput == '1') {
            //create movie m1...
            try { s1.add(m1); }
            catch (shelf_full& e) {
                cerr << e.what() << endl;
            }
        }
        else if (userInput == '2') {
            //create movie m2...
            try { s1.remove(m2); }
            catch (shelf_empty& e) {
                cerr << e.what() << endl;
            }
        }
        else if (userInput == '3') {
            cout << "Movie Count: " << s1.movieCount << endl;
        }
        else { cont = false; }
    }
}