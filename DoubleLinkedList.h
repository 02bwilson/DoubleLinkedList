#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

using namespace std;

class IndexOutOfBounds {
};


class DoubleLinkedList {
private:
	struct node {
		int data; 
		node* prev;
		node* next;
	};
	node* head = new node;
public: 
	DoubleLinkedList();
	void insert(int value);
	void merge(DoubleLinkedList* absorbedList);
	void remove(int value);
	const int& operator[](int index) const;
	int getCount() const;
	void display(bool reverse) const;

};




















#endif 