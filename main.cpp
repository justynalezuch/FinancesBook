#include <iostream>

#include "FinancesBook.h"

using namespace std;



int main()
{

char choice;

    FinancesBook financesBook("users.xml", "incomes.xml", "expenses.xml");

    while (true)
    {
        if (financesBook.isUserLoggedIn() == false)
        {
            choice = financesBook.selectMainMenuOption();

            switch (choice)
            {
            case '1':
                financesBook.userRegistration();
                break;
            case '2':
                financesBook.userLogin();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = financesBook.selectFinancesMenuOption();

            switch (choice)
            {
            case '1':
                financesBook.addIncome();
                break;
            case '2':
                financesBook.addExpense();
                break;
            case '3':
                financesBook.getCurrentMonthBalance();
                break;
            case '4':
                financesBook.getPreviousMonthBalance();
                break;
            case '5':
                financesBook.getCustomPeriodBalance();
                break;
            case '6':
                financesBook.changeCurrentUserPassword();
                break;
            case '7':
                financesBook.logoutUser();
                break;
            }
        }


    }


    return 0;
}


/*int main()
{
    FinancesBook financesBook("users.xml", "incomes.xml", "expenses.xml");

  financesBook.getCustomPeriodBalance();

    return 0;
}
*/
