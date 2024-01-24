// CS2028-lab2-task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <random>
using namespace std;



class Player {
public:
    string Name;
    int ShotsTaken      = 0;
    int ShotsMade       = 0;
    int PassesAttempted = 0;
    int PassesMade      = 0;
    Player(string _Name) {
        Name = _Name;
    }
    bool PassBall() {
        int pull = rand() % 101;
        int modifier = (ShotsTaken > 0) ? (double)ShotsMade / ShotsTaken * 100 : 0;
        int threshold = 50 + modifier;
        return pull < threshold;
    }
};

struct Team {
    static const vector<string> PlayerNames;//contains possible player names
    vector<Player> players;
    int points;
    int possessions;
};
//Weird that I have to define it outside the struct but okay
const vector<string> Team::PlayerNames = { "Jordan","Nate","Curry","Bob","Yogan","Gerschit","Steven","Charlie","Jeff","Tom","Lebron","Mr.Milk","Tony T.","Willy","Gebby" };

void runGame() {
    Team T1;
    Team T2;
    
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
