#ifndef MYLIBRARY_HPP
#define MYLIBRARY_HPP

#include <iostream>
#include <thread>

#include "../include/dynamicArray.hpp"

void breakLine();
void moveTo(int row, int col);
void color(std::string a);
void clearScreen();
void defaultColor();
void printMenu(std::string, dynArr&);
void wait(int);
bool checkName(std::string);

#endif  // MYLIBRARY_HPP