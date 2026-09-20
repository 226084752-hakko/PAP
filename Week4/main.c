 #include <stdio.h>
int main() {
    char name[50];
    double price, budget;
    int registered, docs, lowest;
    printf("Supplier Name: ");
    scanf(" %[^\n]", name);
    printf("Supplier Price: ");
    scanf("%lf", &price);
    printf("Budget: ");
    scanf("%lf", &budget);
    printf("Registered? (1 = Yes, 0 = No): ");
    scanf("%d", &registered);
    printf("Documents Complete? (1 = Yes, 0 = No): ");
    scanf("%d", &docs);
    printf("Is Lowest Price? (1 = Yes, 0 = No): ");
    scanf("%d", &lowest);

    
    int qualified = (registered == 1) && (docs == 1) && (price <= budget);

    printf("\nStatus for %s: ", name);
    if (qualified && (lowest == 1)) {
        printf("PREFERRED SUPPLIER\n");
    } else if (qualified) {
        printf("QUALIFIED\n");
    } else {
        printf("DISQUALIFIED\n");
    }

    return 0;
}
