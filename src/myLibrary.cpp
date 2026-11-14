#include "../include/myLibrary.hpp"

#include "../include/arrowInput.hpp"
#include "../include/newEmployee.hpp"

#define row 5
#define col 25

int selectedIndex = 0;

void breakLine() {
  std::cout << std::endl
            << "==========================================================="
            << std::endl
            << std::endl;
}

void moveTo(int rows, int cols) {
  std::cout << "\033[" << rows << ";" << cols << "H";
}

void color(std::string a) { std::cout << a; }

void defaultColor() { std::cout << "\033[0m"; }

void clearScreen() {
  std::cout << "\033[2J"
            << "\033[H" << std::flush;
}

void printMenu() {
  clearScreen();

  moveTo(row, col);
  char byte1;
  char byte2;
  char byte3;

  std::cout << "Main Menu" << std::endl;

  // Read input until the user chooses to quit
  do {
    for (int i = 1; i <= 3; i++) {
      moveTo(row + i, col);
      if (selectedIndex == i - 1) {
        color(RED);
        std::cout << "→ ";
      } else
        defaultColor();
      std::cout << i << ". "
                << (i == 1   ? "New      "
                    : i == 2 ? "Display  "
                             : "Exit     ")
                << std::endl;
    }

    // CHANGED: wait until a real key arrives (getch_linux returns 0 on timeout)
    do {
      byte1 = getch_linux();
    } while (byte1 == 0);

    // CHANGED: print readable names for Enter and ESC instead of raw bytes
    if (byte1 == '\n' && selectedIndex == 0) {
      clearScreen();
      emp();
      printMenu();
    }
    if (byte1 == '\n' && selectedIndex == 1) {
      clearScreen();
      displayEmp();

      std::cout << std::endl
                << "Press 'Esc' to return to main menu..." << std::flush;
      do {
        byte1 = getch_linux();
        byte2 = getch_linux();
      } while (byte1 != '\033' || byte2 != 0);

      clearScreen();
      moveTo(row, col);
      std::cout << "Main Menu" << std::endl;
    }

    // If the key is the beginning of an arrow-key escape sequence
    if (byte1 == '\033') {
      // CHANGED: a 0 here means no more bytes came in time, so it was a lone
      // ESC
      byte2 = getch_linux();
      if (byte2 != 0) {
        // std::cout << "Byte 2 :: " << byte2 << std::endl;
        byte3 = getch_linux();
        switch (byte3) {
          case 'A':
            selectedIndex--;
            break;
          case 'B':
            selectedIndex++;
            break;
        }
        if (selectedIndex > 2) selectedIndex = 0;
        if (selectedIndex < 0) selectedIndex = 2;
      }
    }
  } while ((byte1 != '\n' || selectedIndex != 2) && byte1 != 'q');
}
