# Saltos - Crossing the River with Jumps

## Description
This project was developed for the "Projeto e Otimização de Algoritmos" (Algorithm Design and Optimization) course. The goal is to compute the number of ways to cross a river using a sequence of stones, considering specific jump constraints. The problem consists of a binary-like string where `1` represents a stone, `0` represents a missing stone, and `m` marks the riverbanks.

The program calculates the number of valid ways to traverse the river, following these rules:
- Allowed jumps: 1, 2, or 3 meters.
- A jump of 3 meters cannot be followed by another jump of 3 meters.
- The solution must be implemented in three different ways:
  1. **Simple recursive approach**
  2. **Recursive approach with memoization**
  3. **Non-recursive (iterative) approach**

## Features
- Computes all possible ways to cross the river while following the given constraints.
- Implements three different algorithmic approaches to optimize performance.
- Command-line input support.

## Installation & Compilation
### Requirements
- A C++ compiler (e.g., `g++` for Linux/macOS, `MinGW` for Windows)

### Compilation
Since the project was initially written in C (`main.c`) and later transitioned to C++ (`main.cpp`), compile the appropriate version as follows:

#### Compiling the C Version:
```sh
gcc -o saltos main.c -Wall
```

#### Compiling the C++ Version:
```sh
g++ -o saltos main.cpp -Wall
```

## Usage
Run the compiled executable with a valid input string representing the river and the stone positions:

```sh
./saltos m101101001m
```

Example output:
```
Recursive approach: There are 1234 ways
Memoized recursive approach: There are 1234 ways
Iterative approach: There are 1234 ways
```

## Technologies Used
- **C / C++** for algorithm implementation
- **Dynamic programming** for optimization

## License
This project is for educational purposes and does not include a specific license.

## Author
Developed as part of a university project for the "Projeto e Otimização de Algoritmos" course.


