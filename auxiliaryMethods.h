#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convFloatToString (float number);
    static string convIntNaString(int number);
    static int convStringNaInt(string number);
    static float convStringToFloat (string number);
    static vector<string> split (string s, char delim);
    static string changeDecimalToDotInAmount (string amount);
    static char loadSign();

//    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

};

#endif
