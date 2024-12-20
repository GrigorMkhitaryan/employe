#ifndef SALESPERSON_HPP
#define SALESPERSON_HPP

#include "Employee.hpp"

class Salesperson : public Employee {
public:
    Salesperson(const std::string& name, double baseSalary, double totalSales);
    virtual double calculateSalary() override;
    virtual void displayInfo() const override;
    void set_totalSales(int sales);
    int get_totalSales() const;

private:
    double totalSales;
};

#endif // SALESPERSON_HPP

