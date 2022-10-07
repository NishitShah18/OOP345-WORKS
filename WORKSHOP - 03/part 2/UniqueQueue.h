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

#ifndef SDDS_UNIQUEQUEUE_H__
#define SDDS_UNIQUEQUEUE_H__
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "Queue.h"
#include "Dictionary.h"
namespace sdds{
    template<typename T>
    class UniqueQueue : public Queue<T, 100>{
    public:
        bool push(const T& item){
            bool found = false;
            for(unsigned int i = 0; i < this->size() && !found; i++){
                if((*this)[i] == item){
                    found = true;
                }
            }
           
            if(!found){
                return  Queue<T, 100>::push(item);
            }
            return false;
        }
    };
    
    template<>
    class UniqueQueue<double> : public Queue<double, 100>{
    public:
        bool push(const double& item){
            bool found = false;
            for(unsigned int i = 0; i < this->size() && !found; i++){
                if(std::fabs((*this)[i] - item) <= 0.005){
                    found = true;
                }
            }
            if(!found){
                return Queue<double, 100>::push(item);
            }
            return false;
        }
        
    };

}
#endif