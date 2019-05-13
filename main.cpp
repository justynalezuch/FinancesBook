#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

#include "Markup.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "FileWithUsers.h"

using namespace std;



int main()
{


    IncomeManager incomemanager;

    incomemanager.addIncome();
    incomemanager.addIncome();
    incomemanager.listAllIncomes();



    //UserManager userManager("users.xml");
    //userManager.listAllUsers();

    return 0;
}
