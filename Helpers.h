#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <string>


using namespace std;

class Helpers
{

public:
    static string convertIntToString(int number);
    static string loadLine();
    static char loadSign();
    static char loadYesNoSign();
    static int convertStringToInt(string number);
    static float convertStringToFloat(string s);

};

#endif
