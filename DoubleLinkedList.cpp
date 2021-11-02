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

	

	if (!head) {
		newNode->prev = nullptr;
		head = newNode;
	}
	else {
		node* nodePtr = new node;
		nodePtr = head; 
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		newNode->prev = nodePtr;
		nodePtr->next = newNode;
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

}
//const int& DoubleLinkedList::operator[](int index) const {

//}
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