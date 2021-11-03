#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

using namespace std; 

int main() {
	// Creating a List 
	DoubleLinkedList* List = new DoubleLinkedList;

	// Insert Values 1 and 2 to linked list 
	List->insert(1);
	List->insert(2);

	// Displaying the values (false) so it isnt reversed
	List->display(false);
	cout << endl;
	
	// Making a second list
	DoubleLinkedList* newList = new DoubleLinkedList;

	// Inserting some new values
	newList->insert(3);
	newList->insert(4);
	newList->insert(5);

	// Merging the second list into the first list
	List->merge(newList);

	// Displaying the new merged list reversed to make sure the head of the absorbed list properly got the previous value from the first list 
	// (absorbedlist->head->prev = last value in first list instead of nullptr)
	List->display(true);
	cout << endl;


	//Displaying the new merged list non reversed
	List->display(false);
	cout << endl;



	// Removing element with values 4 & 5

	List->remove(5);
	List->display(false);
	cout << endl;

	List->remove(4);
	List->display(false);
	cout << endl;

	// Getting the value at index 2
	// :/ 

	cout << List->operator[](2);


	







	return 0;
}