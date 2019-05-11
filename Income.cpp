#include "Income.h"


void Income::setId(int newId)
{
    if(newId >= 0)
        id = newId;
}

void Income::setUserId(int newId)
{
    if(newId >= 0)
        userId = newId;
}

void Income::setDate(string newDate)
{
    date = newDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(double newAmount)
{
    amount = newAmount;
}

int Income::getId()
{
    return id;
}

int Income::getUserId()
{
    return userId;
}

string Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

double Income::getAmount()
{
    return amount;
}

