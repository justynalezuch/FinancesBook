#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "Helpers.h"
#include "DatesMethods.h"
#include "Markup.h"


using namespace std;

class FileWithIncomes
{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

public:

    FileWithIncomes(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName){

        lastIncomeId = 0;
    };

    void addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedUserFromFile(int currentUserId);
    int getLastIncomeId();

};

#endif
