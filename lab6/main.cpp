#include "Queue.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



//outputs the parameter prompt, and then takes a user input.
//will repeat the prompt until the user enters a usable input
//Do not use this with string as the template type!!!
template <typename t> inline t validated_input(string prompt) { 
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

string inline input_s(string prompt) {
	cin.clear();
	string holder;
	cout << prompt << flush;
	getline(cin, holder);
	return holder;
};

//Takes an input bounded by the parameter first and second depending on how flags are set.
//Will continue to prompt for input until a legal input is provided.
//flag format: 0bABCD 
//	A: use low bound
//	B: allow equivalence to lower bound
//	C: use high bound
//	D: allow equivalence to high bound
//if C is set and not A, first will be considered the high bound. otherwise, first is the low bound and second will be the high bound if set.
template <typename t> t bounded_input(string prompt, string name, char flags, t first, t second = t()) {
	bool gt_lower = flags & 0b1000 >> 3; //checking flag bits
	bool et_lower = flags & 0b0100 >> 2;
	bool lt_higher = flags & 0b0010 >> 1;
	bool et_higher = flags & 0b0001 >> 0;
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



int main() {
	while (true) {
		cout << "Enter 1 to test using file.\nEnter 2 to test via cmd.\nEnter 3 to exit." << endl;
		int choice = bounded_input("Enter input: ", "value", 0xb1111, 1, 3); //get user choice

		if (choice == 1) {
			try {
				string fname;
				fstream f;
				while (true) { //file input and validation
					fname = input_s("Enter filename: ");
					f = fstream(fname, ios::in);
					if (f.fail()) {
						cout << "File not found." << endl;
						continue;
					}
					break;
				}
				int size = 0;
				string read_value; //getting the requisite allocation size of words.
				while (!f.eof()) {
					f >> read_value;
					size++;
				}
				f.clear();//reset read position in file
				f.seekg(0, ios::beg);

				Queue<Stack<char>> words(size);
				 
				while (!f.eof()) { //actually read in file
					f >> read_value;
					auto s = new Stack<char>(read_value.size());
					for (int i = 0; i < read_value.size(); i++) {
						char c = read_value[i];
						char* c_ptr = new char(c); //abomination. The pointer is 8x bigger than the data
						s->push(c_ptr);
					}
					words.enqueue(s);
				}

				while (!words.isEmpty()) { //outputs the reversed words in order via the natural output of the queue of stacks.
					auto s = words.dequeue();
					while (!s->isEmpty()) {
						auto c = s->pop();
						string o = "";
						o += *c;
						cout << o;
						delete c; //to make sure this ship doesnt leak memory like a sieve
					}
					cout << " ";
					delete s;
				}
			}
			catch (exception e) {
				cout << e.what() << endl;
			}

		}
		if (choice == 2) {
			try {
				string v = input_s("enter a string to reverse: ");
				Queue<Stack<char>> words(10000); //too lazy to get the correct size, so big number that nobody will reasonably hit. If they do, guess they get the error
				string word = "";
				for (int i = 0; i < v.size(); i++) { //just basic string splitting
					char c = v[i];
					if (c == ' ') {
						auto s = new Stack<char>(word.size());
						for (auto c : word) {
							auto c_ptr = new char(c);
							s->push(c_ptr);
						}
						words.enqueue(s);
						word = "";
					}
					else {
						word += c;
					}
				}
				if (word.size() > 0) {
					auto s = new Stack<char>(word.size());
					for (auto c : word) {
						auto c_ptr = new char(c);
						s->push(c_ptr);
					}
					words.enqueue(s);
					word = "";
				}

				while (!words.isEmpty()) { //outputs the reversed words in order via the natural output of the queue of stacks.
					auto s = words.dequeue();
					while (!s->isEmpty()) {
						auto c = s->pop();
						string o = "";
						o += *c;
						cout << o;
						delete c;
					}
					cout << " ";
					delete s;
				}
				cout << endl;
			}
			catch (queueOverflow) {
				cout << "Queue overflow! really not sure how you managed to enter 100000 spaces but good on you." << endl; //if you see this, you did something nasty.
			}
		}
		if (choice == 3) break;
	}
	return 0;
}