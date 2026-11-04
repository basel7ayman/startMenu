#include <iostream>

void moveTo(int row, int col) {
  std::cout << "\033[" << row << ";" << col << "H";
}
void color(std::string a) { std::cout << a; }
void defaultColor() { std::cout << "\033[0m"; }
void clearScreen() { std::cout << "\033[2J"; }