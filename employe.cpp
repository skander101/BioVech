#include "employe.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Employee::Employee(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance, const QString& facecode)
    : m_id(id), m_nom(nom), m_prenom(prenom), m_poste(poste), m_salaire(salaire), m_age(age), m_assurance(assurance), m_facecode(facecode)
{
    // Ensure the connection is established via Connection class
    if (!m_conn.createconnect()) {
        qDebug() << "Failed to connect to the database";
    }
}

Employee::~Employee() {
    // No need to explicitly close connection here, as it's handled by Connection class
}

int Employee::getId() const { return m_id; }
QString Employee::getNom() const { return m_nom; }
QString Employee::getPrenom() const { return m_prenom; }
QString Employee::getPoste() const { return m_poste; }
double Employee::getSalaire() const { return m_salaire; }
int Employee::getAge() const { return m_age; }
QString Employee::getAssurance() const { return m_assurance; }
QString Employee::getFacecode() const { return m_facecode; }


void Employee::setId(int id) { this->m_id = id; }
void Employee::setNom(QString nom){ this->m_nom = nom;} ;
void Employee::setPrenom(QString prenom){ this->m_prenom = prenom;} ;
void Employee::setPoste(QString poste){ this->m_poste = poste;} ;
void Employee::setSalaire(double Salaire){ this->m_salaire = Salaire;} ;
void Employee::setAge(int age){ this->m_age = age;} ;
void Employee::setAssurance(QString assurance){ this->m_assurance = assurance;} ;
void Employee::setFacecode(QString facecode){ this->m_facecode = facecode;};


// Create employee (INSERT)
bool Employee::createEmployee(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance, const QString& password, const QString& facecode)
{
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in createEmployee";
        return false;
    }
    
    QSqlQuery query(db);
    
    // Modified query to exclude CIN field
    query.prepare("INSERT INTO EMPLOYE (ID, NOM, PRENOM, POSTE, SALAIRE, AGE, ASSURANCE, PASSWORD, FACECODE) "
                "VALUES (:id, :nom, :prenom, :poste, :salaire, :age, :assurance, :password, :facecode)");
    
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":age", age);
    query.bindValue(":assurance", assurance);
    query.bindValue(":password", password);
    query.bindValue(":facecode", facecode);

    
    bool success = query.exec();
    if (!success) {
        qDebug() << "Database error:" << query.lastError().text();
    }
    return success;
}

// Read employee (SELECT)
bool Employee::readEmployee(int id) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in readEmployee";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in readEmployee";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("SELECT * FROM EMPLOYE WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error fetching employee: " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        m_id = query.value("ID").toInt();
        m_nom = query.value("NOM").toString();
        m_prenom = query.value("PRENOM").toString();
        m_poste = query.value("POSTE").toString();
        m_salaire = query.value("SALAIRE").toDouble();
        m_age = query.value("AGE").toInt();
        m_assurance = query.value("ASSURANCE").toString();
        return true;
    }

    return false;  // Employee not found
}

// Update employee (UPDATE)
bool Employee::updateEmployee(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in updateEmployee";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("UPDATE EMPLOYE "
                  "SET NOM = :nom, "
                  "    PRENOM = :prenom, "
                  "    POSTE = :poste, "
                  "    SALAIRE = :salaire, "
                  "    AGE = :age, "
                  "    ASSURANCE = :assurance "
                  "WHERE ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":age", age);
    query.bindValue(":assurance", assurance);

    if (!query.exec()) {
        qDebug() << "Error updating employee: " << query.lastError().text();
        return false;
    }
    return true;
}

// Update employee with password (UPDATE)
bool Employee::updateEmployeeWithPassword(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance, const QString& password) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in updateEmployeeWithPassword";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("UPDATE EMPLOYE "
                  "SET NOM = :nom, "
                  "    PRENOM = :prenom, "
                  "    POSTE = :poste, "
                  "    SALAIRE = :salaire, "
                  "    AGE = :age, "
                  "    ASSURANCE = :assurance, "
                  "    PASSWORD = :password "
                  "WHERE ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":age", age);
    query.bindValue(":assurance", assurance);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Error updating employee with password: " << query.lastError().text();
        return false;
    }
    return true;
}

