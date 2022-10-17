
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
#include <iomanip>
#include "Movie.h"

using namespace std;

namespace sdds
{
  const std::string &Movie::title() const
  {
    return movieName;
  }

  Movie::Movie(const std::string &strMovie)
  {
    if (!strMovie.empty())
    {
      string _tempStr = strMovie;
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
      movieName = _tempStr.substr(0, _tempIdx);
      removeSpace(movieName);
      _tempStr.erase(0, _tempIdx + 1);

      removeSpace(_tempStr);
      _tempIdx = _tempStr.find(',');
      movieYear = std::stoi(_tempStr.substr(0, _tempIdx));
      _tempStr.erase(0, _tempIdx + 1);

      removeSpace(_tempStr);
      removeSpace(_tempStr);
      moviedes = _tempStr;
    }
  }

  std::ostream &operator<<(std::ostream &os, const Movie &src)
  {

    os << setw(40) << std::right << src.movieName << " | ";
    os << std::left << setw(4) << src.movieYear << " | " << src.moviedes << endl;

    return os;
  }
}