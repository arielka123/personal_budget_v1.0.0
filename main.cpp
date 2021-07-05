#include <iostream>
#include "incomeManager.h"
#include "userManager.h"
#include "expenseManager.h"
#include "dateManager.h"
#include "balanceSheet.h"

using namespace std;
int main()
{
    BalanceSheet balanceSheet;
    int idLoggedUser=0;
    char selection;

    while (true)
    {
        if (idLoggedUser == 0)
        {
            selection = balanceSheet.selectFromMainMenu();

            switch (selection)
            {
            case '1':
                balanceSheet.userRegister();
                break;
            case '2':
                idLoggedUser= balanceSheet.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

        if (idLoggedUser>0)
        {
            selection = balanceSheet.selectFromUserMenu();

            switch (selection)
            {
            case '1':
                balanceSheet.addNewIncome();
                break;
            case '2':
                balanceSheet.addNewExpense();
                break;
            case '3':
                balanceSheet.balanceSheetCurrentMonth();
                balanceSheet.accountBalance();
                break;
            case '4':
                balanceSheet.balanceSheetPrevMonth();
                balanceSheet.accountBalance();
                break;
            case '5':
                balanceSheet.balanceSheetSelectedPeriod();
                balanceSheet.accountBalance();
                break;
            case '6':
                balanceSheet.changePassword();
                break;
            case '9':
            idLoggedUser=balanceSheet.userLogOut();
                break;
            }
        }
    }
    return 0;
}

