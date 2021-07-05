#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

#include "income.h"
#include "auxiliaryMethods.h"
#include "userManager.h"
#include "dateManager.h"
#include "xmlWithIncomes.h"

using namespace std;

class IncomeManager
{
    vector <Income> incomes;
    const int LOGGED_USER_ID;
    int idNewIncome;
    float sum;

    UserManager userManager;
    DateManager dateManager;
    XmlWithIncomes xmlWithIncomes;
    int findIdLastIncome();
    int setIdNewIncome();
public:
    IncomeManager(int loggedUserId) :LOGGED_USER_ID(loggedUserId)
    {
        loggedUserId=userManager.getLoggedUserID ();
        incomes = xmlWithIncomes.loadFromFile ();
        idNewIncome = findIdLastIncome();
        sort(incomes.begin(),incomes.end());
    };

    Income addDataNewIncome();
    float sumSelectedIncomes;
    void addNewIncome ();
    void showAllIncomes ();
    float sumAllIncomes();
    void  balanceSheetSelectedPeriod(string date1,string date2);
    void  balanceSheetCurrentMonth();
    void  balanceSheetPrevMonth();

    // void printSumSelectedIncomes();
};

bool operator<( Income &s1,  Income &s2);

#endif
