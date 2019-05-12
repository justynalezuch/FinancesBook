#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "DatesMethods.h"
#include "Helpers.h"


using namespace std;

class IncomeManager
{
    int currentUserId;

    vector <Income> incomes;
   //	FileWithIncomes fileWithIncomes;


    int getNewIncomeId();

public:

   /* IncomeManager(string(incomesFileName)) : (incomesFileName)){
        currentUserId = 0;
        incomes = fileWithIncomes.loadIncomesOfLoggedUserFromTheFile();
    };*/

 Income giveNewIncomeData();
    void addIncome();



};

#endif
