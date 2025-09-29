#include <iostream>
#include "openlocationcode.h"
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QSqlError>
using namespace std;
using namespace openlocationcode;
class Evenement{
private:
    int id;
    double x,y;
    string titre, nomsponsor, description, type,position;
    QDate dateE;
public:
    Evenement();
    Evenement(int, string, string, string, string,string,QDate);
    int getId();
    string getTitre();
    string getNomSponsor();
    string getDescription();
    string getType();
    string getPos();
    QDate getDate();
    double getX();
    double getY();
    void GetCoordinates();
    void setId(int);
    void setX(double);
    void setY(double);
    void setTitre(string);
    void setNomSponsor(string);
    void setDescription(string);
    void setPos(string);
    void setType(string);
    void setDate(QDate);
    bool addEvent();
    bool modifyEvent(int);
    bool DeleteEvent(int);
    QList<QStringList> ListEvent();
};
