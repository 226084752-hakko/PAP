/* lab12.c - Week 12 lab demo: Parts A to D (links with records.c) */
#include <stdio.h>
#include "records.h"

int main(void)
{
    /* ---------- Part A: warm-up ---------- */
    printf("=== Part A: int and pointer ===\n");
    int age = 25;
    int *p = &age;
    printf("value = %d, address = %p, *p = %d\n", age, (void *)&age, *p);
    *p = 30;
    printf("After *p = 30 -> age = %d\n", age);

    int *np = NULL;
    if (np == NULL) printf("np is NULL - not safe to dereference.\n");

    /* ---------- Part B: swap salaries ---------- */
    printf("\n=== Part B: swap salaries ===\n");
    double a = 18500.50, b = 21000.75;
    printf("Before:        A = %.2f, B = %.2f\n", a, b);
    swapWrong(a, b);
    printf("After swapWrong:  A = %.2f, B = %.2f   (unchanged - copies!)\n", a, b);
    swapSalaries(&a, &b);
    printf("After swapSalaries: A = %.2f, B = %.2f (swapped)\n", a, b);

    /* ---------- Part C: arrays to functions ---------- */
    printf("\n=== Part C: arrays and functions ===\n");
    double salaries[4] = {15000.00, 18500.50, 21000.75, 17200.00};
    printf("Before raise:\n");
    displaySalaries(salaries, 4);
    printf("Highest: N$%.2f | Average: N$%.2f\n",
           findHighest(salaries, 4), calculateAverage(salaries, 4));
    giveRaise(salaries, 4, 10.0);
    printf("After 10%% raise (original array changed):\n");
    displaySalaries(salaries, 4);
    printf("Highest: N$%.2f | Average: N$%.2f\n",
           findHighest(salaries, 4), calculateAverage(salaries, 4));

    /* ---------- Part D: modify employee records ---------- */
    printf("\n=== Part D: employee records ===\n");
    Employee staff[5] = {
        {1001, "Maria", "Finance", 18500.50},
        {1002, "Simon", "Roads",   17200.00},
        {1003, "Anna",  "Water",   21000.75}
    };
    int count = 3;
    Employee *found;

    found = findEmployee(staff, count, 1002);             /* test 1: found */
    if (found != NULL) {
        updateSalary(found, 19000.00);
        printf("Found %s, now earns N$%.2f\n", found->name, found->salary);
    }
    found = findEmployee(staff, count, 9999);             /* test 2: not found */
    if (found == NULL) printf("ID 9999 not found - friendly message works.\n");

    found = findEmployee(staff, count, 1001);             /* test 3: updated twice */
    if (found != NULL) {
        updateSalary(found, 20000.00);
        printf("%s update #1: N$%.2f\n", found->name, found->salary);
        updateSalary(found, 22500.00);
        printf("%s update #2: N$%.2f\n", found->name, found->salary);
    }

    /* ---------- Extensions ---------- */
    printf("\n=== Extensions ===\n");
    int i, j;
    for (i = 0; i < count - 1; i++)                       /* sort high -> low */
        for (j = 0; j < count - 1 - i; j++)
            if (staff[j].salary < staff[j + 1].salary)
                swapEmployees(&staff[j], &staff[j + 1]);
    printf("Sorted by salary (highest first):\n");
    for (i = 0; i < count; i++)
        printf("  %s N$%.2f\n", staff[i].name, staff[i].salary);

    printf("\nAddresses:\n");
    for (i = 0; i < count; i++)
        printf("  &staff[%d] = %p\n", i, (void *)&staff[i]);
    printf("Difference between neighbours = %lu bytes; sizeof(Employee) = %zu bytes\n",
           (unsigned long)((char *)&staff[1] - (char *)&staff[0]), sizeof(Employee));
    return 0;
}
