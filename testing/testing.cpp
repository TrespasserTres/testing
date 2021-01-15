#include<iostream>
#include <string>
#include "Header.h"
using namespace std;
#pragma runtime_checks( "", off )
#pragma warning( push )
#pragma warning( disable : 4700 )

int main()
{
    User* First = new User();  // Создание пользователя 1
    User* Second = new User(); // Создание пользователя 2
    User* Third = new User();  // Создание пользователя 3
    string a;                  // Переменная для создания Логина
    string b;                  // Переменная для создания Пароля
    short c;                   // Переменная для меню
    short d = 0;               // счетчик пользователей
    string logent;                  // Переменная ввод Логина
    string f;                  // Переменная ввод Пароля
    bool y = true;             // Переменная выхода из программы
    bool x = true;             // Переменная выхода из чата
    string mes;                // Сообщения
    short i = 0;               // Счетчик сообщений для пользователя 1
    short j = 0;               // Счетчик сообщений для пользователя 2
    short q = 0;               // Счетчик сообщений для пользователя 3
    while (y == true)
    {
        cout << "1 - Create user / 2 - Enter chat / 3 - Exit program / 4 - HELP" << endl;
        cin >> c;
        switch (c)
        {
        case 1:                                                            //Регистрация пользователей
            cout << d << endl;
            if (d == 0)
            {
                cout << "Enter login: " << endl;                           //Запрос логина для первого пользователя
                cin >> a;
                cout << "Enter Password: " << endl;                        //Запрос пароля для первого пользователя
                cin >> b;
                First->setLogin(a);
                First->setPassword(b);
                d++;
            }
            else if (d == 1)
            {
                cout << "Enter login: " << endl;                           //Запрос логина для второго пользователя
                cin >> a;
                if (a == First->getLogin())                                //Проверка свободного логина
                {
                    cout << "This name is buisy " << endl;
                }
                else
                {
                    cout << "Enter Password: " << endl;                    //Запрос пароля для второго пользователя
                    cin >> b;
                    Second->setLogin(a);
                    Second->setPassword(b);
                    d++;
                }
            }
            else if (d == 2)
            {
                cout << "Enter login: " << endl;                           //Запрос логина для третьего пользователя
                cin >> a;
                if ((a == First->getLogin()) || (a == Second->getLogin())) //Проверка свободного логина
                {
                    cout << "The name is buisy " << endl;
                }
                else
                {
                    cout << "Enter Password: " << endl;                    //Запрос пароля для третьего пользователя
                    cin >> b;
                    Third->setLogin(a);
                    Third->setPassword(b);
                    d++;
                }
            }
            else cout << "Too many users" << endl;
            break;
        case 2:                                                            //Вход в Чат
            cout << "Enter login: " << endl;                               //Ввод логина
            cin >> logent;
            cout << "Enter password: " << endl;                            //Ввод пароля
            cin >> f;
            if (((logent == First->getLogin()) && (f == First->getPassword())) ||      //Проверка логина и пароля
                ((logent == Second->getLogin()) && (f == Second->getPassword())) ||
                ((logent == Third->getLogin()) && (f == Third->getPassword())))
            {
                cout << "Welcome to chat" << endl;
                bool x = true;
                while (x == true)
                {
                    cout << "1 - Check messages / 2 - Write a message / 3 Exit chat " << endl;
                    cin >> c;
                    switch (c)
                    {
                    case 1:                                                //Проверка сообщений от пользователя 2
                        if (logent == First->getLogin())
                        {
                            cout << "Your message from " << Second->getLogin() << endl;
                            Second->getmessage(2, j);
                        }
                        break;
                    case 2:
                        if (d == 1)                                         //Отправка сообщений 1 пользователь
                        {
                            cout << "No mo Users in chat" << endl;
                        }
                        else if (d == 2)                                    //Отправка сообщений 2 пользователя
                        {
                            if (logent == First->getLogin())
                            {
                                cout << "send message user name " << Second->getLogin() << endl;
                                getline(cin, mes);
                                Second->mail[1][i] = mes;
                                i++;
                            }
                            if (logent == Second->getLogin())
                            {
                                cout << "send message user name " << First->getLogin() << endl;
                                getline(cin, mes);
                                First->mail[2][j] = mes;
                                j++;
                            }
                        }
                        break;
                    case 3:                                                //Выход из Чата
                        x = false;
                        break;
                    }
                }
            }
            else cout << "Wrong Login or Password " << endl;
            break;
        case 3:
            y = false;
            break;
        case 4:
            if (d > 0)
            {
                First->displayUser();
            }
            if (d > 1)
            {
                Second->displayUser();
            }
            if (d > 2)
            {
                Third->displayUser();
            }
        }
        cout << endl;
    }
    delete First;
    delete Second;
    delete Third;
    return 0;
}