#include "../include/newEmployee.hpp"

#include "../include/myLibrary.hpp"

#define maxEmployees 100
int employeeCount = 0;

Employee storedEmployees[maxEmployees];

Employee::Employee() {
  this->name = "";
  this->salary = 0;
}

void Employee::setName(std::string name) { this->name = name; }

void Employee::setSalary(int salary) { this->salary = salary; }

int Employee::getSalary() const { return salary; }

std::string Employee::getName() const { return name; }

void Employee::display() const {
  std::cout << "Name: Mr." << Employee::getName()
            << ", Salary: " << Employee::getSalary() << "LE" << std::endl;
}

void emp() {
  int count;
  std::string name;
  int salary;

  std::cout << "Enter employee count: ";
  std::cin >> count;

  if (count <= 0 || employeeCount + count > maxEmployees) {
    std::cout << "Invalid employee count." << std::endl;
    return;
  }

  for (int i = 0; i < count; i++) {
    std::cout << "Employee " << i + 1 << std::endl;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    std::cout << "Enter salary: " << std::endl;
    std::cin >> salary;
    if (std::cin.fail()) {
      std::cout << "Invalid syntax." << std::endl;
    }

    storeData(name, salary);
  }
}

void storeData(std::string name, int salary) {
  if (employeeCount >= maxEmployees) return;

  storedEmployees[employeeCount].setName(name);
  storedEmployees[employeeCount].setSalary(salary);

  employeeCount++;
}

void displayEmp() {
  for (int i = 0; i < employeeCount; i++) {
    storedEmployees[i].display();
  }
}
