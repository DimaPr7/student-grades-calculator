# Student Sorting Program

This program implements two strategies for categorizing students into two groups ("failed" and "passed") based on their grades. It evaluates the performance of these strategies with different container types: **Vector**, **List**, and **Deque**. The program measures execution times to compare the efficiency of different approaches.

## Table of Contents
- [Strategies](#strategies)
- [Performance](#performance)
- [Requirements](#requirements)
- [How to Run](#how-to-run)
    - [With Make](#with-make)
    - [With CMake](#with-cmake)
- [File Structure](#file-structure)
- [Notes](#notes)
- [Example Output](#example-output)
- [License](#license)

## Strategies:
The program offers two strategies for categorizing students:

### **Strategy 1: Split into Two Containers**
- **Description**: Students are copied into two new containers: one for "passed" students and one for "failed" students. The original "students" container retains all the data.
- **Memory Usage**: Less efficient as it duplicates data.

### **Strategy 2: Split into One Container**
- **Description**: Students who fail are moved to the "failed" container, and removed from the original container. The base container only retains "passed" students.
- **Memory Usage**: More efficient as it modifies the original container in-place.

## Performance:
The program compares execution times of both strategies with different container types. Below are the results for 1,000,000 students:

### **Strategy 1 (Splitting into Two Containers)**:
- **Vector**: 8500 ms
- **List**: 600 ms
- **Deque**: 500 ms

### **Strategy 2 (Splitting into One Container)**:
- **Vector**: 1200 ms
- **List**: 600 ms
- **Deque**: 1100 ms

## Requirements:
- **C++11 or higher**.
- A **C++ compiler** such as `g++`.

## How to Run:

### **With Make:**
1. Clone the repository.
2. In the terminal, run:
   ```bash
   make

# How to Run

## With Make:
1. Clone the repository:
   `git clone <repository-url>`

2. Navigate to the project directory:
   `cd <project-directory>`

3. In the terminal, run:
   `make`

4. After compilation, run the program:
   `./student_sorting`

## With CMake:
1. Clone the repository:
   `git clone <repository-url>`

2. Navigate to the project directory:
   `cd <project-directory>`

3. In the terminal, run:
   `cmake .`  
   `make`

4. After compilation, run the program:
   `./student_sorting`

# File Structure

The repository contains the following files:

- `main.cpp`: The main entry point of the program.
- `Person.cpp`, `Person.h`: Contains the definition of the Person class representing a student.
- `FileUtils.cpp`, `FileUtils.h`: Functions for generating and reading student data.
- `students.txt`: File containing randomly generated student data.

# Notes

- The program generates random student data and saves it in the `students.txt` file.
- The program uses the `std::remove_if` algorithm to efficiently filter students based on their grades.

# Example Output

Random data generated in file: `students.txt`  
**Strategy 1 (Splitting into two containers):**  
Time (Vector): 8500 ms  
Time (List): 600 ms  
Time (Deque): 500 ms

**Strategy 2 (Splitting into one container):**  
Time (Vector): 1200 ms  
Time (List): 600 ms  
Time (Deque): 1100 ms

Data processing completed!

# Clean Up

To remove compiled files and the executable, run:  
`make clean`

# License

This project is licensed under the MIT License.