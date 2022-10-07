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

#ifndef SDDS_QUEUE_H__
#define SDDS_QUEUE_H__
#include <iostream>
#include <cstdlib>

#include "Dictionary.h"
namespace sdds{
    template<typename T, unsigned int CAPACITY>
    class Queue{
        T* m_array[CAPACITY];
        unsigned int m_size;


    public:
        Queue() : m_size{0} {}
        virtual bool push(const T& item){
            if(m_size < CAPACITY){
                m_array[m_size] = new T(item);
                m_size++;
                return true;
            }
            return false;
        }
        
           T pop(){
            T temp = *m_array[0];
            delete m_array[0];
            for(unsigned int i = 0; i < m_size - 1; i++){
                m_array[i] = m_array[i + 1];
            }
            m_size--;
            return temp;
        }
        unsigned int size() const{
            return m_size;
        }
        void display(std::ostream& os = std::cout) const{
    
            os << "----------------------" << std::endl;
            os << "| Dictionary Content |" << std::endl;
            os << "----------------------" << std::endl;
            for(unsigned int i = 0; i < m_size; i++){
                os << *m_array[i] << std::endl;
            }
            os << "----------------------" << std::endl;
        }
        T operator[](unsigned int index) const{
            if(index < m_size){
                return *m_array[index];
            }
            return T();
        }
        virtual ~Queue(){
            for(unsigned int i = 0; i < m_size; i++){
                delete m_array[i];
            }
        }
    };

}
#endif