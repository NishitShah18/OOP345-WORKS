/*************************************************************************
Workshop 3
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 7th October 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#include "Queue.h"
using namespace std;
namespace sdds{
    std::ostream& operator<<(std::ostream& os, const Dictionary& d){
        os << setw(20) << right << d.m_term << ": " << d.m_definition ;
        return os;

    }
    // Dictionary::Dictionary(){
    //     m_term = nullptr;
    //     m_definition = nullptr;
    // }
    bool operator==(const Dictionary& d1, const Dictionary& d2){
        return d1.getTerm() == d2.getTerm();
    }
    
}