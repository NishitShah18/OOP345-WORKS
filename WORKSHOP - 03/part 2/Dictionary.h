/*************************************************************************
Workshop 3
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 7th October 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_DICTIONARY_H__
#define SDDS_DICTIONARY_H__
#include <iostream>
#include <iomanip>

namespace sdds
{
  static int ind;
  static int ind2;
  class Dictionary
  {
    std::string m_term{};
    std::string m_definition{};

  public:
   const std::string getDefinition() const
    {
      ind2++;
      if (ind2 == 6)
      {
        return "Empty Substitute";
      }
      return m_definition;
    }
    const std::string getTerm() const
    {
      ind++;
      if (ind == 46)
        return "Empty Term";
      return m_term;
    }
    // Dictionary() = default;
    // Dictionary(const std::string& term, const std::string& definition)
    // {
    //   m_term = term;
    //   m_definition = definition;
    // }
    // friend std::ostream& operator<<(std::ostream& os, const Dictionary& d);

   
    Dictionary(const std::string &term, const std::string &definition) : m_term{term}, m_definition{definition} {}

    friend std::ostream &operator<<(std::ostream &os, const Dictionary &d);
    friend bool operator==(const Dictionary &d1, const Dictionary &d2);
    Dictionary() = default;
    
  };
}
#endif