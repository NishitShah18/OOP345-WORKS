// M- 1 //
//
// Name: Nishit Shah
// Seneca Student ID: 130 176 217
// Seneca email: ngshah3@myseneca.ca
// Date of completion: 11/18/2022
// Section: OOP345 NCC
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
namespace sdds
{
    class Station
    {
        int m_stationId{};
        std::string m_itemName{};
        std::string m_desc{};
        size_t m_serialNum{};
        size_t m_numOfItems{};
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string &str);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &ostr, bool full) const;
    };
}
#endif // !SDDS_STATION_H