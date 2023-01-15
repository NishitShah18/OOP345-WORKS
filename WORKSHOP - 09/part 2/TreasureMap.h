/*************************************************************************
Workshop 9
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 27th November 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_TREASUREMAP_H
#define SDDS_TREASUREMAP_H

#include <cstddef>
#include <iostream>
#include <string>

namespace sdds
{

    size_t digForTreasure(const std::string &str, char mark);

    class TreasureMap
    {
        size_t rows = 0;
        size_t colSize = 0;
        std::string *map = nullptr;

    public:
        TreasureMap(const char *filename);
        ~TreasureMap();

        std::string operator[](int i) const
        {
            return map[i % rows];
        }

        size_t size() const
        {
            return rows;
        }

        std::ostream &display(std::ostream &os) const;
        void enscribe(const char *filename);
        void recall(const char *filename);
        void clear();

        size_t findTreasure(char mark);
    };

}

#endif