#include <iostream>
#include <string>
using namespace std;

void admin_menu2();
void inventory_management();

void admin()
{
admin_menu:
    cout << "Enter Password! :";
    string password;
    cin >> password;

    if (password == "admin")
    {
        cout << "Welcome Admin!" << endl;
        admin_menu2();
    }
    else
    {
        cout << "Incorrect Password!" << endl;
        goto admin_menu;
    }
}

void admin_menu2()
{
    while (true)
    {
        cout << "Admin Menu:" << endl;
        cout << "1. Inventory Management" << endl;
        cout << "2. Order Management" << endl;
        cout << "3. Financial Management" << endl;
        cout << "4. Table Management" << endl;
        cout << "5. User Management" << endl;
        cout << "6. Discount Management" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Inventory Management code here
            break;
        case 2:
            // Order Management code here
            break;
        case 3:
            // Financial Management code here
            break;
        case 4:
            // Table Management code here
            break;
        case 5:
            // User Management code here
            break;
        case 6:
            // Discount Management code here
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }
}

void inventory_management()
{
    while (true)
    {
        cout << "Inventory Management Menu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Edit Item" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Update Quantity" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Add Item code here
            break;
        case 2:
            // Edit Item code here
            break;
        case 3:
            // Delete Item code here
            break;
        case 4:
            // Update Quantity code here
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }
}