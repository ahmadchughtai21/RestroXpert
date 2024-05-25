#include <iostream>
#include <string>
// #include "program.cpp"
using namespace std;

void admin()
{
    cout << "Enter Password! :";
    string password;
    cin >> password;

    if (password == "admin")
    {
        cout << "Welcome Admin!" << endl;
    }
    else
    {
        cout << "Incorrect Password!" << endl;
    }
}