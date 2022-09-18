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
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
double g_taxrate = 0;
double g_discount = 0;

#include "carads.h"

using namespace std;
namespace sdds
{
    static int COUNTER = 1;

    Cars::Cars()
    {
        //a C-style null-terminated string of up to 10 characters including the null byte terminator representing the brand of the car.
        strcpy(m_brand, "\0");
        //a C-style null-terminated string of up to 15 characters including the null byte terminator representing the model of the car.
        strcpy(m_model, "\0");
        //the manufacture year of the car.
        m_year = 0;
        //the price of the car represented by a double value.
        m_price = 0.0;
        //the status of the cars as used or new using a single character(holds N or U)
        m_status = 'U';
        //a boolean flag indicating whether or not the car is on promotion discount
        m_onPromotion = false;
        m_specialPrice = 0.0;
        eofErrorSolver = 0;
    }

    void listArgs(int argc, char* argv[])
    {
        int i;

        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        for (i = 0; i < argc; i++)
            std::cout << i+1 << ": " << argv[i] << std::endl;
        cout << "--------------------------\n";
        cout << endl;
    }

    void Cars::read(std::istream& is) {
       
        if (is.bad()) {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        else {
            char forBool{};
            is >> m_status;
            is.ignore();
            is.getline(m_brand, 10, ',');
            is.getline(m_model, 15, ',');
            is >> m_year;
            is.ignore();
            is >> m_price;
            is.ignore();
            is >> forBool;

            m_price = m_price * (1 + g_taxrate);
            if (forBool == 'Y')
            {
                m_onPromotion = true;
                m_specialPrice = m_price - (m_price * g_discount);
            }
            else
            {
                m_onPromotion = false;
            }
        }
        if (is.eof())
        {
            eofErrorSolver = 1;
        } 
        else {
            eofErrorSolver = 0;
        }
    }

    void Cars::display(bool reset) const
    {
        if (reset != 0)
        {
            COUNTER = 1;
        }
        if (eofErrorSolver != 1) {
            if (m_status == '\0') {
                cout << COUNTER << " . No Car" << endl;
            }
            else {
                if (m_onPromotion)
                {
                    cout << setw(2) << left << COUNTER << ". " << setw(10) << left << m_brand << "| " << setw(15) << left << m_model << "| " << setw(1) << left << m_year << " | " << setw(11) << right << fixed << setprecision(2) << m_price << "| " << setw(11) << right << fixed << setprecision(2) << m_specialPrice << endl;

                }
                else {
                    cout << setw(2) << left << COUNTER << ". " << setw(10) << left << m_brand << "| " << setw(15) << left << m_model << "| " << setw(1) << left << m_year << " | " << setw(11) << right << fixed << setprecision(2) << m_price << "|" << endl;
                }
            }
            COUNTER++;
        }
    }

    char Cars::getStatus() const
    {
        return m_status;
    }

}