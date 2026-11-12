#ifndef MYLIBRARY_HPP
#define MYLIBRARY_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void breakLine();
void moveTo(int row, int col);
void color(std::string a);
void clearScreen();
void defaultColor();
void printMenu();
void home(char);

#endif  // MYLIBRARY_HPP