
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
#ifndef SDDS_TENNISLOG_H_
#define SDDS_TENNISLOG_H_

using namespace std;
namespace sdds {
	struct TennisMatch {
		char* m_tournamentID{};
		char* m_tournamentName{};
		size_t m_matchID{};
		char* m_winner{};
		char* m_loser{};
	};
	istream& operator>>(istream& is, TennisMatch& data);

}

#endif // !SDDS_TENNISLOG_H_