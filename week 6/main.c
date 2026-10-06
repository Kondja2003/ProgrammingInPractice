/*
 * PAP521S - Programming in Practice
 * Week 6 Practical Lab: Municipal Information Management System
 *
 * Part A: Employee salaries      (float salaries[50])
 * Part B: Department budgets     (float budgets[10])
 * Part C: Vehicle registrations  (char registrations[20][20])
 */

#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS 10
#define NUM_REGS 20
#define REG_LEN 20

int main() {
    /* ---------- Declarations ---------- */
    float salaries[NUM_SALARIES];
    float budgets[NUM_BUDGETS];
    char registrations[NUM_REGS][REG_LEN];

    float total, average, highest, lowest, temp;
    float searchValue;
    char searchReg[REG_LEN];
    int found;

    /* =====================================================
     * PART A: EMPLOYEE SALARIES
     * ===================================================== */
    printf("=========== PART A: EMPLOYEE SALARIES ===========\n");

    /* 1. Capture 50 salaries */
    for (int i = 0; i < NUM_SALARIES; i++) {
        do {
            printf("Enter salary for employee %d: ", i + 1);
            scanf("%f", &salaries[i]);
            if (salaries[i] <= 0) {
                printf("  Salary must be positive. Try again.\n");
            }
        } while (salaries[i] <= 0);
    }

    /* 2. Display all salaries */
    printf("\n--- All Salaries ---\n");
    for (int i = 0; i < NUM_SALARIES; i++) {
        printf("Employee %2d: %.2f\n", i + 1, salaries[i]);
    }

    /* 3-5. Total, average, highest, lowest */
    total = 0;
    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < NUM_SALARIES; i++) {
        total = total + salaries[i];
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }
    average = total / NUM_SALARIES;

    printf("\n--- Salary Report ---\n");
    printf("Total salary expenditure: %.2f\n", total);
    printf("Average salary:           %.2f\n", average);
    printf("Highest salary:           %.2f\n", highest);
    printf("Lowest salary:            %.2f\n", lowest);

    /* 6. Search for a particular salary (linear search) */
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchValue);

    found = 0;
    for (int i = 0; i < NUM_SALARIES; i++) {
        if (salaries[i] == searchValue) {
            printf("Salary %.2f found for employee %d (index %d)\n",
                   searchValue, i + 1, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Salary %.2f not found.\n", searchValue);
    }

    /* =====================================================
     * PART B: DEPARTMENT BUDGETS
     * ===================================================== */
    printf("\n\n=========== PART B: DEPARTMENT BUDGETS ===========\n");

    /* 1. Capture 10 budgets */
    for (int i = 0; i < NUM_BUDGETS; i++) {
        do {
            printf("Enter budget for department %d: ", i + 1);
            scanf("%f", &budgets[i]);
            if (budgets[i] < 0) {
                printf("  Budget cannot be negative. Try again.\n");
            }
        } while (budgets[i] < 0);
    }

    /* 2. Display the budgets */
    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("Department %2d: %.2f\n", i + 1, budgets[i]);
    }

    /* 3-4. Total and average */
    total = 0;
    for (int i = 0; i < NUM_BUDGETS; i++) {
        total = total + budgets[i];
    }
    average = total / NUM_BUDGETS;

    printf("\nTotal municipal budget:   %.2f\n", total);
    printf("Average department budget: %.2f\n", average);

    /* 5. Sort budgets lowest to highest (bubble sort) */
    for (int i = 0; i < NUM_BUDGETS - 1; i++) {
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");
    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("%2d. %.2f\n", i + 1, budgets[i]);
    }

    /* =====================================================
     * PART C: VEHICLE REGISTRATION NUMBERS
     * ===================================================== */
    printf("\n\n=========== PART C: VEHICLE REGISTRATIONS ===========\n");

    /* 1. Capture 20 registration numbers */
    for (int i = 0; i < NUM_REGS; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    /* 2. Display all registration numbers */
    printf("\n--- Vehicle Registrations ---\n");
    for (int i = 0; i < NUM_REGS; i++) {
        printf("%2d. %s\n", i + 1, registrations[i]);
    }

    /* 3. Search for a particular registration number */
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);

    found = 0;
    for (int i = 0; i < NUM_REGS; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration %s found at position %d (index %d)\n",
                   searchReg, i + 1, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Registration %s not found.\n", searchReg);
    }

    return 0;
}