# Loan Amortization Calculator

This project is a simple C program that calculates loan payment details and generates an amortization table based on user input. The program prompts the user for the principal amount, annual interest rate, and number of payments, then displays the monthly payment and a detailed breakdown of each payment over the life of the loan.

## File Structure

```
loan/                          # (binary/executable output)
loan.c                         # Main source code file
```

- **loan.c**: Main C source file containing the implementation of the loan calculator.
- **loan**: Compiled executable (may appear after building).

## How to Run

1. **Change your file permissions**
   
   
   Open a terminal in the project directory and run:
   ```sh
   chmod 777 loan.c
   ```
2. **Compile the Program**

   
   ```sh
   gcc -std=c99 -Wall -o loan loan.c -lm
   ```

3. **Run the Program**

   Execute the compiled program:
   ```sh
   ./loan
   ```

4. **Follow Prompts**

   Enter the loan amount, annual interest rate, and number of payments as prompted. The program will display loan details and an amortization table.