#include <iostream>
#include <string>
#include "classes.h"

void main_menu();
void mark_attendance();
void view_attendance();

void attendance()
{
    cout << "Attendance Panel" << endl;
    cout << "-----------------" << endl;
    cout << "1. Mark Attendance" << endl;
    cout << "2. View Attendance" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    while (choice < 0 || choice > 2)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        mark_attendance();
        break;
    case 2:
        view_attendance();
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

void mark_attendance()
{
    cout << "Mark Attendance" << endl;
    cout << "----------------" << endl;
    cout << "Enter your staff id: ";
    int staff_id;
    cin >> staff_id;

    if (staffs[staff_id].name == "Unknown")
    {
        cout << "Staff not found!" << endl;
        main_menu();
    }
    else
    {

        cout << "You are marked as present!" << endl;
        staffs[staff_id].attendance = true;
    }
}

void view_attendance()
{
    cout << "View Attendance" << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < 100; i++)
    {
        if (staffs[i].name == "Unknown")
        {
            continue;
        }

        cout << "Staff ID: " << i << endl;
        cout << "Staff Name: " << staffs[i].name << endl;
        cout << "Attendance: " << (staffs[i].attendance ? "Present" : "Absent") << endl;
        cout << endl;
    }
}
