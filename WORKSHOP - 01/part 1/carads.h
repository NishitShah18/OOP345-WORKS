/*************************************************************************
Workshop 1 Part - 1

Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC

Date : 17th September 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H

//Global Variables
extern double g_taxrate;
extern double g_discount;

namespace sdds {

	//Global Function
	//listArgs receives the same parameters as the main function (same types, same order)
	void listArgs(int argc, char* argv[]);

	//Class Cars
	class Cars {
		//a C-style null-terminated string of up to 10 characters including the null byte terminator representing the brand of the car.
		char* m_brand{};
		//a C-style null-terminated string of up to 15 characters including the null byte terminator representing the model of the car.
		char* m_model{};
		//the manufacture year of the car.
		int m_year{};
		//the price of the car represented by a double value.
		double m_price{};
		//the status of the cars as used or new using a single character (holds N or U)
		char m_status{};
		//a boolean flag indicating whether or not the car is on promotion discount
		bool m_onPromotion{};
		size_t m_counter{};

	public:
		//default constructor
		Cars();
		//reads from istream
		void read(std::istream& is);
		//displays to the screen the content of an Cars instance
		void display(bool reset) const;
		//returns if the car is new or used.
		char getStatus() const;
	};
}

#endif