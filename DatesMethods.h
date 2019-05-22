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

    static int getDay(string date);
    static int getMonth(string date);
    static int getYear(string date);

    static string getStrDay(string date);
    static string getStrMonth(string date);
    static string getStrYear(string date);

    static bool isLeap(int year);
    static string getLastDateOfMonth(string currentDate);
    static int getLastDayOfMonth(int month, int year);

    static string getPreviousMonth(string date);
    static string getFirstDay(string date);
    static string getLastDay(string date);

public:

    static int convertStringDateToIntDate(string stringDate);
    static string convertIntDateToStringDate(int date);
    static string getCurrentDate();
    static bool isValidDate(string date);


    static string getFirstDayCurrentMonth();
    static string getLastDayCurrentMonth();

    static bool compareDates(string firstDate, string secondDate);




};

#endif
