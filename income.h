#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeID;
    int userID;
    int incomeDate;
    string incomeItem;
    float incomeAmount;
public:
    void setIncomeID(int newIncomeID);
    void setUserID(int newUserID);
    void setIncomeDate(int newIncomeData);
    void setIncomeItem(string newIncomeItem);
    void setIncomeAmount(float newIncomeAmount);

    int getIncomeID();
    int getUserID();
    int getIncomeDate();
    string getIncomeItem();
    float getIncomeAmount();
};

#endif
