#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int id;
    int userId;
    int date;
    string item;
    float amount;

public:
    void setId(int newId);
    void setUserId(int newId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};
#endif



