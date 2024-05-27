// Made by Muhammad Ahmad Chughtai
// Roll # F2023266634

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "classes.h"

// Global Variables for Counter
int item_id;
int table_id;
int user_id;
int discount_id;
string password = "";

// Prototypes of used functions
void enter_password();
void admin_menu2();
void inventory_management();
void view_inventory();
void add_item();
void edit_item();
void delete_item();
void update_quantity();
void order_management();
void view_orders();
void edit_order_status();
void cancel_order();
void view_cancelled_orders();
void reports();
void generate_financial_report();
void stock_report();
void table_management();
void view_tables();
void add_table();
void edit_table();
void delete_table();
void user_management();
void view_all_staff();
void get_staff_details();
void add_staff();
void edit_staff();
void delete_staff();
void discount_management();
void view_feedbacks();
void discount_list();
void add_discount();
void edit_discount();
void delete_discount();
void view_feedbacks();
void reset_to_default();

void admin()
{
admin:
    enter_password();
}

void enter_password()
{
    if (password == "")
    {
        cout << "Please set a password for the Admin Panel: ";
        cin >> password;
        cout << "Password set successfully!" << endl;
    }
    cout << "Enter Password to access Admin Panel: ";
    string pass;
    cin >> pass;
    if (pass == password)
    {
        admin_menu2();
    }
    else
    {
        cout << "Incorrect Password! Please try again." << endl;
        admin();
    }
}

