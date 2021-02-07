// Queue.h - Specification of Queue ADT (Pointer-based)
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
// Patient's Linked-List Queue Header: Containing Patient's Class (retrieved from the array list) and Queue Linked-List Code and functions 
#pragma once
#include <iostream>   
#include "Patients.h"
#include "MedicalRecordList.h"
using namespace std;

typedef Patients ItemType;

class Queue
{
private:
	struct Node
	{
		int queuenum;
		ItemType item;		// to store data
		Node* next;		// to point to next node
	};

	Node* frontNode;		// to point to the front node
	Node* backNode;			// to point to the back node

public:
	Queue();
	~Queue();

	// enqueue item at back of the queue
	bool enqueue(ItemType item, static int& queuenumber);

	// dequeue item from front of the queue
	bool dequeue();
	bool dequeue(ItemType& item);

	// retrieve item from front of queue
	void getFront(ItemType& item);

	// check if the queue is empty
	bool isEmpty();

	// return the length of the queue
	int getLength();

	// display the items in the queue
	// void print();

	void resetQueueNum();

	int displayfrontQueueNum();
	void getSecondLargest(ItemType& item);

	//int displaypatientQueueNum(ItemType& item);

};

