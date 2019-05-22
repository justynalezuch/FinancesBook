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
    income.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    if(choice == 't' )
    {
        int date = DatesMethods::convertStringDateToIntDate(DatesMethods::getCurrentDate());
        income.setDate(date);

    }
    else if (choice == 'n')
    {
        string date;


        while(true)
        {
            cout<<"Wprowadz date w formacie yyyy-mm-dd: "<<endl;
            cin>>date;
            cin.ignore();

            if(DatesMethods::isValidDate(date))
            {
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


int IncomeManager::getBalanceFromPeriod(string firstDate, string lastDate)
{

    int firstDateNumeric = DatesMethods::convertStringDateToIntDate(firstDate);
    int secondDateNumeric = DatesMethods::convertStringDateToIntDate(lastDate);

    sort(incomes.begin(), incomes.end(), sortByDate());
    float sum = 0;


    for( vector < Income >::iterator itr = incomes.begin(); itr != incomes.end(); itr++ )
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

    cout<<"-------- SUMA PRZYCHODOW --------"<<endl<<endl;
    cout<<sum<<endl;


    return sum;
}




