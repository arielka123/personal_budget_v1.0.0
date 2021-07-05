#include "balanceSheet.h"

int BalanceSheet::getLoggedUserID()
{
    userManager.getLoggedUserID();
}
void BalanceSheet::userRegister()
{
    userManager.userRegister();
}
int BalanceSheet::userLogIn()
{
    userManager.userLogIn();

    if(userManager.ifLogIN())
    {
        expenseManager = new ExpenseManager (userManager.getLoggedUserID());
        incomeManager = new IncomeManager(userManager.getLoggedUserID());
    }
}
void BalanceSheet::changePassword()
{
    userManager.changePassword();
}
int BalanceSheet::userLogOut()
{
   return userManager.userLogOut();
}
void BalanceSheet::showAllUsers()
{
    userManager.showAllUsers();
}
void BalanceSheet::addNewIncome()
{
    incomeManager->addNewIncome();
}
void BalanceSheet::addNewExpense()
{
    expenseManager->addNewExpense();
}

void  BalanceSheet::balanceSheetCurrentMonth()
{
    system("cls");
    cout  <<"....Zestawienie Twoich wydatkow z biezacego miesiaca...."<<endl<<endl;
    expenseManager->balanceSheetCurrentMonth();
    cout <<endl<<"....Zestawienie Twoich przychodow z biezacego miesiaca...."<<endl<<endl;
    incomeManager->balanceSheetCurrentMonth();

    cout <<endl<<"Suma wydatkow w tym miesiacu: "<<expenseManager->sumSelectedExpense<<" zl";
    cout <<"    Suma przychodow w tym miesiacu: "<<incomeManager->sumSelectedIncomes<<" zl"<<endl;
    cout <<" <<<<<<<      Saldo w wybranym okresie: "<<(incomeManager->sumSelectedIncomes)-expenseManager->sumSelectedExpense <<" zl       >>>>>>> ";
    cout <<endl<<"............................................................."<<endl;

}
void  BalanceSheet::balanceSheetPrevMonth()
{
    system("cls");
    cout  <<"....Zestawienie Twoich wydatkow z poprzedniego miesiaca...."<<endl<<endl;
    expenseManager->balanceSheetPrevMonth();
    cout <<endl<<"....Zestawienie Twoich przychodow z poprzedniego miesiaca...."<<endl<<endl;

    incomeManager->balanceSheetPrevMonth();

    cout <<endl<<"Suma  wydatkow w tym miesiacu: "<<expenseManager->sumSelectedExpense<<" zl";
    cout <<"    Suma  przychodow w tym miesiacu "<<incomeManager->sumSelectedIncomes<<" zl"<<endl;
    cout <<" <<<<<<<      Saldo w wybranym okresie: "<<(incomeManager->sumSelectedIncomes)-expenseManager->sumSelectedExpense <<" zl       >>>>>>> ";
    cout <<endl<<"............................................................."<<endl;
}
void  BalanceSheet::balanceSheetSelectedPeriod()
{
    system("cls");
    string date1, date2;
    cout <<"Podaj zakres dat oddzielone spacja w formacie RRRR-MM-DD"<<endl;
    cin>>date1;
    cin>>date2;

    cout <<endl<<"....Zestawienie Twoich wydatkow z wybranego okresu...."<<endl<<endl;
    expenseManager->balanceSheetSelectedPeriod(date1,date2);
    cout <<endl<<"....Zestawienie Twoich przychodow z wybranego okresu...."<<endl<<endl;
    incomeManager->balanceSheetSelectedPeriod(date1,date2);

    cout <<endl<<"Suma wydatkow w wybranaym okresie: "<<expenseManager->sumSelectedExpense<<" zl";
    cout <<"    Suma przychodow w wybranaym okresie: "<<incomeManager->sumSelectedIncomes<<" zl"<<endl;
    cout <<" <<<<<<<      Saldo w wybranym okresie: "<<(incomeManager->sumSelectedIncomes)-expenseManager->sumSelectedExpense <<" zl       >>>>>>> ";
    cout <<endl<<"............................................................."<<endl;
}

void BalanceSheet::accountBalance()
{
    cout <<endl<<"Suma Twoich wszystkich wydatkow: ";
    cout << expenseManager->sumAllExpenses()<<" zl";
    cout <<"  Suma Twoich wszystkich przychodow: ";
    cout <<incomeManager ->sumAllIncomes()<<" zl";
    cout <<endl<<endl<<" <<<<<<<               Saldo: "<<(incomeManager->sumAllIncomes())-(expenseManager->sumAllExpenses())<<" zl                 >>>>>>> "<<endl<<endl;
    system("pause");
}

char BalanceSheet::selectFromMainMenu()
{
    char selection;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Zarejestruj sie" << endl;
    cout << "2. Zaloguj sie" << endl;
    cout << "9. Zakoncz" << endl;
    cout << "---------------------------" << endl;
   // cout << "Twoj wybor: ";
    selection = AuxiliaryMethods::loadSign();

    return selection;
}

char BalanceSheet::selectFromUserMenu()
{
    system("cls");
    char selection;
    cout << "    >>>    TWOJE FINANSE   <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "9. Wyloguj sie " << endl;
    cout << "---------------------------" << endl;
   // cout << "Twoj wybor: ";
    selection = AuxiliaryMethods::loadSign();

     return selection;
}
