// DSA-Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include "MedicalRecordList.h"
#include "SearchMedicalRecord.h"
#include "Patients.h"
#include "Queue.h"
#include <iostream>

int main()
{
    Patients P1 = Patients("Lim Koh Fee", "S0981234J", "Visited 10 times, Had previous heart attacks, Stroke from stress, Fell down stairs, vomit blood, allergic to nearly all drugs except penicillin");
    Patients P2 = Patients("Wang Si Liew", "S1023384T", "Visited 2 times, had spine surgery after car crash, not allergic to any drugs, partially blind and deaf");
    MedicalRecordList MRL1;
    MRL1.add(P1);
    MRL1.add(P2);
    MRL1.print();
    string ICS = "S1023384T";
    MRL1.search(ICS);
}

