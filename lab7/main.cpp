#include <iostream>
#include <random>
#include <ctime>

#include "utils.h"
#include "SparseList.h"
#include "OrderedList.h"
#include "BinaryList.h"
 
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
				delete k_p;
			}
		}
		if (sel == 2) {
			for (int run = 0; run < 100; run++) {
				SparseList<int> SL;
				BinaryList<int> BL;
				OrderedList<int> OL;
				for (int i = 0; i < 25; i++) {
					int k =  rand() % 100 + 1;
					try { SL.addItem(new int(k));}
					catch (exception e) {}
					try { BL.addItem(new int(k)); }
					catch (exception e) {}
					try { OL.addItem(new int(k)); }
					catch (exception e) {}


				}
				for (int i = 0; i < 25; i++) {
					int* k = new int(rand() % 100 + 1);
					try { SL.removeItem(k); }
					catch (exception e) {}
					try { BL.removeItem(k); }
					catch (exception e) {}
					try { OL.removeItem(k); }
					catch (exception e) {}
					delete k;


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