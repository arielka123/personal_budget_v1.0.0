#include "dateManager.h"

struct Date
{
    int day, month, year;
};


int DateManager::addDateToItem()
{
    char wybor;
    int dateToInt=0;
    do
    {
        cout <<" >>>>>>>        PODAJ DATE          <<<<<<< "<<endl;
        cout <<endl<<"       1.     Data dzisiejsza "<<endl;
        cout<<"       2.        Inna data "<<endl;
        cout <<endl<<"###############################################"<<endl<<endl;

        wybor = getch();
        switch (wybor)
        {
            case '1':
            {
                dateToInt = AuxiliaryMethods::convStringNaInt(showDateWithoutDashes(currentDate()));
            }
            break;
            case '2':
            {
                string date;
                do
                {
                    cout <<"         Wpisz date z formacie RRRR-MM-DD "<<endl;
                    cin >> date;
                    dateToInt = AuxiliaryMethods::convStringNaInt(showDateWithoutDashes(date));
                    if (ifDateCorrect(dateToInt)==false)
                    {
                        cerr <<"Cos poszlo nie tak. Wpisz jeszcze raz";
                        Sleep(1000);
                        system("cls");
                    }
                }
                while (ifDateCorrect(dateToInt)==false);
            }
            break;

            default:
            {
                cerr <<"Cos poszlo nie tak. Wybierz jeszcze raz";
                Sleep(1000);
            }
        }
    }
    while (ifDateCorrect(dateToInt)==false);

    return dateToInt;
}

string DateManager ::showDateWithoutDashes(string date)
{
    string newDate="";
    vector<string> v = AuxiliaryMethods::split (date, '-');
    for (auto i : v) newDate+=i;

    return newDate;
}

string DateManager::currentDate()
{
    time_t curr_time;
    tm * curr_tm;
    char date_string[50];

    time(&curr_time);
    curr_tm = localtime(&curr_time);
    strftime(date_string, 50, "%Y-%m-%d", curr_tm);

    return date_string;
}

string DateManager::showDateWithDashes(int dateFromVector)
{
    string date = AuxiliaryMethods::convIntNaString(dateFromVector);

    string newDate="";
    string year="", month="",day="";


    for (int i=0; i< date.length(); i++)
    {
        if(i<=3) year += date[i];
        else if (i>3 && i<=5) month+= date[i];
        else day +=date[i];
    }
    newDate = year + "-"+month +"-"+day;

    return newDate;
}

bool DateManager::isLeapYears(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

bool DateManager::ifDateCorrect(int dateFromVector)
{
    string date = AuxiliaryMethods::convIntNaString(dateFromVector);
    string year="", month="",day="";
    int month2;
    int day2;
    int year2;
    for (int i=0; i< date.length(); i++)
    {
        if(i<=3) year += date[i];
        else if (i>3 && i<=5) month+= date[i];
        else day +=date[i];

        month2 =AuxiliaryMethods::convStringNaInt(month);
        day2=AuxiliaryMethods::convStringNaInt(day);
        year2 =AuxiliaryMethods::convStringNaInt(year);
    }
    if (date.size()<8) return false;
    if(year2<2000) return false;
    if (month2<1 || month2>12) return false;
    if (day2 <1 || day2 >31) return false;

    if (month2 == 4 || month2 ==6 || month2 ==9 || month2 ==11) return (day2<31);

    if (isLeapYears(year2) == false) return (day2 <=28);
    else  return (day2<=29);

    return true;
}
