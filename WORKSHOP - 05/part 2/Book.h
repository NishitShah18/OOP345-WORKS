
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
namespace sdds
{
  class Book
  {
    std::string bookCountry{""};
    size_t bookYear{0};
    double bookPrice{0.0};
    std::string bookdes{""};
    std::string bookAuthor{""};
    std::string bookTitle{""};

  public:
    Book() {}
    const std::string &country() const;
    const size_t &year() const;
    double &price();

    Book(const std::string &strBook);
    const std::string &title() const;

    template <typename T>

    void fixSpelling(T &spellChecker)
    {
      spellChecker(bookdes);
    }
    friend std::ostream &operator<<(std::ostream &os, const Book &src);
  };
}

#endif