/* records.c - capture, store, display, save and load the MFMS records */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "records.h"

Employee employees[MAX_RECORDS];  int employeeCount = 0;
Supplier suppliers[MAX_RECORDS];  int supplierCount = 0;
Asset    assets[MAX_RECORDS];     int assetCount = 0;
Budget   budgets[MAX_RECORDS];    int budgetCount = 0;
Project  projects[MAX_RECORDS];   int projectCount = 0;

/* ---------- small input helpers (read a whole line, then convert) ---------- */
static void readText(const char *prompt, char *dest, size_t size)
{
    printf("%s", prompt);
    if (fgets(dest, (int)size, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    dest[strcspn(dest, "\n")] = '\0';          /* remove the newline */
}

static int readInt(const char *prompt)
{
    char line[64];
    int value;
    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) return 0;
        if (sscanf(line, "%d", &value) == 1) return value;
        printf("  Please enter a whole number.\n");
    }
}

static double readDouble(const char *prompt)
{
    char line[64];
    double value;
    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) return 0.0;
        if (sscanf(line, "%lf", &value) == 1) return value;
        printf("  Please enter a number.\n");
    }
}

static Date readDate(const char *label)
{
    Date d;
    printf("%s\n", label);
    d.day   = readInt("  Day: ");
    d.month = readInt("  Month: ");
    d.year  = readInt("  Year: ");
    return d;
}

/* ---------- Employee ---------- */
void addEmployee(void)
{
    if (employeeCount >= MAX_RECORDS) {
        printf("Employee list is full (%d). Cannot add.\n", MAX_RECORDS);
        return;
    }
    Employee e;
    e.id = readInt("ID: ");
    readText("Name: ", e.name, sizeof e.name);
    readText("Department: ", e.department, sizeof e.department);
    e.salary = readDouble("Salary (N$): ");
    employees[employeeCount] = e;
    employeeCount++;
    printf("Employee added.\n");
}

void displayEmployees(void)
{
    int i;
    if (employeeCount == 0) { printf("No employees stored.\n"); return; }
    printf("\n%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Salary (N$)");
    for (i = 0; i < employeeCount; i++) {
        printf("%-6d %-20s %-15s %12.2f\n", employees[i].id, employees[i].name,
               employees[i].department, employees[i].salary);
    }
}

/* ---------- Supplier ---------- */
void addSupplier(void)
{
    if (supplierCount >= MAX_RECORDS) {
        printf("Supplier list is full (%d). Cannot add.\n", MAX_RECORDS);
        return;
    }
    Supplier s;
    s.id = readInt("ID: ");
    readText("Name: ", s.name, sizeof s.name);
    readText("Email: ", s.email, sizeof s.email);
    readText("Phone: ", s.phone, sizeof s.phone);
    readText("Town: ", s.town, sizeof s.town);
    suppliers[supplierCount] = s;
    supplierCount++;
    printf("Supplier added.\n");
}

void displaySuppliers(void)
{
    int i;
    if (supplierCount == 0) { printf("No suppliers stored.\n"); return; }
    printf("\n%-6s %-20s %-25s %-14s %-12s\n", "ID", "Name", "Email", "Phone", "Town");
    for (i = 0; i < supplierCount; i++) {
        printf("%-6d %-20s %-25s %-14s %-12s\n", suppliers[i].id, suppliers[i].name,
               suppliers[i].email, suppliers[i].phone, suppliers[i].town);
    }
}

/* ---------- Asset (nested Date) ---------- */
void addAsset(void)
{
    if (assetCount >= MAX_RECORDS) {
        printf("Asset list is full (%d). Cannot add.\n", MAX_RECORDS);
        return;
    }
    Asset a;
    a.id = readInt("ID: ");
    readText("Description: ", a.description, sizeof a.description);
    a.value = readDouble("Value (N$): ");
    a.acquired = readDate("Date acquired:");
    assets[assetCount] = a;
    assetCount++;
    printf("Asset added.\n");
}

