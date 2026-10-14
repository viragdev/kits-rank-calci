# KITS Student Rank Calculator 🎓

A simple C project I built as a first-year CSE (AI/ML) student at **Kavikulaguru Institute of Technology and Science (KITS), Ramtek**.

The idea is to make student result calculations easier while practising the concepts I'm learning in PSC.

## Features

- Add student details and subject marks
- Calculate total, percentage, grade, and pass/fail status
- View the class rank list
- Search students by roll number
- Check class average, topper, and pass percentage
- Validate marks and prevent duplicate roll numbers

## Subjects and Faculty

| Code | Subject | Faculty |
|---|---|---|
| CS | Communication Skills | Savita Jambhulkar Ma'am |
| PSC | Problem Solving Using C | S. K. Bhele Sir |
| AA | Applied Algebra | Jyoti Badwaik Ma'am |
| BE | Biology for Engineers | Savyasachi Sir |
| BEE | Basics of Electronics Engineering | Viplov Dhoke Sir |

## Run the Project

You'll need GCC or another C compiler.

**Windows (GCC):**

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o kits_student_rank_calculator.exe
.\kits_student_rank_calculator.exe
```

## Concepts Used

C basics, loops, conditional statements, arrays, strings, structures, functions, pointers, searching, and sorting.

## Note

This project uses sample grading rules for demonstration. Student records are stored in memory and are cleared when the program exits.

## Future Improvements

- Save records using file handling
- Edit and delete student records
- Add subject-wise statistics
- Export results to CSV

---

Made as a learning project while exploring C programming at KITS Ramtek.
