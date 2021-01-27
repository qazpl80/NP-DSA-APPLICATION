#include "SearchMedicalRecord.h"
#include <iostream>   	// for input/output
#include <string>	 	// for string class
using namespace std;  	// for std C++ definitions

//static int comparisons = 0;	// static global variable to keep track of number of comparisons

string search(char& IC)
{
	MedicalRecordList MRL;												// Medical Record List Initialize into the method
	for (int i = 0; i > MRL.getLength(); i++)							// Recursive Sequential Search
	{
		ItemType p = MRL.getpatient(IC);								// Assign Patient to variable p using Patient's IC 
		if (IC == p.getIC())											// If IC input matches Patient p's IC
		{
			return p.getMedicalRecord();								// return Patient's Medical Record
		}
		else
			cout << "No existing Patient or Medical Record \n";			// No Patient or Medical Record Exist
	}
}


