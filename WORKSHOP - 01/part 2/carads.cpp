/*************************************************************************
Workshop 1 Part - 2

Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC

Date : 18th September 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

// I taught my friend a logic of reading file, the code was not shared 
// but I am attaching the piece of code of whoes logic was shared. :)
/*
* His Info :
Name: Jill Vishant Patel
Email: jvpatel23@myseneca.ca
Student ID: 124361213
Date: 18/05/2022
*/
/*
* I helped him with following code:
 class Cars
{
    .
    .
    .
    int eofErrorSolver{};
    .
    .
    .
};
void Cars::read(std::istream& is)
{
    .
    .
    .
    .
    if (is.eof())
    {
        eofErrorSolver = 1;
    }
    else {
        eofErrorSolver = 0;
    }
    .
    .
    .
    .
}
*/

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

    void Cars::setempty() 
    {
        m_brand = nullptr;
        return;
    }

    Cars::Cars()
    {
        //a C-style null-terminated string of up to 10 characters including the null byte terminator representing the brand of the car.
        setempty();
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

    Cars::Cars(const Cars& cars)
    {
        m_brand = new char[strlen(cars.m_brand) + 1];
        strcpy(m_brand, cars.m_brand);

        strcpy(m_model, cars.m_model);

        m_year = cars.m_year;

        m_price = cars.m_price;

        m_status = cars.m_status;

        m_onPromotion = cars.m_onPromotion;
        m_specialPrice = cars.m_specialPrice;
        eofErrorSolver = cars.eofErrorSolver;
    }

    Cars& Cars::operator=(const Cars& cars) 
    {
        if (cars.m_brand)
        {
            delete[] m_brand;
            setempty();
            m_brand = new char[strlen(cars.m_brand) + 1];
            strcpy(m_brand, cars.m_brand);
        }
        else
        {
            delete[] m_brand;
            m_brand = nullptr;
        }

        strcpy(m_model, cars.m_model);

        m_year = cars.m_year;

        m_price = cars.m_price;

        m_status = cars.m_status;

        m_onPromotion = cars.m_onPromotion;
        m_specialPrice = cars.m_specialPrice;
        eofErrorSolver = cars.eofErrorSolver;

        return *this;
    }

    Cars::~Cars()
    {
        delete[] m_brand;
        setempty();
    }

    Cars::operator bool() const
    {
        bool returnValue = false;
        if (m_status == 'N')
        {
            returnValue = true;
        }
        return returnValue;
    }

    void listArgs(int argc, char* argv[])
    {
        int i;

        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        for (i = 0; i < argc; i++)
            cout << "  " << i+1 << ": " << argv[i] << endl;
        cout << "--------------------------\n";
        cout << endl;
    }

    void Cars::read(std::istream& is) 
    {  
        if (is.bad()) {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        else {

            char cString[1024]{};
            char forBool{};

            is >> m_status;
            is.ignore();

            is.getline(cString, 1024, ',');
            m_brand = new char[strlen(cString) + 1];
            strcpy(m_brand, cString);

            is.getline(m_model, 15, ',');

            is >> m_year;
            is.ignore();

            is >> m_price;
            is.ignore();

            is >> forBool;

            if (forBool == 'Y')
            {
                m_onPromotion = true;
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

    void Cars::display(bool reset)
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
                double tempP = 0.0;
                tempP = m_price;
                m_price = m_price * (1 + g_taxrate);
                if (m_onPromotion)
                {
                    double tempsp = 0.0;
                    tempsp = m_specialPrice;
                    m_specialPrice = m_price - (m_price * g_discount);
                    cout << setw(2) << left << COUNTER << ". " << setw(10) << left << m_brand << "| " << setw(15) << left << m_model << "| " << setw(1) << left << m_year << " | " << setw(11) << right << fixed << setprecision(2) << m_price << "| " << setw(11) << right << fixed << setprecision(2) << m_specialPrice << endl;
                    m_specialPrice = tempsp;
                }
                else {
                    cout << setw(2) << left << COUNTER << ". " << setw(10) << left << m_brand << "| " << setw(15) << left << m_model << "| " << setw(1) << left << m_year << " | " << setw(11) << right << fixed << setprecision(2) << m_price << "|" << endl;
                }
                m_price = tempP;
            }
            COUNTER++;
        }
    }

    char Cars::getStatus() const
    {
        return m_status;
    }

    istream& operator>>(istream& is, Cars& cars)
    {
        cars.read(is);
        return is;
    }

    void operator>>(const Cars& car1, Cars& car2)
    {
        car2 = car1;

        return;
    }
}
