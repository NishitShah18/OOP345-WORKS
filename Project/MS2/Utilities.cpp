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
#include "Utilities.h"

using namespace std;

namespace sdds
{
  char Utilities::deli = ' ';

  void Utilities::setFieldWidth(size_t newWidth)
  {
    widthF = newWidth;
  }

  size_t Utilities::getFieldWidth() const
  {
    return widthF;
  }

  std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
  {
    string result = "";
    size_t first_pos = next_pos;

    next_pos = str.find(deli, first_pos);

    if (first_pos == next_pos)
    {
      more = false;
      throw "   ERROR: No token.\n";
    }
    else if (next_pos == string::npos)
    {
      result = str.substr(first_pos);
      widthF = max(result.length(), widthF);
      more = false;
    }
    else
    {
      result = str.substr(first_pos, next_pos - first_pos);
      widthF = max(result.length(), widthF);
      more = true;
    }

    next_pos++;

    return result;
  }

  void Utilities::setDelimiter(char newDelimiter)
  {
    deli = newDelimiter;
  }

  char Utilities::getDelimiter()
  {
    return deli;
  }
}