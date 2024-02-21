#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;


template <typename t> inline t validated_input(string prompt) { //just some wrapper code so the code isnt riddled with input and validation code
	while (true) {
		t holder;
		cout << prompt << flush;
		cin >> holder;
		cin.ignore(1000000, '\n'); //stops cin from interefereing with readline
		if (cin.fail()) {
			cin.clear(); //clear buffer on bad input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "invalid input." << endl;
		}
		else {
			return holder;
		}
	}
};

//simpler function that uses readlines instead of cin>>.
//you cant make an invalid string, so theres no error checking
//the naming is simply a holdover from being a specialized template.
//Had to do away with the specialized template format as it did not play well with directly importing cpp files
string inline validated_input_s(string prompt) {
	cin.clear(); 
	string holder;
	cout << prompt << flush;
	getline(cin, holder);
	return holder;
};


//bounded input function. depending on how flags are set, it will compare a numerical input to the passed bounds
//bits are  use_low_bound, allow_equal_to_lower, use_high_bound, allow_equal_to_high
// 
//if only one bound is passed (only first) it will check the flag bits to figure out which bound is being used
//passing only one bound while setting the flag to use both is considered undefined behavior.

//honestly, overkill for this, but i can copy it into later projects
template <typename t> t bounded_input(string prompt, string name, char flags, t first, t second = t()) {
	bool gt_lower =  flags & 0b1000>>3; //checking flag bits
	bool et_lower =  flags & 0b0100>>2;
	bool lt_higher = flags & 0b0010>>1;
	bool et_higher = flags & 0b0001>>0;
	t lower = 0;
	t higher = 0;
	t input;
	if (gt_lower || et_lower) { //assigning use
		lower = first;
		if (lt_higher) higher = second;
	}
	else if (lt_higher) higher = first;
	while (true) {
		input = validated_input<t>(prompt);
		bool low_pass = (input > lower || !gt_lower) || (input == lower && et_lower); //looks painful but is just some regular boolean math
		bool high_pass = (input < higher || !lt_higher) || (input == higher && et_higher);

		if (!low_pass || !high_pass) { //basic io stuff
			cout << "Invalid input! " << name;
			if (!low_pass) {
				cout << " must be greater than ";
				if (et_lower) cout << "or equal to ";
				cout << lower;
			}
			if (!low_pass && !high_pass) {
				cout << " and";
			}
			if (!high_pass) {
				cout << " must be less than ";
				if (et_lower) cout << "or equal to ";
				cout << higher;
			}
			cout << endl;

		}
		else break;
	}
	return input;
}

class Show { //Show class, defines a basic structure on which to build other show like classes off of.
protected:
	string title, description;
public:
	Show(string Title, string Description) : title(Title), description(Description) {}
	Show() : Show("", "") {};
	string getTitle() { return title; }
	string getDescription(){ return description; }
	void setTitle(string& t) { title = t; }
	void setDescription(string& d) { description = d; }

	virtual void play() = 0; //varies

	void details() { //displays basic details about the show
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
	}

};

class TvShow: public Show { //inherits Show. represents a serialized tv show with multiple episodes
private:
	vector<vector<int>> seasonEpisodeRunTime = {}; //stores episode runtimes
public:
	TvShow(string title, string description, vector<vector<int>> playtimes) :Show(title, description) {
		seasonEpisodeRunTime = playtimes;
	}
	TvShow(vector<vector<int>> playtimes) : Show() {
		seasonEpisodeRunTime = playtimes;
	}
	void play() {
		int season;
		int ep;
		season = bounded_input<int>("Enter season number: ", "season number", 0xb1111, 1, seasonEpisodeRunTime.size()); //asks user for which episode to display
		ep = bounded_input<int>("Enter episode number: ","episode number", 0xb1111, 1, seasonEpisodeRunTime[0].size());
		cout << "The run time is " << seasonEpisodeRunTime[season - 1][ep - 1] << " minutes" << endl;
	}
	void details() { //adds first episode runtime to details
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		cout << "First episode runtime: " << seasonEpisodeRunTime[0][0] << " minutes" << endl;
	}
public:

};

class Movie:public Show { //inherits show, represents a movie
private:
	string openingCredits; //like the opening scroll
public:
	string getCredits() { return openingCredits; }
	void setCredits(string& c) { openingCredits = c; }
	Movie() {};
	Movie(string t, string d, string c) : Show(t, d), openingCredits(c) {}
	Movie(string c) : Movie("","",c) {}

	void play() { //adds opening credits to play
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		cout << "Opening Credits: " << openingCredits << endl;
	}
};