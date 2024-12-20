#include "Employee.hpp"

void Employee::set_BaseSalary(double new_baseSalary) {
    baseSalary = new_baseSalary;
}

double Employee::get_BaseSalary() const {
    return this->baseSalary;
}

const std::string& Employee::getName() const {
    return name;
}

Employee::~Employee() {}

