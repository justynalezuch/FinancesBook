#include "IncomeManager.h"

int IncomeManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

Income IncomeManager::giveNewIncomeData()
{

    Income income;

    char choice;


    cout<<"--- DODAJ PRZYCHOD ---"<<endl;
    cout<<"Czy przychod dotyczy dnia dzisiejszego? Wybierz t (tak), n (nie)"<<endl;

    choice = Helpers::loadYesNoSign();


    if(choice == 't' )
    {
        int date = DatesMethods::convertStringDateToIntDate(DatesMethods::getCurrentDate());
        income.setDate(date);

    }
    else if (choice == 'n')
    {
        string date;
        cout<<"Wprowadz date: "<<endl;
        cin>>date;

        if(DatesMethods::isValidDate(date)) {
        cout<<"Poprawna data."<<endl;

        income.setDate(DatesMethods::convertStringDateToIntDate(date));

        cout<<DatesMethods::convertStringDateToIntDate(date)<<endl;

        }
        else {
            cout<<"Niepoprawna data."<<endl<<endl;
        }

    }







}

