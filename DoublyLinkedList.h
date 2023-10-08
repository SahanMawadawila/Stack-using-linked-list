#include <iostream>
#include "IntNode.h"
using namespace std;


// Doubly linked list class define
class DoublyLinkedList {
public:
	Node* start = NULL;
public:
	void insertBeg(int X); //Insert a new node at the beginning
	void insertEnd(int X); //Insert a node at the end
	void deleteBeg(); //Delete a node from the beginning 
	void deleteEnd(); //Delete a node from the end 
	void deleteByValue(int D); //Delete a node with a given value 
	void print(); //Print current list
	Node* search(int F); //Search an existing element 
	int sum(); //Add list values to get sum

};


// Insert a new node at the beginning
void DoublyLinkedList::insertBeg(int X) {
	Node* temp = new Node();
	temp->data = X;

	//empty linked list
	if (start == NULL) {
		start = temp;
	}

	//not empty linked list
	else {
		temp->right = start;
		start->left = temp;
		start = temp;
	}
}

// Insert a node at the end
void DoublyLinkedList::insertEnd(int X) {
	Node* temp = new Node();
	temp->data = X;

	//empty linked list
	if (start == NULL) {
		start = temp;
	}
	//not empty linked list
	else {
		Node* ptr = start;
		//traverse to the end
		while (ptr->right != NULL) {
			ptr = ptr->right;
		}
		ptr->right = temp;
		temp->left = ptr;
	}
}

// Delete a node from the beginning 
void DoublyLinkedList::deleteBeg() {
	Node* ptr = start;
	//empty linked list
	if (start == NULL) {
		cout << "There is no element to delete." << endl;
	}

	// if the list is of one node 
	else if (start->right == NULL) {
		start = NULL;
	}

	// if there are more than one nodes in the list
	else {
		start = start->right;
		start->left = NULL; // there are no node to the left of the start node
	}
	//free the space by deleting the node
	delete ptr;
}

// Delete a node from the end
void DoublyLinkedList::deleteEnd() {
	Node* ptr = start;
	//empty linked list
	if (start == NULL) {
		cout << "There is no element to delete." << endl;
	}

	// if there is only one node
	else if (start->right == NULL) {
		start = NULL;
	}

	// if there are more than one nodes in the list
	else {
		while (ptr->right != NULL) {
			ptr = ptr->right;
		}
		ptr->left->right = NULL;
	}
	//free the space by deleting the node
	delete ptr;
}

// Delete a node with a given value 
void DoublyLinkedList::deleteByValue(int value) {
	Node* ptr = start;
	bool y = true;

	// Check if the list is empty
	if (start == NULL) {
		cout << "The list is empty. Nothing to delete." << endl;
		return;
	}

	// Special case: Deleting the first node
	if (ptr->data == value) {
		DoublyLinkedList::deleteBeg();
		return;
	}

	// Traverse the list until the value node is found
	while (ptr != NULL) {
		// If the value is found in the node
		if (ptr->data == value) {
			// Special case: Deleting the last node
			if (ptr->right == NULL) {
				ptr->left->right = NULL;
			}
			else {
				ptr->left->right = ptr->right;
				ptr->right->left = ptr->left;
			}
			y = false;
			return;
		}
		ptr = ptr->right; // Jump to the next node
	}

	if (y == true) {
		cout << "Value was not found to delete" << endl;
	}
	//free the memory
	delete ptr;
}


// Print current list
void DoublyLinkedList::print() {
	Node* ptr = start;
	//empty linked list
	if (start == NULL) {
		cout << "Empty linked list" << endl;
	}
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->right;
	}
}

//Search an existing element and return its address
Node* DoublyLinkedList::search(int value) {
	//empty linked list
	if (start == NULL)
		return NULL;

	Node* ptr = start;
	// travers to the node containing the value
	while (ptr != NULL) {
		// if value return the node
		if (ptr->data == value)
			return ptr;
		ptr = ptr->right;
	}
	// if there are no values return a NULL
	return NULL;
}

//sum of the list values
int DoublyLinkedList::sum() {
	int sum = 0;
	Node* ptr = start;

	// traverse the list
	while (ptr != NULL) {
		sum += ptr->data;
		ptr = ptr->right;
	}
	return sum;
}