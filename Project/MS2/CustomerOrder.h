// M- 2 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 11/26/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include "Station.h"

namespace sdds
{
  struct Item
  {
    std::string m_itemName;
    size_t m_serialNumber{0};
    bool m_isFilled{false};

    Item(const std::string &src) : m_itemName(src){};
  };

  class CustomerOrder
  {
    std::string m_name{""};
    std::string m_product{""};
    size_t m_cntItem{0u};
    Item **m_lstItem{nullptr};
    static size_t m_widthField;

  public:
    CustomerOrder(){};
    CustomerOrder(const std::string &src);
    CustomerOrder(const CustomerOrder &src);
    CustomerOrder &operator=(const CustomerOrder &src) = delete;
    CustomerOrder(CustomerOrder &&src) noexcept;
    CustomerOrder &operator=(CustomerOrder &&src) noexcept;
    ~CustomerOrder();
    bool isOrderFilled() const;
    bool isItemFilled(const std::string &itemName) const;
    void fillItem(Station &station, std::ostream &os);
    void display(std::ostream &os) const;
  };
}
#endif