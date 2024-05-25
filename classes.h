#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
    string name;
    string category;
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
    string items[100];
    string customer_name;
    string order_status;
    string order_type;

    Order()
    {
        total_sale_price = 0.0;
        total_cost_price = 0.0;
        customer_name = "Guest";
        order_status = "Nill";
        order_type = "Unknown";
    }
};

class User
{
public:
    string name;
};

class Customer : public User
{
public:
    string phone;
    string email;
    int order_count;

    Customer()
    {
        name = "Unknown";
        phone = "Unknown";
        email = "Unknown";
        order_count = 0;
    }
};

Item items[100];
Order orders[100];
Customer customers[100];