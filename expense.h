#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <algorithm>

using namespace std;

class Expense
{
    int expenseID;
    int userID;
    int expenseDate;
    string expenseItem;
    float expenseAmount;
public:
    void setExpenseID(int newexpenseID);
    void setUserID(int newUserID);
    void setExpenseDate(int newExpenseData);
    void setExpenseItem(string newExpenseItem);
    void setExpenseAmount(float newExpenseAmount);

    int getExpenseID();
    int getUserID();
    int getExpenseDate();
    string getExpenseItem();
    float getExpenseAmount();
};

#endif
