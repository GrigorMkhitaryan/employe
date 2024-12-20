#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include "Employee.hpp"

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

#endif // DEVELOPER_HPP

