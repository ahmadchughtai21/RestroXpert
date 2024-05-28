#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#ifndef CLASSES_H
#define CLASSES_H

using namespace std;

static int count;

class Item
{
public:
    string name;
    double o_price; // Original Price
    double price;   // Selling Price
    int quantity;

    Item()
    {
        name = "Unknown";
        o_price = 0.0;
        price = 0.0;
        quantity = 0;
    }
};

class Order
{
public:
    int id;
    double total_sale_price;
    double total_cost_price;
    int list[100];
    string customer_username;
    string customer_address;
    string customer_phone;
    string customer_email;
    string order_status;
    string order_type;
    string order_date;

    Order()
    {
        total_sale_price = 0.0;
        total_cost_price = 0.0;
        customer_username = "Guest";
        customer_address = "Guest";
        customer_phone = "Guest";
        customer_email = "Guest";
        order_date = "Nill";
        order_status = "Nill";
        order_type = "Unknown";
    }
};

class User
{
public:
    string name;
    string role;

    User()
    {
        name = "Unknown";
        role = "Unknown";
    }
};

class Customer : public User
{
public:
    string username;
    string password;
    string phone;
    string email;
    string address;
    int order_count;

    Customer()
    {
        username = "Unknown";
        password = "Not Set";
        phone = "Unknown";
        email = "Unknown";
        address = "Guest";
    }
};

class Staff : public User
{
public:
    string cnic;
    string phone;
    string email;
    string address;
    string role;
    string status;

    Staff()
    {
        name = "Unknown";
        cnic = "Unknown";
        phone = "Unknown";
        email = "Unknown";
        address = "Unknown";
        role = "Unknown";
        status = "Unknown";
    }
};

class Table
{
public:
    static int capacity;
    string status;
    string reserved_by;

    Table()
    {
        capacity = 0;
        status = "unknown";
        reserved_by = "Unknown";
    }
};
int Table::capacity = 0;

class Discounts
{
public:
    string name;
    double discount;

    Discounts()
    {
        name = "Unknown";
        discount = 0.0;
    }
};

class Feedback
{
public:
    int stars;
    string comments;
    string customer_name;
    string date;
    string status;
    Feedback()
    {
        stars = 0;
        comments = "Unknown";
        customer_name = "Unknown";
        date = "Unknown";
        status = "Unknown";
    }
};

Item items[100];
Order orders[100];
User users[100];
Staff staffs[100];
Customer customers[100];
Table tables[100];
Discounts discounts[100];
Feedback feedbacks[100];

#endif