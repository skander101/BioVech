#ifndef PREDICTIONEVOLUTION_H
#define PREDICTIONEVOLUTION_H

#include <QString>
#include <QList>
#include <QMap>

class PredictionEvolution
{
public:
    PredictionEvolution();
    ~PredictionEvolution();

    QString predireEvolution(int idMicroorganisme);

private:
    QList<QMap<QString, QString>> getCaracteristiquesEtEvolutionsSimilaires(int idMicroorganisme);
    QMap<QString, QString> extraireCaracteristiquesEtEvolution(const QString& texte);
    int comparerCaracteristiques(const QMap<QString, QString>& caracteristiquesAComparer,
                                 const QMap<QString, QString>& caracteristiquesReferentes);
    QString calculerEvolution(const QList<QMap<QString, QString>>& resultats, int idMicroorganisme);
    QList<QString> getCaractéristiquesSimilaires(int idMicroorganisme);
};

#endif // PREDICTIONEVOLUTION_H
