// M- 3 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 12/03/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H
#include <string>
using namespace std; 
namespace sdds
{
    class Station
    {
        int id;
        string name;
        string desc;
        unsigned int nextSerialNo;
        unsigned int noItems;
        static size_t m_widthField;
        static int id_generator;

    public:
        Station(const string &record);
        const string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(ostream &os, bool full) const;
    };
};

#endif
