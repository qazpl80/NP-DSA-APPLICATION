#pragma once
// Patients.h - Definition of Patients class

#include<string>
#include<iostream>
using namespace std;

class Patients
{
private:
	string name;
	/*int queueNum;*/ // the i-th minute Patients joins queue.
	/*string doctorname;*/
	string IC;
	string medicalrecord;

public:
	Patients();
	Patients(string n , string i, string mr);
	void setName(string n);
	string getName();
	void setIC(string i);
	string getIC();
	void setMedicalRecord(string mr);
	string getMedicalRecord();
	string printPatient();
};

