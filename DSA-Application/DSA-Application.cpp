// DSA-Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include "MedicalRecordList.h"
#include "SearchMedicalRecord.h"
#include "Patients.h"
#include "Queue.h"
#include <iostream>

void printMenu()
{
    cout << "---------- Hospital Counter Program ----------";
    cout << "\nOption 1: Add new patient\nOption 2: Show all Patient Details\nOption 3: Retieve Patient's Medical Record by Patient's IC";
    cout << "\nOption 4: Add existing Patient to queue\nOption 5: Display front of queue\n Option 6: Display front and continue in queue";
    cout << "Please select an option from the menu provided: ";
}

int main()
{
    int option;
    static int queuenumber = 0;
    MedicalRecordList defaultList;
    Queue PatientQueue;
    Patients QueueFrontPatient;
    
    while (true)
    {
        printMenu();
        cin >> option;
        if (option == 1)
        {
            string patientname;             // Initialize patientname for Patient's Name
            string patientic;               // Initialize patientic for Patient's IC
            string patientmr;               // Initialize patientmr for Patient's Medical Record

            // Print out selected option
            cout << "Option 1 - Add new patient selected\n------------------------------";

            // Error handling
            try
            {
                // Get Patient's Name
                cout << "\nPlease Enter Patient's Name: ";
                getline(cin, patientname);

                // Get Patient's IC
                cout << "\nPlease Enter Patient's IC: ";
                cin >> patientic;

                // Get Patient's Medical Record
                cout << "\nPlease Enter Patient's Medical Record Details/Description: ";
                cin >> patientmr;

                // Create new Patient
                Patients newPatient = Patients(patientname, patientic, patientmr);

                // Add new Patient into list
                defaultList.add(newPatient);
            }

            // Input invalid or error
            catch (const exception&)
            {
                cout << "Invalid Input, please try again";
            }
            // Add new Patients
            /*Patients P1 = Patients("Lim Koh Fee", "S0981234J", "Visited 10 times, Had previous heart attacks, Stroke from stress, Fell down stairs, vomit blood, allergic to nearly all drugs except penicillin");
            Patients P2 = Patients("Wang Si Liew", "S1023384T", "Visited 2 times, had spine surgery after car crash, not allergic to any drugs, partially blind and deaf");
            Patients P3 = Patients("Xiao Lah Zhi", "S9985242G", "Visited 1 time, Had deep open wound");
            Patients P4 = Patients("Pris Hel Mee", "S2342352Y", "Visited 3 time, Had flu jab");*/
        }
        else if (option == 2)
        {
            // Print out selected option
            cout << "Option 2 - Show all Patient Details\n------------------------------";

            // Error handling
            try
            {
                // Print out all Patient's Name, IC and Medical Record
                defaultList.print();
            }
            catch (const exception&)
            {
                cout << "Error: Please contact the developer to resolve the error.";
            }
        }
        else if (option == 3)
        {
            // Print out selected option
            cout << "Option 3 - Retieve Patient's Medical Record by Patient's IC\n------------------------------";

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
                cout << "Error: Please contact the developer to resolve the error.";
            }
        }
        else if (option == 4)
        {
            // Print out selected option
            cout << "Option 4 - Add existing Patient to queue\n------------------------------";
            Patients patientqueuetemp;                      // Initialize patientqueuetemp for Patient search IC
            string patientqueuename;                        // Initialize patientname for Patient search IC

            // Get Patient's IC to add to the queue
            cout << "Please enter Patient's IC to add into queue: ";
            cin >> patientqueuename;

            //Error handling
            try
            {
                // For-Loop to check the whole Patient List
                for (int i = 0; i > defaultList.getLength(); i++)
                {
                    // Enqueue Patient if IC is found in the List
                    bool success = patientqueuename == defaultList.get(i).getIC();
                    if (success)
                    {
                        patientqueuetemp = defaultList.get(i);

                        // Enqueue Patient
                        PatientQueue.enqueue(patientqueuetemp, queuenumber);

                        // Next Patient set increased queue number
                        queuenumber++;
                    }
                    else
                    {
                        cout << "Patient missing or does not exist in list.";
                    }
                }
            }
            catch (const std::exception&)
            {
                cout << "Error: Please contact the developer to resolve the error.";
            }
        }
        else if (option == 5)
        {
            // Print out selected option
            cout << "Option 5 - Display front of queue\n------------------------------";

            // Error Handling
            try
            {
                PatientQueue.getFront(QueueFrontPatient);
                cout << "\nThe current Patient at the front of the queue is " << QueueFrontPatient.getName() << "\n";
            }
            catch (const exception&)
            {
                cout << "Error: Queue empty or program error.";
            }
        }
        else if (option == 6)
        {
            // If not last patient, print Queue number and display patient name while dequeue
            if (PatientQueue.getLength() != 1)
            {
                PatientQueue.dequeue(QueueFrontPatient);
                string FrontPatientName = QueueFrontPatient.getName();
                cout << "\nCurrent Number: " << PatientQueue.displayfrontQueueNum() << "\t Patient: " << FrontPatientName;
            }

            // If last patient, print Queue number plus 1 and display patient name while dequeue
            else if (PatientQueue.getLength() == 1)
            {
                int Lastqueue = PatientQueue.displayfrontQueueNum() + 1;
                PatientQueue.dequeue(QueueFrontPatient);
                string FrontPatientName = QueueFrontPatient.getName();
                cout << "\nCurrent Number: " << Lastqueue << "\t Patient: " << FrontPatientName;
            }

            // else display no patient in queue
            else 
            {
                cout << "No Patient existing in queue. If you think this is an error, please contact the program's developer";
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
    }
}

