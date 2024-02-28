#include "Queue.h"
#include "Stack.h"
#include <string>
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
	Stack s1 = new Stack(100);
	Queue q1 = new Queue(100);
	// -> Stack... Implementation Try/Catch for overflow
	
	// Stack -> Queue -> Output
	int j = s1.length();
	for (int i = 0; i < j; i++) {
		q1.enqueue(s1.pop());
	}
	j = q1.sizeQueue();
	for (int i = 0; i < j; i++) {
		cout << &(q1.dequeue());
	}
	




	return 0;
}