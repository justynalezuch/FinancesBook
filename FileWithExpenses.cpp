
#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
{

    CMarkup xmlFile;

    xmlFile.Load(EXPENSES_FILE_NAME);


    if(!xmlFile.FindElem("EXPENSES"))

    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENSES");

    }

    xmlFile.IntoElem();

    xmlFile.AddElem("EXPENSE");
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSEID", expense.getId());
    xmlFile.AddElem("USERID", expense.getUserId());
    xmlFile.AddElem("DATE", DatesMethods::convertIntDateToStringDate(expense.getDate()));
    xmlFile.AddElem("ITEM", expense.getItem());
    xmlFile.AddElem("AMOUNT", Helpers::convertFloatToString(expense.getAmount()));

    xmlFile.OutOfElem();
    xmlFile.Save(EXPENSES_FILE_NAME);
    lastExpenseId++;
}

vector <Expense> FileWithExpenses::loadExpensesOfLoggedUserFromFile(int currentUserId)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;

    xml.Load(EXPENSES_FILE_NAME);

    xml.FindElem("EXPENSES");
    xml.IntoElem();
    while ( xml.FindElem("EXPENSE") )
    {
        xml.IntoElem();

        xml.FindElem( "EXPENSEID" );
        expense.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
        lastExpenseId = expense.getId();


        xml.FindElem( "USERID" );
        expense.setUserId(atoi( MCD_2PCSZ(xml.GetData()) ));

        xml.FindElem( "DATE" );
        expense.setDate(DatesMethods::convertStringDateToIntDate(xml.GetData()));

        xml.FindElem( "ITEM" );
        expense.setItem(xml.GetData());

        xml.FindElem( "AMOUNT");
        expense.setAmount(Helpers::convertStringToFloat(xml.GetData()));

        if(expense.getUserId() == currentUserId)
        {

            expenses.push_back(expense);
        }

        xml.OutOfElem();
    }

    return expenses;
}

int FileWithExpenses::getLastExpenseId()
{

    return lastExpenseId;
}