void admin_menu2()
{
    while (true)
    {
    admin_menu2:
        cout << "Admin Menu:" << endl;
        cout << " 1 -> Inventory Management" << endl;      // completed
        cout << " 2 -> Order Management" << endl;          // completed
        cout << " 3 -> Get Reports" << endl;               // completed
        cout << " 4 -> Table Management" << endl;          // completed
        cout << " 5 -> User Management" << endl;           // completed
        cout << " 6 -> Discount Management" << endl;       // completed
        cout << " 7 -> View Feedbacks" << endl;            // completed
        cout << " 8 -> Reset to Default Settings" << endl; // completed
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
            order_management();
            break;
        case 3:
            reports();
            break;
        case 4:
            table_management();
            break;
        case 5:
            user_management();
            break;
        case 6:
            discount_management();
            break;
        case 7:
            view_feedbacks();
            break;
        case 8:
            reset_to_default();
        case 0:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
            goto admin_menu2;
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
            edit_item();

            break;
        case 4:
            delete_item();

            break;
        case 5:
            update_quantity();
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
        if (items[i].name == "Unknown")
        {
            continue;
        }
        cout << "Item ID: " << i << endl;
        cout << "Name: " << items[i].name << endl;
        cout << "Original Price: " << items[i].o_price << endl;
        cout << "Selling Price: " << items[i].price << endl;
        cout << "Profit per Sale: " << items[i].price - items[i].o_price << endl; // "Profit: Selling Price - Original Price
        cout << "Quantity: " << items[i].quantity << endl;
        cout << endl;
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

void edit_item()
{
    cout << "You are editing an Item" << endl;
    cout << "Enter Item ID to edit: ";
    int id;
    cin >> id;

    if (items[id].name == "Unknown")
    {
        cout << "Item not found. Please try again." << endl;
        return;
    }

    cout << "Item Details:" << endl;
    cout << "Name: " << items[id].name << endl;
    cout << "Original Price: " << items[id].o_price << endl;
    cout << "Selling Price: " << items[id].price << endl;
    cout << "Quantity: " << items[id].quantity << endl;

    cout << "Enter new details for this item:" << endl;

    cout << "Enter Item Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    items[id].name = name;
    cout << "Enter Item Original Price: ";
    double o_price;
    cin >> o_price;
    items[id].o_price = o_price;
    cout << "Enter Item Selling Price: ";
    double price;
    cin >> price;
    if (price < o_price)
    {
        cout << "Selling price cannot be less than original price. Please try again." << endl;
        return;
    }
    items[id].price = price;
    cout << "Enter Item Quantity: ";
    int quantity;
    cin >> quantity;
    items[id].quantity = quantity;
    cout << "Item Updated Successfully!" << endl;
}

void delete_item()
{
    cout << "You are deleting an Item" << endl;
    cout << "Enter Item ID to delete: ";
    int id;
    cin >> id;

    if (items[id].name == "Unknown")
    {
        cout << "Item not found. Please try again." << endl;
        return;
    }

    items[id].name = "Unknown";
    items[id].o_price = 0.0;
    items[id].price = 0.0;
    items[id].quantity = 0;

    cout << "Item Deleted Successfully!" << endl;
}

void update_quantity()
{
    cout << "You are updating the quantity of an Item" << endl;
    cout << "Enter Item ID to update quantity: ";
    int id;
    cin >> id;

    if (items[id].name == "Unknown")
    {
        cout << "Item not found. Please try again." << endl;
        return;
    }

    cout << "Item Details:" << endl;
    cout << "Name: " << items[id].name << endl;
    cout << "Original Price: " << items[id].o_price << endl;
    cout << "Selling Price: " << items[id].price << endl;
    cout << "Quantity: " << items[id].quantity << endl;

    cout << "Enter new quantity for this item:" << endl;
    int quantity;
    cin >> quantity;
    items[id].quantity = quantity;
    cout << "Quantity Updated Successfully!" << endl;
}

void order_management()
{
    cout << "Order Management Menu:" << endl;
    cout << " 1 -> View Orders" << endl;
    cout << " 2 -> Edit Order Status" << endl;
    cout << " 3 -> Cancel Order" << endl;
    cout << " 4 -> View Cancelled Order" << endl;
    cout << " 0 -> Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        view_orders();
        break;
    case 2:
        edit_order_status();
        break;
    case 3:
        cancel_order();
        break;

    case 4:
        view_cancelled_orders();
        break;

    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void view_orders()
{
    cout << "Orders List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (orders[i].order_status == "Nill" || orders[i].order_status == "Cancelled")
        {
            continue;
        }
        cout << "Order ID: " << i << endl;
        cout << "Customer Name: " << orders[i].customer_name << endl;
        cout << "Total Sale Price: " << orders[i].total_sale_price << endl;
        cout << "Total Cost Price: " << orders[i].total_cost_price << endl;
        cout << "Total Profit: " << orders[i].total_sale_price - orders[i].total_cost_price << endl;
        cout << "Order Status: " << orders[i].order_status << endl;
        cout << "Order Type: " << orders[i].order_type << endl;
        cout << endl;
    }
}

void edit_order_status()
{
    cout << "You are editing the status of an Order" << endl;
    cout << "Enter Order ID to edit status: ";
    int id;
    cin >> id;

    if (orders[id].order_status == "Nill" || orders[id].order_status == "Cancelled")
    {
        cout << "Order not found. Please try again." << endl;
        return;
    }

    cout << "Order Details:" << endl;
    cout << "Customer Name: " << orders[id].customer_name << endl;
    cout << "Total Sale Price: " << orders[id].total_sale_price << endl;
    cout << "Total Cost Price: " << orders[id].total_cost_price << endl;
    cout << "Total Profit: " << orders[id].total_sale_price - orders[id].total_cost_price << endl;
    cout << "Order Status: " << orders[id].order_status << endl;
    cout << "Order Type: " << orders[id].order_type << endl;

    cout << "Enter new status for this order:" << endl;
    string status;
    cin.ignore();
    getline(cin, status);
    orders[id].order_status = status;
    cout << "Order Status Updated Successfully!" << endl;
}

void cancel_order()
{
    cout << "You are cancelling an Order" << endl;
    cout << "Enter Order ID to cancel: ";
    int id;
    cin >> id;

    if (orders[id].order_status == "Nill" || orders[id].order_status == "Cancelled")
    {
        cout << "Order not found. Please try again." << endl;
        return;
    }

    orders[id].order_status = "Cancelled";
    cout << "Order Cancelled Successfully!" << endl;
}

void view_cancelled_orders()
{
    cout << "Cancelled Orders List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (orders[i].order_status != "Cancelled")
        {
            continue;
        }
        cout << "Order ID: " << i << endl;
        cout << "Customer Name: " << orders[i].customer_name << endl;
        cout << "Total Sale Price: " << orders[i].total_sale_price << endl;
        cout << "Total Cost Price: " << orders[i].total_cost_price << endl;
        cout << "Total Profit: " << orders[i].total_sale_price - orders[i].total_cost_price << endl;
        cout << "Order Status: " << orders[i].order_status << endl;
        cout << "Order Type: " << orders[i].order_type << endl;
        cout << endl;
    }
}

void reports()
{
    cout << "Get Reports Menu:" << endl;
    cout << " 1 -> Generate Financial Report" << endl;
    cout << " 2 -> Stock Report" << endl;
    cout << " 0 -> Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        generate_financial_report();
        break;
    case 2:
        stock_report();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void generate_financial_report()
{
    double total_sales = 0.0;
    double total_profit = 0.0;

    for (int i = 0; i < 100; i++)
    {
        if (orders[i].order_status == "Nill" || orders[i].order_status == "Cancelled")
        {
            continue;
        }
        total_sales = total_sales + orders[i].total_sale_price;
    }
    for (int i = 0; i < 100; i++)
    {
        if (orders[i].order_status == "Nill" || orders[i].order_status == "Cancelled")
        {
            continue;
        }
        total_profit = total_profit + (orders[i].total_sale_price - orders[i].total_cost_price);
    }

    SYSTEMTIME t;
    GetLocalTime(&t);
    cout << "Financial Report as of " << t.wDay << "/" << t.wMonth << "/" << t.wYear << endl;
    cout << "Total Sales: " << total_sales << endl;
    cout << "Total Profit: " << total_profit << endl;
}

void stock_report()
{
    cout << "Stock Report:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (items[i].name == "Unknown")
        {
            continue;
        }

        if (items[i].quantity < 5)
        {
            cout << "Item: " << items[i].name << " - Stock is low. Please restock." << endl;
        }
        else if (items[i].quantity <= 10)
        {
            cout << "Item: " << items[i].name << " - Stock is running low. Consider restocking." << endl;
        }
        cout << "Stock Report Generated Successfully! (If empty, all items are in stock or there are no items in inventory)";
    }
}
void table_management()
{
    cout << "Table Management Menu:" << endl;
    cout << " 1 -> View Tables" << endl;
    cout << " 2 -> Add Table" << endl;
    cout << " 3 -> Edit Table" << endl;
    cout << " 4 -> Delete Table" << endl;
    cout << " 0 -> Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        view_tables();
        break;
    case 2:
        add_table();
        break;
    case 3:
        edit_table();
        break;
    case 4:
        delete_table();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void view_tables()
{
    cout << "Tables List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (tables[i].status == "Unknown")
        {
            continue;
        }
        cout << "Table No: " << i << endl;
        cout << "Table Capacity: " << tables[i].capacity << endl;
        cout << "Table Status: " << tables[i].status << endl;
        cout << endl;
    }
}

void add_table()
{
    cout << "You are adding a Table" << endl;
    table_id++;
add_table:

    cout << "Enter Table Capacity: ";
    int capacity;
    cin >> capacity;
    tables[table_id].capacity = capacity;
    tables[table_id].status = "Available";
}

void edit_table()
{
    cout << "You are editing a Table" << endl;
    cout << "Enter Table No to edit: ";
    int id;
    cin >> id;

    if (tables[id].status == "Unknown")
    {
        cout << "Table not found. Please try again." << endl;
        return;
    }

    cout << "Table Details:" << endl;
    cout << "Table Capacity: " << tables[id].capacity << endl;
    cout << "Table Status: " << tables[id].status << endl;

    cout << "Enter new details for this table:" << endl;

    cout << "Enter Table Capacity: ";
    int capacity;
    cin >> capacity;
    tables[id].capacity = capacity;
    cout << "Enter Table Status: ";
    string status;
    cin >> status;
    tables[id].status = status;

    cout << "Table Updated Successfully!" << endl;
}

void delete_table()
{
    cout << "You are deleting a Table" << endl;
    cout << "Enter Table No to delete: ";
    int id;
    cin >> id;

    if (tables[id].status == "Unknown")
    {
        cout << "Table not found. Please try again." << endl;
        return;
    }

    tables[id].capacity = 0;
    tables[id].status = "Unknown";

    cout << "Table Deleted Successfully!" << endl;
}

void user_management()
{
    cout << "User Management Menu:" << endl;
    cout << " 1 -> View All Staff" << endl;
    cout << " 2 -> Add Staff" << endl;
    cout << " 3 -> Edit Staff Info" << endl;
    cout << " 4 -> Delete Staff Member" << endl;
    cout << " 0 -> Back" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        view_all_staff();
        break;
    case 2:
        add_staff();
        break;
    case 3:
        edit_staff();
        break;
    case 4:
        delete_staff();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void view_all_staff()
{
    cout << "Staff List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (staffs[i].name == "Unknown")
        {
            continue;
        }
        cout << "Staff ID: " << i << endl;
        cout << "Name: " << staffs[i].name << endl;
        cout << "Role: " << staffs[i].role << endl;
        cout << endl;
    }

    cout << " 1 -> Get details of a staff member" << endl;
    cout << " 0 -> Back" << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        get_staff_details();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void get_staff_details()
{
    cout << "Enter Staff ID to get details: ";
    int id;
    cin >> id;

    if (staffs[id].name == "Unknown")
    {
        cout << "Staff not found. Please try again." << endl;
        return;
    }

    cout << "Staff Details:" << endl;
    cout << "Name: " << staffs[id].name << endl;
    cout << "CNIC: " << staffs[id].cnic << endl;
    cout << "Phone: " << staffs[id].phone << endl;
    cout << "Email: " << staffs[id].email << endl;
    cout << "Address: " << staffs[id].address << endl;
    cout << "Role: " << staffs[id].role << endl;
    cout << "Status: " << staffs[id].status << endl;
}

void add_staff()
{
    cout << "You are adding a Staff Member" << endl;
    user_id++;
add_staff:

    cout << "Enter Staff Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    staffs[user_id].name = name;
    cout << "Enter Staff CNIC: ";
    string cnic;
    cin >> cnic;
    staffs[user_id].cnic = cnic;
    cout << "Enter Staff Phone: ";
    string phone;
    cin >> phone;
    staffs[user_id].phone = phone;
    cout << "Enter Staff Email: ";
    string email;
    cin >> email;
    staffs[user_id].email = email;
    cout << "Enter Staff Address: ";
    string address;
    cin.ignore();
    getline(cin, address);
    staffs[user_id].address = address;
    cout << "Enter Staff Role: ";
    string role;
    cin >> role;
    staffs[user_id].role = role;
    cout << "Enter Staff Status: ";
    string status;
    cin >> status;
    staffs[user_id].status = status;

    cout << "Staff Member Added Successfully!" << endl;
    cout << "New Details:" << endl;
    cout << "Name: " << staffs[user_id].name << endl;
    cout << "CNIC: " << staffs[user_id].cnic << endl;
    cout << "Phone: " << staffs[user_id].phone << endl;
    cout << "Email: " << staffs[user_id].email << endl;
    cout << "Address: " << staffs[user_id].address << endl;
    cout << "Role: " << staffs[user_id].role << endl;
    cout << "Status: " << staffs[user_id].status << endl;
}

void edit_staff()
{
    cout << "You are editing a Staff Member" << endl;
    cout << "Enter Staff ID to edit: ";
    int id;
    cin >> id;

    if (staffs[id].name == "Unknown")
    {
        cout << "Staff not found. Please try again." << endl;
        return;
    }

    cout << "Staff Details:" << endl;
    cout << "Name: " << staffs[id].name << endl;
    cout << "CNIC: " << staffs[id].cnic << endl;
    cout << "Phone: " << staffs[id].phone << endl;
    cout << "Email: " << staffs[id].email << endl;
    cout << "Address: " << staffs[id].address << endl;
    cout << "Role: " << staffs[id].role << endl;
    cout << "Status: " << staffs[id].status << endl;

    cout << "Enter new details for this staff member:" << endl;

    cout << "Enter Staff Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    staffs[id].name = name;
    cout << "Enter Staff CNIC: ";
    string cnic;
    cin >> cnic;
    staffs[id].cnic = cnic;
    cout << "Enter Staff Phone: ";
    string phone;
    cin >> phone;
    staffs[id].phone = phone;
    cout << "Enter Staff Email: ";
    string email;
    cin >> email;
    staffs[id].email = email;
    cout << "Enter Staff Address: ";
    string address;
    cin.ignore();
    getline(cin, address);
    staffs[id].address = address;
    cout << "Enter Staff Role: ";
    string role;
    cin >> role;
    staffs[id].role = role;
    cout << "Enter Staff Status: ";
    string status;
    cin >> status;
    staffs[id].status = status;

    cout << "Staff Member Updated Successfully!" << endl;
    cout << "New Details:" << endl;
    cout << "Name: " << staffs[id].name << endl;
    cout << "CNIC: " << staffs[id].cnic << endl;
    cout << "Phone: " << staffs[id].phone << endl;
    cout << "Email: " << staffs[id].email << endl;
    cout << "Address: " << staffs[id].address << endl;
    cout << "Role: " << staffs[id].role << endl;
    cout << "Status: " << staffs[id].status << endl;
}

void delete_staff()
{
    cout << "You are deleting a Staff Member" << endl;
    cout << "Enter Staff ID to delete: ";
    int id;
    cin >> id;

    if (staffs[id].name == "Unknown")
    {
        cout << "Staff not found. Please try again." << endl;
        return;
    }

    cout << "Are you sure you want to delete " << staffs[id].name << endl;
    cout << " 1 -> Yes" << endl;
    cout << " 0 -> No" << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        staffs[id].name = "Unknown";
        staffs[id].cnic = "Unknown";
        staffs[id].phone = "Unknown";
        staffs[id].email = "Unknown";
        staffs[id].address = "Unknown";
        staffs[id].role = "Unknown";
        staffs[id].status = "Unknown";

        cout << "Staff Member Deleted Successfully!" << endl;
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void discount_management()
{
    cout << "Discount Management Menu:" << endl;

    cout << " 1 -> View Discount List" << endl;
    cout << " 2 -> Add Discount" << endl;
    cout << " 3 -> Edit Discount" << endl;
    cout << " 4 -> Delete Discount" << endl;
    cout << " 0 -> Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        discount_list();
        break;
    case 2:
        add_discount();
        break;
    case 3:
        edit_discount();
        break;
    case 4:
        delete_discount();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}
void discount_list()
{
    cout << "Discount List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (discounts[i].name == "Unknown")
        {
            continue;
        }
        cout << "Discount ID: " << i << endl;
        cout << "Name: " << discounts[i].name << endl;
        cout << "Discount Percentage: " << discounts[i].discount << endl;
        cout << endl;
    }
}

void add_discount()
{

    cout << "You are adding a Discount" << endl;
    discount_id++;
add_discount:

    cout << "Enter Discount Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    discounts[discount_id].name = name;
    cout << "Enter Discount Percentage: ";
    double discount;
    cin >> discount;
    discounts[discount_id].discount = discount;
    discount_id++;
    cout << "Discount Added Successfully!" << endl;
}

void edit_discount()
{
    cout << "You are editing a Discount" << endl;
    cout << "Enter Discount ID to edit: ";
    int id;
    cin >> id;

    if (discounts[id].name == "Unknown")
    {
        cout << "Discount not found. Please try again." << endl;
        return;
    }

    cout << "Discount Details:" << endl;
    cout << "Name: " << discounts[id].name << endl;
    cout << "Discount Percentage: " << discounts[id].discount << endl;

    cout << "Enter new details for this discount:" << endl;

    cout << "Enter Discount Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    discounts[id].name = name;
    cout << "Enter Discount Percentage: ";
    double discount;
    cin >> discount;
    discounts[id].discount = discount;

    cout << "Discount Updated Successfully!" << endl;
}

void delete_discount()
{
    cout << "You are deleting a Discount" << endl;
    cout << "Enter Discount ID to delete: ";
    int id;
    cin >> id;

    if (discounts[id].name == "Unknown")
    {
        cout << "Discount not found. Please try again." << endl;
        return;
    }

    cout << "Are you sure you want to delete " << discounts[id].name << endl;
    cout << " 1 -> Yes" << endl;
    cout << " 0 -> No" << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        discounts[id].name = "Unknown";
        discounts[id].discount = 0.0;

        cout << "Discount Deleted Successfully!" << endl;
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

void view_feedbacks()
{
    cout << "You are in Feedbacks List:" << endl;
    cout << " 1 -> View Unread Feedbacks" << endl;
    cout << " 2 -> View Read Feedbacks" << endl;
    cout << " 0 -> Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Unread Feedbacks:" << endl;
        for (int i = 0; i < 100; i++)
        {
            if (feedbacks[i].status == "Read" || feedbacks[i].status == "Unknown")
            {
                continue;
            }
            cout << "Feedback ID: " << i << endl;
            cout << "Customer Name: " << feedbacks[i].customer_name << endl;
            cout << "Stars: " << feedbacks[i].stars << endl;
            cout << "Comments: " << feedbacks[i].comments << endl;
            cout << "Date: " << feedbacks[i].date << endl;
            cout << "Status: " << feedbacks[i].status << endl;
            cout << endl;
        }
        cout << " 1 -> Mark All Feedbacks as Read" << endl;
        cout << " 0 -> Back" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 100; i++)
            {
                if (feedbacks[i].status == "Unread")
                {
                    feedbacks[i].status = "Read";
                }
            }
            cout << "All Feedbacks Marked as Read!" << endl;
            break;

        case 0:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        break;
    case 2:
        cout << "Read Feedbacks:" << endl;
        for (int i = 0; i < 100; i++)
        {
            if (feedbacks[i].status == "Unread" || feedbacks[i].status == "Unknown")
            {
                continue;
            }
            cout << "Feedback ID: " << i << endl;
            cout << "Customer Name: " << feedbacks[i].customer_name << endl;
            cout << "Stars: " << feedbacks[i].stars << endl;
            cout << "Comments: " << feedbacks[i].comments << endl;
            cout << "Date: " << feedbacks[i].date << endl;
            cout << "Status: " << feedbacks[i].status << endl;
            cout << endl;
        }

        break;
    case 0:

        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
}

// File Handling Functions

void load_changes()
{
    ifstream fin;
    fin.open("backend.txt");
    fin >> item_id;
    fin >> table_id;
    fin >> user_id;
    fin >> discount_id;
    fin >> password;
    fin.close();
}

void save_changes()
{
    ofstream fout;
    fout.open("backend.txt");
    fout << item_id;
    fout << endl;
    fout << table_id;
    fout << endl;
    fout << user_id;
    fout << endl;
    fout << discount_id;
    fout << endl;
    fout << password;
    fout.close();
}

void changes_view()
{

    cout << "Showing Database Tables ( Maintainance Mode !!! )" << endl;
    cout << "Item ID: " << item_id << endl;
    cout << "Table ID: " << table_id << endl;
    cout << "User ID: " << user_id << endl;
    cout << "Discount ID: " << discount_id << endl;
    cout << "Password: " << password << endl;
}

void reset_to_default()
{
    item_id = 0;
    table_id = 0;
    user_id = 0;
    discount_id = 0;
    password = "";

    save_changes();
}
