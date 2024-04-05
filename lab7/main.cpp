#include <iostream>
#include <random>
#include <ctime>
 #include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

/*
//////

Authored by Charles Cowdery
This is just a small util library containing some user input methods i wrote.

//////
*/

//prints prompt, and validates that user input is valid for that data type
//else, it reprompts the user. Continue until a valid input
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

//simpler function that uses readlines instead of cin>>.
string input_s(string prompt) {
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
//if C is set and not A, first will be considered the high bound.
//otherwise, first is the low bound and second will be the high bound (if high bound is set).
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

/* Exception Classes */
class listOverflow : public std::exception {
public:
	const char* what() {
		return "listOverflow Exception";
	}
};

class listUnderflow : public std::exception {
public:
	const char* what() {
		return "listUnderflow Exception";
	}
};

class valueDNE : public std::exception {
public:
	const char* what() {
		return "valueDoesNotExist Exception";
	}
};

#define SIZE 75
template<typename T>

class OrderedList {
protected:
	int numCompare;
	int numMove;
	int num;
public:
	/* Variables */
	T* arr[SIZE];


	/* Methods */
	OrderedList() {
		numCompare = 0;
		numMove = 0;
		num = 0;
	}
	void addItem(T* item) {
		if (isFull()) { throw listOverflow(); }
		int pos = 0;
		for (; pos < num; pos++) { //find pos
			numCompare++;
			if (*arr[pos] > *item) break;
		}
		if (pos == num) { //add if at end
			arr[pos] = item;
		}
		else { //shift otherwise
			for (int i = num; i > pos; i--) {
				arr[i] = arr[i - 1];
				numMove++;
			}
			arr[pos] = item;
		}
		num++;
	}
	void removeItem(T* item) {
		if (isEmpty()) throw listUnderflow();

		int pos = 0;
		for (;pos < num; pos++) { // find item
			numCompare++;
			if (*arr[pos] == *item) break;
		}
		if (pos == num) throw valueDNE();

		delete arr[pos];
		for (int i = pos; i < num - 1; ++i) {
			arr[i] = arr[i + 1];
			numMove++;
		}
		num--;
	}
	bool isEmpty() {
		return num == 0;
	}
	bool isFull() {
		return num == SIZE;
	}
	int size() {
		return num;
	}
	void makeEmpty() {
		num = 0;
		numMove = 0;
		numCompare = 0;
	}
	void print() {
		for (int i = 0; i < num; i++) {
			std::cout << *arr[i] << " ";
		}
		cout << endl;
	} // Useful for outputting current list
	void printStats() {
		cout << "comparisons: " << numCompare << " | moves: " << numMove << endl;
	}
};


template<typename U>

class BinaryList : public OrderedList<U> {
public:
	int searchValue(U* value) {
		int high = num;
		int low = 0;
		if (high == low)return 0;
		int mid;
		while (true) {
			mid = (high + low) / 2;
			U* v = arr[mid];
			numCompare++;
			if (*v < *value) {
				if (low == mid) return mid;
				low = mid;
				continue;
			}
			numCompare++;
			if (*v > *value) {
				if (high == mid) return mid;
				high = mid;
				continue;
			}
			return mid;
		}
	}
	void addItem(U* item) {
		if (isFull()) { throw listOverflow(); }
		int index = searchValue(item);
		for (int i = num; i > index; i--) {
			arr[i] = arr[i - 1];
			numMove++;
		}
		if (num != 0) {
			//if(index!=num)index++;
			numCompare++;
			if (*arr[index] < *item)index++;
		}
		arr[index] = item;
		num++;
	}
	void removeItem(U* item) {
		if (this->isEmpty()) {
			throw listUnderflow();
		}
		int index = searchValue(item);
		if (*arr[index] != *item) throw valueDNE();
		delete arr[index];
		num--;
		for (int i = index; i < num; i++) {
			arr[i] = arr[i + 1];
			numMove++;
		}

	}

};


template <typename t>
class SparseList : public OrderedList<t> {
public:
	SparseList() {
		for (int i = 0; i < SIZE; i++) {
			arr[i] = NULL;
		}
	}
	std::pair<int, int> place(t* item) {
		if (num == 0) return std::pair<int, int>(0, 0);
		int low = 0;
		int high = 0;
		for (; high < SIZE; high++) {
			t* at = arr[high];
			if (at != NULL) {
				numCompare++;
				if (*at >= *item) {
					break;
				}
				low = high;
			}
		}
		if (high == SIZE) high--;
		return std::pair<int, int>(low, high);
	}
	int probe(int index, int dir) {
		while (arr[index] != NULL) {
			index += dir;
			if (index == -1) return -1;
			if (index == SIZE) return -1;
		}
		return index;
	}
	void removeItem(t* item) {
		if (isEmpty()) throw listUnderflow();
		for (int i = 0; i < SIZE; i++) {
			if (arr[i] == NULL) continue;
			if (*arr[i] == *item) {
				delete arr[i];
				arr[i] = NULL;
				return;
			}
		}
		throw valueDNE();
	}
	void addItem(t* item) {
		if (isFull()) { throw listOverflow(); }
		auto indexes = place(item);
		int avg = ceil((float)(indexes.first + indexes.second) / 2.0);
		if (arr[avg] == NULL) {
			arr[avg] = item;
			num++;
		}
		else {
			t* at = arr[avg];
			int right_shiftable = probe(avg, 1);
			int left_shiftable = probe(avg, -1);
			numCompare++;
			if (*at >= *item) {
				if (right_shiftable != -1) { // 0ax
					for (int i = right_shiftable; i > avg; i--) {
						numMove++;
						arr[i] = arr[i - 1];
					}
					arr[avg] = item;
				}
				else {
					for (int i = left_shiftable; i < avg; i++) {
						numMove++;
						arr[i] = arr[i + 1];
					}
					arr[avg + 1] = item;
				}
			}
			numCompare++;
			if (*at < *item) { //
				if (left_shiftable != -1) { // xa0
					for (int i = left_shiftable; i < avg; i++) {
						numMove++;
						arr[i] = arr[i + 1];
					}
					arr[avg] = item;
				}
				else {
					for (int i = right_shiftable; i > avg; i--) {
						numMove++;
						arr[i] = arr[i - 1];
					}
					arr[avg] = item;
				}
			}
			num++;
		}
	}
	void makeEmpty() {
		num = 0;
		for (int i = 0; i < SIZE; i++) {
			arr[i] = NULL;
		}
	}
	void print(bool verbose) {
		bool first = true;
		for (int i = 0; i < SIZE; i++) {
			if (arr[i] == NULL) {
				if (verbose) {
					if (!first) {
						cout << " ";
					}
					cout << "X";
					first = false;
				}
				continue;
			}
			if (!first) {
				cout << " ";
			}
			cout << *arr[i];
			first = false;
		}
		cout << endl;
	}
};
int main() {
	srand(time(NULL));
	while (true) {
		cout << "Testing options:" << endl;
		cout << "1) User Test" << endl;
		cout << "2) Automated Test" << endl;
		cout << "3) Quit" << endl;

		int sel = bounded_input<int>("Selection?: ", "Selection", 0b1111, 1, 3);
		if (sel == 3) return 0;
		if (sel == 1) {
			SparseList<int> SL;
			BinaryList<int> BL;
			OrderedList<int> OL;
			while (true) {
				cout << "Ordered List" << endl;
				OL.printStats();
				OL.print();

				cout << "Binary List" << endl;
				BL.printStats();
				BL.print();

				cout << "Sparse List" << endl;
				SL.printStats();
				SL.print(true);

				cout << "Testing options:" << endl;
				cout << "1) Add Item" << endl;
				cout << "2) Remove Item" << endl;
				cout << "3) Quit" << endl;
				cout << endl;
				int sel = bounded_input<int>("Selection?: ", "Selection", 0b1111, 1, 3);

				if (sel == 3) break;
				int k = validated_input<int>("Enter value: ");
				int* k_p = new int(k);
				if (sel == 1) {
					try { SL.addItem(new int(k)); }
					catch (exception e) {}
					try { BL.addItem(new int(k)); }
					catch (exception e) {}
					try { OL.addItem(new int(k)); }
					catch (exception e) {}
				}
				if (sel == 2) {
					try { SL.removeItem(k_p); }
					catch (exception e) {}
					try { BL.removeItem(k_p); }
					catch (exception e) {}
					try { OL.removeItem(k_p); }
					catch (exception e) {}
				}
			}
		}
		if (sel == 2) {
			for (int run = 0; run < 100; run++) {
				SparseList<int> SL;
				BinaryList<int> BL;
				OrderedList<int> OL;
				for (int i = 0; i < SIZE; i++) {
					int k =  rand() % 100 + 1;
					try { SL.addItem(new int(k));}
					catch (exception e) {}
					try { BL.addItem(new int(k)); }
					catch (exception e) {}
					try { OL.addItem(new int(k)); }
					catch (exception e) {}


				}
				for (int i = 0; i < SIZE; i++) {
					int* k = new int(rand() % 100 + 1);
					try { SL.removeItem(k); }
					catch (exception e) {}
					try { BL.removeItem(k); }
					catch (exception e) {}
					try { OL.removeItem(k); }
					catch (exception e) {}


				}
				for (int i = 0; i < 30; i++) {
					int s = rand() % 2;
					int k = (rand() % 100 + 1);
					int* k_p = new int(k);
					if (s == 0) {
						try { SL.addItem(new int(k)); }
						catch (exception e) {}
						try { BL.addItem(new int(k)); }
						catch (exception e) {}
						try { OL.addItem(new int(k)); }
						catch (exception e) {}
					}
					else {
						try { SL.removeItem(k_p); }
						catch (exception e) {}
						try { BL.removeItem(k_p); }
						catch (exception e) {}
						try { OL.removeItem(k_p); }
						catch (exception e) {}
					}
				}
				cout << "Ordered List: ";
				OL.printStats();

				cout << "Binary List: ";
				BL.printStats();

				cout << "Sparse List: ";
				SL.printStats();
			}
		}
	}
	return 0;
}