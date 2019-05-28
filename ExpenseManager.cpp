
#include "ExpenseManager.h"

int ExpenseManager::getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}

void ExpenseManager::addExpense()
{
    system("cls");
    cout<<"---- DODAJ WYDATEK ----"<<endl;

    Expense expense = giveNewExpenseData();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Dodales wydatek." << endl << endl;
    system("pause");
}


Expense ExpenseManager::giveNewExpenseData()
{

    Expense expense;
    char choice;

    system("cls");
    cout<<"--- DODAJ WYDATEK ---"<<endl;
    cout<<"Czy wydatek dotyczy dnia dzisiejszego? Wybierz t (tak), n (nie):"<<endl;

    choice = Helpers::loadYesNoSign();

    expense.setId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(CURRENT_USER_ID);

    if(choice == 't' )
    {
        int date = DatesMethods::convertStringDateToIntDate(DatesMethods::getCurrentDate());
        expense.setDate(date);

    }
    else if (choice == 'n')
    {
        string date;

        cout<<"Wprowadz date w formacie yyyy-mm-dd: "<<endl;

        while(true)
        {
            cin>>date;

            if(DatesMethods::isValidDate(date))
            {
                cin.ignore();
                expense.setDate(DatesMethods::convertStringDateToIntDate(date));
                break;
            }

            cout<<"Niepoprawna data. Wpisz ponownie."<<endl<<endl;
            cin.ignore();
        }
    }

    string item;
    cout<<"Podaj czego dotyczy wydatek: "<<endl;
    item = Helpers::loadLine();
    expense.setItem(item);

    string amount;
    cout<<"Podaj kwote: "<<endl;


    while (true)
    {
        cin>>amount;

        if (Helpers::isNumber(amount))
        {

            expense.setAmount(Helpers::convertStringToFloat(amount));

            break;
        }
        cout << "Wprowadz poprawna kwote: " << endl;
    }


    return expense;

}


float ExpenseManager::getBalanceFromPeriod(int firstDate, int lastDate)
{

    float sum = 0;

    if (expenses.empty() == true)
    {
        cout<<"Brak wydatkow dla danego okresu"<<endl<<endl<<endl;
    }
    else
    {
        sort(expenses.begin(), expenses.end(), sortByDate());


        for( vector < Expense >::iterator itr = expenses.begin(); itr != expenses.end(); itr++ )
        {

            if(itr->getDate() >= firstDate && itr->getDate() <= lastDate)
            {

                cout<<"ID:          "<<itr->getId() << endl;
                cout<<"DATA:        "<<DatesMethods::convertIntDateToStringDate(itr->getDate()) << endl;
                cout<<"PRZEDMIOT:   "<<itr->getItem() << endl;
                cout<<"KWOTA:       "<<itr->getAmount() << endl;
                cout<<endl;

                sum += itr->getAmount();
            }
        }

        cout<<"--------------------"<<endl;
        cout<<"SUMA WYDATKOW: "<<sum<<endl<<endl;
    }


    return sum;
}

