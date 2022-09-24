
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

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<fstream>
#include"TennisLog.h"

using namespace std;

namespace sdds {

	ostream& operator<<(ostream& os, const TennisMatch& match) {
		if (!strcmp(match.m_tournamentID, "\0"))
		{
			os.width(20);
			os.fill('.');
			os << right << TOURNAMENT_ID_HEAD;
			os << " : ";
			os.width(30);
			os.fill('.');
			os << left << match.m_tournamentID << endl;
			os.width(20);
			os.fill('.');
			os << right << MATCH_ID_HEAD;
			os << " : ";
			os.width(30);
			os.fill('.');
			os << left << match.m_matchID << endl;
			os.width(20);
			os.fill('.');
			os << right << TOURNAMENT_NAME_HEAD;
			os << " : ";
			os.width(30);
			os.fill('.');
			os << left << match.m_tournamentName << endl;
			os.width(20);
			os.fill('.');
			os << right << WINNER_NAME_HEAD;
			os << " : ";
			os.width(30);
			os.fill('.');
			os << left << match.m_winner << endl;
			os.width(20);
			os.fill('.');
			os << right << LOSER_NAME_HEAD;
			os << " : ";
			os.width(30);
			os.fill('.');
			os << left << match.m_loser << endl;
		}
		else
		{
			os << "Empty Match";
		}
		
		return os;
	}

	TennisLog::TennisLog() {
		m_tennisMatch = nullptr;
		m_storedMatches = 0;
	}

	TennisLog::TennisLog(const char* FileName) {
		
	}

	// This function receives a TennisMatch object and returns nothing. It adds the object in list.
	void TennisLog::addMatch(const TennisMatch& match){}

	// This function receives a name of a player as a parameter and returns a TennisLog object.
	TennisLog TennisLog::findMatches(const char* name){
		TennisLog temp;
		return temp;
	}

	// The query returns the TennisMatch in the dynamic array at the index provided
	TennisMatch TennisLog::operator[](size_t index) {
		TennisMatch temp;
		return temp;
	}

	// This casting operator will convert the current object to a size_t value.
	TennisLog::operator size_t() {
		return 0;
	}

}