#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expense.h"
#include "Helpers.h"
#include "DatesMethods.h"
#include "Markup.h"


using namespace std;

class FileWithExpenses
{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

public:

    FileWithExpenses(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName){

        lastExpenseId = 0;
    };

    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesOfLoggedUserFromFile(int currentUserId);
    int getLastExpenseId();

};

#endif