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

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;



    int getNewIncomeId();

public:

    IncomeManager(string incomesFileName, int currentUserId) : fileWithIncomes(incomesFileName), ID_ZALOGOWANEGO_UZYTKOWNIKA(currentUserId){
         incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(ID_ZALOGOWANEGO_UZYTKOWNIKA);
     };



    Income giveNewIncomeData();
    void addIncome();
    void listAllIncomes();
    int getBalanceFromPeriod(string firstDate, string lastDate);

    struct sortByDate
    {
        inline bool operator() ( Income& income1,  Income& income2)
        {
            return (income1.getDate() < income2.getDate());
        }
    };

};

#endif
