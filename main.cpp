#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Markup.h"
#include "UserManager.h"

using namespace std;



int main()
{

    UserManager userManager;

    userManager.userRegistration();

    userManager.userLogin();

    userManager.getCurrentUserId();

        userManager.changeCurrentUserPassword();


    userManager.listAllUsers();
    userManager.userLogin();





    return 0;
}
