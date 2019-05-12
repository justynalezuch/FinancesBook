#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Markup.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "FileWithUsers.h"

using namespace std;



int main()
{

    IncomeManager incomemanager;

    incomemanager.giveNewIncomeData();

    //UserManager userManager("users.xml");
    //userManager.listAllUsers();

    return 0;
}
