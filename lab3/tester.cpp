#include "heaps.h"
using namespace std

int main(){
	int littles, lots, heaps;
	string operation;
	bool stop = False;
	while stop != True {
		cout << "obj1 littles:";
		cin >> littles;
		cout << "obj1 lots:";
		cin >> lots;
		cout << "obj1 heaps:";
		cin >> heaps;
		Measure obj1 = Measure(littles,lots,heaps);
		cout << "operation to perform(+,-,/,*,==): ";
		string operation;
		cout << "obj2 littles:";
		cin >> littles;
		cout << "obj2 lots:";
		cin >> lots;
		cout << "obj2 heaps:";
		cin >> heaps;
		if (operation == "+") {Measure obj3 = obj1+obj2;}
		else if (operation == "-") {Measure obj3 = obj1-obj2;}
		else if (operation == "/") {Measure obj3 = obj1/obj2;}
		else if (operation == "*") {Measure obj3 = obj1*obj2;}
		else if (operation == "==") {bool obj3 = obj1==obj2;}
		cout << "results: " << obj3;
		cout << "Continue? (y/n): ";
		cin >> operation;
		if (operation == "n") {stop = True}
	}
	return 0;
}

//Hi