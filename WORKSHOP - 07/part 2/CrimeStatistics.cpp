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

#include "CrimeStatistics.h"

namespace sdds {
    void CrimeStatistics::display(std::ostream& out) const {
        int cimres = 0, resolved = 0;
        std::for_each(crime.begin(), crime.end(), [&](const Crime& cr) {
            cimres += cr.cases;
            resolved += cr.m_resolved;
            });

        std::for_each(crime.begin(), crime.end(), [&](const Crime& cr) {
            out << "| ";
            out.unsetf(std::ios::right);
            out.setf(std::ios::left);
            out << std::setw(22) << cr.province << "| ";

            out.unsetf(std::ios::right);
            out.setf(std::ios::left);

            out << std::setw(16) << cr.district << "| ";

            out.unsetf(std::ios::right);
            out.setf(std::ios::left);

            out << std::setw(21) << cr.desc << "|";
            out.unsetf(std::ios::left);
            out.setf(std::ios::right);

            out << std::setw(7) << cr.year << " |";

            out.unsetf(std::ios::left);
            out.setf(std::ios::right);

            out << std::setw(5) << cr.cases << " | ";

            out.unsetf(std::ios::left);
            out.setf(std::ios::right);

            out << std::setw(3) << cr.m_resolved << " |" << std::endl;

            });
        std::string str = "Total Resolved Cases: ";
        std::string str2 = "Total Crimes: ";
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        out << "|" << std::right << std::setw(78) << "Total Crimes:";
        out << "  " << cimres << " |" << std::endl;
        out << "|" << std::right << std::setw(78) << "Total Resolved Cases:";
        out << "  " << resolved << " |" << std::endl;

    }
    std::ostream& operator << (std::ostream& out,
        const Crime& theCrime) {
        out << "| ";
        out.unsetf(std::ios::right);
        out.setf(std::ios::left);
        out << std::setw(22) << theCrime.province << "| ";

        out.unsetf(std::ios::right);
        out.setf(std::ios::left);

        out << std::setw(16) << theCrime.district << "| ";

        out.unsetf(std::ios::right);
        out.setf(std::ios::left);

        out << std::setw(21) << theCrime.desc << "|";
        out.unsetf(std::ios::left);
        out.setf(std::ios::right);

        out << std::setw(7) << theCrime.year << " | ";

        out.unsetf(std::ios::left);
        out.setf(std::ios::right);

        out << std::setw(4) << theCrime.cases << " | ";

        out.unsetf(std::ios::left);
        out.setf(std::ios::right);

        out << std::setw(3) << theCrime.m_resolved << " |";
        return out;
    }
    std::string extract_token(std::string temp) {

        temp.erase(temp.find_last_not_of(' ') + 1);
        temp.erase(0, temp.find_first_not_of(' '));
        return temp;
    }
    void CrimeStatistics::sort(std::string str) {
        if (str == "Province")
            std::sort(crime.begin(), crime.end(), [&](Crime crime1, Crime crime2) {
            return crime1.province < crime2.province;
                });
        if (str == "Crime")
            std::sort(crime.begin(), crime.end(), [&](Crime crime1, Crime crime2) {
            return crime1.desc < crime2.desc;
                });
        if (str == "Resolved")
            std::sort(crime.begin(), crime.end(), [&](Crime crime1, Crime crime2) {
            return crime1.m_resolved < crime2.m_resolved;
                });
        if (str == "Cases")
            std::sort(crime.begin(), crime.end(), [&](Crime crime1, Crime crime2) {
            return crime1.cases < crime2.cases;
                });
    }

    bool CrimeStatistics::inCollection(std::string temp) const {
        auto cr = std::any_of(crime.begin(), crime.end(), [&](Crime c) {
            return c.desc == temp;
            });
        return cr;
    }
    std::list < Crime > CrimeStatistics::getListForProvince(std::string str) const {
        std::list < Crime > cr;
        std::for_each(crime.begin(), crime.end(), [&](Crime c) {
            if (c.province == str)
                cr.push_back(c);
            });
        return cr;
    }

    void CrimeStatistics::cleanList() {
        std::for_each(crime.begin(), crime.end(), []
        (Crime& c1) {
                if (c1.desc == "[None]")
                    c1.desc = "";
            });
    }

    CrimeStatistics::CrimeStatistics(std::string name) {
        std::fstream load(name);
        if (!load)
            throw "File not found!";
        while (load) {
            std::string load_crime;
            Crime crime_temp;
            std::getline(load, load_crime, '\n');
            if (load_crime != "") {
                crime_temp.province = load_crime.substr(0, 25);
                crime_temp.province = extract_token(crime_temp.province);
                load_crime.erase(0, 25);

                crime_temp.district = load_crime.substr(0, 25);
                crime_temp.district = extract_token(crime_temp.district);
                load_crime.erase(0, 25);

                crime_temp.desc = load_crime.substr(0, 25);
                crime_temp.desc = extract_token(crime_temp.desc);
                load_crime.erase(0, 25);

                crime_temp.year = stoi(load_crime.substr(0, 5));
                crime_temp.year = stoi((extract_token(std::to_string(crime_temp.year))));
                load_crime.erase(0, 5);

                crime_temp.cases = stoi(load_crime.substr(0, 5));
                crime_temp.cases = stoi(extract_token(std::to_string(crime_temp.cases)));
                load_crime.erase(0, 5);

                crime_temp.m_resolved = stoi(load_crime.substr(0, 5));
                crime_temp.m_resolved = stoi(extract_token(std::to_string(crime_temp.m_resolved)));
                load_crime.erase(0, 5);

                crime.push_back(crime_temp);
            }

        }

    }
}