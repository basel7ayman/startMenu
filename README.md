# Start Menu

A C++ terminal app that combines a simple employee-management menu with Linux terminal input handling. The project was built to learn how arrow keys, escape sequences, and terminal control work in a Unix-like environment.

## Overview
This project started as a keyboard-input experiment and expanded into a small console application with:

- An interactive main menu
- Dynamic employee storage using a resizeable array
- Static employee storage using a class-based design
- Arrow-key navigation in the terminal
- Colored terminal output and screen-clearing utilities
- Input validation for names and salaries

## Features
- Detects arrow keys and escape sequences from terminal input
- Supports menu navigation using the keyboard
- Lets the user add employees dynamically
- Displays stored employees in the terminal
- Validates employee names and numeric input
- Uses ANSI escape codes to move the cursor and clear the screen
- Exits when the user presses `q` or selects the exit option

## Project idea
The original goal was to understand how Linux terminal input works, especially escape sequences such as `ESC [ A`, `ESC [ B`, and other arrow-key codes. The project also demonstrates basic C++ data structures, object-oriented programming, and console UI patterns.

## Project structure

```text
startMenu/
├── README.md
├── main
├── .vscode/
│   ├── c_cpp_properties.json
│   └── tasks.json
├── include/
│   ├── arrowInput.hpp
│   ├── dynamicArray.hpp
│   ├── myLibrary.hpp
│   └── newEmployee.hpp
├── src/
│   ├── arrowInput.cpp
│   ├── dynamicArray.cpp
│   ├── myLibrary.cpp
│   ├── newEmployee.cpp
│   └── main.cpp
└── (compiled binary: main)
```

## File details

### Core entry point
- `src/main.cpp`  
  Starts the program, initializes the employee array, and launches the main menu.

### Terminal input and arrow-key detection
- `include/arrowInput.hpp`  
  Declares the raw keyboard input helper for Linux terminals.
- `src/arrowInput.cpp`  
  Uses `termios` and `read()` to read single keys without waiting for Enter. Detects arrow keys and other escape sequences.

### Dynamic employee management
- `include/dynamicArray.hpp`  
  Defines the `employee` struct and the dynamic array structure `dynArr`.
- `src/dynamicArray.cpp`  
  Implements employee insertion, resizing, display, and cleanup for the dynamic storage system.

### Menu and console utilities
- `include/myLibrary.hpp`  
  Declares console helpers such as screen clearing, cursor movement, wait functions, and the menu renderer.
- `src/myLibrary.cpp`  
  Handles ANSI screen control, menu display, validation logic, and keyboard-driven menu navigation.

### Static employee storage using a class
- `include/newEmployee.hpp`  
  Declares the `Employee` class and static storage functions.
- `src/newEmployee.cpp`  
  Implements the Employee class, validation, and static employee array operations.

### VS Code build configuration
- `.vscode/tasks.json`  
  Contains build and run tasks for compiling the project and launching it from VS Code.
- `.vscode/c_cpp_properties.json`  
  Provides C/C++ IntelliSense configuration for the project.

## Build and run
From the project root, run:

```bash
g++ ./src/*.cpp -o main
./main
```

This project is designed for Linux terminals and uses terminal control features that may not behave the same in Windows terminals.

## ChatGPT reference
[View the ChatGPT discussion 1](https://chatgpt.com/share/6aeb8e39-b160-83ea-b9fd-dbb3dc4b6cd1)
[View the ChatGPT discussion 2](https://chatgpt.com/share/6afb7a5e-20a0-83ea-bbdc-1232d0fa3ceb)
