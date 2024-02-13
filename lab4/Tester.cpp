#include <iostream>
#include <string>
#include "Show.cpp"

using namespace std;

// Function to test classes
void testClasses(Show* show) {
    show->details();
    show->play();
}

int main() {
    int choice;
    bool continueTesting = true;
    //Prompt the user for which class to create and values to set the attributes for that class
    while (continueTesting) {
        cout << "Press 1 for an instance of Movie." << endl;
        cout << "Press 2 for an instance of TV Show." << endl;
        cout << "Press 3 for an instance of a MOVIE declared as a Show." << endl;
        cout << "Press 4 for an instance of a TV Show declared as a Show." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, description, credits;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter description: ";
            getline(cin, description);
            cout << "Enter opening credits: ";
            getline(cin, credits);
            Movie movie(title, description, credits);
            testClasses(&movie);
        }
        else if (choice == 2) {
            string title, description;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter description: ";
            getline(cin, description);
            TvShow tvShow;
            tvShow.setTitle(title);
            tvShow.setDescription(description);
            testClasses(&tvShow);
        }
        else if (choice == 3) {
            string credits;
            cout << "Enter opening credits: ";
            cin.ignore();
            getline(cin, credits);
            Show* movieAsShow = new Movie("", "", credits);
            testClasses(movieAsShow);
            delete movieAsShow;
        }
        else if (choice == 4) {
            string title, description;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter description: ";
            getline(cin, description);
            Show* tvShowAsShow = new TvShow();
            tvShowAsShow->setTitle(title);
            tvShowAsShow->setDescription(description);
            testClasses(tvShowAsShow);
            delete tvShowAsShow;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you wish to continue testing? (Yes/No): ";
        string response;
        cin >> response;
        if (response != "Yes") {
            continueTesting = false;
        }
    }

    return 0;
}
