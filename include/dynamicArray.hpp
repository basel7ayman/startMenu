#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <string>

struct employee {
  std::string name;
  int salary;
};

struct dynArr {
  employee* empPtr = nullptr;
  int empCount = 0;
  int capacity = 8;
};

void empDynamic(dynArr&);
void initArr(dynArr&);
void addEmployee(dynArr&, std::string, int);
void resizeArr(dynArr&);
void displayEmployees(dynArr&);
void freeArr(dynArr&);

#endif  // DYNARR.HPP
