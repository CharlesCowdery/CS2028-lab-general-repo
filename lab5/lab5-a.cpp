// Exception Classes
#include "Show.cpp"
#include <stdexcept>

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


// Header for Shelf
#define SIZE 5 //using a preprocessor directive for constant c type array size.
//its what ive been taught personally, dunno how standard it is.
class Shelf {
private:
    Movie movies[SIZE];
    int numMovies = 0;
public:
    Shelf() {}
    Movie remove();
    void add(Movie movie);
    int movieCount() { return numMovies; }
};

// Implementation for Shelf
Movie Shelf::remove() {
    if (numMovies <= 0) { throw ShelfEmpty(); }
    numMovies -= 1;
    return movies[numMovies];
}
void Shelf::add(Movie movie) {
    if (numMovies >= SIZE) { throw ShelfFull(); }
    for (int i = numMovies; i > 0; i--) {
        movies[i] = movies[i - 1];
    }
    movies[0] = movie;
    numMovies += 1;
}  

Movie createMovie() { //handles user inputting for movie creation.
    string title, description, credits;
    title = validated_input_s("Enter title: ");
    description = validated_input_s("Enter Description: ");
    credits = validated_input_s("Enter opening credits: ");
    Movie movie(title, description, credits);

    return movie;
}
// Tester

int main() {
    bool cont = true;
    int userInput = 0;
    Shelf s1;
    while (cont) {
        cout << "action options: " << endl;
        cout << "(1) Add movie to shelf" << endl;
        cout << "(2) Remove movie from shelf" << endl;
        cout << "(3) See how many movies are in shelf" << endl;
        cout << "(4) quit" <<endl ;
        userInput = bounded_input<int>("Which method would you like to invoke?:","input", 0b1111, 1, 4); //get input. uses a helper function from show
        cout << endl;
        if (userInput == 1) {
            cout << "Movie details: --------------" << endl;
            auto m1 = createMovie();
            try { 
                s1.add(m1);
                cout << "Movie added. ----------------" << endl << endl;
            }
            catch (ShelfFull& e) {//error handling if shelf is full
                cerr << e.what() << endl << endl;
            }
        }
        else if (userInput == 2) {
            try { 
                auto m = s1.remove();
                cout << "Movie removed. " << endl;
                cout << "Movie details: -------------" << endl;
                m.play();
                cout << endl;
            }
            catch (ShelfEmpty& e) { //error handling if shelf is empty
                cerr << e.what() << endl << endl;
            }
        }
        else if (userInput == 3) {
            cout << "There are " << s1.movieCount() << " movies on the shelf." << endl << endl;
        }
        else { cont = false; }
    }
}

