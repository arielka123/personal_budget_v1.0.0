#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

#include "expense.h"
#include "auxiliaryMethods.h"
#include "userManager.h"
#include "dateManager.h"
#include "xmlWithExpenses.h"

using namespace std;

class ExpenseManager
{
    vector <Expense> expenses;
    const int LOGGED_USER_ID;
    int idNewExpense;
    float sum;

    UserManager userManager;
    DateManager dateManager;
    XmlWithExpenses xmlWithExpenses;
    int setIdNewExpense();
    int findIdLastExpense();
public:
    ExpenseManager(int loggedUserId) :LOGGED_USER_ID(loggedUserId)
    {
        loggedUserId=userManager.getLoggedUserID ();
        expenses=xmlWithExpenses.loadFromFile();
        idNewExpense = findIdLastExpense();
        sort(expenses.begin(),expenses.end());
    };
    Expense addDataNewExpense();
    float sumSelectedExpense;
    void addNewExpense();
    void showAllExpenses();
    float sumAllExpenses();
    void  balanceSheetSelectedPeriod(string date1,string date2);
    void  balanceSheetCurrentMonth();
    void  balanceSheetPrevMonth();
};

bool operator<(Expense &s1, Expense &s2);


#endif
