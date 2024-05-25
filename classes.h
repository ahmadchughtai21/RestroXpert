#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
    string name;
    string category;
    double price;
    int quantity;

    // Item()
    // {
    //     name = "Unknown";
    //     category = "Uncategorized";
    //     price = 0.0;
    //     quantity = 0;
    // }
};

Item items[100];