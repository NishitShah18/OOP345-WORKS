// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email:
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;

    Station::Station(const std::string &src)
    {
        Utilities util;
        m_stationId = ++Station::id_generator;
        bool more = true;
        size_t pos = 0u;
        try
        {
            m_itemName = util.extractToken(src, pos, more);
            m_serialNum = stoi(util.extractToken(src, pos, more));
            m_numOfItems = stoi(util.extractToken(src, pos, more));
            Station::m_widthField = max(util.getFieldWidth(), Station::m_widthField);
            m_desc = util.extractToken(src, pos, more);
        }
        catch (std::string err)
        {
            cout << err;
        }
    }
    const std::string &Station::getItemName() const
    {
        return m_itemName;
    }
    size_t Station::getNextSerialNumber()
    {
        ++m_serialNum;
        return m_serialNum - 1;
    }
    size_t Station::getQuantity() const
    {
        return m_numOfItems;
    }
    void Station::updateQuantity()
    {
        m_numOfItems == 0 ? m_numOfItems = 0 : --m_numOfItems;
    }
    void Station::display(std::ostream &os, bool full) const
    {
        os << setw(3) << setfill('0') << m_stationId << " | ";
        os << left << setw(Station::m_widthField + 1) << setfill(' ') << m_itemName << " | ";
        os << right << setw(6) << setfill('0') << m_serialNum << " | ";
        if (full)
        {
            os << right << setw(4) << setfill(' ') << m_numOfItems << " | ";
            string desc = m_desc;
            while (desc[0] == ' ')
            {
                desc.erase(0, 1);
            }

            os << desc << endl;
        }
        else
        {
            os << endl;
        }
    }
}