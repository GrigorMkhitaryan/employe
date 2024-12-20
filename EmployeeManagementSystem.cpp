#include <iostream>
#include "Developer.hpp"
#include "Manager.hpp"
#include "SeniorManager.hpp"
#include "Salesperson.hpp"
#include "Executive.hpp"
#include "EmployeeManagementSystem.hpp"

void EmployeeManagementSystem::addEmployee(Employee* employee) {
    employees.push_back(employee);
}

void EmployeeManagementSystem::displayAllEmployees() const {
    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i]->displayInfo();
    }
}

void EmployeeManagementSystem::calculateTotalSalary() const {
    double totalSalary = 0;
    for (int index = 0; index < employees.size(); ++index) {
        totalSalary += employees[index]->calculateSalary();
    }
    std::cout << "Total Salary of all employees: " << totalSalary << "\n";
}

void EmployeeManagementSystem::searchEmployeeByName(const std::string& name) const {
    for (int index = 0; index < employees.size(); ++index) {
        if (employees[index]->getName() == name) {
            employees[index]->displayInfo();
            return;
        }
    }
    std::cout << "Employee not found\n";
}

void EmployeeManagementSystem::searchEmployeeByRole(const std::string& role) const {
    for (int index = 0; index < employees.size(); ++index) {
        if (role == "Developer") {
            Developer* dev = dynamic_cast<Developer*>(employees[index]);
            if (dev) {
                dev->displayInfo();
            }
        }
        else if (role == "Manager") {
            Manager* mgr = dynamic_cast<Manager*>(employees[index]);
            if (mgr) {
                mgr->displayInfo();
            }
        }
        else if (role == "Salesperson") {
            Salesperson* sales = dynamic_cast<Salesperson*>(employees[index]);
            if (sales) {
                sales->displayInfo();
            }
        }
        else if (role == "SeniorManager") {
            SeniorManager* seniorMgr = dynamic_cast<SeniorManager*>(employees[index]);
            if (seniorMgr) {
                seniorMgr->displayInfo();
            }
        }
        else if (role == "Executive") {
            Executive* exec = dynamic_cast<Executive*>(employees[index]);
            if (exec) {
                exec->displayInfo();
            }
        }
    }
}

void EmployeeManagementSystem::removeEmployeeByName(const std::string& name) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i]->getName() == name) {
            delete employees[i];
            employees.erase(employees.begin() + i);
            return;
        }
    }
    std::cout << "Employee not found for removal\n";
}

EmployeeManagementSystem::~EmployeeManagementSystem() {
    for (int index = 0; index < employees.size(); ++index) {
        delete employees[index];
    }
}

