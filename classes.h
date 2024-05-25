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

Item items[100];