#include <stdio.h>
#include "config.h"
#include "budget.h"
#include "utilities.h"

static double revenue = 0.0;
static double expenses = 0.0;

void addBudget(void)
{
    revenue = readDouble("Enter total revenue: ");
    expenses = readDouble("Enter total expenses: ");
    printf("Budget captured successfully.\n");
}

void listBudgets(void)
{
    printf("\n------------------------------------\n");
    printf("BUDGET REPORT\n");
    printf("------------------------------------\n");
    printf("Revenue  = %.2f\n", revenue);
    printf("Expenses = %.2f\n", expenses);
    printf("Balance  = %.2f\n", calculateBudgetBalance());
}

double calculateBudgetBalance(void)
{
    return revenue - expenses;
}

void saveBudgetsText(void)
{
    FILE *file = fopen(BUDGET_TEXT_FILE, "w");

    if (file == NULL)
    {
        perror(BUDGET_TEXT_FILE);
        return;
    }

    fprintf(file, "%.2f|%.2f\n", revenue, expenses);
    fclose(file);
    printf("Budget record saved to text file.\n");
}

void loadBudgetsText(void)
{
    FILE *file = fopen(BUDGET_TEXT_FILE, "r");

    if (file == NULL)
    {
        perror(BUDGET_TEXT_FILE);
        return;
    }

    if (fscanf(file, "%lf|%lf", &revenue, &expenses) == 2)
    {
        printf("Budget record loaded from text file.\n");
    }
    else
    {
        printf("Budget file is malformed.\n");
    }

    fclose(file);
}