// Delete employee (DELETE)
bool Employee::deleteEmployee(int id) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in deleteEmployee";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("DELETE FROM EMPLOYE WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting employee: " << query.lastError().text();
        return false;
    }
    return true;
}
void Employee::populateTable(QTableWidget* tableWidget) {
    // Clear the existing data in the table
    tableWidget->clearContents();
    tableWidget->setRowCount(0); // Reset row count
    
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in populateTable";
        return;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in populateTable";
        return;
    }
    
    QSqlQuery query(db);

    // Query to fetch employee data from the database
    query.prepare("SELECT * FROM EMPLOYE");

    if (!query.exec()) {
        qDebug() << "Error fetching data from the database: " << query.lastError().text();
        return;
    }

    // Iterate through the result set
    int row = 0;
    while (query.next()) {
        // Insert a new row in the table widget
        tableWidget->insertRow(row);

        // Insert the employee data into the respective columns
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));  // ID
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));  // Nom
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));  // Prenom
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("POSTE").toString()));  // Poste
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(query.value("SALAIRE").toDouble())));  // Salaire
        tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(query.value("AGE").toInt())));  // Age
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("ASSURANCE").toString()));  // Poste

        row++;
    }
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = tableWidget->item(row, col);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

void Employee::populatePresetTable(QTableWidget* tableWidget, QList<Employee> emps) {
    tableWidget->setRowCount(0);

    // Populate the table with search results
    for (int i = 0; i < emps.size(); ++i) {
        tableWidget->insertRow(i);
        tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(emps[i].getId())));
        tableWidget->setItem(i, 1, new QTableWidgetItem(emps[i].getNom()));
        tableWidget->setItem(i, 2, new QTableWidgetItem(emps[i].getPrenom()));
        tableWidget->setItem(i, 3, new QTableWidgetItem(emps[i].getPoste()));
        tableWidget->setItem(i, 4, new QTableWidgetItem(emps[i].getSalaire()));
        tableWidget->setItem(i, 5, new QTableWidgetItem(emps[i].getAge()));
        tableWidget->setItem(i, 6, new QTableWidgetItem(emps[i].getAssurance()));
    }
}

QList<Employee> Employee::search(const QString &keyword) {
    QList<Employee> emps;

    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in search";
        return emps;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in search";
        return emps;
    }
    
    QSqlQuery query(db);

    query.prepare("SELECT ID, NOM, PRENOM, POSTE, SALAIRE, AGE, ASSURANCE FROM EMPLOYE "
                  "WHERE LOWER(NOM) LIKE LOWER('%' || :keyword || '%') OR "
                  "LOWER(PRENOM) LIKE LOWER('%' || :keyword || '%') OR "
                  "LOWER(POSTE) LIKE LOWER('%' || :keyword || '%') OR "
                  "LOWER(ASSURANCE) LIKE LOWER('%' || :keyword || '%') OR "
                  "TO_CHAR(ID) LIKE '%' || :keyword || '%'");

    query.bindValue(":keyword", keyword.trimmed());

    qDebug() << "Executing Query:" << query.lastQuery();
    qDebug() << "Bound Values:" << query.boundValues();

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return emps;
    }

    qDebug() << "Fetching results...";
    int count = 0;
    while (query.next()) {
        count++;
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        QString poste = query.value(3).toString();
        double salaire = query.value(4).toDouble();
        int age = query.value(5).toInt();
        QString assurance = query.value(6).toString();

        qDebug() << "Row" << count << ":"
                 << id << nom << prenom << poste << salaire << age << assurance;

        Employee emp(id, nom, prenom, poste, salaire, age, assurance);
        emps.append(emp);
    }

    qDebug() << "Total employees found:" << count;
    return emps;
}

QList<Employee> Employee::getAll() {
    QList<Employee> emps;

    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in getAll";
        return emps;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in getAll";
        return emps;
    }
    
    QSqlQuery query(db);

    query.prepare("SELECT ID, NOM, PRENOM, POSTE, SALAIRE, AGE, ASSURANCE FROM EMPLOYE");


    qDebug() << "Executing Query:" << query.lastQuery();
    qDebug() << "Bound Values:" << query.boundValues();

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return emps;
    }

    qDebug() << "Fetching results...";
    int count = 0;
    while (query.next()) {
        count++;
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        QString poste = query.value(3).toString();
        double salaire = query.value(4).toDouble();
        int age = query.value(5).toInt();
        QString assurance = query.value(6).toString();

        qDebug() << "Row" << count << ":"
                 << id << nom << prenom << poste << salaire << age << assurance;

        Employee emp(id, nom, prenom, poste, salaire, age, assurance);
        emps.append(emp);
    }

    qDebug() << "Total employees found:" << count;
    return emps;
}

