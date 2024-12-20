#ifndef EXECUTIVE_HPP
#define EXECUTIVE_HPP

#include "SeniorManager.hpp"

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

#endif // EXECUTIVE_HPP

