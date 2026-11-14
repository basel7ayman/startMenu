# Start Menu

A simple C++ project for testing keyboard input and arrow-key detection in the terminal.

## Features
- Detects arrow keys using terminal input
- Prints the raw key bytes for debugging
- Exits when the user presses `q` or `Q`
- Runs in a terminal-based console interface

## Project idea
This project was created to learn how Linux terminal input works, especially how escape sequences like `ESC [ A` are used for arrow keys.

## Run it
From the project root:

```bash
g++ src/*.cpp -o main
./main
```

## ChatGPT reference
[View the ChatGPT discussion](https://chatgpt.com/share/6aeb8e39-b160-83ea-b9fd-dbb3dc4b6cd1)
