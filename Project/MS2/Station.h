// M- 2 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 11/26/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds
{
  class Station
  {
    int m_id{0};
    std::string m_name{""};
    std::string m_desc{""};
    size_t m_serial_num{0u};
    size_t m_curr_items{0u};
    static size_t widthF;
    static size_t countID;

  public:
    Station(const std::string &src);
    const std::string &getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream &os, bool full) const;
  };
}
#endif // !SDDS_STATION_H