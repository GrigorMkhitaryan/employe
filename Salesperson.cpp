#include "Salesperson.hpp"

Salesperson::Salesperson(const std::string& name, double baseSalary, double totalSales)
    : totalSales(totalSales) {
    this->name = name;
    this->baseSalary = baseSalary;
}

double Salesperson::calculateSalary() {
    const double commissionRate = 0.20;
    return baseSalary + (commissionRate * totalSales);
}

void Salesperson::displayInfo() const {
    std::cout << "Salesperson: " << name << " Base Salary: " << baseSalary << " Total Sales: " << totalSales << std::endl;
}

void Salesperson::set_totalSales(int sales) {
    this->totalSales = sales;
}

int Salesperson::get_totalSales() const {
    return this->totalSales;
}

