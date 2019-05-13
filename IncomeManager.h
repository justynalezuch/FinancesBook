#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "DatesMethods.h"
#include "Helpers.h"
#include "FileWithIncomes.h"


using namespace std;

class IncomeManager
{

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA = 1;

    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;


    int getNewIncomeId();

public:

    IncomeManager(string incomesFileName) : fileWithIncomes(incomesFileName){
         incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(ID_ZALOGOWANEGO_UZYTKOWNIKA);
     };



    Income giveNewIncomeData();
    void addIncome();
    void listAllIncomes();




};

#endif
