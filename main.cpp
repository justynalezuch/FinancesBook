#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Markup.h"

using namespace std;



int main()
{
     CMarkup xml;
    xml.AddElem( "INCOMES" );
    xml.IntoElem();
    xml.AddElem( "ITEM" );
    xml.IntoElem();
    xml.AddElem( "incomeId", 1 );
    xml.AddElem( "userId", 3 );
    xml.AddElem( "date", 3 );
    xml.AddElem( "item", "AUTO" );
    xml.AddElem( "amount", 15.14 );
    xml.OutOfElem();



    xml.Save("INCOMES.xml");

    cout << "Hello world!" << endl;
    return 0;
}
