#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int item_id = 0;

void admin_menu2();
void inventory_management();
void view_inventory();
void add_item();

void admin()
{
admin_menu:
    string password = "admin"; // Set password here
    cout << "Enter Password! :";
    string user_password;
    cin >> user_password;

    if (user_password == password)
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
        cout << " 1 -> Inventory Management" << endl;
        cout << " 2 -> Order Management" << endl;
        cout << " 3 -> Financial Management" << endl;
        cout << " 4 -> Table Management" << endl;
        cout << " 5 -> User Management" << endl;
        cout << " 6 -> Discount Management" << endl;
        cout << " 0 -> Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inventory_management();
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
        cout << " 1 -> View Inventory List" << endl;
        cout << " 2 -> Add Item" << endl;
        cout << " 3 -> Edit Item" << endl;
        cout << " 4 -> Delete Item" << endl;
        cout << " 5 -> Update Quantity" << endl;
        cout << " 0 -> Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            view_inventory();
            break;
        case 2:
            add_item();

            break;
        case 3:
            // Edit Item code here

            break;
        case 4:
            // Delete Item code here

            break;
        case 5:
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

void view_inventory()
{

    cout << "Inventory List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (items[i].name != "Unknown")
        {
            cout << "Item ID: " << i << endl;
            cout << "Name: " << items[i].name << endl;
            cout << "Original Price: " << items[i].o_price << endl;
            cout << "Selling Price: " << items[i].price << endl;
            cout << "Profit per Sale: " << items[i].price - items[i].o_price << endl; // "Profit: Selling Price - Original Price
            cout << "Quantity: " << items[i].quantity << endl;
            cout << endl;
        }
    }
}

void add_item()
{
    cout << "You are adding an Item" << endl;
    item_id++;
add_item:

    cout << "Enter Item Name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    items[item_id].name = name;
    cout << "Enter Item Original Price: ";
    double o_price;
    cin >> o_price;
    items[item_id].o_price = o_price;
    cout << "Enter Item Selling Price: ";
    double price;
    cin >> price;
    if (price < o_price)
    {
        cout << "Selling price cannot be less than original price. Please try again." << endl;
        goto add_item;
    }
    items[item_id].price = price;
    cout << "Enter Item Quantity: ";
    int quantity;
    cin >> quantity;
    items[item_id].quantity = quantity;
}