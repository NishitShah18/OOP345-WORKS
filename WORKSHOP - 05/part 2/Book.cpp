
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

#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds
{
  const std::string &Book::title() const
  {
    return bookTitle;
  }

  Book::Book(const std::string &strBook)
  {
    string _tempStr = strBook;
    int _tempIdx = 0u;

    auto removeSpace = [=](string &src)
    {
      if (src[0] == ' ')
        src.erase(0, src.find_first_not_of(' '));
      else
        src.erase(src.find_last_not_of(' ') + 1);
    };
    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    bookAuthor = _tempStr.substr(0, _tempIdx);
    removeSpace(bookAuthor);
    _tempStr.erase(0, _tempIdx + 1);
    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    bookTitle = _tempStr.substr(0, _tempIdx);
    removeSpace(bookTitle);
    _tempStr.erase(0, _tempIdx + 1);
    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    bookCountry = _tempStr.substr(0, _tempIdx);
    removeSpace(bookCountry);
    _tempStr.erase(0, _tempIdx + 1);
    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    bookPrice = std::stod(_tempStr.substr(0, _tempIdx));
    _tempStr.erase(0, _tempIdx + 1);
    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    bookYear = std::stoi(_tempStr.substr(0, _tempIdx));
    _tempStr.erase(0, _tempIdx + 1);
    removeSpace(_tempStr);
    removeSpace(_tempStr);
    bookdes = _tempStr;
  }

  const size_t &Book::year() const
  {
    return bookYear;
  }

  double &Book::price()
  {
    return bookPrice;
  }

  const std::string &Book::country() const
  {
    return bookCountry;
  }

  std::ostream &operator<<(std::ostream &os, const Book &src)
  {
    os << setw(20) << std::right << src.bookAuthor << " | ";
    os << setw(22) << src.title() << " | ";
    os << setw(5) << src.country() << " | ";
    os << setw(4) << src.year() << " | ";
    os << setw(6) << fixed << setprecision(2) << src.bookPrice << " | ";
    os << std::left << src.bookdes << endl;

    return os;
  }
}