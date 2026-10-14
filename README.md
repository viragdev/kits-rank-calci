# KITS Student Rank Calculator 🎓

A small C project for my In-Semester 1 exams at **KITS Ramtek**. Each of the five subjects is out of 20, so the maximum total is 100.

## Features

- Enter marks for all five subjects
- Calculate total, percentage, grade, and pass/fail
- View class rankings and search by roll number
- Check class average, topper, and pass percentage
- Validate marks and prevent duplicate roll numbers

## Subjects

| Code | Subject | Faculty |
|---|---|---|
| CS | Communication Skills | Savita Jambhulkar Ma'am |
| PSC | Problem Solving Using C | S. K. Bhele Sir |
| AA | Applied Algebra | Jyoti Badwaik Ma'am |
| BE | Biology for Engineers | Savyasachi Sir |
| BEE | Basics of Electronics Engineering | Viplov Dhoke Sir |

## Run on Windows

Install GCC, open PowerShell in this folder, and run:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o kits_student_rank_calculator.exe
.\kits_student_rank_calculator.exe
```

## Notes

- The program uses example grading rules: 7/20 or more in each subject to pass, and overall percentage for the grade. These are **not confirmed official KITS rules**.
- Records are kept in memory and are cleared when the program exits.
- Built using C fundamentals, functions, arrays, structures, loops, searching, and sorting.

Made as a first-year C programming project.
