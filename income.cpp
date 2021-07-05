#include "income.h"

void Income::setIncomeAmount (float newIncomeAmount)
{
    incomeAmount = newIncomeAmount;
}
void Income::setIncomeDate(int newIncomeDate)
{
    incomeDate = newIncomeDate;
}

void Income::setIncomeID(int newIncomeId)
{
    incomeID = newIncomeId;
}

void Income::setUserID(int newUserID)
{
    userID=newUserID;
}

void Income::setIncomeItem(string newIncomeItem)
{
    incomeItem = newIncomeItem;
}

float Income::getIncomeAmount()
{
    return incomeAmount;
}

int Income::getIncomeID()
{
return incomeID;
}
int Income::getUserID()
{
return userID;
}
int Income::getIncomeDate()
{
return incomeDate;
}
string Income::getIncomeItem()
{
return incomeItem;
}


