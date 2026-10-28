#include <stdio.h>

#define EMPLOYEE_COUNT 50

int main()
{
    float salary;
    float total = 0.0f;
    float highest = 0.0f;
    float lowest = 0.0f;
    float average;
    int employee;SS

    printf("MUNICIPAL EMPLOYEE SALARY ANALYSIS\n\n");

    for (employee = 1; employee <= EMPLOYEE_COUNT; employee++)
    {
        printf("Enter salary for employee %d: ", employee);
        scanf("%f", &salary);

        total = total + salary;

        if (employee == 1)
        {
            highest = salary;
            lowest = salary;
        }

        if (salary > highest)
        {
            highest = salary;
        }

        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    average = total / EMPLOYEE_COUNT;

    printf("\n------------------------------------\n");
    printf("SALARY REPORT\n");
    printf("------------------------------------\n");
    printf("Total Salary   = %.2f\n", total);
    printf("Average Salary = %.2f\n", average);
    printf("Highest Salary = %.2f\n", highest);
    printf("Lowest Salary  = %.2f\n", lowest);
    printf("------------------------------------\n");

    return 0;
}