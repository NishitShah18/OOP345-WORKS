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

#include <iomanip>
#include <sstream>
#include "Racecar.h"

using namespace std;
namespace sdds {
	
	Racecar::Racecar(std::istream& in) :Car(in)
	{
		string temp;
		getline(in, temp);
		booster = stod(temp.substr(0, temp.find('\n')));
	}
	void Racecar::display(std::ostream& out) const
	{
		std::string racecar;
		std::stringstream str_racecar;

		Car::display(str_racecar);
		racecar = str_racecar.str();
		racecar.erase(racecar.size() - 8);
		out << racecar;
		out << setw(6) << setprecision(2) << fixed << topSpeed();
		out << " |*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed()* booster);
	}
}