           index = i;
            found = true;
            break;
        }

        cout << "Enter your password: ";
        string password;
        cin.ignore();
        getline(cin, password);

        if (customers[index].password == password)
        {
            cout << "Sign In Successful!" << endl;
        }
        else
        {
            cout << "Incorrect Password! Please try again." << endl;
            sign_in();
        }
    }
}