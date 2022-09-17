/*************************************************************************
Workshop 1 Part - 1

Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC

Date : 17th September 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#include <iostream>
#include "carads.h"

using namespace std;

double g_taxrate = 0.13;
double g_discount = 0.15;

namespace sdds {
    
    void listArgs(int argc, char** argv)
    {
        cout << "Command Line:\n--------------------------\n";
        cout << "  1: ws\n";
        for (int i = 1; i < argc; i++)
        {
            cout << "  " << i + 1 << ": " << argv[i] << endl;
        }
        cout << "--------------------------\n";
        cout << endl;
    }


}
