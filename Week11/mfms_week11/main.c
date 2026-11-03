/* main.c - MFMS Week 11: store and display the five record types */
#include <stdio.h>
#include "records.h"

static void showMenu(void)
{
    printf("\n===== MFMS - Week 11 =====\n");
    printf("Employees: %d, Suppliers: %d, Assets: %d, Budgets: %d, Projects: %d\n",
           employeeCount, supplierCount, assetCount, budgetCount, projectCount);
    printf(" 1. Add Employee      2. Display Employees\n");
    printf(" 3. Add Supplier      4. Display Suppliers\n");
    printf(" 5. Add Asset         6. Display Assets\n");
    printf(" 7. Add Budget        8. Display Budgets\n");
    printf(" 9. Add Project      10. Display Projects\n");
    printf("11. Save all to files 12. Load all from files\n");
    printf(" 0. Exit\n");
}

int main(void)
{
    int choice;
    char line[32];

    loadAll();                       /* pick up data from a previous run */
    do {
        showMenu();
        printf("Choice: ");
        if (fgets(line, sizeof line, stdin) == NULL) break;
        if (sscanf(line, "%d", &choice) != 1) choice = -1;

        switch (choice) {
            case 1:  addEmployee();      break;
            case 2:  displayEmployees(); break;
            case 3:  addSupplier();      break;
            case 4:  displaySuppliers(); break;
            case 5:  addAsset();         break;
            case 6:  displayAssets();    break;
            case 7:  addBudget();        break;
            case 8:  displayBudgets();   break;
            case 9:  addProject();       break;
            case 10: displayProjects();  break;
            case 11: saveAll();          break;
            case 12: loadAll();          break;
            case 0:  saveAll(); printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
