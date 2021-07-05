#ifndef XMLWITINCOMES_H
#define XMLWITINCOMES_H

#include <iostream>
#include "Markup.h"
#include "income.h"
#include "auxiliaryMethods.h"
#include <vector>
#include <sstream>

using namespace std;

class XmlWithIncomes
{
    CMarkup xxml;
    string filename = "incomes.xml";
    public:
    void saveToFile(Income incomes);
    vector<Income> loadFromFile ();
};

#endif
