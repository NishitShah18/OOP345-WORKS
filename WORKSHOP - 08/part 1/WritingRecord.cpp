/*************************************************************************
Workshop 8
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP345 NCC
Date : 18th November 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		size_t i,j;
        for (i = 0; i < emp.size(); i++) {
            for (j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    EmployeeWage* emWage = new EmployeeWage(emp[i].name, sal[j].salary);
                    try {
                        emWage->rangeValidator();
                    }
                    catch (...) {
                        delete emWage;
                        throw;
                    }
                    if (activeEmp.SINValidation(emp[i].id)) {
                        activeEmp += emWage;
                    }
                    else {
                        throw string{ "SIN doesn't pass validation" };
                    }
                    delete emWage;
                }
            }
        }
		return activeEmp;
	}
}