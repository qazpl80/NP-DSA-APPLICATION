// Patients.cpp - Implementation of Patients class
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
