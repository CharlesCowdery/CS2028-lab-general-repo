
#include <iostream>
#include <stdexcept>
#include <string>
#include "Show.cpp"

#define SIZE 5 //using a preprocessor directive for constant c type array size.
//its what ive been taught personally, dunno how standard it is.

using namespace std;

class CollectionFull : public std::exception {
public:
    const char* what() {
        return "Error, collection is full.";
    }
};

class CollectionEmpty : public std::exception {
public:
    const char* what() {
        return "Error, collection is empty.";
    }
};

template <typename t>
class EntertainmentCollection { //as defined in spec. refer to lab-a for implementation comments, since this is identical to shelf
private:
    t collection[SIZE];
    int num = 0;
public:
    EntertainmentCollection() {}
    t remove() {
        if (num <= 0) { throw CollectionEmpty(); }
        num -= 1;
        return collection[num];
    }
    void add(const t& item) {
        if (num >= SIZE) { throw CollectionFull(); }
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

class VideoGame { //Video game class as defined in the spec
private:
    std::string title;
    std::string genre;
public:
    VideoGame() : title(""), genre("") {}
    VideoGame(const std::string& _title, const std::string& _genre) : title(_title), genre(_genre) {}
    void setTitle(const std::string& _title) {
        title = _title;
    }
    void setGenre(const std::string& _genre) {
        genre = _genre;
    }
    void play() {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
    }
};

VideoGame createGame() { //handles user inputting for game creation.
    string title, description, credits;
    title = validated_input_s("Enter title: ");
    description = validated_input_s("Enter Genre: ");
    VideoGame game(title, description);

    return game;
}


int main() {
    bool cont = true;
    int userInput = 0;
    EntertainmentCollection<VideoGame> s1;
    while (cont) {
        cout << "action options: " << endl;
        cout << "(1) Add game to collection" << endl;
        cout << "(2) Remove game from collection" << endl;
        cout << "(3) See how many game are in collection" << endl;
        cout << "(4) quit" << endl;
        userInput = bounded_input<int>("Which method would you like to invoke?:", "input", 0b1111, 1, 4);
        cout << endl;
        if (userInput == 1) {
            cout << "Game details: --------------" << endl;
            auto m1 = createGame();
            try {
                s1.add(m1);
                cout << "Game added. ----------------" << endl << endl;
            }
            catch (CollectionFull& e) {
                cerr << e.what() << endl << endl;
            }
        }
        else if (userInput == 2) {
            try {
                auto m = s1.remove();
                cout << "Game removed. " << endl;
                cout << "Game details: -------------" << endl;
                m.play();
                cout << endl;
            }
            catch (CollectionEmpty& e) {
                cerr << e.what() << endl << endl;
            }
        }
        else if (userInput == 3) {
            cout << "There are " << s1.count() << " games in the collection." << endl << endl;
        }
        else { cont = false; }
    }
}
