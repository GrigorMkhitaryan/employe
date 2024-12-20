#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class Employee {
public:
    virtual double calculateSalary() = 0;  
    virtual void displayInfo() const = 0; 
    void set_BaseSalary(double new_baseSalary);
    double get_BaseSalary() const;
    virtual const std::string& getName() const;
    virtual ~Employee();

protected:
    std::string name;
    double baseSalary;
};

#endif // EMPLOYEE_HPP

