#include <stdio.h>
#include <string.h>
#include "config.h"
#include "suppliers.h"
#include "utilities.h"

typedef struct
{
    char name[50];
    char email[80];
    char phone[30];
    char town[50];
} Supplier;

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void addSupplier(void)
{
    if (supplierCount == MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    readLine("Enter supplier name: ", suppliers[supplierCount].name, 50);
    readLine("Enter supplier email: ", suppliers[supplierCount].email, 80);
    readLine("Enter supplier phone: ", suppliers[supplierCount].phone, 30);
    readLine("Enter supplier town: ", suppliers[supplierCount].town, 50);
    supplierCount++;
    printf("Supplier added successfully.\n");
}

void listSuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("No suppliers have been added.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("Name: %s | Email: %s | Phone: %s | Town: %s\n",
               suppliers[i].name, suppliers[i].email,
               suppliers[i].phone, suppliers[i].town);
    }
}

void searchSupplier(void)
{
    char name[50];
    int i;

    readLine("Enter supplier name to search for: ", name, 50);

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].name, name) == 0)
        {
            printf("Supplier found: %s | %s\n", suppliers[i].name, suppliers[i].town);
            return;
        }
    }

    printf("Supplier not found.\n");
}

int getSupplierCount(void)
{
    return supplierCount;
}

void saveSuppliersText(void)
{
    FILE *file = fopen(SUPPLIER_TEXT_FILE, "w");
    int i;

    if (file == NULL)
    {
        perror(SUPPLIER_TEXT_FILE);
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        fprintf(file, "%s|%s|%s|%s\n", suppliers[i].name, suppliers[i].email,
                suppliers[i].phone, suppliers[i].town);
    }

    fclose(file);
    printf("%d supplier record(s) saved to text file.\n", supplierCount);
}

void loadSuppliersText(void)
{
    FILE *file = fopen(SUPPLIER_TEXT_FILE, "r");

    if (file == NULL)
    {
        perror(SUPPLIER_TEXT_FILE);
        return;
    }

    supplierCount = 0;
    while (supplierCount < MAX_SUPPLIERS &&
           fscanf(file, "%49[^|]|%79[^|]|%29[^|]|%49[^\n]\n",
                  suppliers[supplierCount].name,
                  suppliers[supplierCount].email,
                  suppliers[supplierCount].phone,
                  suppliers[supplierCount].town) == 4)
    {
        supplierCount++;
    }

    fclose(file);
    printf("%d supplier record(s) loaded from text file.\n", supplierCount);
}
