#include "../include/stack.hpp"
int Stack::activeStacksCount = 0;

int Stack::getactiveStacksCount() {
  // LOG(this->top);//Compiler Error Unabialable for Static memberFunction
  return activeStacksCount;
}
Stack::Stack() {
  activeStacksCount++;
  LOG("No Parameter Constructor Stack()");
  this->sizeArray = 10;
  this->top = -1;
  this->items = new int[sizeArray]{0};
  // ctor
}
Stack::Stack(Stack& s) {
  activeStacksCount++;
  LOG("Copy Constructor :: ");
  this->items = new int[s.sizeArray];
  this->sizeArray = s.sizeArray;
  this->top = s.top;
  for (int i = 0; i <= top; i++) {
    this->items[i] = s.items[i];
  }
}
Stack::Stack(int sizeArray) {
  activeStacksCount++;
  LOG("Parameter Constructor Stack()");
  this->sizeArray = sizeArray;
  this->top = -1;
  this->items = new int[sizeArray];
  // ctor
}
void Stack::push(int data) {
  // 5 items push() push()   push() push() push()
  if (top >= sizeArray - 1) {  // 5
    LOG("Stack is FUll");
    return;  // Early Exit
  }
  top++;  // 0        1        2      3      4
  LOG("We Write index :" << top);
  items[top] = data;
}
int Stack::pop(int* data) {
  if (top == -1) {
    // LOG("Stack Empty");
    return 0;
    // return ??
  }
  *data = items[top];
  items[top] = 0;
  // LOG("Before POP"<<top);
  top--;
  // LOG("After POP"<<top);
  return 1;
}
void Stack::display(void) {
  for (int i = top; i >= 0; i--) {
    LOG(items[i] << "--->");
  }
}
Stack& Stack::operator=(const Stack s) {
  LOG("Assgiment Operator :: ");
  delete[] this->items;
  items = new int[s.sizeArray];
  this->sizeArray = s.sizeArray;
  this->top = s.top;
  for (int i = 0; i <= top; i++) {
    this->items[i] = s.items[i];
  }
  return *this;
}

Stack::~Stack() {
  LOG("Destructor");
  activeStacksCount--;
  delete[] items;
  // dtor
}
