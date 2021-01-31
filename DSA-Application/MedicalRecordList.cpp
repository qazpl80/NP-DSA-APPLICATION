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

// get an Person using IC from the list (retrieve)
ItemType MedicalRecordList::getpatient(string &IC)
{
    ItemType p;
    bool success = (IC == p.getIC());
    if (success)
        return p;
    else
        cout << "Patient does not exist \n";
}

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

void MedicalRecordList::display()
{
    for (int i = 0; i < getLength(); i++)
    {
        ItemType item = get(i);
        //		cout << item << endl;
    }
}

void MedicalRecordList::replace(int index, ItemType item)
{
    bool success = index >= 0 && index < getLength();
    if (success)
        items[index] = item;
}

void MedicalRecordList::print()
{
    for (int i = 0; i < size; i++)
        cout << i << ") " << "\tName: "<< get(i).getName() << "\n\tIC: " << get(i).getIC() << "\n\tMedical Records: " << get(i).getMedicalRecord()<<"\n" << endl;
}


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

//Radix Sort List
//void radixSort(int* arr, int n, int max) 
//{
//    int i, j, m, p = 1, index, temp, count = 0;
//    list<int> pocket[10];      //radix of decimal number is 10
//    for (i = 0; i < max; i++) 
//    {
//        m = pow(10, i + 1);
//        p = pow(10, i);
//        for (j = 0; j < n; j++) 
//        {
//            temp = arr[j] % m;
//            index = temp / p;      //find index for pocket array
//            pocket[index].push_back(arr[j]);
//        }
//        count = 0;
//        for (j = 0; j < 10; j++) 
//        {
//            //delete from linked lists and store to array
//            while (!pocket[j].empty()) 
//            {
//                arr[count] = *(pocket[j].begin());
//                pocket[j].erase(pocket[j].begin());
//                count++;
//            }
//        }
//    }
//}

