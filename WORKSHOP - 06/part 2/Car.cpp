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
#include "Car.h"

using namespace std;
namespace sdds {
	Car::Car(std::istream& in)
	{
		string tag, condition, topSpeed;
		getline(in, tag, ',');
		tag.erase(0, tag.find_first_not_of(" "));
		tag.erase(tag.find_last_not_of(" ") + 1);
		if (tag == "C" || tag == "c" || tag == "r" || tag == "R") {
			getline(in, maker, ',');
			maker.erase(0, maker.find_first_not_of(" "));
			maker.erase(maker.find_last_not_of(" ") + 1);

			getline(in, condition, ',');
			condition.erase(0, condition.find_first_not_of(" "));
			condition.erase(condition.find_last_not_of(" ") + 1);
			if (condition == "n" || condition == "N" || condition == "" || condition == " ")
				conditon = "new";
			if (condition == "u" || condition == "U")
				conditon = "used";
			if (condition == "b" || condition == "B")
				conditon = "broken";
			if (conditon != "new" && conditon != "used" && conditon != "broken")
				throw string("Invalid record!");

			getline(in, topSpeed, ',');
			topSpeed.erase(0, topSpeed.find_first_not_of(" "));
			topSpeed.erase(topSpeed.find_last_not_of(" ") + 1);
			if (isdigit(*topSpeed.c_str())) {
				topspeed = stod(topSpeed);
			}
			else {
				throw string("Invalid record!");
			}
		}
	}
	std::string Car::condition() const
	{
		return conditon;
	}
	double Car::topSpeed() const
	{
		return topspeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << setw(10) << right << maker << " | " << setw(6) << left << conditon
			<< " | " << setw(6) << fixed << setprecision(2)
			<< topspeed << " |";
	}
}