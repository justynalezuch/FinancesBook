
#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "Expense.h"
#include "DatesMethods.h"
#include "Helpers.h"
#include "FileWithExpenses.h"


using namespace std;

class ExpenseManager
{

    const int CURRENT_USER_ID;

    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;



    int getNewExpenseId();

public:

    ExpenseManager(string expenseFileName, int currentUserId) : fileWithExpenses(expenseFileName), CURRENT_USER_ID(currentUserId)
    {
        expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(CURRENT_USER_ID);
    };



    Expense giveNewExpenseData();
    void addExpense();
    void listAllExpenses();
    float getBalanceFromPeriod(int firstDate, int lastDate);


    struct sortByDate
    {
        inline bool operator() ( Expense& expense1,  Expense& expense2)
        {
            return (expense1.getDate() < expense2.getDate());
        }
    };

};

#endif

