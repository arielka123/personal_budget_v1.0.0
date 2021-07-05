#include "auxiliaryMethods.h"

int AuxiliaryMethods::convStringNaInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::convIntNaString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

float AuxiliaryMethods:: convStringToFloat (string number)
{
    float newNumber;
    newNumber = stof (number);
    return newNumber;
}

string AuxiliaryMethods:: convFloatToString (float number)
{
   ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::loadSign()
{
    string entrance = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            sign = entrance[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

vector<string> AuxiliaryMethods::split (string s, char delim)
{

    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim))
    {
        result.push_back (item);
    }

    return result;
}

string AuxiliaryMethods::changeDecimalToDotInAmount (string amount)
{
    string newAmount="";
    char dot='.';
    char decimal =',';

    for (int i=0; i<amount.length(); i++)
    {
        if (isdigit(amount[i]) == true)
        {
            newAmount +=amount[i];
        }
        else if (amount[i] == dot)
        {
        newAmount +=amount[i];
        }
        else if (amount[i]==decimal)
        {
            amount = amount.replace(i,1,".");
            newAmount += amount[i];
        }
        else
        {
            cerr <<"Wpisano nie poprawna wartosc! Wpisz jeszcze raz "<<endl;
            newAmount ="";
            break;
        }
    }
    return newAmount;
}

//char MetodyPomocnicze::wczytajZnak()
//{
//    string wejscie = "";
//    char znak  = {0};
//
//    while (true)
//    {
//        getline(cin, wejscie);
//
//        if (wejscie.length() == 1)
//        {
//            znak = wejscie[0];
//            break;
//        }
//        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
//    }
//    return znak;
//}

//string MetodyPomocnicze::wczytajLinie()
//{
//    string wejscie = "";
//    getline(cin, wejscie);
//    return wejscie;
//}
