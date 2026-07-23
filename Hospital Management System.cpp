#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>
#include <clocale>
using namespace std;

// Max patients
const int MAX = 100;

// Patient data
int ID[MAX];
string Name[MAX];
int Age[MAX];
string Disease[MAX];
string patientDoctor[MAX];

// Number of patients
int patientCount = 0;

// Start screen
void StartSystem()
{
    cout << "Welcome ";
    Sleep(400);
    cout << "To ";
    Sleep(400);
    cout << "Hospital ";
    Sleep(400);
    cout << "Management ";
    Sleep(400);
    cout << "System";
    Sleep(600);

    cout << " .";
    Sleep(300);
    cout << ".";
    Sleep(300);
    cout << ".";
    Sleep(500);

    system("cls");

    cout << "Initializing System Data... ";
    Sleep(500);

    cout << "( ^_^ )";
    Sleep(1200);

    system("cls");
}

// Add patient
void AddPatient()
{
    if (patientCount >= MAX)
    {
        cout << "Patient list is full.\n";
        return;
    }

    int numToAdd;
    cout << "How many patients do you want to add? ";

    // Check patient number
    while (!(cin >> numToAdd) || numToAdd <= 0 || (patientCount + numToAdd > MAX))
    {
        if (!cin || numToAdd <= 0)
        {
            cout << "Invalid number! Please enter a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (patientCount + numToAdd > MAX)
        {
            cout << "Cannot add " << numToAdd << " patients. Only " << (MAX - patientCount) << " spaces remaining.\n";
            cout << "Please enter a valid number of patients: ";
        }
    }

    for (int count = 1; count <= numToAdd; count++)
    {
        cout << "\n--- Entering Data for Patient (" << count << " of " << numToAdd << ") ---\n";

        int id;
        cout << "Enter ID: ";

        // Check ID
        while (!(cin >> id))
        {
            cout << "Invalid ID! Please enter numbers only: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        bool exists = false;

        // Check duplicate ID
        for (int i = 0; i < patientCount; i++)
        {
            if (ID[i] == id)
            {
                exists = true;
                break;
            }
        }

        if (exists)
        {
            cout << "ID already exists! Skipping this patient entry.\n";
            cin.ignore(1000, '\n');
            continue;
        }

        string name;
        cout << "Enter Name: ";
        cin.ignore(1000, '\n');
        getline(cin, name);

        int age;
        cout << "Enter Age: ";

        // Check age
        while (!(cin >> age) || age <= 0)
        {
            cout << "Invalid Age! Please enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        string disease;
        cout << "Enter Disease: ";
        cin.ignore(1000, '\n');
        getline(cin, disease);

        ID[patientCount] = id;
        Name[patientCount] = name;
        Age[patientCount] = age;
        Disease[patientCount] = disease;
        patientDoctor[patientCount] = "None";

        patientCount++;

        cout << "Patient (" << name << ") added successfully!\n";
    }
}
// Search patient
void SearchPatient()
{
    int id;
    cout << "Enter Patient ID: ";

    // Check ID
    while (!(cin >> id))
    {
        cout << "Invalid ID! Please enter numbers only: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Search by ID
    for (int i = 0; i < patientCount; i++)
    {
        if (ID[i] == id)
        {
            cout << "ID: " << ID[i] << endl;
            cout << "Name: " << Name[i] << endl;
            cout << "Age: " << Age[i] << endl;
            cout << "Disease: " << Disease[i] << endl;
            cout << "Doctor: " << patientDoctor[i] << endl;
            return;
        }
    }

    cout << "Patient not found." << endl;
}

// Update patient
void UpdatePatient()
{
    int id;
    cout << "Enter Patient ID: ";

    // Check ID
    while (!(cin >> id))
    {
        cout << "Invalid ID! Please enter numbers only: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Search by ID
    for (int i = 0; i < patientCount; i++)
    {
        if (ID[i] == id)
        {
            cin.ignore(1000, '\n');

            cout << "Enter New Name: ";
            getline(cin, Name[i]);

            cout << "Enter New Age: ";

            // Check age
            while (!(cin >> Age[i]) || Age[i] <= 0)
            {
                cout << "Invalid Age! Please enter a valid number: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            cin.ignore(1000, '\n');

            cout << "Enter New Disease: ";
            getline(cin, Disease[i]);

            cout << "Patient updated successfully." << endl;
            return;
        }
    }

    cout << "Patient not found." << endl;
}

// Assign doctor
void AssignDoctor()
{
    bool found = false;
    int id;
    bool vaild;

    // Check input
    do
    {
        vaild = true;
        cout << "Enter patient ID : ";
        cin >> id;

        if (!cin)
        {
            cout << "Invalid ID! Please enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            vaild = false;
        }

    } while (vaild == false);

    // Search by ID
    for (int i = 0; i < patientCount; i++)
    {
        if (id == ID[i])
        {
            found = true;

            cout << "Enter Doctor Name :";
            cin.ignore(1000, '\n');
            getline(cin, patientDoctor[i]);

            cout << "Doctor assigned successfully\n";
            break;
        }
    }

    if (found == false)
    {
        cout << "Patient not found!" << endl;
    }

    cout << endl;
}

// Show patients
void DisplayPatients()
{
    if (patientCount == 0)
    {
        cout << "No patients found" << endl;
        return;
    }

    // Show all patients
    for (int i = 0; i < patientCount; i++)
    {
        cout << "========  patient " << i + 1 << "=========" << endl;
        cout << "ID : " << ID[i] << endl;
        cout << "Name : " << Name[i] << endl;
        cout << "Age : " << Age[i] << endl;
        cout << "Diseas : " << Disease[i] << endl;
        cout << "Doctor : " << patientDoctor[i] << endl;
        cout << "-------------------------------------" << endl;
    }
}

// Delete patient
void DeletePatient()
{
    bool found = false;
    int id;
    bool vaild;

    // Check input
    do
    {
        vaild = true;
        cout << "Enter patient ID : ";
        cin >> id;

        if (!cin)
        {
            cout << "Invalid ID! Please enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            vaild = false;
        }

    } while (vaild == false);

    // Search by ID
    for (int i = 0; i < patientCount; i++)
    {
        if (id == ID[i])
        {
            found = true;

            // Shift data
            for (int j = i; j < patientCount - 1; j++)
            {
                ID[j] = ID[j + 1];
                Name[j] = Name[j + 1];
                Age[j] = Age[j + 1];
                Disease[j] = Disease[j + 1];
                patientDoctor[j] = patientDoctor[j + 1];
            }

            patientCount--;
            cout << "Patient deleted successfully" << endl;
            break;
        }
    }

    if (found == false)
    {
        cout << "Patient not found!" << endl;
    }
}

// Main menu
int main()
{
    setlocale(LC_ALL, "Arabic");
    StartSystem();

    string choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     HOSPITAL MANAGEMENT SYSTEM     \n";
        cout << "=====================================\n";
        cout << "1- Add Patient(s)\n";
        cout << "2- Search Patient\n";
        cout << "3- Update Patient\n";
        cout << "4- Assign Doctor\n";
        cout << "5- Display Patients\n";
        cout << "6- Delete Patient\n";
        cout << "7- Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice (1-7): ";

        cin >> choice;
        cin.ignore(1000, '\n');

        // Check menu
        if (choice.length() != 1 || choice[0] < '1' || choice[0] > '7')
        {
            cout << "Invalid choice! Please try again.\n";
            continue;
        }

        system("cls");

        switch (choice[0])
        {
        case '1':
            AddPatient();
            break;
        case '2':
            SearchPatient();
            break;
        case '3':
            UpdatePatient();
            break;
        case '4':
            AssignDoctor();
            break;
        case '5':
            DisplayPatients();
            break;
        case '6':
            DeletePatient();
            break;
        case '7':
            cout << "Exiting Program. Goodbye!\n";
            break;
        }

    } while (choice[0] != '7');

    return 0;
}
