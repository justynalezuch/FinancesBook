#include "FinancesBook.h"


void FinancesBook::userRegistration()
{
    userManager.userRegistration();
}

void FinancesBook::userLogin()
{
    userManager.userLogin();
    if(userManager.isUserLoggedIn())
    {
        incomeManager = new IncomeManager(INCOMES_FILE_NAME, userManager.getCurrentUserId());
        expenseManager = new ExpenseManager(EXPENSES_FILE_NAME, userManager.getCurrentUserId());
    }
}


void FinancesBook::changeCurrentUserPassword()
{
    userManager.changeCurrentUserPassword();
}

void FinancesBook::logoutUser()
{
    userManager.logoutUser();
    delete incomeManager;
    incomeManager = NULL;
}

void FinancesBook::addIncome()
{
    if(userManager.isUserLoggedIn())
    {
        incomeManager->addIncome();
    }
    else
    {
        cout<<"Aby dodac przychod, nalezy najpierw sie zalogowac"<<endl;
        system("pause");
    }

}

void FinancesBook::addExpense()
{
    if(userManager.isUserLoggedIn())
    {
        expenseManager->addExpense();
    }
    else
    {
        cout<<"Aby dodac wydatek, nalezy najpierw sie zalogowac"<<endl;
        system("pause");
    }

}


void FinancesBook::listAllIncomes()
{
    if(userManager.isUserLoggedIn())
    {
        incomeManager->listAllIncomes();
    }
    else
    {
        cout<<"Aby wyswietlic przychody, nalezy sie zalogowac"<<endl;
        system("pause");
    }

}


bool FinancesBook::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

char FinancesBook::selectMainMenuOption()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Helpers::loadSign();

    return choice;
}

char FinancesBook::selectFinancesMenuOption()
{
    char choice;

    system("cls");
    cout << " >>> ZARZADZANIE FINANSAMI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Helpers::loadSign();

    return choice;
}

void FinancesBook::getCurrentMonthBalance()
{
    if(userManager.isUserLoggedIn())
    {
        int firstDate = DatesMethods::convertStringDateToIntDate(DatesMethods::getFirstDayCurrentMonth());
        int lastDate = DatesMethods::convertStringDateToIntDate(DatesMethods::getLastDayCurrentMonth());

        system("cls");

        cout<<"-------- BILANS PRZYCHODOW Z OBECNEGO MIESIACA --------"<<endl<<endl;

        float totalIncomes = incomeManager->getBalanceFromPeriod(firstDate, lastDate);

        cout<<"-------- BILANS WYDATKOW Z OBECNEGO MIESIACA --------"<<endl<<endl;

        float totalExpenses = expenseManager->getBalanceFromPeriod(firstDate, lastDate);


        cout<<"PODSUMOWANIE WYDATKOW I PRZYCHODOW DLA PODANEGO OKRESU: ";
        cout<<totalIncomes - totalExpenses<<endl<<endl;

    }
    else
    {

        cout<<"Aby moc wyswietlic bilans musisz sie zalogowac."<<endl;
    }
    system("pause");
}




