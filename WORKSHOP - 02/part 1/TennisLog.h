
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

	static const int MAX_LEN_TOURNAMENT_ID = 10;
	static const int MAX_LEN_TOURNAMENT_NAME = 128;
	static const int MAX_LEN_WINNER_NAME = 64;
	static const int MAX_LEN_LOSER_NAME = 64;
	static const char TOURNAMENT_ID_HEAD[] = "Tourney ID";
	static const char TOURNAMENT_NAME_HEAD[] = "Tourney";
	static const char MATCH_ID_HEAD[] = "Match ID";
	static const char WINNER_NAME_HEAD[] = "Winner";
	static const char LOSER_NAME_HEAD[] = "Loser";

	// TennisMatch: contains data about a single match between two players
	struct TennisMatch {

		//a string representing the Tournament ID
		char m_tournamentID[MAX_LEN_TOURNAMENT_ID + 1] = "\0";
		//a string representing the Tournament Name
		char m_tournamentName[MAX_LEN_TOURNAMENT_NAME + 1] = "\0";
		//a positive integer representing the Match ID
		long long m_matchID{};
		//a string representing the Winner of the match
		char m_winner[MAX_LEN_WINNER_NAME + 1] = "\0";
		//a string representing the Loser of the match
		char m_loser[MAX_LEN_LOSER_NAME + 1] = "\0";
	};

	// Overloaded insertion operator to output a TennisMatch object to an output stream.
	ostream& operator<<(ostream& os, const TennisMatch& match);

	// TennisLog: manages a collection of matches
	class TennisLog {

		//a dynamic array of TennisMatches
		TennisMatch* m_tennisMatch;
		//a count of how many are being stored
		int m_storedMatches{};

	public:
		// Default constructor
		TennisLog();

		// A one argument constructor that receives a filename as a parameter from which the current object will be populated.
		TennisLog(const char* FileName);

		// This function receives a TennisMatch object and returns nothing. It adds the object in list.
		void addMatch(TennisMatch& match);

		// This function receives a name of a player as a parameter and returns a TennisLog object.
		TennisLog findMatches(const char* name);

		// The query returns the TennisMatch in the dynamic array at the index provided
		TennisMatch operator[](size_t index);

		// This casting operator will convert the current object to a size_t value.
		operator size_t();

		// Rule of 5:
		// Will be here...
		// Destructor 
		virtual ~TennisLog();
	};

	// Helper Functions :
	size_t countMatches(const char* FileName);
	void read(std::istream& is, TennisMatch* match);
}

#endif // !SDDS_TENNISLOG_H_