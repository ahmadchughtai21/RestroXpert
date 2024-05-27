#include "classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <windows.h>
#include <fstream>



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

      for(int i=0;i<=100;i++){
       cout << "Enter Your Address ...."<< endl;
       cout << "House No : ";
       cin.ignore();
       getline(cin,addresses[i].house_no);
       cout << "street : ";
       getline(cin,addresses[i].street);
       cout << "city : ";
       getline(cin,addresses[i].city);
       cout << "Country : ";
       getline(cin,addresses[i].country);
       
      }
    }
    void dining(){
       cout << "dining";

       display_menu();
    }

    void display_menu(){
    
    }
 




