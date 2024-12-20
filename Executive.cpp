#include "Executive.hpp"

Executive::Executive(const std::string& name, double baseSalary, int numEmployees, int managersSupervised, double companyPerformance)
    : SeniorManager(name, baseSalary, numEmployees, managersSupervised), companyPerformance(companyPerformance) {}

double Executive::calculateSalary() {
    const double bonusPerEmployee = 500.0;
    const double additionalBonusPerManager = 2000.0;
    const double performanceBonusMultiplier = 0.5;
    return baseSalary + (bonusPerEmployee * get_numEmployess()) + (additionalBonusPerManager * get_supervised()) + (performanceBonusMultiplier * companyPerformance);
}

void Executive::displayInfo() const {
    std::cout << "Executive: " << name << ", Base Salary: " << baseSalary << " Employees Managed: " << get_numEmployess() << " Managers Supervised: " << get_supervised() << " Company Performance: " << get_performance() << std::endl;
}

void Executive::set_performance(double performance) {
    this->companyPerformance = performance;
}

double Executive::get_performance() const {
    return this->companyPerformance;
}


