#include "Microorganisme.h"

// Constructor with optional parameters
Microorganisme::Microorganisme(const QString &nom, const QString &type, const QDate &datem, const QString &caracteristique)
    : m_nom(nom), m_type(type), m_datem(datem), m_caracteristique(caracteristique)
{
}

// Create (Insert) a microorganism record in the database
bool Microorganisme::create()
{
    m_query.prepare("INSERT INTO microorganisme (NOM, TYPE, DATEM, CARACTERISTIQUE) "
                    "VALUES (:nom, :type, TO_DATE(:datem, 'YYYY-MM-DD'), :caracteristique)");
    m_query.bindValue(":nom", m_nom);
    m_query.bindValue(":type", m_type);
    m_query.bindValue(":datem", m_datem.toString("yyyy-MM-dd"));  // Ensure correct date format
    m_query.bindValue(":caracteristique", m_caracteristique);

    if (m_query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Database Error", m_query.lastError().text());
        return false;
    }
}

// Read a microorganism record from the database based on ID
bool Microorganisme::read(int id)
{
    m_query.prepare("SELECT * FROM microorganisme WHERE ID = :id");
    m_query.bindValue(":id", id);

    if (m_query.exec() && m_query.next()) {
        m_id = m_query.value("ID").toInt();
        m_nom = m_query.value("NOM").toString();
        m_type = m_query.value("TYPE").toString();
        m_datem = m_query.value("DATEM").toDate();
        m_caracteristique = m_query.value("CARACTERISTIQUE").toString();
        return true;
    } else {
        QMessageBox::critical(nullptr, "Database Error", m_query.lastError().text());
        return false;
    }
}

// Update an existing microorganism record in the database
bool Microorganisme::update()
{
    m_query.prepare("UPDATE microorganisme SET NOM = :nom, TYPE = :type, DATEM = TO_DATE(:datem, 'YYYY-MM-DD'), CARACTERISTIQUE = :caracteristique WHERE ID = :id");
    m_query.bindValue(":id", m_id);
    m_query.bindValue(":nom", m_nom);
    m_query.bindValue(":type", m_type);
    m_query.bindValue(":datem", m_datem.toString("yyyy-MM-dd"));  // Ensure correct date format
    m_query.bindValue(":caracteristique", m_caracteristique);

    if (m_query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Database Error", m_query.lastError().text());
        return false;
    }
}

// Remove a microorganism record from the database
bool Microorganisme::remove()
{
    m_query.prepare("DELETE FROM microorganisme WHERE ID = :id");
    m_query.bindValue(":id", m_id);

    if (m_query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Database Error", m_query.lastError().text());
        return false;
    }
}



// Getter and Setter methods for each attribute

int Microorganisme::getId() const
{
    return m_id;
}

void Microorganisme::setId(int id)
{
    m_id = id;
}

QString Microorganisme::getNom() const
{
    return m_nom;
}

void Microorganisme::setNom(const QString &nom)
{
    m_nom = nom;
}

QString Microorganisme::getType() const
{
    return m_type;
}

void Microorganisme::setType(const QString &type)
{
    m_type = type;
}

QDate Microorganisme::getDatem() const
{
    return m_datem;
}

void Microorganisme::setDatem(const QDate &datem)
{
    m_datem = datem;
}

QString Microorganisme::getCaracteristique() const
{
    return m_caracteristique;
}

void Microorganisme::setCaracteristique(const QString &caracteristique)
{
    m_caracteristique = caracteristique;
}
