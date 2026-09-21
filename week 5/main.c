#include <stdio.h>

#define EMPLOYEES 50

int main(void) {
    float salary;
    float total = 0.0f;
    float average;
    float highest = 0.0f;
    float lowest = 0.0f;

    for (int i = 1; i <= EMPLOYEES; i++) {
        do {
            printf("Enter salary for employee %d: ", i);
            scanf("%f", &salary);

            if (salary < 0) {
                printf("Salary cannot be negative. Please try again.\n");
            }

        } while (salary < 0);

        total += salary;

        /*
         * The first salary is used to initialise
         * both highest and lowest.
         */
        if (i == 1) {
            highest = salary;
            lowest = salary;
        }

        if (salary > highest) {
            highest = salary;
        }

        if (salary < lowest) {
            lowest = salary;
        }
    }

    average = total / EMPLOYEES;

    printf("\n========== SALARY REPORT ==========\n");
    printf("Total salary expenditure: %.2f\n", total);
    printf("Average salary:           %.2f\n", average);
    printf("Highest salary:           %.2f\n", highest);
    printf("Lowest salary:            %.2f\n", lowest);
    printf("===================================\n");

    return 0;
}