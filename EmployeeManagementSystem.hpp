#ifndef EMPLOYEEMANAGEMENTSYSTEM_HPP
#define EMPLOYEEMANAGEMENTSYSTEM_HPP
#include "Employee.hpp"

class EmployeeManagementSystem final {
public:
    void addEmployee(Employee* employee);
    void displayAllEmployees() const;
    void calculateTotalSalary() const;
    void searchEmployeeByName(const std::string& name) const;
    void searchEmployeeByRole(const std::string& role) const;
    void removeEmployeeByName(const std::string& name);
    ~EmployeeManagementSystem();

private:
    std::vector<Employee*> employees;
};

#endif // EMPLOYEEMANAGEMENTSYSTEM_HPP

