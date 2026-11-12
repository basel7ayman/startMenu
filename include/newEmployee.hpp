#ifndef NEWEMP_HPP
#define NEWEMP_HPP

#include <string>

class Employee {
 private:
  std::string name;
  int salary;

 public:
  Employee();
  Employee(std::string name, int salary);

  void setName(std::string name);
  void setSalary(int salary);

  std::string getName() const;
  int getSalary() const;

  void display() const;
};

void emp();
void storeData(std::string, int);
void displayEmp();

#endif