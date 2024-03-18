template class<typename T>
#include <stdexcept>

/* Exception Classes */
class listUnderflow : public std::exception {
public:
	const char* what() {
		return "listUnderflow Exception";
	}
};

/* Node Class */
class Node {
public:
	/* Variables */
	Node* next;
	Node* prev;
	T data;

	/* Constructor */
	Node(T value);
};

/* Order Doubly Linked List */
class OrdList {
	/* Variables */
	Node* head;
	Node* tail;

	/* Methods */
	OrdList();
	~OrdList();
	void addItem(T value);
	T getItem(T value);
	bool inList(T value);
	bool isEmpty();
	int size();
	T seeNext();
	T seePrev();
	T seeAt(int location);
	void reset();
};