#ifndef XMLWITEXPENSES_H
#define XMLWITEXPENSES_H

#include <iostream>
#include "Markup.h"
#include "expense.h"
#include "auxiliaryMethods.h"
#include <vector>
#include <sstream>

using namespace std;

class XmlWithExpenses
{
    CMarkup xxml;
    string filename = "expenses.xml";
    public:
    void saveToFile(Expense expenses);
    vector<Expense> loadFromFile ();
};

#endif
