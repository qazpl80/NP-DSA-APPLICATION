// Patients.cpp - Implementation of Patients class
#include "Patients.h"

Patients::Patients() {}

Patients::Patients(string n, string i, string mr)
{
	name = n;
	/*queueNum = qNum;*/
	/*doctorname = d;*/
	IC = i;
	medicalrecord = mr;

}

void Patients::setName(string n) { name = n; }

string Patients::getName() { return name; }

//void Patients::setQueueNum(int q) { queueNum = q; }
//
//int Patients::getQueueNum() { return queueNum; }

//void Patients::setDoctor(string d) { doctorname = d; }
//
//string Patients::getDoctor() { return doctorname; }

void Patients::setIC(string i) { IC = i; }

string Patients::getIC() { return IC; }

void Patients::setMedicalRecord(string mr) { medicalrecord = mr; }

string Patients::getMedicalRecord() { return medicalrecord; }


