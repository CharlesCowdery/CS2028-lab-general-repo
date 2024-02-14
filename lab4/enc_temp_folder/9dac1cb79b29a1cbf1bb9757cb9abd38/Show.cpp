#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;


template <typename t> inline t validated_input(string prompt) { //just some wrapper code so the code isnt riddled with validated inputs
	while (true) {
		t holder;
		cout << prompt << flush;
		cin >> holder;
		cin.ignore(1000000, '\n');
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "invalid input." << endl;
		}
		else {
			return holder;
		}
	}
};

string inline validated_input_s(string prompt) {
	cin.clear();
	string holder;
	cout << prompt << flush;
	getline(cin, holder);
	return holder;
};


template <typename t> t bounded_input(string prompt, string name, char flags, t first, t second = t()) {
	bool gt_lower =  flags & 0b1000>>3;
	bool et_lower =  flags & 0b0100>>2;
	bool lt_higher = flags & 0b0010>>1;
	bool et_higher = flags & 0b0001>>0;
	t lower = 0;
	t higher = 0;
	t input;
	if (gt_lower || et_lower) {
		lower = first;
		if (lt_higher) higher = second;
	}
	else if (lt_higher) higher = first;
	while (true) {
		input = validated_input<t>(prompt);
		bool low_pass = (input > lower || !gt_lower) || (input == lower && et_lower);
		bool high_pass = (input < higher || !lt_higher) || (input == higher && et_higher);
		if (!low_pass || !high_pass) {
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

class Show {
protected:
	string title, description;
public:
	Show(string Title, string Description) : title(Title), description(Description) {}
	Show() : Show("", "") {};
	string getTitle() { return title; }
	string getDescription(){ return description; }
	void setTitle(string& t) { title = t; }
	void setDescription(string& d) { description = d; }

	virtual void play() = 0;

	void details() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
	}

};

class TvShow: public Show {
private:
	vector<vector<int>> seasonEpisodeRunTime = {};
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
		season = bounded_input<int>("Enter season number: ", "season number", 0xb1111, 1, seasonEpisodeRunTime.size());
		ep = bounded_input<int>("Enter episode number: ","episode number", 0xb1111, 1, seasonEpisodeRunTime[0].size());
		cout << "The run time is " << seasonEpisodeRunTime[season - 1][ep - 1] << endl;
	}
	void details() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		cout << "First episode runtime: " << seasonEpisodeRunTime[0][0] << " minutes" << endl;
	}
public:

};

class Movie:public Show {
private:
	string openingCredits;
public:
	string getCredits() { return openingCredits; }
	void setCredits(string& c) { openingCredits = c; }
	Movie() {};
	Movie(string t, string d, string c) : Show(t, d), openingCredits(c) {}
	Movie(string c) : Movie("","",c) {}

	void play() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		cout << "Opening Credits: " << openingCredits << endl;
	}
};