#include "classes.h"
#include <iostream>
#include <string>
// #include <iomanip>
#include <windows.h>

SYSTEMTIME o;

using namespace std;
int myindex = 0;
int total = 0;
int total_cost;
// int proceed = 0;

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
    while (choice < 1 || choice > 2)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

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

    while (choice < 1 || choice > 2)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }
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

    // int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (customers[i].username == username)
        {
            myindex = i;
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

        if (customers[myindex].password == password)
        {
            cout << "Sign In Successful!" << endl;

            customers[myindex].order_count++;
            orders[myindex].customer_username = customers[myindex].username;
            orders[myindex].customer_address = customers[myindex].address;
            orders[myindex].customer_phone = customers[myindex].phone;
            orders[myindex].customer_email = customers[myindex].email;
            orders[myindex].order_status = "Pending";
            orders[myindex].order_type = "Home Delivery";
            GetLocalTime(&o);
            orders[myindex].order_date = to_string(o.wDay) + "/" + to_string(o.wMonth) + "/" + to_string(o.wYear); 

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
    // int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (orders[i].customer_username == "Guest")
        {
            myindex = i;
            found = true;
            break;
        }
    }

    orders[myindex].customer_username = "Walk In Customer";
    orders[myindex].order_type = "Dine In";
    orders[myindex].order_status = "Pending";
    GetLocalTime(&o);
    orders[myindex].order_date = to_string(o.wDay) + "/" + to_string(o.wMonth) + "/" + to_string(o.wYear);
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
        cin >> orders[myindex].list[i];
    }
    for (int i = 0; i < items_count; i++)
    {

        items[orders[myindex].list[i]].quantity--;
    }

    for (int i = 0; i < items_count; i++)
    {
        total = total + items[orders[myindex].list[i]].price;
        total_cost = total_cost + items[orders[myindex].list[i]].o_price;
    }

    cout << "------------------ Bill -----------------" << endl;
    cout << "Your Ordered Items" << endl;
    for (int i = 0; i < items_count; i++)
    {
        cout << items[orders[myindex].list[i]].name << " - " << items[orders[myindex].list[i]].price << endl;
    }
    orders[myindex].total_sale_price = total;
    orders[myindex].total_cost_price = total_cost;
    total_sales_final = total_sales_final + orders[myindex].total_sale_price;
    total_cost_final = total_cost_final + orders[myindex].total_cost_price;

    cout << "-----------------------------------------" << endl;

    cout << "Total Price: " << total << endl;

    total = 0;
    total_cost = 0;

    cout << "-----------------------------------------" << endl;

    cout << "Order Placed Successfully!" << endl;
    cout << "Your Order ID is: " << myindex << endl;
    cout << "Your Order Status is: " << orders[myindex].order_status << endl;
    cout << "Your Order Type is: " << orders[myindex].order_type << endl;
    cout << "Your Order Date is: " << orders[myindex].order_date << endl;


    cout << "Would you like to place another order?" << endl;
    cout << " 1 -> Yes" << endl;
    cout << " 0 -> No" << endl;

    int choice;
    cout << "Enter Your Choice : ";
    cin >> choice;

    if (choice == 1)
    {
        main();
    }
    else
    {
        cout << "Thank you for ordering with us!" << endl;
        exit(0);
    }
}

void set_table()
{
    cout << "How many seats do you want to book?" << endl;
    int seats;
    cin >> seats;

    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (tables[i].capacity >= seats && tables[i].status == "Available")
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