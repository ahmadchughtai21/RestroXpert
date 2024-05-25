#include <iostream>
#include <string>
#include <windows.h>
#include "admin.cpp"

// using namespace std;

void admin();

int main()
{
main_menu:
    int choice;

    while (true)
    {
        cout << "RestroXpert - Main Menu" << endl;
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
