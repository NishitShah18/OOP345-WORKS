
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

	// TennisMatch: contains data about a single match between two players
	struct TennisMatch {
		//a string representing the Tournament ID
		char* m_tournamentID{};
		//a string representing the Tournament Name
		char* m_tournamentName{};
		//a positive integer representing the Match ID
		size_t m_matchID{};
		//a string representing the Winner of the match
		char* m_winner{};
		//a string representing the Loser of the match
		char* m_loser{};
	};
	// Overloaded the insertion operator to output a TennisMatch object to an output stream.
	istream& operator>>(istream& is, TennisMatch& data);

	// TennisLog: manages a collection of matches
	class TennisLog {
		//a dynamic array of TennisMatches
		TennisMatch* m_tennisMatch;
		//a count of how many are being stored
		size_t m_storedMatches{};
		// Helper Functions :
		size_t countMatches(const char* FileName);
		void readMatchesDataFromFile(const char* FileName);

	public:

		// Default constructor
		TennisLog();

		// A one argument constructor that receives a filename as a parameter from which the current object will be populated.
		TennisLog(const char* FileName);

		// This function receives a TennisMatch object and returns nothing. It adds the object in list.
		void addMatch(const TennisMatch& match);

		// This function receives a name of a player as a parameter and returns a TennisLog object.
		TennisLog findMatches(const char* name);

		// The query returns the TennisMatch in the dynamic array at the index provided
		TennisMatch operator[](size_t index);

		// This casting operator will convert the current object to a size_t value.
		operator size_t();

		// Rule of 5:
		// later...
		//virtual ~TennisLog();
	};
}

#endif // !SDDS_TENNISLOG_H_