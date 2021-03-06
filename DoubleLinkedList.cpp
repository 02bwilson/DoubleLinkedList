#include "DoubleLinkedList.h"
#include <iostream>

using namespace std; 

DoubleLinkedList::DoubleLinkedList() {
	head = nullptr; 
}
void DoubleLinkedList::insert(int value) {
	
	node* newNode = new node;
	newNode->data = value;
	newNode->next = nullptr; 

	node* nodePtr = new node;
	nodePtr = head;

	if (!head) {
		head = newNode;
		newNode->prev = nullptr;
	}
	else if (head->data >= newNode->data) {
		newNode->next = head;
		newNode->next->prev = newNode;
		head = newNode;
	}
	
	else {
	while (nodePtr->next && nodePtr->next->data < newNode->data)
			nodePtr = nodePtr->next;
			newNode->next = nodePtr->next;

		
		if (nodePtr->next) {
			newNode->next->prev = newNode;
		}
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
	}


		

}
void DoubleLinkedList::merge(DoubleLinkedList* absorbedList) {
	node* nodePtr = new node;
	nodePtr = head;
	while (nodePtr->next) {
		nodePtr = nodePtr->next;
	}
	absorbedList->head->prev = nodePtr;
	nodePtr->next = absorbedList->head;
	
	
}
void DoubleLinkedList::remove(int value) {
	node* nodePtr = new node;
	nodePtr = head;
	for (int i = 0; i < getCount() + 1; i++) {
		if (nodePtr->data == value) {
			nodePtr->prev->next = nodePtr->next;
		}
		if (i == getCount() + 1) {
			nodePtr->next = nullptr;
		}
		nodePtr = nodePtr->next;
		
	}
}

const int& DoubleLinkedList::operator[](int index) const {
	node* nodePtr = new node;
	nodePtr = head;
	if (index > getCount()) {
		throw IndexOutOfBounds();
	}
	else {
		int i = 0;
		while (i != index && nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		return nodePtr->data;
	}
}

int DoubleLinkedList::getCount() const {
	node* nodePtr = new node;
	nodePtr = head;
	int count = 0;
	while (nodePtr->next) {
		count++;
		nodePtr = nodePtr->next;
	}
	return count;
}

void DoubleLinkedList::display(bool reverse) const {
	if (!reverse) {
		node* nodePtr = new node;
		nodePtr = head;
		while (nodePtr->next) {
			cout << nodePtr->data << " ";
			nodePtr = nodePtr->next;
		}
		cout << nodePtr->data;
	}

	else {
		node* nodePtr = new node;
		nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		while (nodePtr->prev) {
			cout << nodePtr->data << " ";
			nodePtr = nodePtr->prev;
		}
		cout << nodePtr->data;
	}
}