#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
class Employee {
public:
    virtual double calculateSalary() = 0;  
    virtual void displayInfo() const = 0; 
    void set_BaseSalary(double new_baseSalary);
    double get_BaseSalary() const;
    virtual const std::string& getName() const;
    virtual ~Employee();

protected:
    std::string name;
    double baseSalary;
};

class Developer : public Employee {
public:
    Developer(const std::string& name, double baseSalary, int projects);
    virtual double calculateSalary() override;
    virtual void displayInfo() const override;
    void set_projects(int project_count);
    int get_projects() const;

private:
    int projects;
};

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

class Salesperson : public Employee {
public:
    Salesperson(const std::string& name, double baseSalary, double totalSales);
    virtual double calculateSalary() override;
    virtual void displayInfo() const override;
    void set_totalSales(int sales);
    int get_totalSales() const;

private:
    double totalSales;
};

class SeniorManager : public Manager {
public:
    SeniorManager(const std::string& name, double baseSalary, int numEmployees, int managersSupervised);
    virtual double calculateSalary() override;
    virtual void displayInfo() const override;
    void set_supervised(int supervise);
    int get_supervised() const;

private:
    int managersSupervised;
};

class Executive : public SeniorManager {
public:
    Executive(const std::string& name, double baseSalary, int numEmployees, int managersSupervised, double companyPerformance);
    virtual double calculateSalary() override;
    virtual void displayInfo() const override;
    void set_performance(double performance);
    double get_performance() const;

private:
    double companyPerformance;
};

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

#include "Employee.cpp"
#endif // EMPLOYEE_HPP

