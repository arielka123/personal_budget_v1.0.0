#ifndef DATEMANAGER_H
#define DATEMANAGER_H

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

class DateManager
{
    struct Date;
    bool isLeapYears(int year);
    int countLeapYears(Date date);

public:
    string currentDate();
    bool ifDateCorrect(int dateFromVector);
    string showDateWithoutDashes(string date);
    int addDateToItem();
    string showDateWithDashes(int dateFromVector);
    int getDifference(Date date1, Date date2);

};



#endif
