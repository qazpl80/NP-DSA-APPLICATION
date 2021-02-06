// List.cpp - Implementation of List ADT using Pointers

#include <cstddef>  // for NULL
#include <new>      // for bad_alloc

#include "DoctorAssignList.h"	// List header

// constructor
DoctorAssignList::DoctorAssignList()
{
	firstNode = NULL;
	size = 0;
}

void DoctorAssignList::sorting()
{
	Node* current;
	Node* bcurrent;
	current = firstNode;
	bcurrent = firstNode->next;

	for (int i = size - 1; i >= 0; i--) {
		current = firstNode;
		bcurrent = firstNode->next;
		for (int j = 0; j < size - 1; j++) {
			if (current->item.getDoctorName() > bcurrent->item.getDoctorName()) {
				swap(current->item, bcurrent->item);
			}
			current = bcurrent;
			bcurrent = bcurrent->next;
		}
	}
}

// add an item to the back of the list (append)
bool DoctorAssignList::add(DItemType item)
{
	// create a new node to store the item
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;		// move to last node
		temp->next = newNode;		// make last node point to the new node
	}
	size++;
	sorting();

	return true;  // no size constraint
}

// add an item at a specified position in the list (insert)
bool DoctorAssignList::add(int index, DItemType item)
{
	bool success = (index >= 0) && (index <= size + 1);

	if (success)
	{
		// create a new node to store the item
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 0) // inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 0; i < index - 1; i++)
				temp = temp->next;		// move to node at the position before the index

			newNode->next = temp->next;	// make new node point to the node pointed to by temp
			temp->next = newNode;		// make temp point to the new node
		}
		size++;
	}
	sorting();
	return success;
}

// remove an item at a specified position in the list
void DoctorAssignList::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		if (index == 0) // remove front node
		{
			Node* temp = firstNode;
			firstNode = firstNode->next;
			delete temp;
		}
		else
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 0; i < index; i++)
			{
				previous = current;
				current = current->next;		// move to next node
			}

			previous->next = current->next;	// delete the current node by
											   // making previous node point to the node pointed to by current node
			delete current;
		}
		size--;  // decrease the size of the list by 1
	}
}

// get an item at a specified position of the list (retrieve)
DItemType DoctorAssignList::get(int index)
{
	DItemType item;
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
			current = current->next;		// move to next node

		item = current->item;
	}

	return item;
}

DItemType* DoctorAssignList::getD(int index)
{
	DItemType* item = NULL;
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
			current = current->next;		// move to next node

		item = &current->item;
	}

	return item;
}

// check if the list is empty
bool DoctorAssignList::isEmpty() { return size == 0; }

// check the size of the list
int DoctorAssignList::getLength() { return size; }

//------------------- Other useful functions -----------------
void DoctorAssignList::print()
{
	sorting();
	Node* temp = firstNode;
	int i = 0;

	if (temp != NULL)		// list is NOT empty
	{
		while (temp != NULL)
		{
			cout << i << ") ";
			cout << temp->item.printDoctor() << "\n" << endl;
			temp = temp->next;		// move to next node
			i++;
		}
	}
	else   // list is empty
		cout << "The list is empty." << endl;
}




