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

#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif // !SDDS_UTILITIES_H_