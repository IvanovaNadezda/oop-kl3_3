//
// Created by inade on 28.05.2022.
//

#include "Cl_app.h"
#include "ClBase.h"
#include "Cl2.h"
#include "Cl3.h"
#include "Cl4.h"
#include "Cl5.h"
#include "Cl6.h"

void Cl_app::signal(string &str)
{
    cout << endl << "Signal from " << getPath();
    str=str+ " (class: 1)";
}

void Cl2::signal(string &str)
{
    cout << endl << "Signal from " << getPath();
    str=str+ " (class: 2)";
}


void Cl3::signal(string &str)
{
    cout << endl << "Signal from " << getPath();
    str=str+ " (class: 3)";
}

void Cl4::signal(string &str)
{
    cout << endl << "Signal from " << getPath();
    str=str+ " (class: 4)";
}

void Cl5::signal(string &str)
{
    cout << endl << "Signal from " << getPath();
    str=str+ " (class: 5)";
}

void Cl6::signal(string &str)
{
    cout << endl << "Signal from " << getPath();
    str=str+ " (class: 6)";
}

void Cl_app::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}

void Cl1::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}

void Cl2::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}

void Cl3::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}

void Cl4::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}

void Cl5::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}

void Cl6::handler(string str)
{
    cout << endl << "Signal to " << getPath() << " Text: " << str;
}