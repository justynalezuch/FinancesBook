#include "DatesMethods.h"

string DatesMethods::getCurrentDate()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d",timeinfo);
    string str(buffer);

    return str;

}

int DatesMethods::getYear(string date)
{

    return Helpers::convertStringToInt(date.substr(0,4));
}

int DatesMethods::getMonth(string date)
{

    return Helpers::convertStringToInt(date.substr(5,2));
}

int DatesMethods::getDay(string date)
{

    return Helpers::convertStringToInt(date.substr(8,2));
}

string DatesMethods::getStrDay(string date)
{

    return (date.substr(8,2));
}

string DatesMethods::getStrYear(string date)
{

    return (date.substr(0,4));
}

string DatesMethods::getStrMonth(string date)
{

    return (date.substr(5,2));
}

int DatesMethods::convertStringDateToIntDate(string date)
{

    return Helpers::convertStringToInt(getStrYear(date)+getStrMonth(date)+getStrDay(date));

}

string DatesMethods::convertIntDateToStringDate(int date)
{
    string strDate = Helpers::convertIntToString(date);

    return (strDate.substr(0,4)+"-"+strDate.substr(4,2)+"-"+strDate.substr(6,2));
}

bool DatesMethods::isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

string DatesMethods::getLastDateOfMonth(string currentDate)
{
    string lastDay = Helpers::convertIntToString(getLastDayOfMonth(getMonth(currentDate), getYear(currentDate)));

    string lastDate = currentDate.substr(0,7)+"-"+lastDay;

    return lastDate;
}

int DatesMethods::getLastDayOfMonth(int month, int year)
{
    if (month == 2)
    {
        if (isLeap(year))
            return 29;
        else
            return 28;
    }

    if (month == 4 ||month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 31;

}

bool DatesMethods::isValidDate(string date)
{

    string maxDate = getLastDateOfMonth(getCurrentDate());

    if(date.length() != 10)
        return false;

    int year = getYear(date);
    int month = getMonth(date);
    int day = getDay(date);

    int maxYear = getYear(maxDate);
    int maxMonth = getMonth(maxDate);
    int maxDay = getDay(maxDate);

    int minYear = 2000;
    int minMonth = 1;
    int minDay = 1;

    if(year < minYear|| year > maxYear)
        return false;
    else
    {
        if (month < 1 || month > 12)
            return false;

        else
        {

            if (month == 2)
            {
                if (isLeap(year))
                    return day <= 30;
                else
                    return day <= 28;
            }

            if (month == 4 ||month == 6 || month == 9 || month == 11)
                return day <= 30;

            else
                return day <= 31;
        }
    }

    return true;


}



string DatesMethods::getPreviousMonth(string date) {

int year = getYear(date);
int month = getMonth(date);

if(month > 1 )  {

month -= 1;

}
else  {

month = 12;
year -= 1;
}

string strMonth = ( month < 10 ) ? "0"+Helpers::convertIntToString(month) : Helpers::convertIntToString(month);


return Helpers::convertIntToString(year)+"-"+strMonth;

}

string DatesMethods::getFirstDay(string date) {

    return date.substr(0,7)+"-01";

}

string DatesMethods::getLastDay(string date) {

    string lastDay = Helpers::convertIntToString(getLastDayOfMonth(getMonth(date), getYear(date)));

   return date.substr(0,7)+"-"+lastDay;

}
string DatesMethods::getFirstDayCurrentMonth()
{

    return getFirstDay(getCurrentDate());
}
string DatesMethods::getLastDayCurrentMonth()
{

    return getLastDay(getCurrentDate());
}










