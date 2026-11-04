#include "../include/myLibrary.hpp"
#define row 5
#define col 10

int main() {
  int selectedIndex = 0;

  clearScreen();

  moveTo(row, col);
  std::cout << "Main Menu" << std::endl;
  for (int i = 1; i <= 3; i++) {
    moveTo(row + i, col);
    if (selectedIndex == i - 1)
      color(BLUE);
    else
      defaultColor();
    std::cout << i << ". "
              << (i == 1   ? "Start"
                  : i == 2 ? "Settings"
                           : "Exit")
              << std::endl;
  }
  defaultColor();

  return 0;
}