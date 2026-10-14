# KITS Student Rank Calculator

A menu-driven C program for entering first-semester student marks, calculating results, ranking students, and viewing a simple class performance summary.

Made as a first-year C programming project for **CSE (AI/ML)** at **Kavikulaguru Institute of Technology and Science (KITS), Ramtek**.

## Features

- Add student records with a roll number and name
- Enter marks for the five first-semester subjects
- Calculate total marks, percentage, grade, and pass/fail result
- View the class rank list, ordered by percentage
- Give students with equal percentages the same rank
- Search for a student by roll number
- View class average, topper, pass count, fail count, and pass percentage
- Validate marks, roll numbers, and basic user input
- Reject duplicate roll numbers

## Subjects and faculty

The subjects and faculty names below reflect the first-semester details entered for this project.

| Code | Subject | Faculty |
|---|---|---|
| CS | Communication Skills | Savita Jambhulkar Ma'am |
| PSC | Problem Solving Using C | S. K. Bhele Sir |
| AA | Applied Algebra | Jyoti Badwaik Ma'am |
| BE | Biology for Engineers | Savyasachi Sir |
| BEE | Basics of Electronics Engineering | Viplov Dhoke Sir |

## Project rules

- Five subjects, each out of 100 marks
- A student must score at least 35 marks in every subject to pass
- Grades: A+ (90% and above), A (80% and above), B (70% and above), C (60% and above), D (50% and above), E (35% and above), F if any subject is failed

**Important:** These grading and passing rules are example rules for this project, not official KITS examination rules. Confirm the college's official rules before using this program for actual academic results.

## Requirements

- GCC or another C11-compatible compiler
- Windows, Linux, or macOS terminal

## Compile and run

### Windows (GCC / MinGW)

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o kits_student_rank_calculator.exe
.\kits_student_rank_calculator.exe
```

### Linux

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o kits_student_rank_calculator
./kits_student_rank_calculator
```

### macOS

```bash
clang -std=c11 -Wall -Wextra -Wpedantic main.c -o kits_student_rank_calculator
./kits_student_rank_calculator
```

## Menu

1. Add student marks
2. View class rank list
3. Search by roll number
4. View class summary
5. About this project
6. Exit

## Concepts used

- Variables, constants, data types, and formatted input/output
- `if-else`, loops, and `switch`
- Arrays and strings
- Structures (`struct`)
- Functions and pointers
- Searching and sorting
- Input validation
- Basic class statistics

## Current limitation

Records are stored in memory and are cleared when the program exits. This version is a learning project, not an official college result system.

## Possible future improvements

- Save and load records with file handling
- Edit or delete records
- Add subject-wise averages and highest marks
- Export the rank list to CSV
- Add a graphical interface

## License

Released under the MIT License. See [`LICENSE`](LICENSE).
