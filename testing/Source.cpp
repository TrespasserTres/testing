#include "Header.h"
#include <string>


void User::setLogin(string log)
{
    Login = log;
}

void User::setPassword(string pas)
{
    Password = pas;
}

void User::displayUser()
{
    cout << "Login - " << Login << endl;
    cout << "Password - " << Password << endl;
}

string User::getLogin()
{
    return Login;
}

string User::getPassword()
{
    return Password;
}

void User::getmessage(short a, short b)
{
    if (b == 0)
    {
        cout << "No message from this user" << endl;
    }
    else if (b > 0)
    {
        for (short i = 0; i < b; i++)
        {
            cout << User::mail[a][i] << endl;
        }
    }
}