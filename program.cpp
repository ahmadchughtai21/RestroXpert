#include <iostream>
#include <string>
#include <windows.h>
#include "admin.cpp"
#include "order.cpp"
#include "attendance.cpp"
#include "feedback.cpp"
// #include "classes.h"

void admin();

int main()
{
main_menu:
    int choice;

    while (true)
    {
        cout << " 888888   8888888   88888    888888  888888     888    88    88 888888   8888888  888888    888888 " << endl;
        cout << "  88  88   88  88  88   88   8 88 8   88  88   88 88    88  88   88  88   88  88   88  88   8 88 8 " << endl;
        cout << "  88  88   88      888         88     88  88  88   88    8888    88  88   88       88  88     88   " << endl;
        cout << "  88888    8888      888       88     88888   88   88     88     88888    8888     88888      88   " << endl;
        cout << "  88 88    88          888     88     88 88   88   88    8888    88       88       88 88      88   " << endl;
        cout << "  88  88   88  88  88   88     88     88  88   88 88    88  88   88       88  88   88  88     88   " << endl;
        cout << "  88   88 8888888   88888     8888    88   88   888    88    88 8888     8888888   88   88   8888  " << endl;

        cout << endl;
        cout << " ************************************************************************************************* " << endl;
        cout << " ************************************ RestroXpert - Main Menu ************************************ " << endl;
        cout << " 1 -> Admin Panel" << endl;
        cout << " 2 -> Order Food" << endl; // take order and end me ask if home delivery or dine in or us hisaab se seats and table book krne hn
        cout << " 3 -> Staff Attendance" << endl;
        cout << " 4 -> Feedback Panel" << endl;
        cout << " 0 -> Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            admin();
            break;
        case 2:
            // Order Food code here
            break;
        case 3:
            // Staff Attendance code here
            break;
        case 4:
            // Feedback Panel code here
            break;
        case 0:
            cout << "Exiting RestroXpert. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
