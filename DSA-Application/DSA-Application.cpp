// DSA-Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include "MedicalRecordList.h"
#include "SearchMedicalRecord.h"
#include "Patients.h"
#include "Queue.h"
#include <iostream>
#include "MedicalRecordList.h"

void printMenu()
{
    cout << "\n---------- Hospital Counter Program ----------";
    cout << "\nOption 1: Add new patient\nOption 2: Remove existing patient\nOption 3: Show all Patient Details\nOption 4: Retieve Patient's Medical Record by Patient's IC";
    cout << "\nOption 5: Add existing Patient to queue\nOption 6: Display front of queue\nOption 7: Dequeue front patient.\nOption 8: Sort Patient List";
    cout << "\nOption 0: Exit Program";
    cout << "\nPlease select an option from the menu provided: ";
}

int main()
{
    string option;
    static int queuenumber = 1;
    MedicalRecordList defaultList;
    Queue PatientQueue;
    Patients QueueFrontPatient;
    
    while (true)
    {
        printMenu();
        cin >> option;
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
                // Get Patient's Name
                cout << "\nPlease Enter Patient's Name: ";
                cin.ignore();
                getline(cin, patientname);
                

                // Get Patient's IC
                cout << "\nPlease Enter Patient's IC: ";
                cin >> patientic;

                // Get Patient's Medical Record
                cout << "\nPlease Enter Patient's Medical Record Details/Description: ";
                cin.ignore();
                getline(cin, patientmr);

                // Create new Patient
                Patients newPatient = Patients(patientname, patientic, patientmr);

                // Add new Patient into list
                defaultList.add(newPatient);
            }

            // Input invalid or error
            catch (const exception&)
            {
                cout << "Invalid Input, please try again.\n";
            }
            // Add new Patients
            /*Patients P1 = Patients("Lim Koh Fee", "S0981234J", "Visited 10 times, Had previous heart attacks, Stroke from stress, Fell down stairs, vomit blood, allergic to nearly all drugs except penicillin");
            Patients P2 = Patients("Wang Si Liew", "S1023384T", "Visited 2 times, had spine surgery after car crash, not allergic to any drugs, partially blind and deaf");
            Patients P3 = Patients("Xiao Lah Zhi", "S9985242G", "Visited 1 time, Had deep open wound");
            Patients P4 = Patients("Pris Hel Mee", "S2342352Y", "Visited 3 time, Had flu jab");*/
        }
        else if (option == "2")
        {
            int patientlistpos;             // Initialize patientname for Patient's Name

            // Print out selected option
            cout << "\nOption 2 - Remove existing patient\n------------------------------\n";
            // Error handling
            try
            {
                if (defaultList.getLength() != 0)
                {
                    // Print out all Patient's Name, IC and Medical Record
                    defaultList.print();
                    // Get Patient's index on the list
                    cout << "\nPlease Enter Patient's index in list: ";
                    cin >> patientlistpos;

                    // Remove exisitng patient from list
                    defaultList.remove(patientlistpos);

                    cout << "List updated successfully.\n";
                    defaultList.print();
                }
                else
                {
                    cout << "List is currently empty, no patient can be found.\n";
                }

            }

            // Input invalid or error
            catch (const exception&)
            {
                cout << "Invalid Input, please try again\n";
            }
            // Add new Patients
            /*Patients P1 = Patients("Lim Koh Fee", "S0981234J", "Visited 10 times, Had previous heart attacks, Stroke from stress, Fell down stairs, vomit blood, allergic to nearly all drugs except penicillin");
            Patients P2 = Patients("Wang Si Liew", "S1023384T", "Visited 2 times, had spine surgery after car crash, not allergic to any drugs, partially blind and deaf");
            Patients P3 = Patients("Xiao Lah Zhi", "S9985242G", "Visited 1 time, Had deep open wound");
            Patients P4 = Patients("Pris Hel Mee", "S2342352Y", "Visited 3 time, Had flu jab");*/
        }
        else if (option == "3")
        {
            // Print out selected option
            cout << "\nOption 3 - Show all Patient Details\n------------------------------\n";

            // Error handling
            try
            {
                if (defaultList.getLength() != 0)
                {
                    // Print out all Patient's Name, IC and Medical Record
                    defaultList.print();
                }
                else
                {
                    cout << "List is currently empty, no patient can be found.\n";
                }
            }
            catch (const exception&)
            {
                cout << "Error: Please contact the developer to resolve the error.\n";
            }
        }
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
                cout << "Error: Please contact the developer to resolve the error.\n";
            }
        }
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
                    if (success)
                    {
                        if (PatientQueue.getLength() == 0)
                        {
                            patientqueuetemp = defaultList.get(i);

                            // Enqueue Patient
                            PatientQueue.enqueue(patientqueuetemp, queuenumber);

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
                        cout << "Patient missing or does not exist in list.\n";
                        break;
                    }
                }
            }
            catch (const std::exception&)
            {
                cout << "Error: Please contact the developer to resolve the error.\n";
            }
        }
        else if (option == "6")
        {
            // Print out selected option
            cout << "\nOption 6 - Display front of queue\n------------------------------\n";
            string QueueFrontPatientName;
            // Error Handling
            try
            {
                PatientQueue.getFront(QueueFrontPatient);
                QueueFrontPatientName = QueueFrontPatient.getName();
                if (PatientQueue.isEmpty() != true)
                {
                    cout << "\nCurrent Number: " << PatientQueue.displayfrontQueueNum() << "\tThe current Patient at the front of the queue is " << QueueFrontPatientName << "\n";
                }
                else
                {
                    cout << "\nNo Patient is in queue." << QueueFrontPatientName << "\n";
                }

            }
            catch (const exception&)
            {
                cout << "Error: Queue empty or program error.\n";
            }
        }


        //    ------------------------------------------------------------------------------------------
        //    FIX YO SHYT   FIX YO SHYT   FIX YO SHYT   FIX YO SHYT   FIX YO SHYT   FIX YO SHYT   FIX YO SHYT   
        //    ------------------------------------------------------------------------------------------

        else if (option == "7")
        {
            cout << "\nOption 7 - Dequeue front patient\n------------------------------\n";
            if (PatientQueue.getLength() != 1)
            {
                PatientQueue.dequeue(QueueFrontPatient);
                cout << "Patient successfully dequeued";

                // Display Next person in line
                if (true)   // Condition
                {

                }
                else        // If last person, stop, get some help
                {

                }
            }
            else
            {
                cout << "No Patient existing in queue. If you think this is an error, please contact the program's developer.\n";
            }
            //// Print out selected option
            //cout << "\nOption 7 - Display front and dequeue\n------------------------------\n";
            //// If not last patient, print Queue number and display patient name while dequeue
            //if (PatientQueue.getLength() != 1)
            //{
            //    PatientQueue.dequeue(QueueFrontPatient);
            //    string FrontPatientName = QueueFrontPatient.getName();
            //    cout << "\nCurrent Number: " << PatientQueue.displayfrontQueueNum() << "\t Patient: " << FrontPatientName;
            //}

            //// If last patient, print Queue number plus 1 and display patient name while dequeue
            //else if (PatientQueue.getLength() == 1)
            //{
            //    int Lastqueue = PatientQueue.displayfrontQueueNum() + 1;
            //    PatientQueue.dequeue(QueueFrontPatient);
            //    string FrontPatientName = QueueFrontPatient.getName();
            //    cout << "\nCurrent Number: " << Lastqueue << "\t Patient: " << FrontPatientName;
            //}
            //else if (PatientQueue.getLength() == 0)
            //{
            //    cout << "No Patient existing in queue. If you think this is an error, please contact the program's developer.\n";
            //}
            //// else display no patient in queue
            //else 
            //{
            //    cout << "No Patient existing in queue. If you think this is an error, please contact the program's developer.\n";
            //}

        }
        else if (option == "8")
        {
            cout << "\nOption 8 - Sort Patient List\n------------------------------";

            int sizeoflist = defaultList.getLength();
            defaultList.selectionSort(sizeoflist);

            // Print out all Patient's Name, IC and Medical Record
            defaultList.print();
        }
        else if (option == "0")
        {
            cout << "\n---------- End of Program ----------\nProgram developed by Yuan Ming and Gladys\n";
            break;
        }
        else
        {
            cout << "Please try again.\n";
            continue;
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

