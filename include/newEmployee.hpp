#ifndef NEWEMP_HPP
#define NEWEMP_HPP

#include <string>

class Employee {
 private:
  std::string name;
  int salary;

 public:
  Employee();

  void setName(std::string);
  void setSalary(int);

  std::string getName() const;
  int getSalary() const;

  void display() const;
};

void empStatic();
void storeData(std::string, int);
void displayEmp();

#endif