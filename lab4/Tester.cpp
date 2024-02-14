#pragma once

#include <iostream>
#include <string>
#include "Show.cpp"

using namespace std;

// Function to test classes
void testClasses(Show* show) { //self explanatory. calls the member functions related to show based objects
    cout << endl;
    cout << "*-details: " << endl;
    show->details();
    cout << endl;
    cout << "*-play: " << endl;
    show->play();
    cout << endl;
}

Movie createMovie() { //handles user inputting for movie creation.
    string title, description, credits;
    title = validated_input_s("Enter title: ");
    description = validated_input_s("Enter Description: ");
    credits = validated_input_s("Enter opening credits: ");
    Movie movie(title, description, credits);

    return movie;
}

TvShow createTvShow() { //handles user inputting for TvShow creation.
    string title, description;
    vector<vector<int>> runtimes;

    title = validated_input_s("Enter title: ");
    description = validated_input_s("Enter Description: ");
    int season_count = bounded_input<int>("how many seasons?: ", "season count", 0b1100, 0);
    int episode_count = bounded_input<int>("how many episodes per season?: ", "episode count", 0b1100, 0);

    runtimes.resize(season_count);//too lazy to push on the fly, so im just resizing to the correct size and bracket accessing
    for (auto& season : runtimes) season.resize(episode_count);
    for (int s = 0; s < season_count; s++) {
        for (int e = 0; e < episode_count; e++) {
            string prompt = "Enter the runtime of s" + to_string(s + 1) + "e" + to_string(e + 1) + ": "; //fetch each episode runtime
            int length = bounded_input<int>(prompt, "runtime", 0b1100, 0);
            runtimes[s][e] = length;
        }
    }

    TvShow tvShow(title, description, runtimes);

    return tvShow;
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
        cout << "Press 5 to exit" << endl;
        choice = bounded_input("Enter your choice: ", "selection", 0b1111, 1, 5);
        cout << endl;

        if (choice == 1) { //these are all straightforward implementations of the testing guidelines
            cout << "testing MOVIE: " << endl;
            Movie movie = createMovie();
            testClasses(&movie);
        }
        else if (choice == 2) {
            cout << "testing TVSHOW: " << endl;
            TvShow tvShow = createTvShow();
            testClasses(&tvShow);
        }
        else if (choice == 3) {
            cout << "testing MOVIE as SHOW: " << endl;
            Movie movie = createMovie();

            Show* movieAsShow = &movie;
            testClasses(movieAsShow);
        }
        else if (choice == 4) {
            cout << "testing TVSHOW as SHOW: " << endl;
            TvShow tvShow = createTvShow();
            Show* tvShowAsShow = &tvShow;
            testClasses(tvShowAsShow);
        }

        cout << "Do you wish to continue testing? (Yes/No): ";
        string response;
        cin >> response;
        for (int i = 0; i < response.size(); i++)
            response[i] = tolower(response[i]); //make response lowercase
        if (response != "y") { //check just the first letter to account for people being lazy and going 'y'
            continueTesting = false;
        }
    }

    return 0;
}