bool Employee::verifycredentials(QString name1,QString name2,QString mail,QString pswd)
{
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in verifycredentials";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in verifycredentials";
        return false;
    }
    
    QSqlQuery query(db);

    query.prepare("SELECT * FROM EMPLOYE "
                  "WHERE LOWER(NOM) LIKE LOWER(:name1) "
                  "AND LOWER(PRENOM) LIKE LOWER(:name2) "
                  "AND ID = :pswd");

    query.bindValue(":name1", name1);
    query.bindValue(":name2", name2);
    query.bindValue(":pswd", pswd.toInt());

    if (!query.exec() || mail!="BioVech.pro") {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }
    
    // Check if we found at least one matching record
    return query.next();
}

bool Employee::verifyCINPassword(int cin, const QString& password) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in verifyCINPassword";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("SELECT * FROM EMPLOYE WHERE CIN = :cin AND PASSWORD = :password");
    query.bindValue(":cin", cin);
    query.bindValue(":password", password);
    
    if (query.exec() && query.next()) {
        qDebug() << "Successfully authenticated employee with CIN:" << cin;
        m_id = query.value("ID").toInt();
        m_nom = query.value("NOM").toString();
        m_prenom = query.value("PRENOM").toString();
        m_poste = query.value("POSTE").toString();
        m_salaire = query.value("SALAIRE").toDouble();
        m_age = query.value("AGE").toInt();
        m_assurance = query.value("ASSURANCE").toString();
        return true;
    } else {
        qDebug() << "Authentication failed for CIN:" << cin;
        qDebug() << "Query error:" << query.lastError().text();
        return false;
    }
}

bool Employee::verifyIDPassword(int id, const QString& password) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in verifyIDPassword";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("SELECT * FROM EMPLOYE WHERE ID = :id AND PASSWORD = :password");
    query.bindValue(":id", id);
    query.bindValue(":password", password);
    
    if (query.exec() && query.next()) {
        qDebug() << "Successfully authenticated employee with ID:" << id;
        m_id = query.value("ID").toInt();
        m_nom = query.value("NOM").toString();
        m_prenom = query.value("PRENOM").toString();
        m_poste = query.value("POSTE").toString();
        m_salaire = query.value("SALAIRE").toDouble();
        m_age = query.value("AGE").toInt();
        m_assurance = query.value("ASSURANCE").toString();
        return true;
    } else {
        qDebug() << "Authentication failed for ID:" << id;
        qDebug() << "Query error:" << query.lastError().text();
        return false;
    }
}

// Update face code for employee
bool Employee::updateFaceCode(int id, const QString& faceCode) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in updateFaceCode";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in updateFaceCode";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("UPDATE EMPLOYE SET FACECODE = :facecode WHERE ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":facecode", faceCode);
    
    if (!query.exec()) {
        qDebug() << "Error updating face code: " << query.lastError().text();
        return false;
    }
    
    qDebug() << "Face code updated successfully for ID:" << id;
    return true;
}

// Get face code for employee
QString Employee::getFaceCode(int id) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in getFaceCode";
        return QString();
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in getFaceCode";
        return QString();
    }
    
    QSqlQuery query(db);
    
    query.prepare("SELECT FACECODE FROM EMPLOYE WHERE ID = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error fetching face code: " << query.lastError().text();
        return QString();
    }

    if (query.next()) {
        QString faceCode = query.value("FACECODE").toString();
        qDebug() << "Retrieved face code for ID:" << id;
        return faceCode;
    }
    
    qDebug() << "No face code found for ID:" << id;
    return QString();
}

// Verify employee using face code
bool Employee::verifyFaceCode(const QString& faceCode) {
    // Create a connection instance and establish connection
    Connection c;
    bool test = c.createconnect();
    
    if (!test) {
        qDebug() << "Database connection failed in verifyFaceCode";
        return false;
    }

    // Get the named database connection
    QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
    
    if (!db.isOpen()) {
        qDebug() << "Database is not open in verifyFaceCode";
        return false;
    }
    
    QSqlQuery query(db);
    
    query.prepare("SELECT * FROM EMPLOYE WHERE FACECODE = :facecode");
    query.bindValue(":facecode", faceCode);
    
    if (!query.exec()) {
        qDebug() << "Error verifying face code: " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        m_id = query.value("ID").toInt();
        m_nom = query.value("NOM").toString();
        m_prenom = query.value("PRENOM").toString();
        m_poste = query.value("POSTE").toString();
        m_salaire = query.value("SALAIRE").toDouble();
        m_age = query.value("AGE").toInt();
        m_assurance = query.value("ASSURANCE").toString();
        return true;
    }
    
    return false;
}
