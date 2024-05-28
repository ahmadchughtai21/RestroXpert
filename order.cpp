#include "classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

void delivery();
void dining();
void display_menu();

void order()
{
order:
    int choice;
    cout << "Welcome.... " << endl
         << endl
         << "For Delivery select 1 .... " << endl
         << "For Dining select 2 .... " << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        delivery();
        break;
    case 2:
        dining();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        goto order;
    }
}

void delivery()
{
    cout << "delivery";

    display_menu();
}
void dining()
{
    cout << "dining";

    display_menu();
}

void display_menu()
{
    cout << "Menu" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (
            items[i].name == "Unknown" || items[i].name == "")
        {
            continue;
        }
        cout << " " << i + 1 << " -> " << items[i].name << " ----------------------------- "
             << "Price = " << items[i].price << " Rs" << endl;
    }

    cout << "Enter the item number you want to order (0 to exit): ";
    int list[100];
    int i = 0;
    while (true)
    {
        cin >> list[i];
        if (list[i] == 0)
        {
            break;
        }
        i++;
    }

    cout << "You have selected the following items: " << endl;
    for (int j = 0; j < i; j++) // shows the all seletected items
    {
        cout << items[list[j] - 1].name << " ---------------------------- " << items[list[j] - 1].price << " Rs" << endl;
    }

    int total = 0;
    for (int j = 0; j < i; j++) // calculate the total bill
    {
        total = total + items[list[j] - 1].price;
    }
    cout << "Total Bill: " << total << " Rs" << endl;
}
