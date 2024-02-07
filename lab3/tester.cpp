#include "heaps.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	int littles, lots, heaps;
	string operation;
	bool stop = false;
	while(stop != true){
		cout << "obj1 littles:"; //getting object 1 data
		cin >> littles;
		cout << "obj1 lots:";
		cin >> lots;
		cout << "obj1 heaps:";
		cin >> heaps;
		Measure obj1 = Measure(littles,lots,heaps);
		

		cout << "operation to perform(+,-,/,*,==): "; //get operation
		string operation;
		cin >> operation;
		
		cout << "obj2 littles:"; //getting object 2 data
		cin >> littles;
		cout << "obj2 lots:";
		cin >> lots;
		cout << "obj2 heaps:";
		cin >> heaps;
		Measure obj2 = Measure(littles, lots, heaps);

		Measure obj3;							//picking operation and performing it
		if (operation == "+") obj3 = obj1+obj2;
		if (operation == "-") obj3 = obj1-obj2;
		if (operation == "/") obj3 = obj1/obj2;
		if (operation == "*") obj3 = obj1*obj2;
		if (operation == "==") {
			bool res = obj1 == obj2;
			cout << "results: " << (res?"true":"false") << endl; //its own output statement due to data types
		}
		else cout << "results (l/L/H): " << string(obj3) << " ("<<obj3.allLittles() << ")" << endl; //print result, with the decimal equivalent for testing purposes

		bool exit = true;
		while (true) { //prompt the user if theyd like to exit until a valid respose is given
			string continue_answer;
			cout << "Continue? (y/n): ";
			cin >> continue_answer;
			char c_ans = tolower(continue_answer[0]); //makes it so yes and no are also valid compared to y or n

			if (c_ans == 'n') break;
			if (c_ans == 'y') { 
				cout << endl; //formatting 
				exit = false;
				break;
			}
		}
		if (exit) break;
	}
	return 0;
}

//Hi