void displayAssets(void)
{
    int i;
    if (assetCount == 0) { printf("No assets stored.\n"); return; }
    printf("\n%-6s %-25s %14s  %-10s\n", "ID", "Description", "Value (N$)", "Acquired");
    for (i = 0; i < assetCount; i++) {
        printf("%-6d %-25s %14.2f  %02d/%02d/%d\n", assets[i].id, assets[i].description,
               assets[i].value, assets[i].acquired.day, assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

/* ---------- Budget (balance = allocated - spent) ---------- */
void addBudget(void)
{
    if (budgetCount >= MAX_RECORDS) {
        printf("Budget list is full (%d). Cannot add.\n", MAX_RECORDS);
        return;
    }
    Budget b;
    readText("Department: ", b.department, sizeof b.department);
    b.allocated = readDouble("Allocated (N$): ");
    b.spent     = readDouble("Spent (N$): ");
    budgets[budgetCount] = b;
    budgetCount++;
    printf("Budget added.\n");
}

void displayBudgets(void)
{
    int i;
    if (budgetCount == 0) { printf("No budgets stored.\n"); return; }
    printf("\n%-15s %14s %14s %14s\n", "Department", "Allocated", "Spent", "Balance");
    for (i = 0; i < budgetCount; i++) {
        double balance = budgets[i].allocated - budgets[i].spent;
        printf("%-15s %14.2f %14.2f %14.2f%s\n", budgets[i].department,
               budgets[i].allocated, budgets[i].spent, balance,
               balance < 0 ? "  <-- OVERSPENT" : "");
    }
}

/* ---------- Project (two nested Dates) ---------- */
void addProject(void)
{
    if (projectCount >= MAX_RECORDS) {
        printf("Project list is full (%d). Cannot add.\n", MAX_RECORDS);
        return;
    }
    Project p;
    p.id = readInt("ID: ");
    readText("Title: ", p.title, sizeof p.title);
    p.budget = readDouble("Budget (N$): ");
    p.startDate = readDate("Start date:");
    p.endDate   = readDate("End date:");
    projects[projectCount] = p;
    projectCount++;
    printf("Project added.\n");
}

void displayProjects(void)
{
    int i;
    if (projectCount == 0) { printf("No projects stored.\n"); return; }
    printf("\n%-6s %-25s %14s  %-10s  %-10s\n", "ID", "Title", "Budget (N$)", "Start", "End");
    for (i = 0; i < projectCount; i++) {
        printf("%-6d %-25s %14.2f  %02d/%02d/%d  %02d/%02d/%d\n", projects[i].id,
               projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month, projects[i].startDate.year,
               projects[i].endDate.day, projects[i].endDate.month, projects[i].endDate.year);
    }
}

/* ---------- Files: fwrite() / fread() ---------- */
static int saveArray(const char *file, const void *data, size_t size, int count)
{
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) { perror(file); return 0; }
    fwrite(&count, sizeof count, 1, fp);             /* record count first */
    fwrite(data, size, (size_t)count, fp);           /* then all records   */
    fclose(fp);
    return 1;
}

static int loadArray(const char *file, void *data, size_t size, int *count)
{
    int n = 0;
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) return 0;                        /* no file yet: fine */
    if (fread(&n, sizeof n, 1, fp) != 1 || n < 0 || n > MAX_RECORDS) {
        fclose(fp);
        return 0;
    }
    n = (int)fread(data, size, (size_t)n, fp);
    fclose(fp);
    *count = n;
    return 1;
}

void saveAll(void)
{
    int ok = 1;
    ok &= saveArray("employees.dat", employees, sizeof employees[0], employeeCount);
    ok &= saveArray("suppliers.dat", suppliers, sizeof suppliers[0], supplierCount);
    ok &= saveArray("assets.dat",    assets,    sizeof assets[0],    assetCount);
    ok &= saveArray("budgets.dat",   budgets,   sizeof budgets[0],   budgetCount);
    ok &= saveArray("projects.dat",  projects,  sizeof projects[0],  projectCount);
    printf(ok ? "All records saved.\n" : "Some records could not be saved.\n");
}

void loadAll(void)
{
    int loaded = 0;
    loaded += loadArray("employees.dat", employees, sizeof employees[0], &employeeCount);
    loaded += loadArray("suppliers.dat", suppliers, sizeof suppliers[0], &supplierCount);
    loaded += loadArray("assets.dat",    assets,    sizeof assets[0],    &assetCount);
    loaded += loadArray("budgets.dat",   budgets,   sizeof budgets[0],   &budgetCount);
    loaded += loadArray("projects.dat",  projects,  sizeof projects[0],  &projectCount);
    printf("Loaded %d of 5 data files.\n", loaded);
}

/* =====================  WEEK 12 : POINTERS  ===================== */

/* Part B: swap salaries ------------------------------------------ */
void swapWrong(double a, double b)          /* works on COPIES - original unchanged */
{
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b)     /* works on the ORIGINALS */
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

/* Part C: arrays passed to functions ------------------------------ */
void displaySalaries(const double salaries[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];
    int i;
    for (i = 1; i < n; i++) {
        if (salaries[i] > highest) highest = salaries[i];
    }
    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;
    for (i = 0; i < n; i++) total += salaries[i];
    return total / n;
}

void giveRaise(double salaries[], int n, double percent)   /* changes the original */
{
    int i;
    for (i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

/* Part D: modify employee records through pointers ---------------- */
void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id)
{
    int i;
    for (i = 0; i < n; i++) {
        if (list[i].id == id) return &list[i];   /* address of the match */
    }
    return NULL;                                  /* not found */
}

void updateEmployeeSalaryMenu(void)
{
    int id = readInt("Employee ID to update: ");
    Employee *found = findEmployee(employees, employeeCount, id);

    if (found == NULL) {
        printf("No employee with ID %d was found.\n", id);
        return;
    }
    printf("Current record: %d | %s | %s | N$%.2f\n",
           found->id, found->name, found->department, found->salary);
    updateSalary(found, readDouble("New salary (N$): "));
    printf("Updated record: %d | %s | %s | N$%.2f\n",
           found->id, found->name, found->department, found->salary);
}

/* Extensions ------------------------------------------------------ */
void swapEmployees(Employee *a, Employee *b)
{
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

void increaseBudget(Budget *b, double amount)
{
    b->allocated += amount;
}

void increaseBudgetMenu(void)
{
    char dept[20];
    int i;
    readText("Department: ", dept, sizeof dept);
    for (i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].department, dept) == 0) {
            increaseBudget(&budgets[i], readDouble("Amount to add (N$): "));
            printf("%s now has N$%.2f allocated (balance N$%.2f).\n", budgets[i].department,
                   budgets[i].allocated, budgets[i].allocated - budgets[i].spent);
            return;
        }
    }
    printf("No budget found for department '%s'.\n", dept);
}
