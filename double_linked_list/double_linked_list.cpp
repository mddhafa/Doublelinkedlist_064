#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START = NULL;
public :
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

void DoubleLinkedList::addNode() {
	int nim;
	string nama;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of student: ";
	cin >> nama;

	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; //step 2
	newNode->nama = nama; //step 2

	/*insert a node in the beginig of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {// check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode; // step4
		newNode->prev = NULL; //Step 5
		START = newNode; // step 6
		return;
	}
	
	/*Inserting a Node Between Two Nodes in the list*/
	Node* current = START; //1.a
	Node* previous = NULL; //1.b 
	while (current->next != NULL && current->next->noMhs < nim) //step 1c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" <<endl;
		return;
	}

	newNode->next = current->next; //step 4
	newNode->prev = current; //step5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; // step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; //step 1.a
	*current = START; //1.b
	while (*current != NULL && (*current)->noMhs != rollNo) { //step1.c
		*previous = *current; //step 1.d
		*current = (*current)->next; //step1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;//step2
	if (previous != NULL)
		previous->next = current->next; //step3
	else
		START = current->next;

	delete current; //step4
	return true;
}

