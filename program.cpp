#include <iostream>
#include <string>
#include "admin.cpp"
#include "order.cpp"
#include "attendance.cpp"
#include "feedback.cpp"
#include "classes.h"

void admin();
void load_changes();
void save_changes();
void changes_view();
void attendance();
void feedback_panel();
void main_menu();

int main()
{
    load_changes();
    // changes_view(); // mantainance mode

    cout << " 888888   8888888   88888    888888  888888     888   88    88 888888   8888888  888888    888888 " << endl;
    cout << "  88  88   88  88  88   88   8 88 8   88  88   88 88   88  88   88  88   88  88   88  88   8 88 8 " << endl;
    cout << "  88  88   88      888         88     88  88  88   88   8888    88  88   88       88  88     88   " << endl;
    cout << "  88888    8888      888       88     88888   88   88    88     88888    8888     88888      88   " << endl;
    cout << "  88 88    88          888     88     88 88   88   88   8888    88       88       88 88      88   " << endl;
    cout << "  88  88   88  88  88   88     88     88  88   88 88   88  88   88       88  88   88  88     88   " << endl;
    cout << "  88   88 8888888   88888     8888    88   88   888   88    88 8888     8888888   88   88   8888  " << endl;
    cout << endl;

    main_menu();
}
void main_menu()
{

main_menu:
    cout << " ************************************************************************************************* " << endl;
    cout << " ************************************ RestroXpert - Main Menu ************************************ " << endl;
    cout << " 1 -> Admin Panel" << endl;
    cout << " 2 -> Order Food" << endl; // take order and end me ask if home delivery or dine in or us hisaab se seats and table book krne hn
    cout << " 3 -> Staff Attendance" << endl;
    cout << " 4 -> Feedback Panel" << endl;
    cout << " 5 -> Save and Continue" << endl;
    cout << " 0 -> Save and Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    while (choice < 0 || choice > 5)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        admin();
        break;
    case 2:
        order();
        break;
    case 3:
        attendance();
        break;
    case 4:
        feedback_panel();
        break;
    case 5:
        cout << "Saving changes..." << endl;
        save_changes();
        cout << "Changes saved successfully." << endl;
        break;

    case 0:
        cout << "Saving changes and exiting RestroXpert..." << endl;
        save_changes();
        cout << "Exiting RestroXpert. Goodbye!" << endl;

        // changes_view(); // maintanance mode

        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

    cout << endl;
}
