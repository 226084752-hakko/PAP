#include <stdio.h>
#include <string.h>

int main()
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];

    char backupName[100];
    char description[250];
    char searchName[100];

    printf("=== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ===\n");
    printf("--- WEEK 7: SUPPLIER MANAGEMENT ---\n\n");

    printf("Enter supplier name: ");
    fgets(supplierName, 100, stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, 100, stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, 30, stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, 50, stdin);
    town[strcspn(town, "\n")] = '\0';

  
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name: %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town: %s\n", town);

  
    printf("\n--- STRING LENGTHS ---\n");
    printf("Supplier Name Length: %zu\n", strlen(supplierName));
    printf("Email Length: %zu\n", strlen(email));
    printf("Town Length: %zu\n", strlen(town));

   
    strcpy(backupName, supplierName);

    printf("\n--- BACKUP COPY ---\n");
    printf("Original Name: %s\n", supplierName);
    printf("Backup Name: %s\n", backupName);

    
    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");

    printf("\n--- SUPPLIER DESCRIPTION ---\n");
    printf("%s\n", description);

   
    printf("\n--- SUPPLIER SEARCH ---\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0)
    {
        printf("Supplier found!\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    return 0;
}