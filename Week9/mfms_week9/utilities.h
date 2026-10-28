#ifndef UTILITIES_H
#define UTILITIES_H

void clearInputBuffer(void);
void readLine(const char *prompt, char text[], int size);
int readInt(const char *prompt);
double readDouble(const char *prompt);
void pauseScreen(void);

#endif
