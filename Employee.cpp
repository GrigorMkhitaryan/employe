#include "Employee.hpp"

void Employee::set_BaseSalary(double new_baseSalary) {
    baseSalary = new_baseSalary;
}

double Employee::get_BaseSalary() const {
    return this->baseSalary;
}

const std::string& Employee::getName() const {
    return name;
}

Employee::~Employee() {}

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

Manager::Manager(const std::string& name, double baseSalary, int numEmployees)
    : numEmployees(numEmployees) {
    this->name = name;
    this->baseSalary = baseSalary;
}

double Manager::calculateSalary() {
    const double bonusPerEmployee = 200.0;
    return baseSalary + (bonusPerEmployee * numEmployees);
}

void Manager::displayInfo() const {
    std::cout << "Manager: " << name << " Base Salary: " << baseSalary << " Employees Managed: " << numEmployees << std::endl;
}

void Manager::set_numEmployess(int employess) {
    if (employess < 0) {
        std::cerr << "Number of employees cannot be negative." << std::endl;
        numEmployees = 0;
        return;
    }
    this->numEmployees = employess;
}

int Manager::get_numEmployess() const {
    return this->numEmployees;
}

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

