#include "IncomeManager.h"

int IncomeManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

void IncomeManager::addIncome()
{
    Income income = giveNewIncomeData();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Dodales przychod." << endl << endl;
    system("pause");
}

void IncomeManager::listAllIncomes()
{
    for(int i = 0; i <incomes.size(); i++)
    {
        cout<<incomes[i].getId() << endl;
        cout<<incomes[i].getUserId() << endl;
        cout<<incomes[i].getDate() << endl;
        cout<<incomes[i].getItem() << endl;
        cout<<incomes[i].getAmount() << endl;
        cout<<endl;
    }

    system("pause");
}


Income IncomeManager::giveNewIncomeData()
{

    Income income;
    char choice;


    cout<<"--- DODAJ PRZYCHOD ---"<<endl;
    cout<<"Czy przychod dotyczy dnia dzisiejszego? Wybierz t (tak), n (nie):"<<endl;

    choice = Helpers::loadYesNoSign();

    income.setId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(CURRENT_USER_ID);

    if(choice == 't' )
    {
        int date = DatesMethods::convertStringDateToIntDate(DatesMethods::getCurrentDate());
        income.setDate(date);

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
                income.setDate(DatesMethods::convertStringDateToIntDate(date));
                break;
            }

            cout<<"Niepoprawna data. Wpisz ponownie."<<endl<<endl;
            cin.ignore();
        }
    }

    string item;
    cout<<"Podaj czego dotyczy przychod: "<<endl;
    item = Helpers::loadLine();
    income.setItem(item);

    string amount;
    cout<<"Podaj kwote: "<<endl;


    while (true)
    {
        cin>>amount;

        if (Helpers::isNumber(amount))
        {

            income.setAmount(Helpers::convertStringToFloat(amount));

            break;
        }
        cout << "Wprowadz poprawna kwote: " << endl;
    }


    return income;

}


float IncomeManager::getBalanceFromPeriod(int firstDate, int lastDate)
{

    float sum = 0;

    if (incomes.empty() == true)
    {
        cout<<"Brak wydatkow dla danego okresu"<<endl<<endl<<endl;
    }
    else
    {
        sort(incomes.begin(), incomes.end(), sortByDate());

        for( vector < Income >::iterator itr = incomes.begin(); itr != incomes.end(); itr++ )
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

        cout<<endl<<"-------- SUMA PRZYCHODOW --------"<<endl<<endl;
        cout<<sum<<endl<<endl;
    }


    return sum;
}




