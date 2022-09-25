
/*************************************************************************
Workshop 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 24th September 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

//including the necessary guards in the header file
#pragma once
#ifndef SDDS_TIMER_H_
#define SDDS_TIMER_H_

using namespace std;
namespace sdds {

    class Timer
    {
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
    public:
        Timer() {};
        // A modifier that starts the timer (takes the current timestamp and stores it in an attribute).
        void start();
        // A modifier that stops the timer (takes the current timestamp) and returns how many nanoseconds passed since the timer has started as a long long value.
        long long stop();
        virtual ~Timer() {};
    };
	
}

#endif // !SDDS_TENNISLOG_H_