#include "classes.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

SYSTEMTIME o;

using namespace std;

int total = 0;
int total_cost;
int proceed = 0;

int main();
void delivery();
void sign_up();
void sign_in();
void dine_in();
void display_menu();
void set_table();

void order()
{
order:
    int choice;
    cout << "Welcome To the Order Panel" << endl;
    cout << " 1 -> Home Delivery" << endl;
    cout << " 2 -> Dine In" << endl;
    cout << " 0 -> Exit" << endl;

    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        delivery();
        break;
    case 2:
        dine_in();
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
    cout << "Welcome to the Delivery Panel" << endl;
    cout << "Sign Up or Sign In" << endl;
    cout << " 1 -> Sign Up" << endl;
    cout << " 2 -> Sign In" << endl;

    int choice;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Sign Up" << endl;
        sign_up();
        sign_in();
        break;
    case 2:
        cout << "Sign In" << endl;
        sign_in();
        display_menu();
        break;

    default:
        cout << "Invalid choice! Please try again." << endl;
        delivery();
    }
}

void sign_up()
{

    cout << "Setup your username: ";
    string username;
    cin >> username;

    for (int i = 0; i < 100; i++)
    {
        if (customers[i].username == username)
        {
            cout << "User Already Exists, Please Sign in or try a new Username" << endl;

            cout << " 1 -> Sign In" << endl;
            cout << " 2 -> Try a new Username" << endl;

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
    cin >> username;

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

    if (!found)
    {
        cout << "User not found! Please try again." << endl;
        delivery();
    }
    else
    {
        cout << "Enter your password: ";
        string password;
        cin.ignore();
        getline(cin, password);

        if (customers[index].password == password)
        {
            cout << "Sign In Successful!" << endl;

            customers[index].order_count++;
            orders[index].customer_username = customers[index].username;
            orders[index].customer_address = customers[index].address;
            orders[index].customer_phone = customers[index].phone;
            orders[index].customer_email = customers[index].email;
            orders[index].order_status = "Pending";
            orders[index].order_type = "Home Delivery";
            GetLocalTime(&o);
            orders[index].order_date = to_string(o.wDay) + "/" + to_string(o.wMonth) + "/" + to_string(o.wYear);
            index = proceed;

            display_menu();
        }
        else
        {
            cout << "Incorrect Password! Please try again." << endl;
            sign_in();
        }
    }
}
void dine_in()
{
    cout << "Welcome to the Dine In Panel" << endl;
    int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (customers[i].name == "Unknown")
        {
            index = i;
            found = true;
            break;
        }
    }
    proceed = index;
    orders[index].order_type = "Dine In";
    orders[index].order_status = "Pending";
    GetLocalTime(&o);
    orders[index].order_date = to_string(o.wDay) + "/" + to_string(o.wMonth) + "/" + to_string(o.wYear);
    set_table();
}

void display_menu()
{
    cout << "Welcome to the Menu Panel" << endl;

    cout << "-------------------Menu-------------------" << endl;

    for (int i = 0; i < 100; i++)
    {
        if (items[i].name == "Unknown")
        {
            continue;
        }
        cout << i << " -> " << items[i].name << " - " << items[i].price << endl;
    }

    cout << "-----------------------------------------" << endl;

    cout << "Enter how many items you want to order: ";
    int items_count;
    cin >> items_count;

    for (int i = 0; i < items_count; i++)
    {
        cout << "Enter the item number: ";
        cin >> orders[proceed].list[i];
    }
    for (int i = 0; i < items_count; i++)
    {

        items[orders[proceed].list[i]].quantity--;
    }

    for (int i = 0; i < items_count; i++)
    {
        total = total + items[orders[proceed].list[i]].price;
        total_cost = total_cost + items[orders[proceed].list[i]].o_price;
    }

    cout << "------------------ Bill -----------------" << endl;
    cout << "Your Ordered Items" << endl;
    for (int i = 0; i < items_count; i++)
    {
        cout << items[orders[proceed].list[i]].name << " - " << items[orders[proceed].list[i]].price << endl;
    }

    cout << "-----------------------------------------" << endl;

    cout << "Total Price: " << total << endl;

    orders[proceed].total_sale_price = total;
    orders[proceed].total_cost_price = total_cost;

    cout << "-----------------------------------------" << endl;
}

void set_table()
{
    cout << "How many seats do you want to book?" << endl;
    int seats;
    cin >> seats;

    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (tables[i].capacity >= seats)
        {
            found = true;
            cout << "Table Booked Successfully!" << endl;
            cout << "Table Number: " << tables[i].id << endl;
            tables[i].status = "Booked";
            display_menu();
        }
    }

    if (!found)
    {
        cout << "Sorry, no table available for your required capacity." << endl;
        cout << "Please try again later." << endl;
        main();
    }
}
