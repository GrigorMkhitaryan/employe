#include "SeniorManager.hpp"

SeniorManager::SeniorManager(const std::string& name, double baseSalary, int numEmployees, int managersSupervised)
    : Manager(name, baseSalary, numEmployees), managersSupervised(managersSupervised) {}

double SeniorManager::calculateSalary() {
    const double bonusPerEmployee = 300.0;
    const double additionalBonusPerManager = 500.0;
    return baseSalary + (bonusPerEmployee * get_numEmployess()) + (additionalBonusPerManager * managersSupervised);
}

void SeniorManager::displayInfo() const {
    std::cout << "Senior Manager: " << name << " Base Salary: " << baseSalary << " Employees Managed: " << get_numEmployess() << " Managers Supervised: " << managersSupervised << std::endl;
}

void SeniorManager::set_supervised(int supervise) {
    if (supervise < 0) {
        std::cerr << "Number of supervised cannot be negative." << std::endl;
        managersSupervised = 0;
        return;
    }
    this->managersSupervised = supervise;
}

int SeniorManager::get_supervised() const {
    return this->managersSupervised;
}

