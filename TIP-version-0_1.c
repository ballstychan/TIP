#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for Accounts
typedef struct {
    char title[50];
    double debit;
    double credit;
} Account;

typedef struct {
    Account assets[10];
    Account liabilities[10];
    Account equity[10];
    Account income[10];
    Account expenses[10];
    int assetCount;
    int liabilityCount;
    int equityCount;
    int incomeCount;
    int expenseCount;
} Accounts;

// Function prototypes
void initializeAccounts(Accounts *accounts);
void addAccount(Account accounts[], int *count, char *title, double debit, double credit);
void printAccounts(Account accounts[], int count, char *header);
void prepareFinancialStatements(Accounts *accounts);

int main() {
    Accounts accounts;
    initializeAccounts(&accounts);

    // Add some accounts
    addAccount(accounts.assets, &accounts.assetCount, "Cash", 10000.0, 0.0);
    addAccount(accounts.liabilities, &accounts.liabilityCount, "Accounts Payable", 0.0, 5000.0);
    addAccount(accounts.equity, &accounts.equityCount, "Owner's Capital", 0.0, 5000.0);
    addAccount(accounts.income, &accounts.incomeCount, "Sales", 0.0, 12000.0);
    addAccount(accounts.expenses, &accounts.expenseCount, "Salaries Expense", 2000.0, 0.0);

    // Print accounts
    printAccounts(accounts.assets, accounts.assetCount, "Assets");
    printAccounts(accounts.liabilities, accounts.liabilityCount, "Liabilities");
    printAccounts(accounts.equity, accounts.equityCount, "Equity");
    printAccounts(accounts.income, accounts.incomeCount, "Income");
    printAccounts(accounts.expenses, accounts.expenseCount, "Expenses");


    prepareFinancialStatements(&accounts);

    return 0;
}

void initializeAccounts(Accounts *accounts) {
    accounts->assetCount = 0;
    accounts->liabilityCount = 0;
    accounts->equityCount = 0;
    accounts->incomeCount = 0;
    accounts->expenseCount = 0;
}

void addAccount(Account accounts[], int *count, char *title, double debit, double credit) {
    strcpy(accounts[*count].title, title);
    accounts[*count].debit = debit;
    accounts[*count].credit = credit;
    (*count)++;
}

void printAccounts(Account accounts[], int count, char *header) {
    printf("%s:\n", header);
    for (int i = 0; i < count; i++) {
        printf("%s: Debit: %.2f, Credit: %.2f\n", accounts[i].title, accounts[i].debit, accounts[i].credit);
    }
    printf("\n");
}

void prepareFinancialStatements(Accounts *accounts) {
    double totalAssets = 0.0, totalLiabilities = 0.0, totalEquity = 0.0, totalIncome = 0.0, totalExpenses = 0.0;

    for (int i = 0; i < accounts->assetCount; i++) {
        totalAssets += accounts->assets[i].debit - accounts->assets[i].credit;
    }

    for (int i = 0; i < accounts->liabilityCount; i++) {
        totalLiabilities += accounts->liabilities[i].credit - accounts->liabilities[i].debit;
    }

    for (int i = 0; i < accounts->equityCount; i++) {
        totalEquity += accounts->equity[i].credit - accounts->equity[i].debit;
    }

    for (int i = 0; i < accounts->incomeCount; i++) {
        totalIncome += accounts->income[i].credit - accounts->income[i].debit;
    }

    for (int i = 0; i < accounts->expenseCount; i++) {
        totalExpenses += accounts->expenses[i].debit - accounts->expenses[i].credit;
    }

    printf("Income Statement:\n");
    double netIncome = totalIncome - totalExpenses;
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Income: %.2f\n\n", netIncome);

    printf("Statement of Financial Position:\n");
    printf("Total Assets: %.2f\n", totalAssets);
    printf("Total Liabilities: %.2f\n", totalLiabilities);
    printf("Total Equity: %.2f\n\n", totalEquity);

    printf("Accounting Equation: Assets = Liabilities + Equity\n");
    printf("%.2f = %.2f + %.2f\n\n", totalAssets, totalLiabilities, totalEquity);
}
