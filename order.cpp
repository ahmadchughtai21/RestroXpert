




// 1. Home Delivery //Address
// 2. Dine in //











// // #include "classes.h"
// // #include <iostream>
// // #include <vector>
// // #include <string>
// // #include <map>
// // #include <iomanip>

// // using namespace std;

// // struct Item
// // {
// //     string name = "Unknown";
// //     double o_price = 0.0;
// //     double price = 0.0;
// //     int quantity = 0;
// // };

// // struct Order
// // {
// //     string customer_name;
// //     double total_sale_price = 0.0;
// //     double total_cost_price = 0.0;
// //     string order_status = "Nill";
// //     string order_type;
// // };

// // Item items[100];
// // Order orders[100];
// // int item_id = -1; // To track item IDs

// // struct OrderItem
// // {
// //     string name;
// //     int quantity;
// //     double totalPrice;
// // };

// // class OrderingSystem
// // {
// // private:
// //     map<string, double> menu;
// //     vector<OrderItem> order;

// // public:
// //     OrderingSystem()
// //     {
// //         // Initialize the menu with the provided items
// //         menu["tikka pizza"] = 10.99;
// //         menu["supreme pizza"] = 9.99;
// //         menu["fajita pizza"] = 8.99;
// //         menu["burger"] = 5.99;
// //         menu["pepsi"] = 2.99;
// //         menu["coke"] = 2.99;
// //         menu["shawarma"] = 5.99;
// //         menu["water"] = 1.99;
// //         menu["doner"] = 4.99;
// //         menu["tacos"] = 12.99;
// //         menu["chocolate and brownie"] = 7.99;
// //         menu["sandwich"] = 3.99;
// //         menu["grilled chicken"] = 15.99;
// //         menu["fish"] = 15.99;
// //         menu["fries"] = 5.99;
// //         menu["loaded fries"] = 9.99;
// //         menu["bbq"] = 15.99;
// //         menu["ice cream"] = 2.99;
// //     }

// //     void displayMenu() const
// //     {
// //         cout << "Menu:\n";
// //         for (const auto &item : menu)
// //         {
// //             cout << setw(20) << left << item.first << " - $" << fixed << setprecision(2) << item.second << "\n";
// //         }
// //     }

// //     void addItemToOrder(const string &itemName, int quantity)
// //     {
// //         if (menu.find(itemName) != menu.end())
// //         {
// //             double itemPrice = menu[itemName];
// //             order.push_back({itemName, quantity, itemPrice * quantity});
// //             cout << "Added " << quantity << " of " << itemName << " to the order.\n";
// //         }
// //         else
// //         {
// //             cout << "Item not found in the menu.\n";
// //         }
// //     }

// //     void displayOrder() const
// //     {
// //         cout << "Current Order:\n";
// //         double totalCost = 0;
// //         for (const auto &item : order)
// //         {
// //             cout << "Item: " << item.name << ", Quantity: " << item.quantity << ", Total Price: $" << fixed << setprecision(2) << item.totalPrice << "\n";
// //             totalCost += item.totalPrice;
// //         }
// //         cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << "\n";
// //     }

// //     void checkout()
// //     {
// //         cout << "Checking out...\n";
// //         displayOrder();
// //         // Process payment logic here
// //         cout << "Payment processed.\n";
// //         order.clear();
// //     }
// // };

// // // Function declarations
// // void view_inventory();
// // void add_item();
// // void edit_item();
// // void delete_item();
// // void update_quantity();
// // void order_management();
// // void view_orders();
// // void edit_order_status();
// // void cancel_order();
// // void view_cancelled_orders();

// // // Main function
// // int main()
// // {
// //     OrderingSystem os;
// //     int choice;

// //     do
// //     {
// //         cout << "\nMain Menu:\n";
// //         cout << "1. Display Menu\n";
// //         cout << "2. Add Item to Order\n";
// //         cout << "3. Display Current Order\n";
// //         cout << "4. Checkout\n";
// //         cout << "5. Admin Menu\n";
// //         cout << "6. Exit\n";
// //         cout << "Enter your choice: ";
// //         cin >> choice;

// //         switch (choice)
// //         {
// //         case 1:
// //             os.displayMenu();
// //             break;
// //         case 2:
// //         {
// //             string itemName;
// //             int quantity;
// //             cout << "Enter item name: ";
// //             cin.ignore();
// //             getline(cin, itemName);
// //             cout << "Enter quantity: ";
// //             cin >> quantity;
// //             os.addItemToOrder(itemName, quantity);
// //             break;
// //         }
// //         case 3:
// //             os.displayOrder();
// //             break;
// //         case 4:
// //             os.checkout();
// //             break;
// //         case 5:
// //             int adminChoice;
// //             cout << "\nAdmin Menu:\n";
// //             cout << "1. View Inventory\n";
// //             cout << "2. Add Item\n";
// //             cout << "3. Edit Item\n";
// //             cout << "4. Delete Item\n";
// //             cout << "5. Update Quantity\n";
// //             cout << "6. Order Management\n";
// //             cout << "0. Back to Main Menu\n";
// //             cout << "Enter your choice: ";
// //             cin >> adminChoice;

