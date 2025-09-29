#ifndef MICROORGANISME_H
#define MICROORGANISME_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlQueryModel>

class Microorganisme
{
public:
    Microorganisme(const QString &nom = "", const QString &type = "",
                   const QDate &datem = QDate(), const QString &caracteristique = "");


    bool create();
    bool read(int id);
    bool update();
    bool remove();


    int getId() const;
    void setId(int id);
    QString getNom() const;
    void setNom(const QString &nom);
    QString getType() const;
    void setType(const QString &type);
    QDate getDatem() const;
    void setDatem(const QDate &datem);
    QString getCaracteristique() const;
    void setCaracteristique(const QString &caracteristique);




private:
    int m_id;
    QString m_nom;
    QString m_type;
    QDate m_datem;
    QString m_caracteristique;

    QSqlQuery m_query;  // Database query object
};

#endif
