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

public:

    FileWithIncomes(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName){

    };

    void addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedUserFromFile(int currentUserId);

};

#endif
