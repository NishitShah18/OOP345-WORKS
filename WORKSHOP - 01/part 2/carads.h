/*************************************************************************
Workshop 1 Part - 2

Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC

Date : 18th September 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_CARADS_H_
#define SDDS_CARADS_H_
extern double g_taxrate;
extern double g_discount;
namespace sdds
{
    void listArgs(int argc, char* argv[]);
    
    class Cars
    {
        //a C-style null-terminated string of up to 10 characters including the null byte terminator representing the brand of the car.
        char* m_brand{};
        //a C-style null-terminated string of up to 15 characters including the null byte terminator representing the model of the car.
        char m_model[15]{};
        //the manufacture year of the car.
        int m_year{};
        //the price of the car represented by a double value.
        double m_price{};
        //the status of the cars as used or new using a single character(holds N or U)
        char m_status{};
        //a boolean flag indicating whether or not the car is on promotion discount
        bool m_onPromotion{};
        double m_specialPrice{};
        int eofErrorSolver{};

    public:

        // Rule of three
        ~Cars();
        Cars(const Cars& cars);
        Cars& operator=(const Cars& cars);
        
        operator bool() const;

        void setempty();
        Cars();
        void read(std::istream& is);
        void display(bool reset);
        char getStatus() const;
    };
    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);
}
#endif // !SDDS_CARADS_H_