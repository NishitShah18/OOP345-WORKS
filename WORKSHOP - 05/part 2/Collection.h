
/*************************************************************************
Workshop 5
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 16th October 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds
{
  template <typename T>
  class Collection
  {
    T *c_item{nullptr};
    std::string c_name{""};
    size_t c_numOfCol{0u};
    void (*c_observer)(const Collection<T> &, const T &){nullptr}; // observer function pointer

  public:
    Collection(const std::string &name) : c_name(name) {} // constructor
    Collection(const Collection &) = delete;              // copy constructor
    Collection &operator=(const Collection &) = delete;   // copy assignment operator

    ~Collection()
    { // destructor
      if (c_item)
      {
        delete[] c_item;
        c_item = nullptr;
      }
    }

    const std::string &name() const
    {
      return c_name;
    }

    size_t size() const
    {

      return c_numOfCol;
    }

    void setObserver(void (*observer)(const Collection<T> &, const T &))
    { // observer function pointer
      c_observer = observer;
    }

    Collection<T> &operator+=(const T &item)
    {
      bool _same = false;

      for (auto i = 0u; i < c_numOfCol; ++i)
      {
        if (c_item[i].title() == item.title())
          _same = true;
      }

      if (!_same)
      {
        if (c_numOfCol == 0u)
        {
          c_item = new T[++c_numOfCol];
          c_item[0] = item;
        }
        else
        {
          T *_temp = new T[c_numOfCol];

          for (auto i = 0u; i < c_numOfCol; ++i)
            _temp[i] = c_item[i];
          delete[] c_item;
          c_item = nullptr;
          c_item = new T[++c_numOfCol];
          for (auto i = 0u; i < c_numOfCol - 1u; ++i)
            c_item[i] = _temp[i];

          c_item[c_numOfCol - 1u] = item;
          delete[] _temp;
          _temp = nullptr;

          if (c_observer)
            c_observer(*this, item);
        }
      }

      return *this;
    }

    T &operator[](size_t idx) const
    {
      if (idx >= size())
      {
        std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";

        throw std::out_of_range(err);
      }
      return c_item[idx];
    }

    T *operator[](const std::string &title) const
    {

      bool _found{false};
      size_t _idx{0u};

      for (auto i = 0u; i < c_numOfCol && !_found; ++i)
      {
        if (c_item[i].title() == title)
        {
          _idx = i;
          _found = true;
        }
      }
      if (!_found)
      {
        return nullptr;
      }

      return &c_item[_idx];
    }
  };

  template <typename T>
  std::ostream &operator<<(std::ostream &os, const Collection<T> &src)
  {
    for (auto i = 0u; i < src.size(); ++i)
      os << src[i];

    return os;
  }
}
#endif