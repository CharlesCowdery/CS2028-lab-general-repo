#include <iostream>
#include <string>
#include <cstdlib>
#include "LinearHash.h"
#include "ChainedHash.h"

using namespace std;

// Generate a random SKU
string generateRandomSKU(int length) {
    const string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string result;
    for (int i = 0; i < length; ++i) {
        result.push_back(charset[rand() % charset.length()]);
    }
    return result;
}

// Display menu and get user input
int getMenuChoice() {
    int choice;
    cout << "Prompt the user for the following options:" << endl;
    cout << "1. User Test" << endl;
    cout << "2. Automated Test" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Display user test options
int getUserTestChoice() {
    int choice;
    cout << "For User Test" << endl;
    cout << "1. Linear Probing from Task 1" << endl;
    cout << "2. Separate Chaining from Task 4" << endl;
    cout << "3. Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Display user test operations
int getUserTestOperationChoice() {
    int choice;
    cout << "For option 1 and 2 of User Test" << endl;
    cout << "1. Add an item" << endl;
    cout << "2. Remove an item" << endl;
    cout << "3. Search an item" << endl;
    cout << "4. Display length" << endl;
    cout << "5. Exit to User Test options" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    // Seed random number generator
    srand(time(nullptr));

    int choice;
    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1: {
                int testChoice;
                do {
                    testChoice = getUserTestChoice();
                    switch (testChoice) {
                        case 1: {
                            // Test Linear Probing from Task 1
                            break;
                        }
                        case 2: {
                            // Test Separate Chaining from Task 4
                            break;
                        }
                        case 3: {
                            // Return to main menu
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                } while (testChoice != 3);
                break;
            }
            case 2: {
                // Automated Test
                break;
            }
            case 3: {
                // Quit
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
