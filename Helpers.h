#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Helpers
{

public:
    static string convertIntToString(int number);
    static string loadLine();
    static int convertStringToInt(string number);
};

#endif
