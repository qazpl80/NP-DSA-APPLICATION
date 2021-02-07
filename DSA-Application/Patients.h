#pragma once
// Patients.h - Definition of Patients class
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
// Patient Class Header: Containing Patient's Name, IC and Medical Record
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

