#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "utilities.h"

void displayMainMenu(void)
{
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Add Employee\n");
    printf("2. Employee Operations\n");
    printf("3. Supplier Operations\n");
    printf("4. Budget Operations\n");
    printf("5. Asset Operations\n");
    printf("6. View Summary Report\n");
    printf("7. Save All Text Data\n");
    printf("8. Load All Text Data\n");
    printf("9. Save Employee Binary Data\n");
    printf("10. Load Employee Binary Data\n");
    printf("11. Exit\n");
}

void employeeOperations(void)
{
    int choice;

    printf("\n1. List Employees\n");
    printf("2. Search Employee\n");
    choice = readInt("Enter choice: ");

    if (choice == 1)
    {
        listEmployees();
    }
    else if (choice == 2)
    {
        searchEmployee();
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

void supplierOperations(void)
{
    int choice;

    printf("\n1. Add Supplier\n");
    printf("2. List Suppliers\n");
    printf("3. Search Supplier\n");
    choice = readInt("Enter choice: ");

    if (choice == 1)
    {
        addSupplier();
    }
    else if (choice == 2)
    {
        listSuppliers();
    }
    else if (choice == 3)
    {
        searchSupplier();
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

void budgetOperations(void)
{
    int choice;

    printf("\n1. Capture Budget\n");
    printf("2. View Budget\n");
    choice = readInt("Enter choice: ");

    if (choice == 1)
    {
        addBudget();
    }
    else if (choice == 2)
    {
        listBudgets();
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

void assetOperations(void)
{
    int choice;

    printf("\n1. Add Asset\n");
    printf("2. List Assets\n");
    choice = readInt("Enter choice: ");

    if (choice == 1)
    {
        addAsset();
    }
    else if (choice == 2)
    {
        listAssets();
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

int main(void)
{
    int choice;

    do
    {
        displayMainMenu();
        choice = readInt("Enter choice: ");

        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                employeeOperations();
                break;
            case 3:
                supplierOperations();
                break;
            case 4:
                budgetOperations();
                break;
            case 5:
                assetOperations();
                break;
            case 6:
                displaySummaryReport();
                break;
            case 7:
                saveEmployeesText();
                saveSuppliersText();
                saveAssetsText();
                saveBudgetsText();
                break;
            case 8:
                loadEmployeesText();
                loadSuppliersText();
                loadAssetsText();
                loadBudgetsText();
                break;
            case 9:
                saveEmployeesBinary();
                break;
            case 10:
                loadEmployeesBinary();
                break;
            case 11:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 11);

    return 0;
}
