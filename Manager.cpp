#include "Manager.hpp"

Manager::Manager(const std::string& name, double baseSalary, int numEmployees)
    : numEmployees(numEmployees) {
    this->name = name;
    this->baseSalary = baseSalary;
}

double Manager::calculateSalary() {
    const double bonusPerEmployee = 200.0;
    return baseSalary + (bonusPerEmployee * numEmployees);
}

void Manager::displayInfo() const {
    std::cout << "Manager: " << name << " Base Salary: " << baseSalary << " Employees Managed: " << numEmployees << std::endl;
}

void Manager::set_numEmployess(int employess) {
    if (employess < 0) {
        std::cerr << "Number of employees cannot be negative." << std::endl;
        numEmployees = 0;
        return;
    }
    this->numEmployees = employess;
}

int Manager::get_numEmployess() const {
    return this->numEmployees;
}

