#include <stdio.h>
#include <math.h>

// Your Name(s): Mikhai Rochelle

// DO NOT place any variable declarations outside of any function(s)
// (i.e, no global variable declarations)

// You are free to add other (helper) functions to this program.

int main() {
    double P, annual_rate, i, monthly_payment;
    int n;

    // Prompt user for input
    printf("Enter the loan amount (principal): ");
    scanf("%lf", &P);
    printf("Enter the annual interest rate (in percent): ");
    scanf("%lf", &annual_rate);
    printf("Enter the number of payments: ");
    scanf("%d", &n);

    // Calculate monthly interest rate as a decimal
    i = annual_rate / 1200.0;

    // Calculate monthly payment
    if (i != 0) {
        monthly_payment = P * i / (1 - pow(1 + i, -n));
    } else {
        monthly_payment = P / n;
    }

    printf("\nLoan Information Details:\n\n");
    printf("Amount Borrowed: $%.2f\n", P);
    printf("Annual Interest Rate: %.2f%%\n", annual_rate);
    printf("Monthly Interest Rate (in percent): %.2f%%\n", annual_rate / 12.0);
    printf("Monthly Interest Rate (in decimal): %.4f\n", i);
    printf("Number of Payments: %d\n", n);
    printf("Monthly Payment Amount: $%.2f\n\n", monthly_payment);

    printf("Amortization Table for the Loan:\n\n");
    printf("%5s %20s %18s %18s %18s %18s %18s\n", 
        "Month", "Beginning Balance", "Monthly Payment", "Interest Payment", "Principal Payment", "Ending Balance", "Total Interest");

    double balance = P;
    double total_interest = 0.0;
    for (int month = 1; month <= n; month++) {
        double interest = balance * i;
        double principal = monthly_payment - interest;
        if (month == n) {
            // Adjust final payment to pay off remaining balance
            monthly_payment = balance + interest;
            principal = balance;
        }
        double end_balance = balance - principal;
        total_interest += interest;

        printf("%5d %20.2f %18.2f %18.2f %18.2f %18.2f %18.2f\n",
            month, balance, monthly_payment, interest, principal, end_balance > 0 ? end_balance : 0.0, total_interest);

        balance = end_balance;
        if (balance < 0.01) break; // Loan paid off
    }

    return 0;
}