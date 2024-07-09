// Made by Muhammad Ahmad Chughtai
// Roll # F2023266634

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "classes.h"

// Global Variables for Counter
// int item_id;
double total_sales_final;
double total_cost_final;
// int table_id;
// int user_id;
// int discount_id;
string password = "";

// Prototypes of used functions
void main_menu();
void enter_password();
void set_password();
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
void save_changes();
void load_changes();
void update_table();

void admin()
{
admin:
    enter_password();
}

void enter_password()
{
    if (password == "")
    {
        set_password();
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

void set_password()
{
    cout << "Please set a New Password for the Admin Panel: ";
    cin >> password;
    cout << "Password set successfully!" << endl;
    save_changes();
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
        cout << " 5 -> Staff Management" << endl;          // completed
        cout << " 6 -> Discount Management" << endl;       // completed
        cout << " 7 -> View Feedbacks" << endl;            // completed
        cout << " 8 -> Change Admin Password" << endl;     // completed
        cout << " 9 -> Reset to Default Settings" << endl; // completed
        cout << " 0 -> Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice < 0 || choice > 9)
        {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

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
            set_password();
        case 9:
            reset_to_default();
            break;
        case 0:
            main_menu();
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

        while (choice < 0 || choice > 5)
        {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

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
        if (items[i].name == "Unknown" || items[i].name == "")
        {
            continue;
        }
        else
        {
            cout << "Item ID: " << i << endl;
            cout << "Name: " << items[i].name << endl;
            cout << "Original Price: " << items[i].o_price << endl;
            cout << "Selling Price: " << items[i].price << endl;
            cout << "Profit per Sale: " << items[i].price - items[i].o_price << endl; // "Profit: Selling Price - Original Price
            cout << "Quantity: " << items[i].quantity << endl;
            cout << endl;
        }
    }
}

void add_item()
{
    cout << "You are adding an Item" << endl;
    int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (items[i].name == "Unknown" || items[i].name == "")
        {
            index = i;
            found = true;
            break;
        }
    }
    // item_id++;
add_item:

    cout << "Enter Item Name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    items[index].name = name;
    cout << "Enter Item Original Price: ";
    double o_price;
    cin >> o_price;
    while (o_price < 0 || o_price > 1000000)
    {
        cout << "Invalid! Try Again" << endl;
        goto add_item;
    }
    items[index].o_price = o_price;
    cout << "Enter Item Selling Price: ";
    double price;
    cin >> price;
    while (price < 0 || o_price > 1000000)
    {
        cout << "Invalid! Try Again" << endl;
        goto add_item;
    }
    if (price < o_price)
    {
        cout << "Selling price cannot be less than original price. Please try again." << endl;
        goto add_item;
    }
    items[index].price = price;
    cout << "Enter Item Quantity: ";
    int quantity;
    cin >> quantity;
    while (quantity < 0 || quantity > 1000)
    {
        cout << "Invalid! Try Again" << endl;
        goto add_item;
    }
    items[index].quantity = quantity;

    cout << "Item Added Successfully!" << endl;
    save_changes();
}

void edit_item()
{
    cout << "You are editing an Item" << endl;
    cout << "Enter Item ID to edit: ";
    int id;
    cin >> id;

    if (items[id].name == "Unknown" || items[id].name == "")
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
    save_changes();
}

void delete_item()
{
    cout << "You are deleting an Item" << endl;
    cout << "Enter Item ID to delete: ";
    int id;
    cin >> id;

    if (items[id].name == "Unknown" || items[id].name == "")
    {
        cout << "Item not found. Please try again." << endl;
        return;
    }

    items[id].name = "Unknown";
    items[id].o_price = 0.0;
    items[id].price = 0.0;
    items[id].quantity = 0;

    cout << "Item Deleted Successfully!" << endl;
    save_changes();
}

void update_quantity()
{
    cout << "You are updating the quantity of an Item" << endl;
    cout << "Enter Item ID to update quantity: ";
    int id;
    cin >> id;

    if (items[id].name == "Unknown" || items[id].name == "")
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
    save_changes();
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
    while (choice < 0 || choice > 4)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

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
        cout << "------------------------------------------" << endl;
        cout << "Order ID: " << i << endl;
        cout << "Customer Name: " << orders[i].customer_username << endl;
        cout << "Total Sale Price: " << orders[i].total_sale_price << endl;
        cout << "Total Cost Price: " << orders[i].total_cost_price << endl;
        cout << "Total Profit: " << orders[i].total_sale_price - orders[i].total_cost_price << endl;
        cout << "Order Status: " << orders[i].order_status << endl;
        cout << "Order Type: " << orders[i].order_type << endl;
        cout << "Order Date: " << orders[i].order_date << endl;
        cout << "Address : " << orders[i].customer_address << endl;
        cout << "Items in Order : " << endl;
        for (int j = 0; j < 100; j++)
        {
            if (orders[i].list[j] == -1)
            {
                continue;
            }
            cout << items[orders[i].list[j]].name << endl;
        }
        cout << endl;
    }
    save_changes();
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
    cout << "Customer Name: " << orders[id].customer_username << endl;
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
    save_changes();
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
    save_changes();
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
        cout << "Customer Name: " << orders[i].customer_username << endl;
        cout << "Total Sale Price: " << orders[i].total_sale_price << endl;
        cout << "Total Cost Price: " << orders[i].total_cost_price << endl;
        cout << "Total Profit: " << orders[i].total_sale_price - orders[i].total_cost_price << endl;
        cout << "Order Status: " << orders[i].order_status << endl;
        cout << "Order Type: " << orders[i].order_type << endl;
        cout << endl;
    }
    save_changes();
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

    while (choice < 0 || choice > 2)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

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
    SYSTEMTIME t;
    GetLocalTime(&t);
    cout << "Financial Report as of " << t.wDay << "/" << t.wMonth << "/" << t.wYear << endl;
    cout << "Total Sales: " << total_sales_final << endl;
    cout << "Total Cost: " << total_cost_final << endl;
    cout << "Financial Report Generated Successfully!" << endl;
    save_changes();
}

