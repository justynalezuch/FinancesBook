#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income)
{

    CMarkup xmlFile;

    xmlFile.Load(INCOMES_FILE_NAME);


    if(!xmlFile.FindElem("INCOMES"))

    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("INCOMES");

    }

    xmlFile.IntoElem();

    xmlFile.AddElem("INCOME");
    xmlFile.IntoElem();
    xmlFile.AddElem("INCOMEID", income.getId());
    xmlFile.AddElem("USERID", income.getUserId());
    xmlFile.AddElem("DATE", DatesMethods::convertIntDateToStringDate(income.getDate()));
    xmlFile.AddElem("ITEM", income.getItem());
    xmlFile.AddElem("AMOUNT", Helpers::convertFloatToString(income.getAmount()));

    xmlFile.OutOfElem();
    xmlFile.Save(INCOMES_FILE_NAME);
    lastIncomeId++;
}

vector <Income> FileWithIncomes::loadIncomesOfLoggedUserFromFile(int currentUserId)
{
    vector <Income> incomes;
    Income income;

    CMarkup xml;

    xml.Load(INCOMES_FILE_NAME);

    xml.FindElem("INCOMES");
    xml.IntoElem();
    while ( xml.FindElem("INCOME") )
    {
        xml.IntoElem();

        xml.FindElem( "INCOMEID" );
        income.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
        lastIncomeId = income.getId();


        xml.FindElem( "USERID" );
        income.setUserId(atoi( MCD_2PCSZ(xml.GetData()) ));

        xml.FindElem( "DATE" );
        income.setDate(DatesMethods::convertStringDateToIntDate(xml.GetData()));

        xml.FindElem( "ITEM" );
        income.setItem(xml.GetData());

        xml.FindElem( "AMOUNT");
        income.setAmount(Helpers::convertStringToFloat(xml.GetData()));

        if(income.getUserId() == currentUserId)
        {

            incomes.push_back(income);
        }

        xml.OutOfElem();
    }

    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{

    return lastIncomeId;
}

