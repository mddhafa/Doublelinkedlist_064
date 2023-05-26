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

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else{
		cout << "\nRecords in asceding order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->nama << endl;
			currentNode = currentNode->next;
		}
	}
}


void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode->next != NULL) {
			cout << currentNode->noMhs << " " << currentNode->nama << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be delete: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << "delete" << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\n Enter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found " << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nNama: " << curr->nama << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2.Deletea record from the list" << endl;
			cout << "3.View all records in the ascending order of roll number" << endl;
			cout << "4.View all records in the descending order of roll number" << endl;
			cout << "5.search for a record in the list" << endl;
			cout << "6.exit" << endl;
			cout << "\nEnter your choice(1 - 6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "check for the values entered." << endl;
		}
	}
}