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
extern Employee employees[MAX_RECORDS];  extern int employeeCount;
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

#endif
