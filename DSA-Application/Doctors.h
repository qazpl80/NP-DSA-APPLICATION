#pragma once
// Doctors.h - Definition of Patients class
//
// Class: T03
// Team Group: Team F
//
// |Name                       |Student Number |
//-----------------------------|---------------|
// |Tan Yuan Ming	           |(S10198319C)   |
// |Gladys Chua Ling Hui	   |(S10196678G)   |
//
// Doctor Class Header: Containing Doctor Name and Patient (retrieved from the array list)
#include<string>
#include<iostream>
#include"Patients.h"
using namespace std;

class Doctors
{
private:
	string doctorname;
	Patients assignedpatient;

public:
	Doctors();
	Doctors(string dn, Patients p);
	void setDoctorName(string dn);
	string getDoctorName();
	void setassignedpatient(Patients p);
	Patients getassignedpatient();
	string printDoctor();
};

