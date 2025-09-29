#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("BioVech");
    db.setUserName("admin");
    db.setPassword("admin");

    if (db.open())
        test=true;





    return  test;
}
