#include "PredictionEvolution.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QList>
#include <QMap>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <algorithm>

// Constructeur
PredictionEvolution::PredictionEvolution() {}

// Destructeur
PredictionEvolution::~PredictionEvolution() {}

// Fonction principale pour prédire l'évolution du microorganisme
QString PredictionEvolution::predireEvolution(int idMicroorganisme) {
    // Étape 1 : Récupérer les caractéristiques et évolutions des microorganismes similaires
    QList<QMap<QString, QString>> resultatsSimilaires = getCaracteristiquesEtEvolutionsSimilaires(idMicroorganisme);

    qDebug() << "Caractéristiques et évolutions similaires récupérées : ";
    for (const auto& resultat : resultatsSimilaires) {
        qDebug() << "Caractéristiques : " << resultat.value("Caractéristiques");
        qDebug() << "Évolution : " << resultat.value("Évolution");
    }

    // Étape 2 : Comparer les caractéristiques et calculer l'évolution
    QString evolution = calculerEvolution(resultatsSimilaires, idMicroorganisme);

    return evolution;
}

// Fonction pour récupérer les caractéristiques et évolutions des microorganismes similaires
QList<QMap<QString, QString>> PredictionEvolution::getCaracteristiquesEtEvolutionsSimilaires(int idMicroorganisme) {
    QList<QMap<QString, QString>> resultats;

    // Récupérer les caractéristiques et évolutions des microorganismes similaires à partir de la base de données
    QSqlQuery query;
    query.prepare("SELECT CARACTERISTIQUE FROM ADMIN.MICROORGANISME WHERE ID != :id");
    query.bindValue(":id", idMicroorganisme);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des caractéristiques et évolutions : " << query.lastError().text();
        return resultats;
    }

    while (query.next()) {
        QString caracteristique = query.value("CARACTERISTIQUE").toString();
        QMap<QString, QString> resultatsExtraits = extraireCaracteristiquesEtEvolution(caracteristique);
        resultats.append(resultatsExtraits);
    }

    return resultats;
}

// Fonction pour extraire les caractéristiques et l'évolution d'un texte
QMap<QString, QString> PredictionEvolution::extraireCaracteristiquesEtEvolution(const QString& texte) {
    QMap<QString, QString> resultats;

    // Extraire les caractéristiques avant le séparateur "Évolution:"
    QRegularExpression patternCaracteristiques("Caractéristiques:(.*?)(?=Évolution:|$)");
    QRegularExpressionMatch matchCaracteristiques = patternCaracteristiques.match(texte);
    if (matchCaracteristiques.hasMatch()) {
        resultats["Caractéristiques"] = matchCaracteristiques.captured(1).trimmed();
    }

    // Extraire l'évolution après le séparateur "Évolution:"
    QRegularExpression patternEvolution("Évolution:(.*?)(?=$)");
    QRegularExpressionMatch matchEvolution = patternEvolution.match(texte);
    if (matchEvolution.hasMatch()) {
        resultats["Évolution"] = matchEvolution.captured(1).trimmed();
    } else {
        resultats["Évolution"] = ""; // Si aucune évolution n'est présente
    }

    return resultats;
}

// Fonction pour comparer les caractéristiques et calculer un score de similarité
int PredictionEvolution::comparerCaracteristiques(const QMap<QString, QString>& caracteristiquesAComparer,
                                                  const QMap<QString, QString>& caracteristiquesReferentes) {
    int similarite = 0;
    for (auto it = caracteristiquesAComparer.begin(); it != caracteristiquesAComparer.end(); ++it) {
        QString valueAComparer = it.value().trimmed();
        QString valueReferente = caracteristiquesReferentes.value(it.key()).trimmed();

        // Comparer les chaînes après suppression des espaces inutiles
        if (valueAComparer == valueReferente) {
            similarite++;
        }
    }
    return similarite;
}

// Fonction pour calculer l'évolution d'un microorganisme
QString PredictionEvolution::calculerEvolution(const QList<QMap<QString, QString>>& resultats, int idMicroorganisme) {
    // Si la liste des résultats est vide, retourner une évolution par défaut
    if (resultats.isEmpty()) {
        return "Aucune évolution détectée";
    }

    // Comparer les caractéristiques de chaque microorganisme pour évaluer l'évolution
    QList<int> similarites;
    QList<QString> evolutions;  // Liste pour stocker les évolutions
    QString evolutionPrédite = "Aucune évolution détectée";  // Valeur par défaut

    for (const QMap<QString, QString>& result : resultats) {
        // Extraire les caractéristiques et les évolutions
        QString caracteristiques = result.value("Caractéristiques");
        QString evolution = result.value("Évolution");

        // Si l'évolution est définie, on ajoute à la liste pour comparaison
        if (!evolution.isEmpty()) {
            int similarite = comparerCaracteristiques(result, result);  // Comparer les caractéristiques

            similarites.append(similarite);
            evolutions.append(evolution); // Ajouter l'évolution correspondante
        }
    }

    // Si des similarités ont été trouvées, retourner l'évolution associée
    if (!similarites.isEmpty()) {
        int scoreMax = *std::max_element(similarites.begin(), similarites.end());
        if (scoreMax > 0) {
            int indexMax = similarites.indexOf(scoreMax);
            evolutionPrédite = evolutions.at(indexMax);  // Retourner l'évolution du microorganisme le plus similaire
        }
    }

    return evolutionPrédite;
}
