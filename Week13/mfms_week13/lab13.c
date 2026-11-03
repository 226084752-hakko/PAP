/* lab13.c - Week 13: unlimited employees with malloc() and realloc() */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    int capacity = 2;            /* slots available */
    int count = 0;               /* slots used */
    int i;
    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    /* TODO 1: malloc room for 'capacity' employees */
    employees = malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0) {
        printf("Name (one word): ");
        scanf("%29s", e.name);
        printf("Salary: ");
        scanf("%lf", &e.salary);

        /* TODO 2: full? double the capacity using a temporary pointer */
        if (count == capacity) {
            capacity = capacity * 2;
            bigger = realloc(employees, capacity * sizeof(Employee));
            if (bigger == NULL) {
                free(employees);          /* old block still valid: free it */
                return 1;
            }
            employees = bigger;
            printf(" (grown to %d slots)\n", capacity);
        }

        /* TODO 3: store e, then count++ */
        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    /* TODO 4: display everyone, then the count and capacity */
    for (i = 0; i < count; i++) {
        printf("%d %s N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("Employees: %d | Capacity: %d\n", count, capacity);

    /* TODO 5: give the memory back */
    free(employees);
    employees = NULL;

    return 0;
}
