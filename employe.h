#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QByteArray>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include "connection.h"  // Include the Connection class header
#include <QTableWidget>


class Employee {
public:
    Employee(int id = -1, const QString& nom = "", const QString& prenom = "", const QString& poste = "", double salaire = 0.0, int age = 0, const QString& assurance = QString(), const QString& facecode = QString());
    ~Employee();

    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getPoste() const;
    double getSalaire() const;
    int getAge() const;
    QString getAssurance() const;
    QString getFacecode() const;

    void setId(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setPoste(QString poste);
    void setSalaire(double Salaire);
    void setAge(int age);
    void setAssurance(QString assurance);
    void setFacecode(QString facecode);


    bool createEmployee(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance, const QString& password, const QString& facecode);
    bool readEmployee(int id);
    bool updateEmployee(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance);
    bool updateEmployeeWithPassword(int id, const QString& nom, const QString& prenom, const QString& poste, double salaire, int age, const QString& assurance, const QString& password);
    bool deleteEmployee(int id);
    void populateTable(QTableWidget* tableWidget);
    QList<Employee>search(const QString &keyword);
    void populatePresetTable(QTableWidget* tableWidget,QList<Employee> emps);
    QList<Employee>getAll();
    bool verifycredentials(QString name1,QString name2,QString mail,QString pswd);
    bool verifyCINPassword(int cin, const QString& password);
    bool verifyIDPassword(int id, const QString& password);
    
    // Face recognition methods
    bool updateFaceCode(int id, const QString& faceCode);
    bool verifyFaceCode(const QString& faceCode);
    QString getFaceCode(int id);

private:
    int m_id;
    QString m_nom;
    QString m_prenom;
    QString m_poste;
    double m_salaire;
    int m_age;
    QString m_assurance;
    QString m_facecode;

    Connection m_conn;  // Connection object to manage DB connection
};

#endif // EMPLOYEE_H
