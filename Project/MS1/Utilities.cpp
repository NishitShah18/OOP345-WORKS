// M- 1 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 11/18/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"
using namespace std;
namespace sdds
{
    void trim(string &src)
    {
        if (src.length() > 0)
        {
            int begin = src.find_first_not_of(' ');
            int end = src.find_last_not_of(' ');
            if (begin == -1)
            {
                src = "";
            }
            else
            {
                src = src.substr(begin, end - begin + 1);
            }
        }
    }

    char Utilities::m_delimiter{};
    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
    {
        int next_del;
        string result;
        if (str[next_pos] == m_delimiter)
        {
            more = false;
            throw -1;
        }
        else
        {
            string temp = str.substr(next_pos);
            if ((next_del = temp.find_first_of(m_delimiter)) != -1)
            {
                result = temp.substr(0, next_del);
                trim(result);
                next_pos += next_del + 1;
                more = true;
            }
            else
            {
                result = temp;
                trim(result);
                more = false;
            }
        }
        if (m_widthField < result.length())
            m_widthField = result.length();

        return result;
    }
    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}