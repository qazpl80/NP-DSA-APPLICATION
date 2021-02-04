#pragma once
// Doctors.h - Definition of Patients class

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

