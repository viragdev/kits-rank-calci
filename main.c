/*
 * KITS Student Rank Calculator
 * First-year engineering C programming project.
 *
 * College: Kavikulaguru Institute of Technology and Science (KITS), Ramtek
 * Branch: CSE (AI/ML)
 *
 * This program records marks for five first-semester subjects, calculates
 * results, ranks students by percentage, and displays class statistics.
 *
 * Student records are kept in memory for the current run only.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define SUBJECT_COUNT 5
#define NAME_LENGTH 60
#define PASS_MARKS 35

typedef struct {
    const char *code;
    const char *name;
    const char *faculty;
} Subject;

static const Subject subjects[SUBJECT_COUNT] = {
    {"CS",  "Communication Skills",                    "Savita Jambhulkar Ma'am"},
    {"PSC", "Problem Solving Using C",                 "S. K. Bhele Sir"},
    {"AA",  "Applied Algebra",                          "Jyoti Badwaik Ma'am"},
    {"BE",  "Biology for Engineers",                    "Savyasachi Sir"},
    {"BEE", "Basics of Electronics Engineering",        "Viplov Dhoke Sir"}
};

typedef struct {
    int roll_number;
    char name[NAME_LENGTH];
    int marks[SUBJECT_COUNT];
    int total;
    float percentage;
    char grade[3];
    int passed;
} Student;

static Student students[MAX_STUDENTS];
static int student_count = 0;

static void read_line(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);

    if (fgets(buffer, (int)size, stdin) == NULL) {
        printf("\nInput ended. Closing the program.\n");
        exit(EXIT_SUCCESS);
    }

    size_t length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    } else {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Clear any extra characters from an overlong input line. */
        }
    }
}

static int read_int_range(const char *prompt, int minimum, int maximum) {
    char input[128];

    for (;;) {
        char *end_pointer;
        long value;

        read_line(prompt, input, sizeof(input));
        errno = 0;
        value = strtol(input, &end_pointer, 10);

        while (isspace((unsigned char)*end_pointer)) {
            end_pointer++;
        }

        if (input[0] == '\0' || end_pointer == input || *end_pointer != '\0' ||
            errno != 0 || value < minimum || value > maximum) {
            printf("Please enter a whole number from %d to %d.\n",
                   minimum, maximum);
            continue;
        }

        return (int)value;
    }
}

static void read_student_name(char *name, size_t size) {
    for (;;) {
        read_line("Student name: ", name, size);

        int has_text = 0;
        for (size_t i = 0; name[i] != '\0'; i++) {
            if (!isspace((unsigned char)name[i])) {
                has_text = 1;
                break;
            }
        }

        if (!has_text) {
            printf("Name cannot be blank. Please try again.\n");
            continue;
        }

        for (size_t i = 0; name[i] != '\0'; i++) {
            if (name[i] == '\t') {
                name[i] = ' ';
            }
        }
        return;
    }
}

static int find_student_index(int roll_number) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            return i;
        }
    }
    return -1;
}

static void calculate_result(Student *student) {
    student->total = 0;
    student->passed = 1;

    for (int i = 0; i < SUBJECT_COUNT; i++) {
        student->total += student->marks[i];
        if (student->marks[i] < PASS_MARKS) {
            student->passed = 0;
        }
    }

    student->percentage =
        (float)student->total / (SUBJECT_COUNT * 100) * 100.0f;

    if (!student->passed) {
        strcpy(student->grade, "F");
    } else if (student->percentage >= 90.0f) {
        strcpy(student->grade, "A+");
    } else if (student->percentage >= 80.0f) {
        strcpy(student->grade, "A");
    } else if (student->percentage >= 70.0f) {
        strcpy(student->grade, "B");
    } else if (student->percentage >= 60.0f) {
        strcpy(student->grade, "C");
    } else if (student->percentage >= 50.0f) {
        strcpy(student->grade, "D");
    } else {
        strcpy(student->grade, "E");
    }
}

/* Students with the same percentage receive the same rank. */
static int get_rank(const Student *student) {
    int rank = 1;

    for (int i = 0; i < student_count; i++) {
        if (students[i].percentage > student->percentage) {
            rank++;
        }
    }

    return rank;
}

static void print_student_details(const Student *student) {
    printf("\nStudent: %s\n", student->name);
    printf("Roll number: %d\n", student->roll_number);
    printf("---------------------------------------------\n");

    for (int i = 0; i < SUBJECT_COUNT; i++) {
        printf("%s (%s): %d/100\n",
               subjects[i].code, subjects[i].name, student->marks[i]);
    }

    printf("Total: %d/%d\n", student->total, SUBJECT_COUNT * 100);
    printf("Percentage: %.2f%%\n", student->percentage);
    printf("Grade: %s\n", student->grade);
    printf("Result: %s\n", student->passed ? "PASS" : "FAIL");
    printf("Class rank: %d\n", get_rank(student));
}

