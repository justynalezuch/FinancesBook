#ifndef DATESMETHODS_H
#define DATESMETHODS_H

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Helpers.h"


using namespace std;



class DatesMethods
{
    const string MIN_VALID_DATE = "2000-01-01";

    static int getDay(string date);
    static int getMonth(string date);
    static int getYear(string date);

    static string getStrDay(string date);
    static string getStrMonth(string date);
    static string getStrYear(string date);

    static bool isLeap(int year);
    static string getLastDateOfMonth(string currentDate);
    static int getLastDayOfMonth(int month, int year);

   // const string FRIST_DAY_CURRENT_MONTH = getCurrentDate();
   // const string LAST_DAY_CURRENT_MONTH = getLastDayOfMonth(getCurrentDate());

public:

    static string getCurrentDate();
    static int convertStringDateToIntDate(string stringDate);
    static string convertIntDateToStringDate(int date);
    static bool isValidDate(string date);




};

#endif
