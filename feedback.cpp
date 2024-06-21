#include <iostream>
#include <string>
#include <windows.h>
#include "classes.h"

SYSTEMTIME f;

void give_feedback();

void feedback_panel()
{
    cout << "Feedback Panel" << endl;
    cout << "1. Give Feedback" << endl;
    cout << "2. Back" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        give_feedback();
        break;
    case 2:
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return;
}

void give_feedback()
{
    cout << "Give Feedback" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (feedbacks[i].status == "Read" || feedbacks[i].status == "Unread")
        {
            continue;
        }

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, feedbacks[i].customer_name);
        cout << "Rate us (1-5): ";
        cin >> feedbacks[i].stars;
        cout << "Enter your feedback: ";
        string comments;
        cin.ignore();
        getline(cin, comments);
        feedbacks[i].comments = comments;
        GetLocalTime(&f);
        feedbacks[i].date = to_string(f.wDay) + "/" + to_string(f.wMonth) + "/" + to_string(f.wYear);
        feedbacks[i].status = "Unread";
        cout << "Feedback submitted successfully!" << endl;
        main_menu();
    }
}