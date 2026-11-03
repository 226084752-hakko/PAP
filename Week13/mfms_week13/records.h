/* records.h - the five MFMS record types and their functions */
#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired;          /* nested structure */
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;         /* nested structures */
    Date endDate;
} Project;

/* One array + one counter per record type (defined in records.c) */
/* Employees now live on the HEAP: no fixed upper limit (Week 13) */
#define INITIAL_CAPACITY 2
extern Employee *employees;  extern int employeeCount;  extern int employeeCapacity;
extern Supplier suppliers[MAX_RECORDS];  extern int supplierCount;
extern Asset    assets[MAX_RECORDS];     extern int assetCount;
extern Budget   budgets[MAX_RECORDS];    extern int budgetCount;
extern Project  projects[MAX_RECORDS];   extern int projectCount;

/* Add / display */
void addEmployee(void);   void displayEmployees(void);
void addSupplier(void);   void displaySuppliers(void);
void addAsset(void);      void displayAssets(void);
void addBudget(void);     void displayBudgets(void);
void addProject(void);    void displayProjects(void);

/* Binary file persistence (fwrite / fread) */
void saveAll(void);
void loadAll(void);

/* ===== Week 12: pointers ===== */
void   swapSalaries(double *a, double *b);              /* pass by address */
void   swapWrong(double a, double b);                   /* pass by value (fails) */
void   displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
double calculateAverage(const double salaries[], int n);
void   giveRaise(double salaries[], int n, double percent);
void   updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id); /* NULL if not found */
void   updateEmployeeSalaryMenu(void);
void   swapEmployees(Employee *a, Employee *b);
void   increaseBudget(Budget *b, double amount);
void   increaseBudgetMenu(void);

/* ===== Week 13: dynamic memory ===== */
int  initEmployees(void);               /* malloc the starting array   */
void freeEmployees(void);               /* free() the array            */
void searchEmployeeMenu(void);          /* search by ID                */
int  removeEmployee(int id);            /* extension: delete + shift   */
void removeEmployeeMenu(void);
void shrinkEmployees(void);             /* extension: shrink to fit    */

#endif
