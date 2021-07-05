#include "incomeManager.h"

void  IncomeManager::balanceSheetPrevMonth()
{
    sort(incomes.begin(),incomes.end());
    sumSelectedIncomes=0;
    int j=0;
    int currentDate =0;
    currentDate = AuxiliaryMethods::convStringNaInt(dateManager.showDateWithoutDashes(dateManager.currentDate()));
    int dateWithoutDays = (currentDate/100)*100;
    int prevDateWithoutDays = ((currentDate/100)-1)*100;

    for (int i=0; i<incomes.size(); i++)
    {
        if(incomes[i].getIncomeDate()>prevDateWithoutDays)
        {
            if(incomes[i].getIncomeDate()<dateWithoutDays)
            {
            cout <<j+1<<". ";
            cout <<  dateManager.showDateWithDashes(incomes[i].getIncomeDate())<< " ";
            cout << incomes[i].getIncomeItem() << " ";
            cout << incomes[i].getIncomeAmount() << " zl";
            sumSelectedIncomes += incomes[i].getIncomeAmount();

            cout <<endl;
            j++;
            }
        }
    }
}

void  IncomeManager::balanceSheetCurrentMonth()
{
    sort(incomes.begin(),incomes.end());
    sumSelectedIncomes=0;
    int currentDate =0;
    currentDate = AuxiliaryMethods::convStringNaInt(dateManager.showDateWithoutDashes(dateManager.currentDate()));

    int dateWithoutDays = (currentDate/100)*100;
    int j=0;

    for (int i=0; i<incomes.size(); i++)
    {
        if(incomes[i].getIncomeDate()>dateWithoutDays)
        {
            cout <<j+1<<". ";
            cout <<  dateManager.showDateWithDashes(incomes[i].getIncomeDate())<< " ";
            cout << incomes[i].getIncomeItem() << " ";
            cout << incomes[i].getIncomeAmount() << " zl";
            sumSelectedIncomes += incomes[i].getIncomeAmount();
            cout <<endl;
            j++;
        }
    }
}

void  IncomeManager:: balanceSheetSelectedPeriod(string date1,string date2)
{
    sort(incomes.begin(),incomes.end());
    int tmp=0;
    int j=0;
    sumSelectedIncomes=0;

    int date1asInt, date2asInt;

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

        for (int i=0; i<incomes.size(); i++)
        {
            if(incomes[i].getIncomeDate()>=date1asInt)
            {
                if(incomes[i].getIncomeDate() <= date2asInt)
                {
                    cout <<j+1<<". ";
                    cout <<  dateManager.showDateWithDashes(incomes[i].getIncomeDate())<< " ";
                    cout << incomes[i].getIncomeItem() << " ";
                    cout << incomes[i].getIncomeAmount() << " zl ";
                    sumSelectedIncomes +=incomes[i].getIncomeAmount();
                    cout <<endl;
                    j++;
                }

            }
        }
    }
}



Income IncomeManager::addDataNewIncome ()
{
    string item, amount;
    system("cls");

    Income income;
    income.setUserID(LOGGED_USER_ID);
    income.setIncomeID(setIdNewIncome());
    cout <<"###############################################"<<endl<<endl;
    cout <<" >>>>>>> CZEGO DOTYCZY PRZYCHOD?    <<<<<<< "<<endl;
    cin >>item;
    income.setIncomeItem(item);

    cout <<"       PODAJ WARTOSC PRZYCHODU W PLN        "<<endl;
    cin >>amount;

    while (AuxiliaryMethods::changeDecimalToDotInAmount(amount) =="" )
    {
        system("pause");
        system("cls");
        cout <<"       PODAJ WARTOSC PRZYCHODU W PLN        "<<endl;
        cin >>amount;
    }
    amount =AuxiliaryMethods::changeDecimalToDotInAmount(amount);
    income.setIncomeAmount(AuxiliaryMethods::convStringToFloat(amount));
    income.setIncomeDate(dateManager.addDateToItem());

    system("cls");

    return income;
}
void IncomeManager ::addNewIncome ()
{
    Income income = addDataNewIncome();
    incomes.push_back(income);

    xmlWithIncomes.saveToFile(income);
}

float IncomeManager::sumAllIncomes()
{
    float sum=0;

    for (int i=0; i<incomes.size(); i++)
    {
        sum +=incomes[i].getIncomeAmount();
    }
    return sum;
}

void IncomeManager:: showAllIncomes ()
{
    float sum=0;
   // sort(incomes.begin(),incomes.end());
    cout <<endl<<" >>>>>>>       TWOJE WPLYWY         <<<<<<<"<<endl<<endl;

    for (int i=0; i<incomes.size(); i++)
    {
        //cout << incomes[i].getIncomeID() << ". ";
        cout <<i+1<<". ";
        cout <<  dateManager.showDateWithDashes(incomes[i].getIncomeDate())<< " ";
        cout << incomes[i].getIncomeItem() << " ";
        cout << incomes[i].getIncomeAmount() << " zl";
        cout <<endl;

        sum +=incomes[i].getIncomeAmount();
    }
    cout <<endl<<"Suma wszystkich Twoich wplywow wynosi : "<<sumAllIncomes()<< " zl"<<endl<<endl;

    system("Pause");
}

int IncomeManager::findIdLastIncome()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeID();
}

int IncomeManager::setIdNewIncome()
{
    idNewIncome = idNewIncome+1;

    return idNewIncome;
}

bool operator<(Income &s1, Income &s2)
{
    return s1.getIncomeDate() < s2.getIncomeDate();
}
