#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "Helpers.h"

using namespace std;

class FinancesBook
{
    UserManager userManager;
    IncomeManager *incomeManager;
    const string INCOMES_FILE_NAME;

public:
    FinancesBook(string usersFileName, string incomesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName)
    {

        incomeManager = NULL;
    };
    ~FinancesBook()
    {

        delete incomeManager;
        incomeManager = NULL;
    };

    void userRegistration();
    void userLogin();
    void changeCurrentUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    void addIncome();
    void listAllIncomes();

    char selectMainMenuOption();
    char selectFinancesMenuOption();


};
