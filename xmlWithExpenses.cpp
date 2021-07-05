#include "xmlWithExpenses.h"

void XmlWithExpenses::saveToFile(Expense expenses)
{
    bool fileExists = xxml.Load(filename);

    if (!fileExists)
    {
        xxml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xxml.AddElem("Expenses");
    }
    xxml.FindElem();
    xxml.IntoElem();
    xxml.AddElem("Expense");
    xxml.IntoElem();
    xxml.AddElem("UserId", expenses.getUserID());
    xxml.AddElem("ExpenseId", expenses.getExpenseID());
    xxml.AddElem("ExpenseDate", expenses.getExpenseDate());
    xxml.AddElem("ExpenseItem", expenses.getExpenseItem());
    xxml.AddElem("ExpenseAmount",AuxiliaryMethods::convFloatToString (expenses.getExpenseAmount()));
    xxml.Save(filename);
}

vector<Expense> XmlWithExpenses::loadFromFile ()
{
    Expense expense;
    vector <Expense> expenses;

    bool fileExists = xxml.Load(filename);
    if (!fileExists)
    {
        cout << "Brak pliku z uzytkownikami";
        return expenses;
    }

    xxml.FindElem();
    xxml.IntoElem();

    while (xxml.FindElem() == true )
    {
        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("UserId");
        expense.setUserID(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("ExpenseId");
        expense.setExpenseID(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("ExpenseDate");
        expense.setExpenseDate(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("ExpenseItem");
        expense.setExpenseItem(xxml.GetData());
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("ExpenseAmount");
        expense.setExpenseAmount(AuxiliaryMethods::convStringToFloat(xxml.GetData()));
        xxml.OutOfElem();

        expenses.push_back(expense);
    }
    xxml.ResetPos();

    return expenses;
}


