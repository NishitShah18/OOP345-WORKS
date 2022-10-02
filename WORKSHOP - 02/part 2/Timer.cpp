
/*************************************************************************
Workshop 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 25th September 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<chrono>
#include"Timer.h"

using namespace std;

namespace sdds {

	// A modifier that starts the timer (takes the current timestamp and stores it in an attribute).
	void Timer::start()
	{
		m_startTime = std::chrono::steady_clock::now();
	}

	// A modifier that stops the timer (takes the current timestamp) and returns how many nanoseconds passed since the timer has started as a long long value.
	long long Timer::stop()
	{
		m_endTime = std::chrono::steady_clock::now();
		long long timeDiff = size_t (std::chrono::duration_cast <std::chrono::nanoseconds> (m_endTime - m_startTime).count());
		return timeDiff;
	}

}