#ifndef METHODSUSINGDATE_H
#define METHODSUSINGDATE_H

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

#include "income.h"
#include "auxiliaryMethods.h"

using namespace std;

class DateManager1
{
    string currentDate();
    string showDateWithoutDashes(string date);
    bool ifDateCorrect(int dateFromVector);
    bool isLeapYears(int year);

public:
    int addDateToItem();
    string showDateWithDashes(int dateFromVector);
};


#endif
