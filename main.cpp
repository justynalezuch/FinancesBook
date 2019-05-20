#include <iostream>
#include <vector>
#include <algorithm>
#include "FinancesBook.h"


#include "IncomeManager.h"



using namespace std;



int main()
{

char choice;

    FinancesBook financesBook("users.xml", "incomes.xml");

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
                financesBook.listAllIncomes();
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
