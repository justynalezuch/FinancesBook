
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
    Expense expense = giveNewExpenseData();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Dodales wydatek." << endl << endl;
    system("pause");
}

void ExpenseManager::listAllExpenses()
{
    for(int i = 0; i <expenses.size(); i++)
    {
        cout<<expenses[i].getId() << endl;
        cout<<expenses[i].getUserId() << endl;
        cout<<expenses[i].getDate() << endl;
        cout<<expenses[i].getItem() << endl;
        cout<<expenses[i].getAmount() << endl;
        cout<<endl;
    }

    system("pause");
}


Expense ExpenseManager::giveNewExpenseData()
{

    Expense expense;
    char choice;

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


int ExpenseManager::getBalanceFromPeriod(string firstDate, string lastDate)
{

    int firstDateNumeric = DatesMethods::convertStringDateToIntDate(firstDate);
    int secondDateNumeric = DatesMethods::convertStringDateToIntDate(lastDate);

    sort(expenses.begin(), expenses.end(), sortByDate());
    float sum = 0;


    for( vector < Expense >::iterator itr = expenses.begin(); itr != expenses.end(); itr++ )
    {

        if(itr->getDate() >= firstDateNumeric && itr->getDate() <= secondDateNumeric)
        {

            cout<<itr->getId() << endl;
            cout<<itr->getUserId() << endl;
            cout<<itr->getDate() << endl;
            cout<<itr->getItem() << endl;
            cout<<itr->getAmount() << endl;
            cout<<endl;

            sum += itr->getAmount();
        }
    }

    cout<<"-------- SUMA WYDATKOW --------"<<endl<<endl;
    cout<<sum<<endl;


    return sum;
}

