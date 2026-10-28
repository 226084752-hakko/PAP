#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void displaySummaryReport(void)
{
    printf("\n------------------------------------\n");
    printf("MUNICIPAL FINANCIAL SUMMARY REPORT\n");
    printf("------------------------------------\n");
    printf("Employees        = %d\n", getEmployeeCount());
    printf("Suppliers        = %d\n", getSupplierCount());
    printf("Assets           = %d\n", getAssetCount());
    printf("Total Payroll    = %.2f\n", calculatePayrollTotal());
    printf("Budget Balance   = %.2f\n", calculateBudgetBalance());
    printf("------------------------------------\n");
}
