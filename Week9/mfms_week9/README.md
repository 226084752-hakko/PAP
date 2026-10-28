# Municipal Financial Management System - Weeks 9 and 10

This project modularises the Municipal Financial Management System and adds persistent storage.

## Modules

- `main.c`: controls the main menu and application flow.
- `employees.c`: employee capture, search, reports, text storage, and binary storage.
- `suppliers.c`: supplier capture, display, search, and text storage.
- `budget.c`: revenue/expense capture, balance calculation, and text storage.
- `assets.c`: asset capture, display, and text storage.
- `utilities.c`: reusable input and helper functions.
- `reports.c`: summary reporting that uses employee, budget, supplier, and asset modules.
- `config.h`: shared storage limits and data-file paths.

## Build

Compile each required Week 9 module separately:

```powershell
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
```

Compile the Week 9 supplier extension and Week 10 assets module as well:

```powershell
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc -std=c99 -Wall -Wextra -pedantic -c assets.c
```

Link every object file:

```powershell
gcc main.o employees.o budget.o utilities.o reports.o suppliers.o assets.o -o mfms
```

Run the program in PowerShell:

```powershell
.\mfms.exe
```

## Module dependency diagram

```text
main.c --> employees.h --> employees.c --> utilities.h
       --> suppliers.h --> suppliers.c --> utilities.h
       --> budget.h    --> budget.c    --> utilities.h
       --> assets.h    --> assets.c    --> utilities.h
       --> reports.h   --> reports.c --> employees.h, budget.h, suppliers.h, assets.h
```

## Persistence

The `data` directory is created in the project so the program can save employee, supplier, asset, and budget text files. Employee data can also be saved and loaded as `employees.dat` to demonstrate `fwrite()` and `fread()`.
