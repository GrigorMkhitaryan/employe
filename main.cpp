#include "Employee.hpp"

int main() {
    EmployeeManagementSystem ems;

    // Create some employees
    Developer* dev1 = new Developer("John Doe", 60000, 5);
    Manager* mgr1 = new Manager("Jane Smith", 80000, 10);
    Salesperson* sales1 = new Salesperson("Jim Brown", 40000, 50000);
    SeniorManager* seniorMgr1 = new SeniorManager("Paul White", 100000, 5, 2);
    Executive* exec1 = new Executive("Mary Green", 150000, 20, 5, 2.5);

    // Add them to the system
    ems.addEmployee(dev1);
    ems.addEmployee(mgr1);
    ems.addEmployee(sales1);
    ems.addEmployee(seniorMgr1);
    ems.addEmployee(exec1);

    // Display all employees
    std::cout << "All Employees:\n";
    ems.displayAllEmployees();

    // Calculate total salary
    ems.calculateTotalSalary();

    // Search for an employee by name
    std::cout << "\nSearch for employee 'Jane Smith':\n";
    ems.searchEmployeeByName("Jane Smith");

    // Search for employees by role
    std::cout << "\nSearch for Managers:\n";
    ems.searchEmployeeByRole("Manager");

    // Remove an employee
    ems.removeEmployeeByName("John Doe");

    // Display remaining employees
    std::cout << "\nRemaining Employees after removal:\n";
    ems.displayAllEmployees();

    return 0;
}

