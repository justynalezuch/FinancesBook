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

void Income::setDate(int newDate)
{
    date = newDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(float newAmount)
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

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}



