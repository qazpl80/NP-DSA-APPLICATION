// DSA-Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Class: T03
// Team Group: Team F
//
// |Name                       |Student Number |
//-----------------------------|---------------|
// |Tan Yuan Ming	           |(SXXXXXXXXC)   |
// |Gladys Chua Ling Hui	   |(SXXXXXXXXG)   |
//
//
// Main Program with Command-Line Interface and Error Handling

using namespace std;
#include "MedicalRecordList.h"
#include "SearchMedicalRecord.h"
#include "Patients.h"
#include "Queue.h"
#include "Doctors.h"
#include "DoctorAssignList.h"
#include <iostream>
#include "MedicalRecordList.h"


void printMenu()
{
    cout << "\n\n---------- Clinic Counter Program ----------";
    cout << "\nOption 1: Add new patient\nOption 2: Modify Patient's details existing in the List\nOption 3: Show all Patient Details\nOption 4: Retieve Patient's Medical Record by Patient's IC";
    cout << "\nOption 5: Add existing Patient to queue\nOption 6: Display front of queue\nOption 7: Dequeue front patient.\nOption 8: Sort Patient List";
    cout << "\nOption 9: Doctor's Assign Details\nOption 10: Reset Queue Number\nOption 0: Exit Program";
    cout << "\nPlease select an option from the menu provided: ";
}

