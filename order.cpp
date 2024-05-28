#include "classes.h"
#include <iostream>
#include <string>
// #include <windows.h>

using namespace std;

// SYSTEMTIME o;
// GetLocalTime(&o);

int main();
void delivery();
void sign_up();
void sign_in();
void dining();
void display_menu();

void order()
{
order:
    int choice;
    cout << "Welcome To the Order Panel" << endl;
    cout << "1 -> Home Delivery" << endl;
    cout << "2 -> Dine In" << endl;
    cout << "0 -> Exit" << endl;

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
        cout << "Exiting Order Panel..." << endl;
        main();
        break;
    default:
        cout << "Invalid choice! Please try again." << endl;
        goto order;
    }
}

void delivery()
{
    cout << "Welcome to the Home Delivery Panel" << endl;
    cout << "Please Sign Up or Sign in to continue" << endl;

    cout << "1 -> Sign Up" << endl;
    cout << "2 -> Sign In" << endl;
    cout << "0 -> Exit" << endl;

    int choice;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Sign Up" << endl;
        sign_up();
        break;
    case 2:
        cout << "Sign In" << endl;
        sign_in();
        break;
    case 0:
        cout << "Exiting Home Delivery Panel..." << endl;
        order();
        break;
    default:
        cout << "Invalid choice! Please try again." << endl;
        delivery();
    }
}

void sign_up()
{

    cout << "Enter your username: ";
    string username;
    cin.ignore();
    getline(cin, username);

    for (int i = 0; i < 100; i++)
    {
        if (customers[i].username == username)
        {
            cout << "User Already Exists, Please Sign in or try a new Username" << endl;

            cout << "1 -> Sign In" << endl;
            cout << "2 -> Try a new Username" << endl;

            int choice;
            cout << "Enter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Sign In" << endl;
                sign_in();
                break;
            case 2:
                cout << "Sign Up" << endl;
                sign_up();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                sign_up();
            }
        }
    }

    int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (customers[i].username == "Unknown")
        {
            index = i;
            found = true;
            break;
        }
    }

    cout << "Enter your password: ";
    string password;
    cin.ignore();
    getline(cin, password);

    cout << "Enter your phone number: ";
    string phone;
    cin.ignore();
    getline(cin, phone);

    cout << "Enter your email: ";
    string email;
    cin.ignore();
    getline(cin, email);

    cout << "Enter your complete address: ";
    string address;
    cin.ignore();
    getline(cin, address);

    cout << "Sign Up Successful!" << endl;
    cout << "Your username is: " << username << endl;
    cout << "Your phone number is: " << phone << endl;
    cout << "Your email is: " << email << endl;
    cout << "Your address is: " << address << endl;

    customers[index].username = username;
    customers[index].password = password;
    customers[index].phone = phone;
    customers[index].email = email;
    customers[index].address = address;
    customers[index].role = "Customer";
}

void sign_in()
{
    cout << "Enter your username: ";
    string username;
    cin.ignore();
    getline(cin, username);

    bool found = false;
    int index = -1;

    for (int i = 0; i < 100; i++)
    {
        if (customers[i].username == username)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "User not found! Please try again." << endl;
        sign_in();
    }
    else
    {
        cout << "Enter your password: ";
        string password;
        cin.ignore();
        getline(cin, password);

        int index = -1;
        bool found = false;
        for (int i = 0; i < 100; i++)
        {
            if (customers[i].username == username)
            {
                index = i;
                found = true;
                break;
            }
        }
        if (customers[index].password == password)
        {
            cout << "Sign In Successful!" << endl;
            cout << "Welcome " << customers[index].username << endl;

            int index = -1;
            bool found = false;
            for (int i = 0; i < 100; i++)
            {
                if (orders[i].order_status == "Nill")
                {
                    index = i;
                    found = true;
                    break;
                }
            }

            // orders[index].order_date = to_string(o.wDay) + "/" + to_string(o.wMonth) + "/" + to_string(o.wYear);
            orders[index].customer_name = customers[index].username;
            orders[index].order_status = "Pending";
            orders[index].order_type = "Home Delivery";
            orders[index].customer_phone = customers[index].phone;
            orders[index].customer_address = customers[index].address;

            display_menu();
        }
        else
        {
            cout << "Incorrect password! Please try again." << endl;
            sign_in();
        }
    }
}

void dining()
{
    cout << "Welcome to the Dine In Panel" << endl;
    display_menu();
}

void display_menu()
{
    cout << "Welcome to the Menu" << endl;
    cout << "Here is the list of items you can order: " << endl;

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
