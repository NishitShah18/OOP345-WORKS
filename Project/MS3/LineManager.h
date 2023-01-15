// M- 3 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 12/03/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H
#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"
using namespace std;
namespace sdds
{
    class LineManager
    {
        vector<Workstation *> m_active_Line;
        size_t m_cntCustomer_Order;
        Workstation *m_first_Station;

    public:
        LineManager(const string &file, const vector<Workstation *> &stations);
        void reorderStations();
        bool run(ostream &os);
        void display(ostream &os) const;
    };
};

#endif
