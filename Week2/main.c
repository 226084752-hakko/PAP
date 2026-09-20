#include <stdio.h>

int main() {
    double revenue = 0.0;
    double expenses = 0.0;
    double balance = 0.0;

    printf("===========================================\n");
    printf("        MUNICIPAL BUDGET CALCULATOR        \n");
    printf("===========================================\n\n");
    printf("Enter total municipal revenue ($): ");
    if (scanf("%lf", &revenue) != 1) {
        printf("Error: Invalid numerical input for revenue.\n");
        return 1;
    }
    printf("Enter total municipal expenses ($): ");
    if (scanf("%lf", &expenses) != 1) {
        printf("Error: Invalid numerical input for expenses.\n");
        return 1;
    }
    balance = revenue - expenses;

    printf("\n===========================================\n");
    printf("             FINANCIAL REPORT              \n");
    printf("===========================================\n");
    printf("Total Revenue:  $%15.2f\n", revenue);
    printf("Total Expenses: $%15.2f\n", expenses);
    printf("-------------------------------------------\n");
    printf("Net Balance:    $%15.2f\n", balance);
    printf("-------------------------------------------\n");
    if (balance > 0.0) {
        printf("Status: SURPLUS of $%'.2f\n", balance);
    } else if (balance < 0.0) {
        printf("Status: DEFICIT of $%'.2f\n", balance);
    } else {
        printf("Status: BALANCED BUDGET ($0.00)\n");
    }
    printf("===========================================\n");

    return 0;
}