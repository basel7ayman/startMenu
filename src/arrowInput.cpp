#include <termios.h>
#include <unistd.h>

#include <cstdio>
#include <iostream>

#include "../include/myLibrary.hpp"
#include "../include/newEmployee.hpp"

char getch_linux() {
  char buf = 0;  // Variable to store the input character

  struct termios old = {0};  // Structure to save current terminal settings

  // Save the current terminal settings
  tcgetattr(0, &old);

  // Disable Canonical Mode (do not wait for Enter key)
  old.c_lflag &= ~ICANON;

  // Disable Echo so typed characters are not displayed
  old.c_lflag &= ~ECHO;

  // Require at least one character to be read
  old.c_cc[VMIN] = 0;

  // No timeout while waiting for input
  old.c_cc[VTIME] = 0.1;

  // Apply the modified settings immediately
  tcsetattr(0, TCSANOW, &old);

  // Read a single character immediately from the keyboard
  read(0, &buf, 1);

  // Re-enable Canonical Mode
  old.c_lflag |= ICANON;

  // Re-enable Echo
  old.c_lflag |= ECHO;

  // Restore the terminal to its original settings
  tcsetattr(0, TCSADRAIN, &old);

  // Return the character that was read
  return buf;
}

void showOP() {
  // Display instructions for the user
  std::printf(
      "Press the arrow keys to test the program (press 'q' to quit):\n");
  char byte1 = 'q';
  char byte2 = 'q';
  char byte3 = 'q';

  // Read input until the user chooses to quit
  do {
    // CHANGED: wait until a real key arrives (getch_linux returns 0 on timeout)
    do {
      byte1 = getch_linux();
    } while (byte1 == 0);

    // CHANGED: print readable names for Enter and ESC instead of raw bytes
    if (byte1 == '\n') {
      // std::cout << "Byte 1 :: Enter" << std::endl;

    } else if (byte1 == '\033') {
      // std::cout << "Byte 1 :: ^[" << std::endl;
    }

    // If the key is the beginning of an arrow-key escape sequence
    if (byte1 == '\033') {
      // CHANGED: a 0 here means no more bytes came in time, so it was a lone
      // ESC
      byte2 = getch_linux();
      if (!byte2 == 0) {
        // std::cout << "ESC pressed alone" << std::endl;

        // std::cout << "Byte 2 :: " << byte2 << std::endl;
        byte3 = getch_linux();
        // std::cout << "Byte 3 :: " << byte3 << std::endl;

        switch (byte3) {
          case 'A':
            std::printf("↑ Up Arrow\n");
            break;
          case 'B':
            std::printf("↓ Down Arrow\n");
            break;
          case 'C':
            std::printf("→ Right Arrow\n");
            break;
          case 'D':
            std::printf("← Left Arrow\n");
            break;
          case 'H':
            std::printf("Home Button\n");
            break;
          case 'F':
            std::printf("End Button\n");
            break;
          default:
            std::printf("Unknown escape sequence\n");
            break;
        }
      }
    }
    std::cout << "=================================" << std::endl;
  } while (byte1 != 'q' && byte1 != 'Q');
  // Exit the program successfully
}