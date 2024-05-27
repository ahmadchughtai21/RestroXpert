<<<<<<< HEAD
#include "classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

 using namespace std;
 
 void delivery();
 void dining();
 void display_menu();

 void order(){
    order:
    int choice;
    cout << "Welcome.... "<< endl<< endl << "For Delivery select 1 .... "<< endl<< "For Dining select 2 .... "<<endl;
    cout  << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){

        case 1:
           delivery();
           break;
        case 2:
           dining();
           break;
        case 0:
           return;
        default:
          cout << "Invalid choice! Please try again." << endl;
            goto order; 
      }
    }
 
    void delivery(){
       cout << "delivery";

       display_menu();
       
    }
    void dining(){
       cout << "dining";

       display_menu();
    }

    void display_menu(){
    
    }
 




