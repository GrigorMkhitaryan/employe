#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Employee.hpp"

class Manager : public Employee {
public:
    Manager(const std::string& name, double baseSalary, int numEmployees);
    virtual double calculateSalary() override;
    virtual void displayInfo() const override;
    void set_numEmployess(int employess);
    int get_numEmployess() const;

private:
    int numEmployees;
};

#endif // MANAGER_HPP

