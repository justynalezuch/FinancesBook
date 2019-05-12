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


char Helpers::loadSign()
{
    string entry = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

char Helpers::loadYesNoSign()
{
    string entry = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1 && (entry == "t" || entry == "n")) {

            sign = entry[0];
            break;
        }
        cout << "Wprowadz t lub n" << endl;
    }
    return sign;
}


int Helpers::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
