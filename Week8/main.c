#include <stdio.h>
#include <string.h>

float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void displayWelcome();
void displayMenu();
void supplierManagement();

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}

void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu()
{
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void supplierManagement()
{
    char supplier[100];
    char town[100];
    char description[250];

    getchar();
    printf("Enter supplier name: ");
    fgets(supplier, sizeof(supplier), stdin);
    supplier[strcspn(supplier, "\n")] = '\0';
    printf("Enter supplier town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    strcpy(description, supplier);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");

    printf("Supplier description: %s\n", description);
    printf("Supplier name length: %d\n", (int)strlen(supplier));
}

int main()
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int choice;
    int employeeID;
    int position;
    float amount;
    float basic;
    float housing;
    float transport;
    float revenue;
    float expenses;
    float balance;

    displayWelcome();

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Gross Salary = %.2f\n", calculateSalary(basic, housing, transport));
                break;

            case 2:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT = %.2f\n", calculateVAT(amount));
                break;

            case 3:
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget Balance = %.2f\n", balance);

                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;

            case 4:
                printf("Enter employee ID: ");
                scanf("%d", &employeeID);
                position = searchEmployee(employeeID, employeeIDs, 5);

                if (position >= 0)
                {
                    printf("Employee found at position %d.\n", position);
                }
                else
                {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                supplierManagement();
                break;

            case 6:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
