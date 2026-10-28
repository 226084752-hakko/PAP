# Test runs

## Test 1 - Employee and text persistence

1. Add employee ID `1001`, name `Maria`, salary `18500.50`.
2. Choose **Save All Text Data**.
3. Restart the program and choose **Load All Text Data**.
4. List employees and confirm that Maria is displayed.

Expected result: the employee is restored from `data/employees.txt`.

## Test 2 - Supplier, budget, asset, and summary report

1. Add supplier `ABC Office Supplies` in Windhoek.
2. Capture revenue `500000` and expenses `350000`.
3. Add asset ID `2001`, name `Council Vehicle`, value `250000`.
4. Choose **View Summary Report**.

Expected result: the report shows one supplier, one asset, and a budget balance of `150000.00`.

## Test 3 - Binary employee persistence

1. Add one or more employee records.
2. Choose **Save Employee Binary Data**.
3. Restart the program and choose **Load Employee Binary Data**.
4. List employees.

Expected result: the employee records are restored from `data/employees.dat`.

## Error handling checks

- Choose **Load All Text Data** before any files exist: each module reports the missing file through `perror()`.
- Enter text when a menu expects a number: the reusable input functions ask again.
- Attempt to load a malformed employee binary file: the program reports that the binary file is invalid.