int main()
{
    string option;
    static int queuenumber = 1;
    MedicalRecordList defaultList;
    Queue PatientQueue;
    Patients QueueFrontPatient;
    Patients QueueSecondPatient;
    DoctorAssignList defaultDoctorList;

    while (true)
    {
        printMenu();
        cin >> option;

        // Option 1 -----------------------------------------------------------------------------------------------------------------------------------------------
        if (option == "1")
        {
            string patientname;             // Initialize patientname for Patient's Name
            string patientic;               // Initialize patientic for Patient's IC
            string patientmr;               // Initialize patientmr for Patient's Medical Record

            // Print out selected option
            cout << "\nOption 1 - Add new patient selected\n------------------------------";

            // Error handling
            try
            {
                while (true)
                {
                    cout << "\nEnter '0' to exit ";

                    // Get Patient's Name
                    cout << "\nPlease Enter Patient's Name: ";
                    cin.ignore();
                    getline(cin, patientname);

                    // If user enter "0", exit create new patient option
                    if (patientname == "0")
                        break;

                    // Get Patient's IC
                    cout << "\nPlease Enter Patient's IC: ";
                    cin >> patientic;

                    // If user enter "0", exit create new patient option
                    if (patientic == "0")
                        break;

                    // Get Patient's Medical Record
                    cout << "\nPlease Enter Patient's Medical Record Details/Description: ";
                    cin.ignore();
                    getline(cin, patientmr);

                    // If user enter "0", exit create new patient option
                    if (patientmr == "0")
                        break;

                    // Create new Patient
                    Patients newPatient = Patients(patientname, patientic, patientmr);

                    // Add new Patient into list
                    defaultList.add(newPatient);
                    cout << "\nPatient Successfully added into list.";
                    break;
                }
            }

            // Input invalid or error
            catch (const exception&)
            {
                cout << "\nInvalid Input, please try again.\n";
            }
        }

        // Option 2 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "2")
        {
            // Print out selected option
            cout << "\nOption 2 - Modify Patient's details existing in the List\n------------------------------";

            int patientlistpos;             // Initialize patient position in the list
            string modifyoption;            // Initialize option to modify or remove existing patient
            cout << "\nOption 1: Modify Patient's Name\nOption 2: Modify Patient's IC\nOption 3: Modify Patient's Medical Record\nOption 4: Remove an existing patient\nPlease select an option to modify the patient's details: ";
            cin >> modifyoption;            // Get user's option

            if (modifyoption == "1")
            {
                // Print out selected option
                cout << "\nOption 1 - Modify Patient's Name\n------------------------------\n";

                // Error Handling
                try
                {
                    // If list is not empty, continue
                    if (defaultList.isEmpty() != 1)
                    {
                        // Print out all Patient's Name, IC and Medical Record
                        defaultList.print();

                        // Get Patient's index on the list
                        cout << "\nPlease Enter Patient's index in list: ";
                        cin >> patientlistpos;

                        // If patient's index does not exist in list, print out "Patient does not exist."
                        if (defaultList.get(patientlistpos).getName().length() != 0)
                        {

                            // initialize new Patient's name
                            string newpatientname;

                            // Get new Patient's IC for the list
                            cout << "\nPlease Enter new Patient's Name in list: ";
                            cin.ignore();
                            getline(cin, newpatientname);
                            defaultList.getP(patientlistpos)->setName(newpatientname);

                            cout << "List updated successfully.\n";
                            defaultList.print();
                        }
                        else
                        {
                            cout << "Patient does not exist.\n";
                        }
                        
                    }
                    else
                    {
                        cout << "\nList is currently empty and/or no patient can be found.\n";
                    }
                }
                catch (const exception&)
                {
                    cout << "\nList is currently empty and/or no patient can be found.\n";
                }
            }
            else if (modifyoption == "2")
            {
                // Print out selected option
                cout << "\nOption 2 - Modify Patient's IC\n------------------------------\n";
                try
                {
                    // If list is not empty, continue
                    if (defaultList.isEmpty() != 1)
                    {
                        // Print out all Patient's Name, IC and Medical Record
                        defaultList.print();

                        // Get Patient's index on the list
                        cout << "\nPlease Enter Patient's index in list: ";
                        cin >> patientlistpos;

                        // If patient's index does not exist in list, print out "Patient does not exist."
                        if (defaultList.get(patientlistpos).getIC().length() != 0)
                        {
                            //initialize new Patient's IC
                            string newpatientic;

                            // Get new Patient's IC for the list
                            cout << "\nPlease Enter new Patient's IC in list: ";
                            cin >> newpatientic;
                            defaultList.getP(patientlistpos)->setIC(newpatientic);

                            cout << "\nList updated successfully.\n";
                            defaultList.print();
                        }
                        else
                        {
                            cout << "Patient does not exist.\n";
                        }
                        
                    }
                    else
                    {
                        cout << "\nList is currently empty and/or no patient can be found.\n";
                    }
                }
                catch (const exception&)
                {
                    cout << "\nList is currently empty and/or no patient can be found.\n";
                }
            }
            else if (modifyoption == "3")
            {
                try
                {
                    // Print out selected option
                    cout << "\nOption 3 - Modify Patient's Medical Record\n------------------------------\n";

                    // Print out all Patient's Name, IC and Medical Record
                    defaultList.print();

                    // Get Patient's index on the list
                    cout << "\nPlease Enter Patient's index in list: ";
                    cin >> patientlistpos;

                    // If patient's index does not exist in list, print out "Patient does not exist."
                    if (defaultList.get(patientlistpos).getIC().length() != 0)
                    {
                        //initialize new Patient's Medical Record
                        string newpatientmedicalrecord;

                        // Get new Patient's Medical record for the list
                        cout << "\nPlease Enter new Patient's Medical Record in list: ";
                        cin.ignore();
                        getline(cin, newpatientmedicalrecord);

                        // Set new medical record for patient
                        defaultList.getP(patientlistpos)->setMedicalRecord(newpatientmedicalrecord);

                        cout << "\nList updated successfully.\n";
                        defaultList.print();
                    }
                    else
                    {
                        cout << "Patient does not exist.\n";
                    }
                }

                // Input invalid or error
                catch (const std::exception&)
                {
                    cout << "\nList is currently empty and/or no patient can be found.\n";
                }
            }
            else if (modifyoption == "4")
            {
                // Print out selected option
                cout << "\nOption 4 - Remove an existing Patient\n------------------------------\n";

                // Error handling
                try
                {
                    // If list is not empty, continue
                    if (defaultList.isEmpty() != 1)
                    {
                        // Print out all Patient's Name, IC and Medical Record
                        defaultList.print();

                        // Get Patient's index on the list
                        cout << "\nPlease Enter Patient's index in list: ";
                        cin >> patientlistpos;

                        // If patient's index does not exist in list, print out "Patient does not exist."
                        if (defaultList.get(patientlistpos).getIC().length() != 0)
                        {
                            // Remove exisitng patient from list
                            defaultList.remove(patientlistpos);

                            cout << "\nList updated successfully.\n";
                            defaultList.print();
                        }
                        else
                        {
                            cout << "Patient does not exist.\n";
                        }
                    }
                    else
                    {
                        cout << "\nList is currently empty and/or no patient can be found.\n";
                    }
                }
                // Input invalid or error
                catch (const exception&)
                {
                    cout << "\nInvalid Input, please try again\n";
                }
            }
            else
            {
                cout << "\nInvalid Input, please try again\n";
            }
        }

        // Option 3 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "3")
        {
            // Print out selected option
            cout << "\nOption 3 - Show all Patient Details\n------------------------------\n";

            // Error handling
            try
            {
                // If list is not empty, continue
                if (defaultList.isEmpty() != 1)
                {
                    // Print out all Patient's Name, IC and Medical Record
                    defaultList.print();
                }
                else
                {
                    cout << "\nList is currently empty, no patient can be found.\n";
                }
            }

            // Input invalid or error
            catch (const exception&)
            {
                cout << "\nError: Please contact the developer to resolve the error.\n";
            }
        }

        // Option 4 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "4")
        {
            // Print out selected option
            cout << "\nOption 4 - Retieve Patient's Medical Record by Patient's IC\n------------------------------\n";

            string searchIC;                    // Initialize patientname for Patient search IC

            // Get Patient's IC to search
            cout << "Enter Patient's IC: ";
            cin >> searchIC;

            // Error handling
            try
            {
                // Search exisitng Patient and print out if success
                defaultList.search(searchIC);
            }
            catch (const exception&)
            {
                cout << "\nError: Please contact the developer to resolve the error.\n";
            }
        }

        // Option 5 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "5")
        {
            // Print out selected option
            cout << "\nOption 5 - Add existing Patient to queue\n------------------------------\n";
            Patients patientqueuetemp;                      // Initialize patientqueuetemp for Patient search IC
            string patientqueueic;                          // Initialize patientname for Patient search IC

            // Get Patient's IC to add to the queue
            cout << "Please enter Patient's IC to add into queue: ";
            cin >> patientqueueic;

            //Error handling
            try
            {
                // For-Loop to check the whole Patient List
                for (int i = 0; i < defaultList.getLength(); i++)
                {
                    // Enqueue Patient if IC is found in the List
                    bool success = patientqueueic == defaultList.get(i).getIC();

                    // If patient exist check
                    if (success)
                    {
                        if (PatientQueue.getLength() == 0)
                        {
                            patientqueuetemp = defaultList.get(i);

                            // Enqueue Patient
                            PatientQueue.enqueue(patientqueuetemp, queuenumber);
                            // Next Patient set increased queue number
                            queuenumber++;

                            cout << "\nPatient successfully added into the queue.\n";
                            break;
                        }
                        else
                        {
                            // Get patient in list and add into queue
                            patientqueuetemp = defaultList.get(i);

                            // Enqueue Patient
                            PatientQueue.enqueue(patientqueuetemp, queuenumber);

                            // Next Patient set increased queue number
                            queuenumber++;

                            cout << "\nPatient successfully added into the queue.\n";
                            break;
                        }

                    }
                    // If patient does not exist but list is not finished check
                    else if (!success)
                    {
                        continue;
                    }
                    // If patient does not exist check
                    else
                    {
                        cout << "\nPatient missing or does not exist in list.\n";
                        break;
                    }
                }
            }
            catch (const std::exception&)
            {
                cout << "\nError: Please contact the developer to resolve the error.\n";
            }
        }

        // Option 6 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "6")
        {
            // Print out selected option
            cout << "\nOption 6 - Display front of queue\n------------------------------\n";
            string QueueFrontPatientName;       // Initialize QueueFrontPatientName for storing front of queue's patient's name
            
            // Error Handling
            try
            {
                // Get front of queue patient and put into QueueFrontPatient string
                PatientQueue.getFront(QueueFrontPatient);

                // Get front of queue patient name and put into QueueFrontPatient string
                QueueFrontPatientName = QueueFrontPatient.getName();

                // Get second of queue patient name and put into QueueFrontPatient string
                PatientQueue.getSecondLargest(QueueSecondPatient);
               
                // Check if list is not empty and have at least 2 patient in queue
                if (PatientQueue.isEmpty() != true && PatientQueue.getLength() >= 2)
                {
                    cout << "\nCurrent Number: " << PatientQueue.displayfrontQueueNum() << "\tThe current Patient at the front of the queue is " << QueueFrontPatientName << "\n";
                    cout << "\nNext Number: " << PatientQueue.displayfrontQueueNum()+1  << "\tThe next Patient is " << QueueSecondPatient.getName() << "\n";

                }
                // Check if list is not empty and have at least 1 patient in queue
                else if (PatientQueue.isEmpty() != true && PatientQueue.getLength() == 1)
                {
                    cout << "\nCurrent Number: " << PatientQueue.displayfrontQueueNum() << "\tThe current Patient at the front of the queue is " << QueueFrontPatientName << "\n";
                    cout << "\nNo one else is in queue.\n";
                }
                else
                {
                    cout << "\nNo Patient is in queue." << "\n";
                }

            }
            catch (const exception&)
            {
                cout << "\nError: Queue empty or program error.\n";
            }
        }

        // Option 7 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "7")
        {
            // Print out selected option
            cout << "\nOption 7 - Dequeue front patient\n------------------------------\n";

            // If patient queue's length is not equals to 1
            if (PatientQueue.getLength() != 1)
            {
                PatientQueue.dequeue(QueueFrontPatient);
                cout << "\nPatient successfully dequeued";
            }
            else
            {
                cout << "\nNo Patient existing in queue.\n";
            }
        }

        // Option 8 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "8")
        {
            // Print out selected option
            cout << "\nOption 8 - Sort Patient List\n------------------------------\n";

            // Sort List
            int sizeoflist = defaultList.getLength();
            defaultList.selectionSort(sizeoflist);

            // Print out all Patient's Name, IC and Medical Record
            defaultList.print();
        }

        // Option 9 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "9")
        {
            int doctorlistpos;                              // Initialize patient position in the list
            string doctorname;                              // Initialize doctorname for Doctor's Name
            string doctorassignedpatientic;                 // Initialize doctorassignedpatient for Doctor's Assigned Patient using Patient's IC
            Patients doctorpatienttemp;                     // Initialize doctor's assigned patient for adding to the list
            string newdoctorname;                           // Initialize new doctor name for modification
            string newassignedpatientic;                    // initialize Patient's IC to search
            Patients newassignedpatient;                    // initialize new Assigned Patient for modification

            cout << "\nOption 9 - Doctor's Assign Details\n------------------------------";
            // Print out selected option

            string doctoroption;            // Initialize option for doctors
            cout << "\nOption 1: Add New Doctor Details\nOption 2: Remove an Existing Doctor Details\nOption 3: Display All Doctor Details\nOption 4: Modify Doctor's Name\nOption 5: Modify Doctor's Assigned Patient\nPlease select an option: ";
            cin >> doctoroption;            // Get user's option

            if (doctoroption == "1")
            {
                // Print out selected option
                cout << "\nOption 1 - Add new doctor\n------------------------------\n";

                // Error Handling
                try
                {
                    // Get Doctor's Name
                    cout << "\nPlease Enter Doctor's Name: ";
                    cin.ignore();
                    getline(cin, doctorname);

                    // Get Patient's IC
                    cout << "\nPlease Enter Doctor's Assigned Patient IC: ";
                    cin >> doctorassignedpatientic;

                   
                    // Search exisitng Patient and print out if success
                    defaultList.returnsearch(doctorassignedpatientic,doctorpatienttemp);
                    bool success = doctorpatienttemp.getIC().length() != 0;
                    if (success)
                    {
                        // Create new Doctor
                        Doctors newDoctor = Doctors(doctorname, doctorpatienttemp);

                        // Add new Patient into list
                        defaultDoctorList.add(newDoctor);

                        cout << "\nPatient Successfully added\n";
                    }
                    else 
                    {
                        cout << "\nNo patient found.\n";
                    }
                }
                catch (const exception&)
                {
                    cout << "\nError with adding doctor.\n";
                }
            }
            else if (doctoroption == "2")
            {
                // Print out selected option
                cout << "\nOption 2 - Remove an existing doctor\n------------------------------\n";
                try
                {
                    int doctorlistindex;

                    // Print out all Doctor's Details
                    defaultDoctorList.print();
                    // Get Doctor's index on the list
                    cout << "\nPlease Enter Doctor index in list: ";
                    cin >> doctorlistindex;
                    if (defaultDoctorList.getLength() != 0 && defaultDoctorList.get(doctorlistindex).getassignedpatient().getIC().length() != 0)
                    {

                        // Remove exisitng patient from list
                        defaultDoctorList.remove(doctorlistindex);

                        cout << "\nList updated successfully.\n";
                        defaultDoctorList.print();
                    }
                    else
                    {
                        cout << "\nList is currently empty and/or no doctor can be found.\n";
                    }
                }
                catch (const exception&)
                {
                    cout << "\nList is currently empty and/or no doctor can be found.\n";
                }
            }
            else if (doctoroption == "3")
            {
                // Print out selected option
                cout << "\nOption 3 - Display Doctor Details\n------------------------------\n";

                try
                {
                        // Print out all Doctor's Details
                        defaultDoctorList.print();
                }

                // Input invalid or error
                catch (const std::exception&)
                {
                    cout << "\nList is currently empty and/or no doctor can be found.\n";
                }
            }
            else if (doctoroption == "4")
            {
                // Print out selected option
                cout << "\nOption 4 - Modify Doctor's Name\n------------------------------\n";

                // Error handling
                try
                {

                    // Print out all Doctor's Details
                    defaultDoctorList.print();

                    if (defaultList.isEmpty() != 1 && defaultDoctorList.isEmpty() != 1)
                    {
                        // Get Doctor's index on the list
                        cout << "\nPlease Enter Doctor's index in list: ";
                        cin >> doctorlistpos;

                        if (defaultDoctorList.getLength() != 0 && defaultDoctorList.get(doctorlistpos).getassignedpatient().getIC().length() != 0)
                        {

                            // Get Doctor's index on the list
                            cout << "\nPlease Enter new Doctor's Name: ";
                            cin.ignore();
                            getline(cin, newdoctorname);

                            // Update List for new doctor name
                            defaultDoctorList.getD(doctorlistpos)->setDoctorName(newdoctorname);

                            cout << "\nList updated successfully.\n";
                            defaultDoctorList.print();
                        }
                        else
                        {
                            cout << "\nList is currently empty and/or no doctor can be found.\n";
                        }
                    }
                    else
                    {
                        cout << "\nDoctor or Patient List is currently empty and/or no doctor/patient can be found.\n";
                    }
                }
                // Input invalid or error
                catch (const exception&)
                {
                    cout << "\nInvalid Input, please try again\n";
                }
            }
            else if (doctoroption == "5")
            {
                // Print out selected option
                cout << "\nOption 5 - Modify Doctor's Assigned Patient\n------------------------------\n";

                // Error handling
                try
                {
                    // Print out all Doctor's Name, IC and Medical Record
                    defaultDoctorList.print();

                    if (defaultList.isEmpty() != true && defaultDoctorList.isEmpty() != true)
                    {
                        // Get Doctor's index on the list
                        cout << "\nPlease Enter Doctor's index in list: ";
                        cin >> doctorlistpos;

                        if (defaultDoctorList.getLength() != 0 && defaultDoctorList.get(doctorlistpos).getassignedpatient().getIC().length() != 0)
                        {
                            // Get new Patient's IC in the list
                            cout << "\nPlease Enter new Patient's IC in list: ";
                            cin >> newassignedpatientic;

                            // Search exisitng Patient and put into newassignedpatient variable
                        
                            defaultList.returnsearch(newassignedpatientic,newassignedpatient);
                            bool success = newassignedpatient.getIC().length() != 0;
                            if (success) 
                            {
                                // Update List for new assigned patient
                                defaultDoctorList.getD(doctorlistpos)->setassignedpatient(newassignedpatient);

                                cout << "\nList updated successfully.\n";
                                defaultDoctorList.print();
                            }
                            else 
                            {
                                cout << "\nNo Patient found.\n";
                            }
                        }
                        else
                        {
                            cout << "\nDoctor or Patient List is currently empty and/or no doctor/patient can be found.\n";
                        }
                    }
                    else
                    {
                        cout << "\nDoctor or Patient List is currently empty and/or no doctor/patient can be found.\n";
                    }

                }
                // Input invalid or error
                catch (const exception&)
                {
                    cout << "\nInvalid Input, please try again\n";
                }
            }
            else
            {
                cout << "\nInvalid Input, please try again\n";
            }
        }
        else if (option == "10")
        {
            string patientqueueic;          // Initialize Patient's IC to find from list to add to queue
            Patients patientqueuetemp;      // Initialize Patient to add to queue

            // Print out selected option
            cout << "\nOption 10 - Reset Queue Number\n------------------------------\n";

            // Reset Queue Number and Queue
            PatientQueue.resetQueueNum();
            queuenumber = 1;

            // Get Patient's IC to search in the queue
            cout << "Please add new patient into queue: ";
            cin >> patientqueueic;
            try
            {
                // For-Loop to check the whole Patient List
                for (int i = 0; i < defaultList.getLength(); i++)
                {
                    // Enqueue Patient if IC is found in the List
                    bool success = patientqueueic == defaultList.get(i).getIC();
                    if (success)
                    {
                        if (PatientQueue.getLength() == 0)
                        {
                            patientqueuetemp = defaultList.get(i);

                            // Enqueue Patient
                            PatientQueue.enqueue(patientqueuetemp, queuenumber);
                            // Next Patient set increased queue number
                            queuenumber++;

                            cout << "\nPatient successfully added into the queue.\n";
                            break;
                        }
                        else
                        {
                            patientqueuetemp = defaultList.get(i);

                            // Enqueue Patient
                            PatientQueue.enqueue(patientqueuetemp, queuenumber);

                            // Next Patient set increased queue number
                            queuenumber++;

                            cout << "\nPatient successfully added into the queue.\n";
                            break;
                        }

                    }
                    else if (!success)
                    {
                        continue;
                    }
                    else
                    {
                        cout << "\nPatient missing or does not exist in list.\n";
                        break;
                    }
                }
            }
            catch (const std::exception&)
            {
                cout << "\nError: Please contact the developer to resolve the error.\n";
            }
            PatientQueue.dequeue();
        }

        // Option 0 -----------------------------------------------------------------------------------------------------------------------------------------------
        else if (option == "0")
        {
            cout << "\n---------- End of Program ----------\nProgram developed by Yuan Ming and Gladys\n";
            break;
        }
        
        // Other Option -----------------------------------------------------------------------------------------------------------------------------------------------
        else
        {
            cout << "\nPlease try again.\n";
            continue;
        }
    }
}

        // Add new List
       /* MedicalRecordList MRL1;*/

        //Populate the lsit
        /*MRL1.add(P1);
        MRL1.add(P2);
        MRL1.add(P3);
        MRL1.add(P4);*/

        // Print List
       /* MRL1.print();*/

        // Search medical record by IC
        /*MRL1.search("S1023384T");*/

        // Add new queue
        /*Queue Booking;*/

        //if (user press enqueue option, and successfully added, increase queue number by 1)
        // Add patient to queue
        //Booking.enqueue(P1, queuenumber);
        //Booking.enqueue(P2, queuenumber);
        //queuenumber++;
        //Booking.enqueue(P3, queuenumber);
        //queuenumber++;
        //Booking.enqueue(P4, queuenumber);
        //queuenumber++;

        // Add Front patient variable
        /*Patients Front;*/

        // Put front patient from queue into variable Front
        /*Booking.getFront(Front);*/

        // Print Front patient variable's name
        /*cout << "\n" << Front.getName() << "\n";*/

        


        /*Booking.dequeue(Front);
        FrontQueuePatient = Front.getName();
        cout << "\nCurrent Number: " << Booking.displayfrontQueueNum() << "\t Patient: " << FrontQueuePatient;

        Booking.dequeue(Front);
        FrontQueuePatient = Front.getName();
        cout << "\nCurrent Number: " << Booking.displayfrontQueueNum() << "\t Patient: " << FrontQueuePatient;



        int Lastqueue = Booking.displayfrontQueueNum() + 1;
        Booking.dequeue(Front);
        FrontQueuePatient = Front.getName();
        cout << "\nCurrent Number: " << Lastqueue << "\t Patient: " << FrontQueuePatient;*/


