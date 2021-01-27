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
    Patients P3 = Patients("Xiao Lah Zhi", "S9985242G", "Visited 1 time, Had deep open wound");
    MedicalRecordList MRL1;
    MRL1.add(P1);
    MRL1.add(P2);
    MRL1.add(P3);
    MRL1.print();
    MRL1.search("S1023384T");
}

