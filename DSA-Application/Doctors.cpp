// Patients.cpp - Implementation of Patients class
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
// Doctor Class Source File: Containing Doctor Name and Patient (retrieved from the array list)
#include "Doctors.h"

Doctors::Doctors() {}

Doctors::Doctors(string dn, Patients p)
{
	doctorname = dn;
	assignedpatient = p;
}

void Doctors::setDoctorName(string dn)
{
	doctorname = dn;
}
string Doctors::getDoctorName()
{
	return doctorname;
}
void Doctors::setassignedpatient(Patients p)
{
	assignedpatient = p;
}
Patients Doctors::getassignedpatient()
{
	return assignedpatient;
}
string Doctors::printDoctor()
{
	string print;
	cout << "\tDoctor's Name: " << getDoctorName() << "\n\tAssigned Patient Name: " << getassignedpatient().getName() << "\n\tAssigned Patient IC: " << getassignedpatient().getIC();
	return print;
}
