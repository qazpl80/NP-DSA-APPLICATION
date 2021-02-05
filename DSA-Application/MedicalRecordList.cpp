// MedicalRecord.cpp - Implementation of List ADT using Array

#include "MedicalRecordList.h"  //header file
#include <iostream>

using namespace std;
// constructor
MedicalRecordList::MedicalRecordList()
{
    size = 0;
}

// add a new item to the back of the list (append)
bool MedicalRecordList::add(ItemType newItem)
{
    bool success = size < MAX_SIZE;
    if (success)
    {
        items[size] = newItem; // add to the end of the list
        size++;                // increase the size of the list by one
    }
    return success;
}

// add a new item at a specified position in the list (insert)
bool MedicalRecordList::add(int index, ItemType newItem)
{
    bool success = (index >= 0) && (index <= size) && (size < MAX_SIZE);
    if (success)
    {  // make room for new item by shifting all items at
       // positions >= index toward the end of the
       // List (no shift if index == size)
        for (int pos = size; pos >= index; pos--)
            items[pos] = items[pos - 1];
        // insert new item
        items[index] = newItem;
        size++;  // increase the size of the list by one
    }
    return success;
}

// remove an item at a specified position in the list
void MedicalRecordList::remove(int index)
{
    bool success = (index >= 0) && (index < size);
    if (success)
    {  // delete item by shifting all items at positions >
       // index toward the beginning of the list
       // (no shift if index == size)
        for (int pos = index; pos < size; pos++)
            items[pos] = items[pos + 1];
        size--;  // decrease the size of the list by one
    }

}

// get an item at a specified position of the list (retrieve)
ItemType MedicalRecordList::get(int index)
{
    ItemType dataItem;
    bool success = (index >= 0) && (index < size);
    if (success)
        dataItem = items[index];

    return dataItem;
}

ItemType* MedicalRecordList::getP(int index)
{
    ItemType* dataItem = NULL;
   
    bool success = (index >= 0) && (index < size);
    if (success)
        dataItem = &items[index];

    return dataItem;
}
//
//ItemType MedicalRecordList::getpatient()
//{
//    ItemType p;
//    return p;
//}

// check if the list is empty
bool MedicalRecordList::isEmpty()
{
    return size == 0;
}

// check the size of the list
int MedicalRecordList::getLength()
{
    return size;
}

// replace item in the list
void MedicalRecordList::replace(int index, ItemType item)
{
    bool success = index >= 0 && index < getLength();
    if (success)
        items[index] = item;
}

// print all patient in the list
void MedicalRecordList::print()
{
    for (int i = 0; i < size; i++)
        cout << i << ") " << "\tName: "<< get(i).getName() << "\n\tIC: " << get(i).getIC() << "\n\tMedical Records: " << get(i).getMedicalRecord()<<"\n" << endl;
}

// search for patient in the list using patient's IC
void MedicalRecordList::search(string IC)   // Search Patient using Patient's ID
{
    for (int i = 0; i < size; i++)	
    {
        ItemType item = get(i);             // Assign item as Patient and retrieve patient from list
        bool success = item.getIC() == IC;  // Success if Patient IC matched with provided IC
        if (success)
        {
            cout << "Medical Record of Patient: " << item.getMedicalRecord();	// Return Patient's Medical Record
            break;                                                              // End Loop
        }
        else if ((item.getIC() != IC) && size - 1 == i)
        {    
            cout << "No Medical Record Found";                                  //If last item and IC not correct, print No Medical Record Found
            break;
        }
        else
            continue;
    }
}

// search for patient in the list using patient's IC
Patients MedicalRecordList::returnsearch(string IC)   // Search Patient using Patient's ID
{
    for (int i = 0; i < size; i++)
    {
        ItemType item = get(i);             // Assign item as Patient and retrieve patient from list
        bool success = item.getIC() == IC;  // Success if Patient IC matched with provided IC
        if (success)
        {
            return item;	// Return Patient's Medical Record
            break;                                                              // End Loop
        }
        else if ((item.getIC() != IC) && size - 1 == i)
        {
            break;
        }
        else
            continue;
    }
}

// selection sort recursive function using partition to split and compare
void MedicalRecordList::selectionSort(int n)
{
    //starting position
    int startlist;

    int firstindex;
    //current name with the smallest alphabet
    Patients firstvalue;
    for (startlist = 0; startlist < (n - 1); startlist++) //go through whole list 
    {
        // assume first index is smallest alphabet
        firstindex = startlist;

        // assign current smallest alphabet to firstvalue
        firstvalue = get(startlist); 

        // look for a smaller alphabet in the rest of the array list
        for (int index = (startlist + 1); index < n; index++)
        {
            // if a smaller alphabet is found, remember the current name
            if (get(index).getName() < get(firstindex).getName())
            {
                firstindex = index;
            }
            
            
        }

        // swap previously recorded smallest name with currently recorded new smallest name
        
        replace(startlist,get(firstindex));
        replace(firstindex, firstvalue);
       
    }

    //for (int last = n - 1; last >= 1; last--)
    //{
    //    // select largest item in array[0..last]
    //    int largest = indexOfLargest(array, last + 1);

    //    // swap largest item array[largest] with array[last]
    //    swap(array[largest], array[last]);
    //}
}

//int indexOfLargest(ItemType array[], int n)
//{
//    int largestIndex = 0;          // index of  largest item
//    for (int i = 1; i < n; i++)
//    {
//        if (array[i] > array[largestIndex])
//            largestIndex = i;
//    }
//
//    return largestIndex;
//}

//void swap(ItemType& x, ItemType& y)
//{
//    ItemType temp = x;
//    x = y;
//    y = temp;
//}


