
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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace sdds
{
  const int STR_SIZE = 6;
  class SpellChecker
  {
    std::string badWords[STR_SIZE]{};
    std::string goodWords[STR_SIZE]{};
    size_t replaceWor[STR_SIZE]{};

  public:
    SpellChecker() {}
    SpellChecker(const char *filename);
    void operator()(std::string &text);
    void showStatistics(std::ostream &out) const;
  };
}
#endif