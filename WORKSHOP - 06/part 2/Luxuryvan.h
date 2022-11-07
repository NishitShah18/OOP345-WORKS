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

#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include "Van.h"
namespace sdds {
	class Luxuryvan : public Van {
		std::string m_consumption;
	public:
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}

#endif // ! SDDS_LUXURYVAN_H