// //             switch (adminChoice)
// //             {
// //             case 1:
// //                 view_inventory();
// //                 break;
// //             case 2:
// //                 add_item();
// //                 break;
// //             case 3:
// //                 edit_item();
// //                 break;
// //             case 4:
// //                 delete_item();
// //                 break;
// //             case 5:
// //                 update_quantity();
// //                 break;
// //             case 6:
// //                 order_management();
// //                 break;
// //             case 0:
// //                 break;
// //             default:
// //                 cout << "Invalid choice. Please try again.\n";
// //             }
// //             break;
// //         case 6:
// //             cout << "Exiting the program.\n";
// //             break;
// //         default:
// //             cout << "Invalid choice. Please try again.\n";
// //         }
// //     } while (choice != 6);

// //     return 0;
// // }

// // // Function definitions
// // void view_inventory()
// // {
// //     cout << "Inventory List:\n";
// //     for (int i = 0; i < 100; i++)
// //     {
// //         if (items[i].name == "Unknown")
// //         {
// //             continue;
// //         }
// //         cout << "Item ID: " << i << "\n";
// //         cout << "Name: " << items[i].name << "\n";
// //         cout << "Original Price: " << items[i].o_price << "\n";
// //         cout << "Selling Price: " << items[i].price << "\n";
// //         cout << "Profit per Sale: " << items[i].price - items[i].o_price << "\n";
// //         cout << "Quantity: " << items[i].quantity << "\n\n";
// //     }
// // }

// // void add_item()
// // {
// //     cout << "You are adding an Item\n";
// //     item_id++;
// // add_item:
// //     cout << "Enter Item Name: ";
// //     cin.ignore();
// //     string name;
// //     getline(cin, name);

// //     items[item_id].name = name;
// //     cout << "Enter Item Original Price: ";
// //     double o_price;
// //     cin >> o_price;
// //     items[item_id].o_price = o_price;
// //     cout << "Enter Item Selling Price: ";
// //     double price;
// //     cin >> price;
// //     if (price < o_price)
// //     {
// //         cout << "Selling price cannot be less than original price. Please try again.\n";
// //         goto add_item;
// //     }
// //     items[item_id].price = price;
// //     cout << "Enter Item Quantity: ";
// //     int quantity;
// //     cin >> quantity;
// //     items[item_id].quantity = quantity;
// // }

// // void edit_item()
// // {
// //     cout << "You are editing an Item\n";
// //     cout << "Enter Item ID to edit: ";
// //     int id;
// //     cin >> id;

// //     if (items[id].name == "Unknown")
// //     {
// //         cout << "Item not found. Please try again.\n";
// //         return;
// //     }

// //     cout << "Item Details:\n";
// //     cout << "Name: " << items[id].name << "\n";
// //     cout << "Original Price: " << items[id].o_price << "\n";
// //     cout << "Selling Price: " << items[id].price << "\n";
// //     cout << "Quantity: " << items[id].quantity << "\n";

// //     cout << "Enter new details for this item:\n";

// //     cout << "Enter Item Name: ";
// //     cin.ignore();
// //     string name;
// //     getline(cin, name);
// //     items[id].name = name;
// //     cout << "Enter Item Original Price: ";
// //     double o_price;
// //     cin >> o_price;
// //     items[id].o_price = o_price;
// //     cout << "Enter Item Selling Price: ";
// //     double price;
// //     cin >> price;
// //     if (price < o_price)
// //     {
// //         cout << "Selling price cannot be less than original price. Please try again.\n";
// //         return;
// //     }
// //     items[id].price = price;
// //     cout << "Enter Item Quantity: ";
// //     int quantity;
// //     cin >> quantity;
// //     items[id].quantity = quantity;
// //     cout << "Item Updated Successfully!\n";
// // }

// // void delete_item()
// // {
// //     cout << "You are deleting an Item\n";
// //     cout << "Enter Item ID to delete: ";
// //     int id;
// //     cin >> id;

// //     if (items[id].name == "Unknown")
// //     {
// //         cout << "Item not found. Please try again.\n";
// //         return;
// //     }

// //     items[id].name = "Unknown";
// //     items[id].o_price = 0.0;
// //     items[id].price = 0.0;
// //     items[id].quantity = 0;

// //     cout << "Item Deleted Successfully!\n";
// // }

// // void update_quantity()
// // {
// //     cout << "You are updating the quantity of an Item\n";
// //     cout << "Enter Item ID to update quantity: ";
// //     int id;
// //     cin >> id;

