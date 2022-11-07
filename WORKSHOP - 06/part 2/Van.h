/*************************************************************************
Workshop 6
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 6th November 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Van : public Vehicle {
		std::string m_maker{};
		std::string m_type;
		std::string m_condition;
		std::string m_purpose;
		double m_topSpeed;
	public:
		Van(std::istream& in);
		std::string condition()const;
		std::string type() const;
		std::string usage() const;
		double topSpeed()const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_VAN_H
