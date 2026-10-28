#include <stdio.h>
#include "config.h"
#include "employees.h"
#include "utilities.h"

typedef struct
{
    int id;
    char name[50];
    double salary;
} Employee;

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

void addEmployee(void)
{
    if (employeeCount == MAX_EMPLOYEES)
    {
        printf("Employee storage is full.\n");
        return;
    }

    employees[employeeCount].id = readInt("Enter employee ID: ");
    readLine("Enter employee name: ", employees[employeeCount].name, 50);
    employees[employeeCount].salary = readDouble("Enter employee salary: ");
    employeeCount++;
    printf("Employee added successfully.\n");
}

void listEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("No employees have been added.\n");
        return;
    }

    printf("\n------------------------------------\n");
    printf("EMPLOYEE REPORT\n");
    printf("------------------------------------\n");
    for (i = 0; i < employeeCount; i++)
    {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].salary);
    }
}

void searchEmployee(void)
{
    int id = readInt("Enter employee ID to search for: ");
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("Employee found: %s | Salary: %.2f\n",
                   employees[i].name, employees[i].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

double calculatePayrollTotal(void)
{
    double total = 0.0;
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        total += employees[i].salary;
    }

    return total;
}

int getEmployeeCount(void)
{
    return employeeCount;
}

void saveEmployeesText(void)
{
    FILE *file = fopen(EMPLOYEE_TEXT_FILE, "w");
    int i;

    if (file == NULL)
    {
        perror(EMPLOYEE_TEXT_FILE);
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        fprintf(file, "%d|%s|%.2f\n",
                employees[i].id, employees[i].name, employees[i].salary);
    }

    fclose(file);
    printf("%d employee record(s) saved to text file.\n", employeeCount);
}

void loadEmployeesText(void)
{
    FILE *file = fopen(EMPLOYEE_TEXT_FILE, "r");

    if (file == NULL)
    {
        perror(EMPLOYEE_TEXT_FILE);
        return;
    }

    employeeCount = 0;
    while (employeeCount < MAX_EMPLOYEES &&
           fscanf(file, "%d|%49[^|]|%lf\n",
                  &employees[employeeCount].id,
                  employees[employeeCount].name,
                  &employees[employeeCount].salary) == 3)
    {
        employeeCount++;
    }

    fclose(file);
    printf("%d employee record(s) loaded from text file.\n", employeeCount);
}

void saveEmployeesBinary(void)
{
    FILE *file = fopen(EMPLOYEE_BINARY_FILE, "wb");

    if (file == NULL)
    {
        perror(EMPLOYEE_BINARY_FILE);
        return;
    }

    if (fwrite(&employeeCount, sizeof employeeCount, 1, file) != 1 ||
        fwrite(employees, sizeof employees[0], employeeCount, file) != (size_t)employeeCount)
    {
        perror("Error writing binary employees");
    }
    else
    {
        printf("%d employee record(s) saved to binary file.\n", employeeCount);
    }

    fclose(file);
}

void loadEmployeesBinary(void)
{
    FILE *file = fopen(EMPLOYEE_BINARY_FILE, "rb");
    int storedCount;

    if (file == NULL)
    {
        perror(EMPLOYEE_BINARY_FILE);
        return;
    }

    if (fread(&storedCount, sizeof storedCount, 1, file) != 1 ||
        storedCount < 0 || storedCount > MAX_EMPLOYEES ||
        fread(employees, sizeof employees[0], storedCount, file) != (size_t)storedCount)
    {
        printf("Unable to load a valid binary employee file.\n");
        fclose(file);
        return;
    }

    employeeCount = storedCount;
    fclose(file);
    printf("%d employee record(s) loaded from binary file.\n", employeeCount);
}
