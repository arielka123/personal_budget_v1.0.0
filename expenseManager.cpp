#include "expenseManager.h"

void  ExpenseManager::balanceSheetPrevMonth()
{
    sort(expenses.begin(),expenses.end());

    sumSelectedExpense =0;
    int j=0;
    int currentDate =0;
    currentDate = AuxiliaryMethods::convStringNaInt(dateManager.showDateWithoutDashes(dateManager.currentDate()));
    int dateWithoutDays = (currentDate/100)*100;
    int prevDateWithoutDays = ((currentDate/100)-1)*100;

    for (int i=0; i<expenses.size(); i++)
    {
        if(expenses[i].getExpenseDate()>prevDateWithoutDays)
        {
            if(expenses[i].getExpenseDate()<dateWithoutDays)
            {
                cout <<j+1<<". ";
                cout <<  dateManager.showDateWithDashes(expenses[i].getExpenseDate())<< " ";
                cout << expenses[i].getExpenseItem() << " ";
                cout << expenses[i].getExpenseAmount() << " zl";
                sumSelectedExpense += expenses[i].getExpenseAmount();
                cout <<endl;
                j++;
            }
        }
    }
}

void  ExpenseManager::balanceSheetCurrentMonth()
{
    sort(expenses.begin(),expenses.end());
    sumSelectedExpense =0;
    int currentDate =0;
    currentDate = AuxiliaryMethods::convStringNaInt(dateManager.showDateWithoutDashes(dateManager.currentDate()));

    int dateWithoutDays = (currentDate/100)*100;
    int j=0;

    for (int i=0; i<expenses.size(); i++)
    {
        if(expenses[i].getExpenseDate()>dateWithoutDays)
        {
            cout <<j+1<<". ";
            cout <<  dateManager.showDateWithDashes(expenses[i].getExpenseDate())<< " ";
            cout << expenses[i].getExpenseItem() << " ";
            cout << expenses[i].getExpenseAmount() << " zl";
            sumSelectedExpense += expenses[i].getExpenseAmount();
            cout <<endl;
            j++;
        }
    }
}

void  ExpenseManager:: balanceSheetSelectedPeriod(string date1,string date2)
{
    sort(expenses.begin(),expenses.end());

    int tmp=0;
    int j=0;
    sumSelectedExpense=0;
    int date1asInt=0, date2asInt=0;

    date1asInt = AuxiliaryMethods::convStringNaInt(dateManager.showDateWithoutDashes(date1));
    date2asInt = AuxiliaryMethods::convStringNaInt(dateManager.showDateWithoutDashes(date2));

    if (dateManager.ifDateCorrect(date1asInt)&& dateManager.ifDateCorrect(date2asInt))
    {
        if (date1asInt > date2asInt)
        {
            tmp=date1asInt;
            date1asInt = date2asInt;
            date2asInt = tmp;
        }

        for (int i=0; i<expenses.size(); i++)
        {
            if(expenses[i].getExpenseDate()>=date1asInt)
            {

                if(expenses[i].getExpenseDate() <= date2asInt)
                {
                    cout <<j+1<<". ";
                    cout <<  dateManager.showDateWithDashes(expenses[i].getExpenseDate())<< " ";
                    cout << expenses[i].getExpenseItem() << " ";
                    cout << expenses[i].getExpenseAmount() << " zl";
                    sumSelectedExpense += expenses[i].getExpenseAmount();
                    cout <<endl;
                    j++;
                }
            }
        }
    }
}

Expense ExpenseManager::addDataNewExpense()
{
    string item, amount;

    Expense expense;
    system("cls");

    expense.setUserID(LOGGED_USER_ID);
    expense.setExpenseID(setIdNewExpense());
    cout <<endl<<"###############################################"<<endl<<endl;

    cout <<" >>>>>>> CZEGO DOTYCZY WYDATEK ?    <<<<<<< "<<endl;
    cin >>item;
    expense.setExpenseItem(item);

    cout <<"        PODAJ WARTOSC WYDATKU W PLN         "<<endl;

    cin >>amount;

    while (AuxiliaryMethods::changeDecimalToDotInAmount(amount) =="" )
    {
        Sleep(1000);
        system("cls");
        cout <<"        PODAJ WARTOSC WYDATKU W PLN         "<<endl;
        cin >>amount;
    }
    amount =AuxiliaryMethods::changeDecimalToDotInAmount(amount);
    expense.setExpenseAmount(AuxiliaryMethods::convStringToFloat(amount));

    expense.setExpenseDate(dateManager.addDateToItem());

    system("cls");

    return expense;
}
void ExpenseManager::addNewExpense ()
{
    Expense expense = addDataNewExpense();
    expenses.push_back(expense);
    xmlWithExpenses.saveToFile(expense);
}

float ExpenseManager::sumAllExpenses()
{
    sum=0;

    for (int i=0; i<expenses.size(); i++)
    {
        sum +=expenses[i].getExpenseAmount();
    }
    return sum;
}


void ExpenseManager:: showAllExpenses ()
{
    sort(expenses.begin(),expenses.end());

    cout<<endl<<" >>>>>>>       TWOJE WYDATKI        <<<<<<<"<<endl<<endl;

    for (int i=0; i<expenses.size(); i++)
    {
        cout <<i+1<<". ";
        cout <<  dateManager.showDateWithDashes(expenses[i].getExpenseDate())<< " ";
        cout << expenses[i].getExpenseItem() << " ";
        cout << expenses[i].getExpenseAmount() << " zl";
        cout <<endl;
    }
    system("Pause");
}

int ExpenseManager::findIdLastExpense()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseID();
}


int ExpenseManager::setIdNewExpense()
{
    idNewExpense = idNewExpense+1;

    return idNewExpense;
}

bool operator<( Expense &s1, Expense &s2)
{
    return s1.getExpenseDate() < s2.getExpenseDate();
}

