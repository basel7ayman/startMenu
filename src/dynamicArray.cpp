#include "../include/dynamicArray.hpp"

#include "../include/myLibrary.hpp"
#include "../include/newEmployee.hpp"

void empDynamic(dynArr& d1) {
  int count;
  std::string name;
  int salary;

  std::cout << "Enter employee count: ";
  std::cin >> count;

  if (std::cin.fail() || count <= 0) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid employee count." << std::endl << std::flush;
    std::cout << "Try Again with lower number." << std::endl << std::flush;
    wait(1);
    return;
  }

  for (int i = 0; i < count; i++) {
    std::cout << "Employee " << i + 1 << std::endl;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    if (checkName(name) == 0) {
      std::cout << "Invalid name, please try again." << std::endl;
      std::cin.clear();
      i--;  // repeat this employee
      continue;
    }

    std::cout << "Enter salary: " << std::endl;
    std::cin >> salary;

    if (std::cin.fail()) {
      std::cout << "Invalid salary, please try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      i--;  // repeat this employee
      continue;
    }
    addEmployee(d1, name, salary);
  }
}

void initArr(dynArr& d) { d.empPtr = new employee[d.capacity]; }

void addEmployee(dynArr& d, std::string name, int salary) {
  if (d.empCount == d.capacity) {
    resizeArr(d);
  }
  d.empPtr[d.empCount] = {name, salary};
  d.empCount++;
}

void resizeArr(dynArr& d) {
  d.capacity = d.capacity * 2;
  employee* ptr;
  ptr = new employee[d.capacity];
  for (int i = 0; i < d.empCount; i++) {
    ptr[i] = d.empPtr[i];
  }
  delete[] d.empPtr;
  d.empPtr = ptr;
}

void displayEmployees(dynArr& d) {
  for (int i = 0; i < d.empCount; i++) {
    std::cout << "Name: Mr." << d.empPtr[i].name
              << ", Salary: " << d.empPtr[i].salary << "LE" << std::endl;
  }
}

void freeArr(dynArr& d) {
  delete[] d.empPtr;
  d.empPtr = nullptr;
  d.empCount = 0;
  d.capacity = 8;
}