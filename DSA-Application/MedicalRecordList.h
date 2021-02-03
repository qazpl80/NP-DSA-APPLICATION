#pragma once
// MedicalRecordList.h - - Specification of List ADT
#include <string>
#include <iostream>
using namespace std;

#include "Patients.h"
const int MAX_SIZE = 100;
typedef Patients ItemType;

class MedicalRecordList
{
private:
    ItemType items[MAX_SIZE];
    int      size;

public:

    // constructor
    MedicalRecordList();

    // add a new item to the back of the list (append)
    // pre : size < MAX_SIZE
    // post: new item is added to the back of the list
    //       size of list is increased by 1
    bool add(ItemType newItem);

    // add a new item at a specified position in the list (insert)
    // pre : 1 <= index <= size && size < MAX_SIZE
    // post: new item is added to the specified position in the list
    //       size of list is increased by 1
    bool add(int index, ItemType newItem);

    // remove an item at a specified position in the list
    // pre : 1 <= index <= size
    // post: item is removed the specified position in the list
    //       size of list is decreased by 1
    void remove(int index);

    void display();

    void replace(int index, ItemType item);

    // get an item at a specified position of the list (retrieve)
    // pre : 1 <= index <= size
    // post: none
    ItemType get(int index);

    //// get an IC at a specified position of the list (retrieve)
    //ItemType getpatient();

    // check if the list is empty
    // pre : none
    // post: none
    // return true if the list is empty; otherwise returns false
    bool isEmpty();

    // check the size of the list
    // pre : none
    // post: none
    // return the number of items in the list
    int getLength();

    void print();

    void search(string IC);

    void selectionSort( int n);

    //int partition(ItemType array[], int left, int right);

    //void swap(ItemType& x, ItemType& y);

};
