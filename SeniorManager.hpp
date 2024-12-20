#ifndef SENIORMANAGER_HPP
#define SENIORMANAGER_HPP

#include "Manager.hpp"

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

#endif // SENIORMANAGER_HPP

