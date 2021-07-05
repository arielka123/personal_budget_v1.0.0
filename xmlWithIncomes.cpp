#include "xmlWithIncomes.h"

void XmlWithIncomes::saveToFile(Income incomes)
{
    bool fileExists = xxml.Load(filename);

    if (!fileExists)
    {
        xxml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xxml.AddElem("Incomes");
    }
    xxml.FindElem();
    xxml.IntoElem();
    xxml.AddElem("Income");
    xxml.IntoElem();
    xxml.AddElem("UserId", incomes.getUserID());
    xxml.AddElem("IncomeId", incomes.getIncomeID());
    xxml.AddElem("IncomeDate", incomes.getIncomeDate());
    xxml.AddElem("IncomeItem", incomes.getIncomeItem());
    xxml.AddElem("IncomeAmount", AuxiliaryMethods::convFloatToString (incomes.getIncomeAmount()));
    xxml.Save(filename);
}


vector<Income> XmlWithIncomes::loadFromFile ()
{
    Income income;
    vector <Income> incomes;

    bool fileExists = xxml.Load( filename );
    if (!fileExists)
    {
        cout << "Brak pliku z uzytkownikami";
        return incomes;
    }

    xxml.FindElem();
    xxml.IntoElem();

    while (xxml.FindElem() == true )
    {
        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("UserId");
        income.setUserID(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("IncomeId");
        income.setIncomeID(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("IncomeDate");
        income.setIncomeDate(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("IncomeItem");
        income.setIncomeItem(xxml.GetData());
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("IncomeAmount");
        income.setIncomeAmount(AuxiliaryMethods::convStringToFloat(xxml.GetData()));
        xxml.OutOfElem();

        incomes.push_back(income);
    }
    xxml.ResetPos();

    return incomes;
}


