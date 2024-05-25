#include <iostream>
#include <string>
using namespace std;

void admin_menu2();
void admin()
{
admin_menu:
    cout << "Enter Password! :";
    string password;
    cin >> password;

    if (password == "admin")
    {
        cout << "Welcome Admin!" << endl;
        admin_menu2();
    }
    else
    {
        cout << "Incorrect Password!" << endl;
        goto admin_menu;
    }
}

void admin_menu2()
{
    
}