#ifndef BALANCES_H
#define BALANCES_H

#include "Helpers.h"
#include "DatesMethods.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"


#include <iostream>

using namespace std;

class Balances
{


public:
   IncomeManager incomeManager;
    ExpenseManager expenseManager;

    void getCurrentMonthBalance();
    //void getLastMonthBalance();
    //void getCustomPeriodBalance();

};
#endif
