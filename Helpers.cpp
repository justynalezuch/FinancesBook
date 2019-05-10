#include "Helpers.h"

string Helpers::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string Helpers::loadLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

int Helpers::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
