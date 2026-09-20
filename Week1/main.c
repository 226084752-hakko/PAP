#include <stdio.h>
int main () {
float basicSalary;
float housingAllowance;
float transportAllowance;
float tax;
float grossSalary;
float netSalary;
printf("Enter Basic Salary: ");
scanf("%f", &basicSalary);
printf("Enter Housing Allowance: ");
scanf("%f", &housingAllowance);
printf("Enter Transport Allowance: ");
scanf("%f", &transportAllowance);
printf("Enter Tax: ");
scanf("%f", &tax);
grossSalary = basicSalary + housingAllowance + transportAllowance;
netSalary = grossSalary - tax;
printf("\n grossSalary :%.2f\n",grossSalary);
printf("\n netSalary :%.2f\n",netSalary);
return 0;
}