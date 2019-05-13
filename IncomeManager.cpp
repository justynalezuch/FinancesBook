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

    income.setId(getNewIncomeId());
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
    cin>>amount;
    income.setAmount(Helpers::convertStringToFloat(amount));


    return income;

}

