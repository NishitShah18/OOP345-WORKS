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
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
  size_t CustomerOrder::m_widthField = 0u;

  CustomerOrder::CustomerOrder(const std::string &src)
  {
    Utilities util;
    bool more = true;
    size_t pos = 0u;
    size_t idx = 0u;

    try
    {
      m_name = util.extractToken(src, pos, more);
      // remove space at the beginning of the string
      m_name.erase(0, m_name.find_first_not_of(' '));
      // remove space at the end of the string
      m_name.erase(m_name.find_last_not_of(' ') + 1);

      m_product = util.extractToken(src, pos, more);
      // remove space at the beginning of the product name
      m_product.erase(0, m_product.find_first_not_of(' '));
      // remove space at the end of the product name
      m_product.erase(m_product.find_last_not_of(' ') + 1);

      m_cntItem = std::count(src.begin(), src.end(), util.getDelimiter()) - 1;

      if (m_cntItem)
        m_lstItem = new Item *[m_cntItem];

      while (more && m_cntItem)
      {
        m_lstItem[idx] = new Item(util.extractToken(src, pos, more));
        ++idx;
      }

      CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
    }
    catch (std::string err)
    {
      cout << err;
    }
    // else {
    //   m_lstItem = nullptr;
    // }
  }

  CustomerOrder::CustomerOrder(const CustomerOrder &src)
  {
    throw false;
  }

  CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept
  {
    *this = std::move(src);
  }

  CustomerOrder &CustomerOrder::operator=(CustomerOrder &&src) noexcept
  {
    if (this != &src)
    {
      if (m_lstItem)
      {
        for (auto i = 0u; i < m_cntItem; ++i)
          delete m_lstItem[i];

        delete[] m_lstItem;
      }

      m_name = src.m_name;
      m_product = src.m_product;
      m_cntItem = src.m_cntItem;
      m_lstItem = src.m_lstItem;
      // set the src object to a safe empty state
      src.m_name = "";
      src.m_product = "";
      src.m_cntItem = 0u;
      src.m_lstItem = nullptr;
    }

    return *this;
  }

  CustomerOrder::~CustomerOrder()
  {
    if (m_lstItem)
    {
      for (auto i = 0u; i < m_cntItem; ++i)
        delete m_lstItem[i];

      delete[] m_lstItem;
      m_lstItem = nullptr;
    }
  }

  bool CustomerOrder::isOrderFilled() const
  {
    bool filled = true;

    for (auto i = 0u; i < m_cntItem; ++i)
    {
      if (!m_lstItem[i]->m_isFilled)
      {
        filled = false;
        break;
      }
    }
    /*
    if (filled)
      cout << "Order filled" << endl;
    else
      cout << "Order not filled" << endl;

    */
    return filled;
  }

  bool CustomerOrder::isItemFilled(const std::string &itemName) const
  {
    bool result = false;

    for (auto i = 0u; i < m_cntItem; ++i)
      m_lstItem[i]->m_itemName == itemName ? result = false : result = true;

    return result;
  }

  void CustomerOrder::fillItem(Station &station, std::ostream &os)
  {
    for (auto i = 0u; i < m_cntItem; ++i)
    {
      if (m_lstItem[i]->m_itemName == station.getItemName())
      {
        if (station.getQuantity())
        {
          station.updateQuantity();
          m_lstItem[i]->m_isFilled = true;
          m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
          os << "    Filled ";
        }
        else
          os << "    Unable to fill ";

        os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
      }
      // else{
      //   os << "    Unable to fill ";
      //   os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
      // }
    }
  }

  void CustomerOrder::display(std::ostream &os) const
  {

    os << m_name << " - " << m_product << endl;

    for (auto i = 0u; i < m_cntItem; ++i)
    {
      os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
      /*
      if (m_lstItem[i]->m_isFilled)
        os << "FILLED";
      else
        os << "MISSING";

      */
      // remove space at the beginning of the item name
      string itemName = m_lstItem[i]->m_itemName;
      itemName.erase(0, itemName.find_first_not_of(' '));

      os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << itemName;
      os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
    }
  }
}