static void add_student(void) {
    if (student_count >= MAX_STUDENTS) {
        printf("\nThe record limit of %d students has been reached.\n",
               MAX_STUDENTS);
        return;
    }

    Student new_student = {0};

    printf("\nAdd a student record\n");
    printf("--------------------\n");

    new_student.roll_number =
        read_int_range("Roll number (1-999999): ", 1, 999999);

    if (find_student_index(new_student.roll_number) != -1) {
        printf("That roll number is already in the records.\n");
        return;
    }

    read_student_name(new_student.name, sizeof(new_student.name));

    printf("\nEnter marks out of 100 for each subject.\n");
    for (int i = 0; i < SUBJECT_COUNT; i++) {
        char prompt[180];
        snprintf(prompt, sizeof(prompt), "%s - %s: ",
                 subjects[i].code, subjects[i].name);
        new_student.marks[i] = read_int_range(prompt, 0, 100);
    }

    calculate_result(&new_student);
    students[student_count] = new_student;
    student_count++;

    printf("\nRecord added.\n");
    print_student_details(&students[student_count - 1]);
}

static void display_rank_list(void) {
    if (student_count == 0) {
        printf("\nNo records yet. Add a student first.\n");
        return;
    }

    /* Sort indices rather than moving the original student records. */
    int order[MAX_STUDENTS];
    for (int i = 0; i < student_count; i++) {
        order[i] = i;
    }

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[order[j]].percentage >
                students[order[i]].percentage) {
                int temporary = order[i];
                order[i] = order[j];
                order[j] = temporary;
            }
        }
    }

    printf("\nClass rank list\n");
    printf("--------------------------------------------------------------------------\n");
    printf("%-6s %-9s %-22s %-10s %-12s %-7s %-7s\n",
           "Rank", "Roll No.", "Student name", "Total", "Percentage",
           "Grade", "Result");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < student_count; i++) {
        const Student *student = &students[order[i]];
        printf("%-6d %-9d %-22.22s %3d/%-5d %-11.2f%% %-7s %-7s\n",
               get_rank(student), student->roll_number, student->name,
               student->total, SUBJECT_COUNT * 100, student->percentage,
               student->grade, student->passed ? "PASS" : "FAIL");
    }
}

static void search_student(void) {
    if (student_count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int roll_number =
        read_int_range("\nEnter roll number to search: ", 1, 999999);
    int index = find_student_index(roll_number);

    if (index == -1) {
        printf("No student found with roll number %d.\n", roll_number);
        return;
    }

    print_student_details(&students[index]);
}

static void show_class_summary(void) {
    if (student_count == 0) {
        printf("\nNo records available for the class summary.\n");
        return;
    }

    int total_marks = 0;
    int passed_count = 0;
    int topper_index = 0;

    for (int i = 0; i < student_count; i++) {
        total_marks += students[i].total;

        if (students[i].passed) {
            passed_count++;
        }

        if (students[i].percentage > students[topper_index].percentage) {
            topper_index = i;
        }
    }

    float class_average =
        (float)total_marks / (student_count * SUBJECT_COUNT);
    float pass_percentage =
        (float)passed_count / student_count * 100.0f;

    printf("\nClass performance summary\n");
    printf("-------------------------\n");
    printf("Students recorded: %d\n", student_count);
    printf("Class average: %.2f%%\n", class_average);
    printf("Students passed: %d\n", passed_count);
    printf("Students failed: %d\n", student_count - passed_count);
    printf("Pass percentage: %.2f%%\n", pass_percentage);
    printf("Topper: %s (Roll No. %d, %.2f%%)\n",
           students[topper_index].name,
           students[topper_index].roll_number,
           students[topper_index].percentage);
}

static void show_project_info(void) {
    printf("\nKITS Student Rank Calculator\n");
    printf("Kavikulaguru Institute of Technology and Science, Ramtek\n");
    printf("Branch: CSE (AI/ML) | First-year C programming project\n\n");
    printf("Subjects and faculty\n");
    printf("--------------------\n");

    for (int i = 0; i < SUBJECT_COUNT; i++) {
        printf("%s - %s | %s\n",
               subjects[i].code, subjects[i].name, subjects[i].faculty);
    }

    printf("\nProject rules\n");
    printf("-------------\n");
    printf("Five subjects, each out of 100 marks.\n");
    printf("A student must score at least %d in every subject to pass.\n",
           PASS_MARKS);
    printf("Grades: A+ (90+), A (80+), B (70+), C (60+), D (50+), E (35+), F (failed subject).\n");
    printf("These are project rules for demonstration, not official KITS grading rules.\n");
    printf("Records remain in memory and are cleared when the program exits.\n");
}

static void show_menu(void) {
    printf("\nKITS Student Rank Calculator\n");
    printf("1. Add student marks\n");
    printf("2. View class rank list\n");
    printf("3. Search by roll number\n");
    printf("4. View class summary\n");
    printf("5. About this project\n");
    printf("6. Exit\n");
}

int main(void) {
    printf("KITS Student Rank Calculator\n");
    printf("CSE (AI/ML) | KITS Ramtek\n");

    for (;;) {
        show_menu();
        int choice = read_int_range("Choose an option (1-6): ", 1, 6);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_rank_list();
                break;
            case 3:
                search_student();
                break;
            case 4:
                show_class_summary();
                break;
            case 5:
                show_project_info();
                break;
            case 6:
                printf("\nThanks for using the KITS Student Rank Calculator.\n");
                return 0;
        }
    }
}
