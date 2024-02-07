#include <string>
using namespace std;


class Show {
protected:
	string title, description;
public:
	Show() : Show(0) {};
	Show(string Title, string Description) : title(Title), description(Description) {}
	string getTitle() { return title; }
	string getDescription{ return description; }
	void setTitle(string& t) { title = t; }
	void setDescription(string& d) { description = d; }

	virtual void play() = 0;

	void details() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
	}

};

class TvShow::public Show {
private:
	int seasonEpisodeRunTime[5][5];
public:
	TvShow()
		void play() {
		int season;
		int ep;
		cout << "Enter episode number: ";
		cin >> season;
		cout << "Enter season number: ";
		cin >> ep;
		cout << "The run time is " << seasonEpisodeRunTime[season - 1][ep - 1] << endl;
	}
	void details() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		cout << "First episode runtime: " << seasonEpisodeRunTime[0][0]
	}
public:

};

class Movie::public Show {
private:
	string openingCredits;
public:
	string getCredits() { return openingCredits; }
	void setCredits(string& c) { openingCredits = c; }
	Movie() {};
	Movie(t, d, c) { title = t; description = d; openingCredits = c; }
	Movie(c) { openinngCredits = c; }

	void play() {
		cout << "Title: " << title << endl;
		cout << "Description: " << description << endl;
		cout << "Opening Credits: " << openingCredits << endl;
	}
};