// //     if (items[id].name == "Unknown")
// //     {
// //         cout << "Item not found. Please try again.\n";
// //         return;
// //     }

// //     cout << "Item Details:\n";
// //     cout << "Name: " << items[id].name << "\n";
// //     cout << "Original Price: " << items[id].o_price << "\n";
// //     cout << "Selling Price: " << items[id].price << "\n";
// //     cout << "Quantity: " << items[id].quantity << "\n";

// //     cout << "Enter new quantity for this item:\n";
// //     int quantity;
// //     cin >> quantity;
// //     items[id].quantity = quantity;
// //     cout << "Quantity Updated Successfully!\n";
// // }

// // void order_management()
// // {
// //     cout << "Order Management Menu:\n";
// //     cout << "1 -> View Orders\n";
// //     cout << "2 -> Edit Order Status\n";
// //     cout << "3 -> Cancel Order\n";
// //     cout << "4 -> View Cancelled Orders\n";
// //     cout << "0 -> Exit\n";

// //     int choice;
// //     cout << "Enter your choice: ";
// //     cin >> choice;

// //     switch (choice)
// //     {
// //     case 1:
// //         view_orders();
// //         break;
// //     case 2:
// //         edit_order_status();
// //         break;
// //     case 3:
// //         cancel_order();
// //         break;
// //     case 4:
// //         view_cancelled_orders();
// //         break;
// //     case 0:
// //         return;
// //     default:
// //         cout << "Invalid choice! Please try again.\n";
// //         break;
// //     }
// // }

// // void view_orders()
// // {
// //     cout << "Orders List:\n";
// //     for (int i = 0; i < 100; i++)
// //     {
// //         if (orders[i].order_status == "Nill" || orders[i].order_status == "Cancelled")
// //         {
// //             continue;
// //         }
// //         cout << "Order ID: " << i << "\n";
// //         cout << "Customer Name: " << orders[i].customer_name << "\n";
// //         cout << "Total Sale Price: " << orders[i].total_sale_price << "\n";
// //         cout << "Total Cost Price: " << orders[i].total_cost_price << "\n";
// //         cout << "Total Profit: " << orders[i].total_sale_price - orders[i].total_cost_price << "\n";
// //         cout << "Order Status: " << orders[i].order_status << "\n";
// //         cout << "Order Type: " << orders[i].order_type << "\n\n";
// //     }
// // }

// // void edit_order_status()
// // {
// //     cout << "You are editing the status of an Order\n";
// //     cout << "Enter Order ID to edit status: ";
// //     int id;
// //     cin >> id;

// //     if (orders[id].order_status == "Nill" || orders[id].order_status == "Cancelled")
// //     {
// //         cout << "Order not found. Please try again.\n";
// //         return;
// //     }

// //     cout << "Order Details:\n";
// //     cout << "Customer Name: " << orders[id].customer_name << "\n";
// //     cout << "Total Sale Price: " << orders[id].total_sale_price << "\n";
// //     cout << "Total Cost Price: " << orders[id].total_cost_price << "\n";
// //     cout << "Total Profit: " << orders[id].total_sale_price - orders[id].total_cost_price << "\n";
// //     cout << "Order Status: " << orders[id].order_status << "\n";
// //     cout << "Order Type: " << orders[id].order_type << "\n";

// //     cout << "Enter new status for this order (Completed/Cancelled): ";
// //     string status;
// //     cin.ignore();
// //     getline(cin, status);
// //     orders[id].order_status = status;
// //     cout << "Order Status Updated Successfully!\n";
// // }

// // void cancel_order()
// // {
// //     cout << "You are cancelling an Order\n";
// //     cout << "Enter Order ID to cancel: ";
// //     int id;
// //     cin >> id;

// //     if (orders[id].order_status == "Nill" || orders[id].order_status == "Cancelled")
// //     {
// //         cout << "Order not found or already cancelled. Please try again.\n";
// //         return;
// //     }

// //     orders[id].order_status = "Cancelled";
// //     cout << "Order Cancelled Successfully!\n";
// // }

// // void view_cancelled_orders()
// // {
// //     cout << "Cancelled Orders List:\n";
// //     for (int i = 0; i < 100; i++)
// //     {
// //         if (orders[i].order_status != "Cancelled")
// //         {
// //             continue;
// //         }
// //         cout << "Order ID: " << i << "\n";
// //         cout << "Customer Name: " << orders[i].customer_name << "\n";
// //         cout << "Total Sale Price: " << orders[i].total_sale_price << "\n";
// //         cout << "Total Cost Price: " << orders[i].total_cost_price << "\n";
// //         cout << "Total Profit: " << orders[i].total_sale_price - orders[i].total_cost_price << "\n";
// //         cout << "Order Status: " << orders[i].order_status << "\n";
// //         cout << "Order Type: " << orders[i].order_type << "\n\n";
// //     }
// // }
