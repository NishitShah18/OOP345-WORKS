// M- 3 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 12/03/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <stdexcept>
using namespace std;
namespace sdds
{
    class Utilities
    {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(size_t new_Width);
        size_t getFieldWidth() const;
        string extractToken(const string &str, size_t &next_pos, bool &more);
        static void setDelimiter(char new_Delimiter)
        {
            m_delimiter = new_Delimiter;
        }
        static char getDelimiter()
        {
            return m_delimiter;
        }
    };
};
#endif
