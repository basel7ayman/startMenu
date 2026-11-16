#include "../include/dynamicArray.hpp"
#include "../include/myLibrary.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

int main() {
  struct dynArr d;
  initArr(d);
  printMenu(MAGENTA, d);
  freeArr(d);

  return 0;
}