#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clearInputBuffer(void)
{
    int character;

    while ((character = getchar()) != '\n' && character != EOF)
    {
    }
}

void readLine(const char *prompt, char text[], int size)
{
    printf("%s", prompt);
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

int readInt(const char *prompt)
{
    int value;

    printf("%s", prompt);
    while (scanf("%d", &value) != 1)
    {
        printf("Invalid number. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    return value;
}

double readDouble(const char *prompt)
{
    double value;

    printf("%s", prompt);
    while (scanf("%lf", &value) != 1)
    {
        printf("Invalid number. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    return value;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
}
