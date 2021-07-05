#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <windows.h>
#include <cstdlib>

#include "expenseManager.h"
#include "incomeManager.h"
#include "userManager.h"
#include "auxiliaryMethods.h"

using namespace std;

class BalanceSheet
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    float sumAllExpenses();
    float sumAllIncomes();

public:
    BalanceSheet()
    {
        incomeManager = NULL;
        expenseManager = NULL;
    };

    ~BalanceSheet()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };

    char selectFromMainMenu();
    char selectFromUserMenu();

    int getLoggedUserID();
    void userRegister ();
    int userLogIn ();
    void changePassword();
    int userLogOut ();
    void showAllUsers ();

    void addNewIncome();
    void addNewExpense();
    void showAllIncomes();
   // void showAllExpenses();

    void  balanceSheetCurrentMonth();
    void  balanceSheetPrevMonth();
    void  balanceSheetSelectedPeriod();

    void accountBalance();
};


#endif
