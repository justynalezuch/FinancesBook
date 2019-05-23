#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "Income.h"
#include "DatesMethods.h"
#include "Helpers.h"
#include "FileWithIncomes.h"


using namespace std;

class IncomeManager
{

    const int CURRENT_USER_ID;

    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;



    int getNewIncomeId();

public:

    IncomeManager(string incomesFileName, int currentUserId) : fileWithIncomes(incomesFileName), CURRENT_USER_ID(currentUserId){
         incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(CURRENT_USER_ID);
     };



    Income giveNewIncomeData();
    void addIncome();
    void listAllIncomes();
    float getBalanceFromPeriod(int firstDate, int lastDate);

    struct sortByDate
    {
        inline bool operator() ( Income& income1,  Income& income2)
        {
            return (income1.getDate() < income2.getDate());
        }
    };

};

#endif
