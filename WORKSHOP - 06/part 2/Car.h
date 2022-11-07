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

#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car :public Vehicle
	{
		std::string maker = "";
		std::string conditon = "";
		double topspeed = 0;
	public:
		
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H_