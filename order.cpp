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
void print_bill();
void sitting();

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
    display_menu();
    for(int i=0;i<=count;i++) {
    cout << "Enter your Address .... "<< endl;
    cout << "House No : ";
    cin.ignore();
    getline(cin,addresses[i].house_no);
    cout << "Street : ";
    getline(cin,addresses[i].street);
    cout << "City : ";
    getline(cin,addresses[i].city);
    cout << "Country : ";
    getline(cin,addresses[i].country);
    }
    print_bill();
    count++;

}
void dining()
{
    cout << "dining";

    display_menu();
    sitting();
}

void display_menu()
{
    cout << "-----Menu-----" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (
            items[i].name == "Unknown" || items[i].name == "")
        {
            continue;
        }
        cout << " " << i + 1 << " -> " << items[i].name << endl
             << "Price = " << items[i].price << endl;
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
    for (int j = 0; j < i; j++)
    {
        cout << items[list[j] - 1].name << " - " << items[list[j] - 1].price << endl;
    }
}

    void print_bill()
{
    int list[100];
    double total=0;
    int i = 0;
    cout << "----- Bill -----" << endl;
    
   
        cout << "Delivery Address: " << endl;
        for(int i=0;i<=count;i++){
        cout << addresses[count].house_no << ", " << addresses[count].street << ", " << addresses[count].city << ", " << addresses[count].country << endl;
        }

     
    cout << "----- Bill -----" << endl;
    
        for (int i = 0; i<=count; i++)
    {
        cout << items[list[count]].name << " - " << items[list[count]].price << endl;
        total=total+items[list[count]].price;
    }
    
    cout << "Total: $" << fixed << setprecision(2) << total << endl;
    cout << "----------------" << endl;
}
void sitting(){

    
     
}
