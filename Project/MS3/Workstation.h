// M- 3 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 12/03/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"
using namespace std;
extern deque<sdds::CustomerOrder> g_pending;
extern deque<sdds::CustomerOrder> g_completed;
extern deque<sdds::CustomerOrder> g_incomplete;
namespace sdds
{
    class Workstation : public Station
    {
        deque<CustomerOrder> m_orders;
        Workstation *m_pNextStation = nullptr;

    public:
        Workstation(const string &data);
        void fill(ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station = nullptr);
        Workstation *getNextStation() const;
        void display(ostream &os) const;
        Workstation &operator+=(CustomerOrder &&new_Order);
        bool empty() const;
    };
};
#endif