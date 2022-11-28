// M- 2 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 11/26/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
  // default constructor to intialize class variables to the 0
  size_t Station::widthF = 0u;
  size_t Station::countID = 0u;
  // Station::Station(const std::string &src)
  // {
  //   Utilities util;
  //   bool more = true;
  //   size_t next_pos = 0u;
  //   try
  //   {
  //     m_id = stoi(util.extractToken(src, next_pos, more));
  //     m_name = util.extractToken(src, next_pos, more);
  //     m_desc = util.extractToken(src, next_pos, more);
  //     m_serial_num = stoi(util.extractToken(src, next_pos, more));
  //     m_curr_items = stoi(util.extractToken(src, next_pos, more));
  //     widthF = max(widthF, m_name.length());
  //     countID++;
  //   }
  //   catch (const char *msg)
  //   {
  //     cout << msg;
  //   }
  // }
  Station::Station(const std::string &src)
  {
    Utilities util;
    m_id = ++Station::countID;
    bool more = true;
    size_t pos = 0u;

    try
    {
      m_name = util.extractToken(src, pos, more);
      m_serial_num = stoi(util.extractToken(src, pos, more));
      m_curr_items = stoi(util.extractToken(src, pos, more));
      Station::widthF = max(util.getFieldWidth(), Station::widthF);
      m_desc = util.extractToken(src, pos, more);
    }
    catch (std::string err)
    {
      cout << err;
    }
    // while(more) {
    //   m_desc += " " + util.extractToken(src, pos, more);
    // }
  }

  const std::string &Station::getItemName() const
  {
    return m_name;
  }

  size_t Station::getNextSerialNumber()
  {
    ++m_serial_num;
    return m_serial_num - 1;
  }

  size_t Station::getQuantity() const
  {
    return m_curr_items;
  }

  void Station::updateQuantity()
  {
    m_curr_items == 0 ? m_curr_items = 0 : --m_curr_items;
  }

  void Station::display(std::ostream &os, bool full) const
  {
    // os << "[" << right << setw(3) << setfill('0') << m_id << "]";
    // os << " Item: " << left << setw(Station::widthF) << setfill(' ') << m_name;
    // os << " [" << right << setw(6) << setfill('0') << m_serial_num << "]";
    /*

            001 | Armchair        | 654321 |
            002 | Bed             | 123456 |
            003 | Dresser         | 056789 |
            004 | Nighttable      | 000887 |
            005 | Filing Cabinet  | 987654 |
            006 | Office Chair    | 147852 |
            007 | Bookcase        | 000987 |
            008 | Desk            | 459214 |
    */
    os << setw(3) << setfill('0') << m_id << " | ";
    os << left << setw(Station::widthF) << setfill(' ') << m_name << " | ";
    os << right << setw(6) << setfill('0') << m_serial_num << " | ";

    if (full)
    {
      /*

                  001 | Armchair        | 654321 |   10 | Upholstered Wing Chair
                  002 | Bed             | 123456 |    5 | Queen size bed with headboard
                  003 | Dresser         | 056789 |    7 | 6-Drawer Unit
                  004 | Nighttable      | 000887 |    5 | Nightstand with 2 drawers
                  005 | Filing Cabinet  | 987654 |    5 | 3-drawer filing cabinet
                  006 | Office Chair    | 147852 |   20 | High-back carpet-rollers
                  007 | Bookcase        | 000987 |    5 | 5-shelf open bookcase
                  008 | Desk            | 459214 |    2 | 6-foot worktable
      */
      os << right << setw(4) << setfill(' ') << m_curr_items << " | ";
      // remove white space from the beginning and end of the string
      string desc = m_desc;
      while (desc[0] == ' ')
      {
        desc.erase(0, 1);
      }

      os << desc << endl;
    }

    else
      os << endl;
  }
}