// Patients.cpp - Implementation of Patients class
#include "Patients.h"

Patients::Patients() {}

Patients::Patients(string n, string i, string mr)
{
	name = n;
	IC = i;
	medicalrecord = mr;

}

void Patients::setName(string n) { name = n; }

string Patients::getName() { return name; }

void Patients::setIC(string i) { IC = i; }

string Patients::getIC() { return IC; }

void Patients::setMedicalRecord(string mr) { medicalrecord = mr; }

string Patients::getMedicalRecord() { return medicalrecord; }

string Patients::printPatient() 
{
	string print;
	cout << "Name: " << getName() << "\nIC: " << getIC() << "\nMedical Record: " << getMedicalRecord();
	return print;
}
