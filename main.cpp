#include <iostream>
#include "Markup.h"
#include "UserManager.h"
#include "IncomeManager.h"


using namespace std;



int main()
{

    IncomeManager incomemanager("incomes.xml");

    incomemanager.addIncome();
    incomemanager.addIncome();

    incomemanager.listAllIncomes();

    return 0;
}
