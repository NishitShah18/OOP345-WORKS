/*************************************************************************
Workshop 7
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 13th November 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_CRIMESTATISTICE_H
#define SDDS_CRIMESTATISTICE_H

#include<string>
#include<fstream>
#include<iomanip>
#include<list>
#include<algorithm>
#include<vector>

namespace sdds {

    struct Crime {
        std::string province;
        std::string district;
        std::string desc;
        int cases;
        int year;
        int m_resolved;

    };
    class CrimeStatistics {
        std::vector < Crime > crime;
    public:
        CrimeStatistics(std::string file);
        void display(std::ostream& out) const;
        void sort(std::string str);
        void cleanList();
        bool inCollection(std::string str) const;
        std::list < Crime > getListForProvince(std::string str) const;

    };
    std::ostream& operator << (std::ostream& out,
        const Crime& theCrime);

}
#endif // !SDDS_CRIMESTATISTICE_H