#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "Helpers.h"
#include "DatesMethods.h"

using namespace std;

class FinancesBook
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    FinancesBook(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {

        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~FinancesBook()
    {

        delete incomeManager;
        delete expenseManager;
        incomeManager = NULL;
        expenseManager = NULL;
    };

    void userRegistration();
    void userLogin();
    void changeCurrentUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    void addIncome();
    void addExpense();
    void getCurrentMonthBalance();
    void getPreviousMonthBalance();

    void listAllIncomes();

    char selectMainMenuOption();
    char selectFinancesMenuOption();


};
