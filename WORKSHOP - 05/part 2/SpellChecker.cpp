
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

#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
  SpellChecker::SpellChecker(const char *filename)
  {
    ifstream _readFile(filename);

    if (!_readFile)
    {
      throw "Bad file name!";
    }
    else
    {
      string _line{""};
      size_t _count{0u};
      int _space{0u};

      while (_count < STR_SIZE && getline(_readFile, _line))
      {
        _line.erase(0, _line.find_first_not_of(' '));
        _space = _line.find(' ');
        badWords[_count] = _line.substr(0, _space);
        _line.erase(0, _space);

        _line.erase(0, _line.find_first_not_of(' '));
        _space = _line.find(' ');
        goodWords[_count] = _line.substr(0, _space);
        ++_count;
      }
    }
  }

  void SpellChecker::operator()(std::string &text)
  {
    for (auto i = 0; i < STR_SIZE; ++i)
    {
      while (text.find(badWords[i]) != string::npos)
      {
        text.replace(text.find(badWords[i]), badWords[i].size(), goodWords[i]);
        ++replaceWor[i];
      }
    }
  }

  void SpellChecker::showStatistics(std::ostream &out) const
  {
    out << "Spellchecker Statistics" << endl;

    for (auto i = 0u; i < STR_SIZE; ++i)
      out << setw(15) << std::right << badWords[i] << ": " << replaceWor[i] << " replacements" << std::left << endl;
  }
}