void stock_report()
{
    cout << "Stock Report:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (items[i].name == "Unknown" || items[i].name == "")
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
    }
    cout << "Stock Report Generated Successfully! (If empty, all items are in stock or there are no items in inventory)";
    save_changes();
}
void table_management()
{
    cout << "Table Management Menu:" << endl;
    cout << " 1 -> View Tables" << endl;
    cout << " 2 -> Add Table" << endl;
    cout << " 3 -> Edit Table" << endl;
    cout << " 4 -> Delete Table" << endl;
    cout << " 5 -> Update Table" << endl;
    cout << " 0 -> Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 0 || choice > 5)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

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
    case 5:
        update_table();
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
    save_changes();
}

void update_table()
{

    int a;
    cout << "current table in system : ";
    cout << tables->capacity << endl;
    cout << "Amount of Table to be Added : ";
    cin >> a;
    tables->capacity = tables->capacity + a;
    cout << "Now total table Available : " << tables->capacity << endl;
}

void view_tables()
{
    cout << "Tables List:" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (tables[i].status == "Unknown" || tables[i].status == "")
        {
            continue;
        }
        cout << "Table No: " << tables[i].id << endl;
        cout << "Table Capacity: " << tables[i].capacity << endl;
        cout << "Table Status: " << tables[i].status << endl;
        cout << endl;
    }

    save_changes();
}

void add_table()
{
    cout << "You are adding a Table" << endl;
    int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (tables[i].status == "Unknown" || tables[i].status == "")
        {
            index = i;
            found = true;
            break;
        }
    }
add_table:

    cout << "Enter Table Capacity: ";
    int capacity;
    cin >> capacity;
    tables[index].id = index;
    tables[index].capacity = capacity;
    tables[index].status = "Available";

    cout << "Table Added Successfully!" << endl;
    save_changes();
}

