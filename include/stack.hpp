#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#define LOG(str) std::cout << str << std::endl  // Macors
class Stack {
 private:
  int top;
  int sizeArray;
  int *items;
  // 1. Declare a static variable to count active stacks
  static int activeStacksCount;

 public:
  Stack();
  Stack(int sizeArray);
  ~Stack();
  Stack(Stack &s);
  void push(int data);
  int pop(int *data);
  void display(void);
  Stack &operator=(const Stack s);
  int getactiveStacksCount();
};

#endif  // STACK_HPP
