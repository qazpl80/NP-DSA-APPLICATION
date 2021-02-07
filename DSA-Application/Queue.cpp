// Queue.cpp - Implementation of Queue ADT (Pointer-based)
//
// Class: T03
// Team Group: Team F
//
// |Name                       |Student Number |
//-----------------------------|---------------|
// |Tan Yuan Ming	           |(S10198319C)   |
// |Gladys Chua Ling Hui	   |(S10196678G)   |
//
//
// Patient's Linked-List Queue Source File: Containing Patient's Class (retrieved from the array list) and Queue Linked-List Code and functions 
#include "Queue.h"


static int queuenumber = 1;

Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

Queue::~Queue() { }

bool Queue::enqueue(const ItemType item,  static int& queuenumber)
{

	// create a new node to store data
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	newNode->queuenum = queuenumber;

	// insert the new node
	if (isEmpty())					// enqueue at the front
	{
		frontNode = newNode;
		backNode = newNode;
	}
	else							// enqueue at the back
	{
		backNode->next = newNode;
		backNode = newNode;			// new node is at back
	}
	return true;
}

bool Queue::dequeue()
{
	
	bool success = !isEmpty();
	if (success)					// queue is not empty -> remove front
	{
		Node* temp = frontNode;		// to be returned to the system
		if (backNode == frontNode)  // only one node in the queue
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
	if (success)					// queue is not empty
	{
		item = frontNode->item;		// retrieve front item
		dequeue();					// delete front
	}
	

		


	return success;
}

void Queue::getFront(ItemType& item)
{
	bool success = !isEmpty();
	if (success)					// queue is not empty -> retrieve item at the front
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
void Queue::getSecondLargest(ItemType& item)
{
	bool success = !isEmpty();
	if (success && (getLength() >= 2))					// queue is not empty -> retrieve item at the front

		item = frontNode->next->item;




}
bool Queue::isEmpty() { return frontNode == NULL; }

void Queue::resetQueueNum() 
{
	// Reset number count
	
	
	
	frontNode->next = NULL;
	backNode->next  = NULL;
	
	
	
}

int Queue::displayfrontQueueNum()
{
	bool success = !isEmpty();
	if (success)					// queue is not empty -> retrieve item at the front
		return frontNode->queuenum;
	else
		return NULL;
}

//int Queue::displaypatientQueueNum(ItemType& item)
//{
//	bool success = !isEmpty();
//	if (success)					// queue is not empty -> retrieve item at the front
//		for (int i = 0; i > getLength(); i++)
//		{
//			if (item == Node->item)
//			{
//
//			}
//		}
//}