void edit_table()
{
    cout << "You are editing a Table" << endl;
    cout << "Enter Table No to edit: ";
    int id;
    cin >> id;

    if (tables[id].status == "Unknown" || tables[id].status == "")
    {
        cout << "Table not found. Please try again." << endl;
        return;
    }

    cout << "Table Details:" << endl;
    cout << "Table No: " << tables[id].id << endl;
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
    save_changes();
}

void delete_table()
{
    cout << "You are deleting a Table" << endl;
    cout << "Enter Table No to delete: ";
    int id;
    cin >> id;

    if (tables[id].status == "Unknown" || tables[id].status == "")
    {
        cout << "Table not found. Please try again." << endl;
        return;
    }
    int t = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (tables[i].id == id)
        {
            t = i;
            found = true;
            break;
        }
    }
    tables[t].capacity = 0;
    tables[t].status = "Unknown";

    cout << "Table Deleted Successfully!" << endl;
    save_changes();
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
    while (choice < 0 || choice > 4)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

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
        if (staffs[i].name == "Unknown" || staffs[i].name == "")
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

    while (choice < 0 || choice > 1)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }
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
    save_changes();
}

void get_staff_details()
{
    cout << "Enter Staff ID to get details: ";
    int id;
    cin >> id;

    if (staffs[id].name == "Unknown" || staffs[id].name == "")
    {
        cout << "Staff not found. Please try again." << endl;
        return;
    }

    cout << "Staff Details:" << endl;
    cout << "Staff ID: " << id << endl;
    cout << "Name: " << staffs[id].name << endl;
    cout << "CNIC: " << staffs[id].cnic << endl;
    cout << "Phone: " << staffs[id].phone << endl;
    cout << "Email: " << staffs[id].email << endl;
    cout << "Address: " << staffs[id].address << endl;
    cout << "Role: " << staffs[id].role << endl;
    cout << "Status: " << staffs[id].status << endl;

    save_changes();
}

void add_staff()
{
    cout << "You are adding a Staff Member" << endl;
    int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (staffs[i].name == "Unknown" || staffs[i].name == "")
        {
            index = i;
            found = true;
            break;
        }
    }
add_staff:

    cout << "Enter Staff Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    staffs[index].name = name;
    cout << "Enter Staff CNIC: ";
    string cnic;
    cin >> cnic;
    staffs[index].cnic = cnic;
    cout << "Enter Staff Phone: ";
    string phone;
    cin >> phone;
    staffs[index].phone = phone;
    cout << "Enter Staff Email: ";
    string email;
    cin >> email;
    staffs[index].email = email;
    cout << "Enter Staff Address: ";
    string address;
    cin.ignore();
    getline(cin, address);
    staffs[index].address = address;
    cout << "Enter Staff Role: ";
    string role;
    cin >> role;
    staffs[index].role = role;
    cout << "Enter Staff Status: ";
    string status;
    cin >> status;
    staffs[index].status = status;

    cout << "Staff Member Added Successfully!" << endl;
    cout << "New Details:" << endl;
    cout << "Staff ID: " << index << endl;
    cout << "Name: " << staffs[index].name << endl;
    cout << "CNIC: " << staffs[index].cnic << endl;
    cout << "Phone: " << staffs[index].phone << endl;
    cout << "Email: " << staffs[index].email << endl;
    cout << "Address: " << staffs[index].address << endl;
    cout << "Role: " << staffs[index].role << endl;
    cout << "Status: " << staffs[index].status << endl;

    save_changes();
}

void edit_staff()
{
    cout << "You are editing a Staff Member" << endl;
    cout << "Enter Staff ID to edit: ";
    int id;
    cin >> id;

    if (staffs[id].name == "Unknown" || staffs[id].name == "")
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

    save_changes();
}

void delete_staff()
{
    cout << "You are deleting a Staff Member" << endl;
    cout << "Enter Staff ID to delete: ";
    int id;
    cin >> id;

    if (staffs[id].name == "Unknown" || staffs[id].name == "")
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

    save_changes();
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

    while (choice < 0 || choice > 5)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

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
        if (discounts[i].name == "Unknown" || discounts[i].name == "")
        {
            continue;
        }
        cout << "Discount ID: " << i << endl;
        cout << "Name: " << discounts[i].name << endl;
        cout << "Discount Percentage: " << discounts[i].discount << endl;
        cout << endl;
    }
    save_changes();
}

