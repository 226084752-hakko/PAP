#include <stdio.h>
#include <string.h>

#define SALARY_COUNT 50
#define BUDGET_COUNT 10
#define REGISTRATION_COUNT 20

int main()
{
    float salaries[SALARY_COUNT];
    float budgets[BUDGET_COUNT];
    char registrations[REGISTRATION_COUNT][20];
    float totalSalary = 0.0f;
    float highestSalary = 0.0f;
    float lowestSalary = 0.0f;
    float totalBudget = 0.0f;
    float searchSalary;
    char searchRegistration[20];
    int salaryFound = 0;
    int registrationFound = 0;
    int i;
    int j;
    float temporaryBudget;

    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n\n");

    printf("EMPLOYEE SALARIES\n");
    for (i = 0; i < SALARY_COUNT; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary += salaries[i];

        if (i == 0)
        {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    printf("\nDEPARTMENT BUDGETS\n");
    for (i = 0; i < BUDGET_COUNT; i++)
    {
        printf("Enter budget %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget += budgets[i];
    }

    for (i = 0; i < BUDGET_COUNT - 1; i++)
    {
        for (j = 0; j < BUDGET_COUNT - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temporaryBudget = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temporaryBudget;
            }
        }
    }

    printf("\nVEHICLE REGISTRATIONS\n");
    for (i = 0; i < REGISTRATION_COUNT; i++)
    {
        printf("Enter registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);

    for (i = 0; i < SALARY_COUNT; i++)
    {
        if (salaries[i] == searchSalary)
        {
            salaryFound = 1;
            printf("Salary found at position %d.\n", i + 1);
            break;
        }
    }

    if (salaryFound == 0)
    {
        printf("Salary not found.\n");
    }

    printf("Enter registration to search for: ");
    scanf("%19s", searchRegistration);

    for (i = 0; i < REGISTRATION_COUNT; i++)
    {
        if (strcmp(registrations[i], searchRegistration) == 0)
        {
            registrationFound = 1;
            printf("Registration found at position %d.\n", i + 1);
            break;
        }
    }

    if (registrationFound == 0)
    {
        printf("Registration not found.\n");
    }

    printf("\n------------------------------------\n");
    printf("EMPLOYEE SALARY REPORT\n");
    printf("------------------------------------\n");
    for (i = 0; i < SALARY_COUNT; i++)
    {
        printf("Salary %d = %.2f\n", i + 1, salaries[i]);
    }
    printf("Average Salary = %.2f\n", totalSalary / SALARY_COUNT);
    printf("Highest Salary = %.2f\n", highestSalary);
    printf("Lowest Salary  = %.2f\n", lowestSalary);

    printf("\nDEPARTMENT BUDGET REPORT\n");
    for (i = 0; i < BUDGET_COUNT; i++)
    {
        printf("Budget %d = %.2f\n", i + 1, budgets[i]);
    }
    printf("Total Budget   = %.2f\n", totalBudget);
    printf("Average Budget = %.2f\n", totalBudget / BUDGET_COUNT);

    printf("\nVEHICLE REGISTRATION REPORT\n");
    for (i = 0; i < REGISTRATION_COUNT; i++)
    {
        printf("Registration %d = %s\n", i + 1, registrations[i]);
    }

    return 0;
}
