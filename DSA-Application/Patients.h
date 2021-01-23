#pragma once
// Patients.h - Definition of Patients class

#include<string>
#include<iostream>
using namespace std;

class Patients
{
private:
	string name;
	int queueNum; // the i-th minute Patients joins queue.
	string doctorname;
	char IC;
	string medicalrecord;

public:
	Patients();
	Patients(string n, int q, string d , char i, string mr);
	void setName(string n);
	string getName();
	void setQueueNum(int q);
	int getQueueNum();
	void setDoctor(string d);
	string getDoctor();
	void setIC(char i);
	char getIC();
	void setMedicalRecord(string mr);
	string getMedicalRecord();
};