void add_discount()
{

    cout << "You are adding a Discount" << endl;
    // discount_id++;
    int index = -1;
    bool found = false;
    for (int i = 0; i < 100; i++)
    {
        if (discounts[i].name == "Unknown" || discounts[i].name == "")
        {
            index = i;
            found = true;
            break;
        }
    }
add_discount:

    cout << "Enter Discount Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    discounts[index].name = name;
    cout << "Enter Discount Percentage: ";
    double discount;
    cin >> discount;
    discounts[index].discount = discount;
    // discount_id++;
    cout << "Discount Added Successfully!" << endl;
    save_changes();
}

void edit_discount()
{
    cout << "You are editing a Discount" << endl;
    cout << "Enter Discount ID to edit: ";
    int id;
    cin >> id;

    if (discounts[id].name == "Unknown" || discounts[id].name == "")
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
    save_changes();
}

void delete_discount()
{
    cout << "You are deleting a Discount" << endl;
    cout << "Enter Discount ID to delete: ";
    int id;
    cin >> id;

    if (discounts[id].name == "Unknown" || discounts[id].name == "")
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
    save_changes();
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

    while (choice < 0 || choice > 2)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        cout << "Unread Feedbacks:" << endl;
        for (int i = 0; i < 100; i++)
        {
            if (feedbacks[i].status == "Read" || feedbacks[i].status == "Unknown" || feedbacks[i].status == "")
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
            if (feedbacks[i].status == "Unread" || feedbacks[i].status == "Unknown" || feedbacks[i].status == "")
            {
                continue;
            }
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
    save_changes();
}

void reset_to_default()
{
    double total_sales = 0.0;
    double total_profit = 0.0;

    password = "";

    save_changes();
}
void changes_view()
{

    cout << "Showing Database Tables ( Maintanance Mode !!! )" << endl;
    cout << "Password: " << password << endl;
}

// File Handling Functions

void save_changes()
{
    ofstream fout;
    fout.open("database/items.txt");

    for (int i = 0; i < 100; i++)
    {
        fout << items[i].name;
        fout << endl;
    }
    for (int i = 0; i < 100; i++)
    {
        fout << items[i].o_price;
        fout << endl;
    }
    for (int i = 0; i < 100; i++)
    {
        fout << items[i].price;
        fout << endl;
    }
    for (int i = 0; i < 100; i++)
    {
        fout << items[i].quantity;
        fout << endl;
    }

    // reading order items
    ofstream forder;
    forder.open("database/orders.txt");
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            forder << orders[i].list[j];
            forder << endl;
        }
        forder << endl;
    }

    // saving password
    ofstream fpass;
    fpass.open("database/password.txt");
    fpass << password;

    // closing files
    fout.close();
    fpass.close();
    forder.close();
}

void load_changes()
{
    ifstream fin;
    fin.open("database/items.txt");

    for (int i = 0; i < 100; i++)
    {
        getline(fin, items[i].name);
    }
    for (int i = 0; i < 100; i++)
    {
        string line;
        getline(fin, line);
        stringstream ss(line);
        ss >> items[i].o_price;
    }

    for (int i = 0; i < 100; i++)
    {
        string line;
        getline(fin, line);
        stringstream ss(line);
        ss >> items[i].price;
    }
    for (int i = 0; i < 100; i++)
    {
        string line;
        getline(fin, line);
        stringstream ss(line);
        ss >> items[i].quantity;
    }

    // loading password
    ifstream fpass;
    fpass.open("database/password.txt");
    fpass >> password;

    // loading order items
    ifstream forder;
    forder.open("database/orders.txt");
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            string line;
            getline(forder, line);
            stringstream ss(line);
            ss >> orders[i].list[j];
        }
    }

    // loading files
    fin.close();
    fpass.close();
    forder.close();
}