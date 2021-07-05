#include "expense.h"

void Expense::setExpenseAmount (float newExpenseAmount)
{
    expenseAmount = newExpenseAmount;
}
void Expense::setExpenseDate(int newExpenseDate)
{
    expenseDate = newExpenseDate;
}
void Expense::setExpenseID(int newExpenseId)
{
    expenseID = newExpenseId;
}
void Expense::setUserID(int newUserID)
{
    userID=newUserID;
}
float Expense::getExpenseAmount()
{
    return expenseAmount;
}
void Expense::setExpenseItem(string newExpenseItem)
{
    expenseItem = newExpenseItem;
}

int Expense::getExpenseID()
{
return expenseID;
}
int Expense::getUserID()
{
return userID;
}
int Expense::getExpenseDate()
{
return expenseDate;
}
string Expense::getExpenseItem()
{
return expenseItem;
}


