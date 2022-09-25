
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
	
	// Overloaded insertion operator to output a TennisMatch object to an output stream.
	ostream& operator<<(ostream& os, const TennisMatch& match) {
		if (strcmp(match.m_tournamentID, "\0"))
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

	// Default constructor
	TennisLog::TennisLog() {
		m_tennisMatch = nullptr;
		m_storedMatches = 0;
	}

	// A one argument constructor that receives a filename as a parameter from which the current object will be populated.
	TennisLog::TennisLog(const char* FileName) {
		
		m_tennisMatch = nullptr;
		
		m_storedMatches = countMatches(FileName);

		m_tennisMatch = new TennisMatch[m_storedMatches];

		int i = 0;
		ifstream file;

		file.open(FileName, ios::in);

		if (file.bad())
		{
			cerr << "Error opening file" << endl;
			exit(1);
		}
		else {
			file.ignore(1028, '\n');
			while (file.good())
			{
				read(file, &m_tennisMatch[i]);
				i++;
			}
		}

		return;
	}

	// Destructor
	TennisLog::~TennisLog() {
		delete[] m_tennisMatch;
		m_storedMatches = 0;
	}

	// This function receives a TennisMatch object and returns nothing. It adds the object in list.
	void TennisLog::addMatch(TennisMatch& match){
		TennisMatch* temp = new TennisMatch[this->m_storedMatches];
		if (this->m_storedMatches != 0) 
		{
			for (int i = 0; i < this->m_storedMatches; i++)
			{
				strcpy(temp[i].m_loser, this->m_tennisMatch[i].m_loser);
				strcpy(temp[i].m_tournamentID, this->m_tennisMatch[i].m_tournamentID);
				strcpy(temp[i].m_tournamentName, this->m_tennisMatch[i].m_tournamentName);
				strcpy(temp[i].m_winner, this->m_tennisMatch[i].m_winner);
				temp[i].m_matchID = this->m_tennisMatch[i].m_matchID;
			}
		}

		this->m_storedMatches++;

		delete[] this->m_tennisMatch;
		this->m_tennisMatch = new TennisMatch[this->m_storedMatches];

		for (int i = 0; i < (this->m_storedMatches-1); i++)
		{
			strcpy(this->m_tennisMatch[i].m_loser, temp[i].m_loser);
			strcpy(this->m_tennisMatch[i].m_tournamentID, temp[i].m_tournamentID);
			strcpy(this->m_tennisMatch[i].m_tournamentName, temp[i].m_tournamentName);
			strcpy(this->m_tennisMatch[i].m_winner, temp[i].m_winner);
			this->m_tennisMatch[i].m_matchID = temp[i].m_matchID;
		}
		strcpy(this->m_tennisMatch[this->m_storedMatches-1].m_loser, match.m_loser);
		strcpy(this->m_tennisMatch[this->m_storedMatches-1].m_tournamentID, match.m_tournamentID);
		strcpy(this->m_tennisMatch[this->m_storedMatches-1].m_tournamentName, match.m_tournamentName);
		strcpy(this->m_tennisMatch[this->m_storedMatches-1].m_winner, match.m_winner);
		this->m_tennisMatch[this->m_storedMatches-1].m_matchID = match.m_matchID;
	}

	// This function receives a name of a player as a parameter and returns a TennisLog object.
	TennisLog TennisLog::findMatches(const char* name){
		TennisLog log;
		for (int i = 0; i < this->m_storedMatches; i++) {
			if (strcmp(this->m_tennisMatch[i].m_loser, name) == 0 || strcmp(this->m_tennisMatch[i].m_winner, name) == 0) {
				log.m_storedMatches++;
			}
		}

		log.m_tennisMatch = new TennisMatch[log.m_storedMatches];

		int index = 0;

		for (int i = 0; i < this->m_storedMatches && index < log.m_storedMatches; i++)
		{
			if (strcmp(this->m_tennisMatch[i].m_loser, name) == 0 || strcmp(this->m_tennisMatch[i].m_winner, name) == 0) {
				strcpy(log.m_tennisMatch[index].m_loser, this->m_tennisMatch[i].m_loser);
				strcpy(log.m_tennisMatch[index].m_tournamentID, this->m_tennisMatch[i].m_tournamentID);
				strcpy(log.m_tennisMatch[index].m_tournamentName, this->m_tennisMatch[i].m_tournamentName);
				strcpy(log.m_tennisMatch[index].m_winner, this->m_tennisMatch[i].m_winner);
				log.m_tennisMatch[index].m_matchID = this->m_tennisMatch[i].m_matchID;
				
				index++;
			}
		}

		return log;
	}

	// The query returns the TennisMatch in the dynamic array at the index provided
	TennisMatch TennisLog::operator[](size_t index) {
		TennisMatch temp;
		if (this->m_tennisMatch != nullptr)
		{
			strcpy(temp.m_loser,this->m_tennisMatch[index].m_loser);
			strcpy(temp.m_tournamentID,this->m_tennisMatch[index].m_tournamentID);
			strcpy(temp.m_tournamentName,this->m_tennisMatch[index].m_tournamentName);
			strcpy(temp.m_winner,this->m_tennisMatch[index].m_winner);
			temp.m_matchID = this->m_tennisMatch[index].m_matchID;
		}
		return temp;
	}


	// This casting operator will convert the current object to a size_t value.
	TennisLog::operator size_t() {
		return this->m_storedMatches;
	}

	// A Helper Function :
	size_t countMatches(const char* FileName) {
		char temp = '\0';
		size_t lines = 0;
		size_t totalMatches = 0;
		ifstream file;
		
		file.open(FileName, ios::in);
		
		file.get(temp);
		
		while (file)
		{
			if (temp == '\n')
			{
				lines++;
			}
			file.get(temp);
		}
		
		totalMatches = lines - 1;
		
		return totalMatches;
	}

	// A Helper Function :
	void read(istream& is, TennisMatch* match) {
		is.getline(match->m_tournamentID, 1028, ',');
		is.getline(match->m_tournamentName, 1028, ',');
		is >> match->m_matchID;
		is.ignore();
		is.getline(match->m_winner, 1028, ',');
		is.getline(match->m_loser, 1028, '\n');

		return;
	}
}