#include "Developer.hpp"

Developer::Developer(const std::string& name, double baseSalary, int projects)
    : projects(projects) {
    this->name = name;
    this->baseSalary = baseSalary;
}

double Developer::calculateSalary() {
    const double bonusPerProject = 100.0;
    return baseSalary + (bonusPerProject * projects);
}

void Developer::displayInfo() const {
    std::cout << "Developer: " << name << " Base Salary: " << baseSalary << " Projects: " << projects << std::endl;
}

void Developer::set_projects(int project_count) {
    if (project_count < 0) {
        std::cerr << "Number of projects cannot be negative." << std::endl;
        projects = 0;
        return;
    }
    this->projects = project_count;
}

int Developer::get_projects() const {
    return this->projects;
}

