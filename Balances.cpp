#include "Balances.h"



void Balances::getCurrentMonthBalance()
{

    int firstDate = DatesMethods::convertStringDateToIntDate(DatesMethods::getFirstDayCurrentMonth());
    int lastDate = DatesMethods::convertStringDateToIntDate(DatesMethods::getLastDayCurrentMonth());

    float totalIncomes = incomeManager.getBalanceFromPeriod(firstDate, lastDate);
    float totalExpenses = expenseManager.getBalanceFromPeriod(firstDate, lastDate);


    cout<<"BILANS WYDATKOW I PRZYCHODOW DLA PODANEGO OKRESU: "<<endl;

    cout<<totalIncomes - totalExpenses<<endl;


}
