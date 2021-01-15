#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    string mail[3][10]{ {"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty"}, {"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty"}, {"Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty","Empty"} };
    void setLogin(string log);
    void setPassword(string pass);
    void displayUser();
    string getLogin();
    string getPassword();
    void getmessage(short a, short b);
private:
    string Login;
    string Password;
};