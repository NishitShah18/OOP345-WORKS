
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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds
{
  class Movie
  {
    std::string movieName{""};
    std::string moviedes{""};
    size_t movieYear{0u};

  public:
    Movie() {}

    const std::string &title() const;

    Movie(const std::string &strMovie);

    template <typename T>

    void fixSpelling(T &spellChecker)
    {
      spellChecker(movieName);
      spellChecker(moviedes);
    }

    friend std::ostream &operator<<(std::ostream &os, const Movie &src);
  };
}
#endif