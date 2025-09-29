#include "Evenement.h"

Evenement::Evenement(){
    id=0;
    titre="";
    nomsponsor="";
    description="";
    position="";
    type="";
}
Evenement::Evenement(int i, string tt, string ns, string d, string ty, string pos, QDate de ){
    id=i;
    titre=tt;
    nomsponsor=ns;
    description=d;
    position=pos;
    type=ty;
    dateE=de;
}
int Evenement::getId(){
    return id;
}
string Evenement::getTitre(){
    return titre;
}
string Evenement::getNomSponsor(){
    return nomsponsor	;
}
string Evenement::getDescription(){
    return description;
}
string Evenement::getType(){
    return type;
}
string Evenement::getPos(){
    return position;
}
QDate Evenement::getDate(){
    return dateE;
}
double Evenement::getX(){
    return x;
}
double Evenement::getY(){
    return y;
}
void Evenement::setId(int i){
    id=i;
}
void Evenement::setTitre(string t){
    titre=t;
}
void Evenement::setNomSponsor(string n){
    nomsponsor=n;
}
void Evenement::setDescription(string d){
    description=d;
}
void Evenement::setType(string t){
    type=t;
}
void Evenement::setPos(string p){
    position=p;
}
void Evenement::setDate(QDate d){
    dateE=d;
}
void Evenement::setX(double a){
    x=a;
}
void Evenement::setY(double b){
    y=b;
}
bool Evenement::addEvent(){
    QSqlQuery query;
    QString res= QString::number(id);
    QString Titr=QString::fromStdString(titre);
    QString nomS=QString::fromStdString(nomsponsor);
    QString desc=QString::fromStdString(description);
    QString Typ=QString::fromStdString(type);
    QString Pos=QString::fromStdString(position);

    query.prepare("INSERT INTO EVENEMENT(Id, Titre, NOMSPONSOR, Description, Datee, Type, Position) VALUES (:Id, :Titre, :NOMSPONSOR, :Description, TO_DATE(:Datee,'YYYY-MM-DD'), :Type, :Position)");
    query.bindValue(":Id",res.toInt());
    query.bindValue(":Titre",Titr);
    query.bindValue(":NOMSPONSOR",nomS);
    query.bindValue(":Description",desc);
    query.bindValue(":Datee",dateE.toString("yyyy-MM-dd"));
    query.bindValue(":Type",Typ);
    query.bindValue(":Position",Pos);
    if(!query.exec()){
        qDebug()<<"Error: "<<query.lastError().text();
        return false;
    }
    return true;
}
bool Evenement::modifyEvent(int i){
    QSqlQuery query;
    QString res=QString::number(i);
    QString Titr=QString::fromStdString(titre);
    QString nomS=QString::fromStdString(nomsponsor);
    QString desc=QString::fromStdString(description);
    QString Pos=QString::fromStdString(position);
    QString Typ=QString::fromStdString(type);
    query.prepare("update EVENEMENT set titre=:Titre, NOMSPONSOR=:NOMSPONSOR, Description=:Description, Datee=TO_Date(:Datee,'YYYY-MM-DD'), Type=:Type, Position=:Position WHERE Id=:Id");
    query.bindValue(":Id",res.toInt());
    query.bindValue(":Titre",Titr);
    query.bindValue(":NOMSPONSOR",nomS);
    query.bindValue(":Description",desc);
    query.bindValue(":Datee",dateE.toString("yyyy-MM-dd"));
    query.bindValue(":Type",Typ);
    query.bindValue(":Position",Pos);
    if(!query.exec()){
        qDebug()<<"Error: "<<query.lastError().text();
        return false;
    }
    return true;

}
bool Evenement::DeleteEvent(int i){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from EVENEMENT where Id=:id");
    query.bindValue(":id",i);
    return query.exec();
}
QList<QStringList> Evenement::ListEvent(){
    QList<QStringList> data;
    QSqlQuery query("select * from EVENEMENT");
    while(query.next()){
        QStringList row;
        row<<query.value(0).toString();
        row<<query.value(1).toString();
        row<<query.value(2).toString();
        row<<query.value(3).toString();
        row<<query.value(4).toDate().toString("dd/MM/yyyy");
        row<<query.value(5).toString();
        row<<query.value(6).toString();
        data.append(row);
    }
    return data;
}
void Evenement::GetCoordinates(){
    LatLng ref = { 36.89796929275437, 10.189987847617902 };
    string fullcode=RecoverNearest(position,ref);
    CodeArea area=Decode(fullcode);
    x=area.GetCenter().latitude;
    y=area.GetCenter().longitude;
    qDebug()<<"Position: "<<position;
    qDebug()<<"Latitude: "<<x;
    qDebug()<<"Longitude: "<<y;
}
