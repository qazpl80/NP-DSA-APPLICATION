// Queue.cpp - Implementation of Queue ADT (Pointer-based)

#include "Queue.h"

Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

Queue::~Queue() { }

bool Queue::enqueue(const ItemType item)
{
	// create a new node to store data
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// insert the new node
	if (isEmpty())	// enqueue at the front
	{
		frontNode = newNode;
		backNode = newNode;
	}
	else			// enqueue at the back
	{
		backNode->next = newNode;
		backNode = newNode;  // new node is at back
	}

	return true;
}

bool Queue::dequeue()
{
	bool success = !isEmpty();
	if (success)					// queue is not empty -> remove front
	{
		Node* temp = frontNode;		// to be returned to the system
		if (frontNode == backNode)  // only one node in the queue
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
			frontNode = frontNode->next;

		// return node to the system
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}

	return success;
}

bool Queue::dequeue(ItemType& item)
{
	bool success = !isEmpty();
	if (success)				// queue is not empty
	{
		item = frontNode->item; // retrieve front item
		dequeue();              // delete front
	}

	return success;
}

void Queue::getFront(ItemType& item)
{
	bool success = !isEmpty();
	if (success) // queue is not empty -> retrieve item at the front
		item = frontNode->item;
}

int Queue::getLength()
{
	Node* temp = frontNode;
	int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

bool Queue::isEmpty() { return frontNode == NULL; }

ItemType Queue::secondLargest()
{
	Node* temp = frontNode - 1;
	int count = 0;
	int largest;
	Node* tempc = frontNode;
	while (temp != backNode)
	{
		Node* temp = frontNode - 1;
		temp = temp->next;
		if (frontNode->item >= tempc->item)
		{
			largest = frontNode->item;
			tempc = tempc->next;
		}
		else if (temp->item >= frontNode->item)
		{
			largest = tempc->item;
		}
	}
	temp + 1;
	if (backNode->item > temp->item)
	{
		largest = tempc->item;
	}
	else if (temp->item > backNode->item)
	{
		largest = backNode->item;
	}
}


