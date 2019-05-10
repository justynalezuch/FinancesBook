#include "FileWithUsers.h"

vector <User> FileWithUsers::loadUsersFromTheFile()
{
    vector <User> users;
    User user;

    CMarkup xml;

    xml.Load(USERS_FILE_NAME);

    xml.FindElem("USERS");
    xml.IntoElem();
    while ( xml.FindElem("USER") )
    {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        user.setId(atoi( MCD_2PCSZ(xml.GetData()) ));

        xml.FindElem( "LOGIN" );
        user.setLogin(xml.GetData());

        xml.FindElem( "PASSWORD" );
        user.setPassword(xml.GetData());

        xml.FindElem( "NAME" );
        user.setName(xml.GetData());

        xml.FindElem( "SURNAME");
        user.setSurname(xml.GetData());

        users.push_back(user);
        xml.OutOfElem();
    }

    return users;
}


void FileWithUsers::addUserToFile(User user)
{

    CMarkup xmlFile;

    xmlFile.Load(USERS_FILE_NAME);


    if(!xmlFile.FindElem("USERS"))

    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");

    }

    xmlFile.IntoElem();

    xmlFile.AddElem("USER");
    xmlFile.IntoElem();
    xmlFile.AddElem("USERID", user.getId());
    xmlFile.AddElem("LOGIN", user.getLogin());
    xmlFile.AddElem("PASSWORD", user.getPassword());
    xmlFile.AddElem("NAME", user.getName());
    xmlFile.AddElem("SURNAME", user.getSurname());

    xmlFile.OutOfElem();

    xmlFile.Save(USERS_FILE_NAME);

}



void FileWithUsers::saveAllUsersInTheFile(vector <User> &users)
{
    CMarkup xml;
    xml.AddElem( "USERS" );
    xml.IntoElem();
    string date;

    for( vector <User>::iterator itr = users.begin(); itr != users.end(); itr++ ) {

        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem("USERID", itr->getId());
        xml.AddElem("LOGIN", itr->getLogin());
        xml.AddElem("PASSWORD", itr->getPassword());
        xml.AddElem("NAME", itr->getName());
        xml.AddElem("SURNAME", itr->getSurname());

        xml.OutOfElem();
        xml.Save(USERS_FILE_NAME);
    }
}

