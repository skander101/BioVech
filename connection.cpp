#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    // Check if the connection already exists
    if (QSqlDatabase::contains("BioVechConnection")) {
        qDebug() << "Connection already exists.";
        QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
        if (db.isOpen()) {
            return true;
        } else {
            // Connection exists but is closed, try to reopen it
            if (db.open()) {
                qDebug() << "Reopened existing connection successfully!";
                return true;
            } else {
                qDebug() << "Failed to reopen existing connection:" << db.lastError().text();
                // Remove the invalid connection and try to create a new one
                QSqlDatabase::removeDatabase("BioVechConnection");
            }
        }
    }

    // Add a named connection to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "BioVechConnection");
    
    // Set up database connection for Oracle using ODBC
    db.setDatabaseName("BioVech"); // ODBC DSN name
    db.setUserName("admin");
    db.setPassword("admin");
    
    // Attempt to open the connection
    if (db.open()) {
        qDebug() << "Database connection successful!";
        return true;
    } else {
        qDebug() << "Error connecting to database:" << db.lastError().text();
        return false;
    }
}

void Connection::printDriverInfo() {
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << "Available database drivers:";
    for (const QString &driver : drivers) {
        qDebug() << " " << driver;
    }
}

bool Connection::testConnection() {
    // Create a new connection for testing
    Connection conn;
    bool connected = conn.createconnect();
    
    if (connected) {
        qDebug() << "Connection test SUCCESSFUL. Database is open.";
    } else {
        qDebug() << "Connection test FAILED. Could not create connection.";
    }
    
    return connected;
}
