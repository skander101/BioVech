#include "Dialogue.h"

Dialogue::Dialogue(QWidget *parent) : QDialog(parent)
{
    // Créer les boutons radio
    radioType = new QRadioButton("Type", this);
    radioSponsor = new QRadioButton("Sponsor", this);
    radioTitle = new QRadioButton("Title", this);

    // Créer le champ de saisie
    lineEdit = new QLineEdit(this);

    // Créer les boutons "Search" et "Cancel"
    searchButton = new QPushButton("Search", this);
    cancelButton = new QPushButton("Cancel", this);

    // Appliquer un style aux QRadioButton
    QString radioButtonStyle = R"(
    QRadioButton {
        color: rgb(30, 143, 83); /* Couleur du texte en vert */
    }
    QRadioButton::indicator {
        color: rgb(30, 143, 83); /* Couleur de l'indicateur en vert */
        border: 2px solid gray; /* Bordure par défaut */
        width: 13px;
        height: 13px;
        border-radius: 7px; /* Pour un indicateur rond */
    }
    QRadioButton::indicator:checked {
        border-color: rgb(30, 143, 83); /* Bordure verte lorsque sélectionné */
        background-color: transparent; /* Fond transparent pour ne pas changer la couleur de fond */
    }
)";
    radioType->setStyleSheet(radioButtonStyle);
    radioSponsor->setStyleSheet(radioButtonStyle);
    radioTitle->setStyleSheet(radioButtonStyle);

    // Organiser les widgets dans un layout vertical
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(radioType);
    layout->addWidget(radioSponsor);
    layout->addWidget(radioTitle);
    layout->addWidget(lineEdit);
    layout->addWidget(searchButton);
    layout->addWidget(cancelButton);

    // Connecter les boutons
    connect(searchButton, &QPushButton::clicked, this, &QDialog::accept); // Fermer la fenêtre et accepter
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject); // Fermer la fenêtre et annuler
}

QString Dialogue::getSearchText() const
{
    return lineEdit->text(); // Retourner le texte saisi dans le QLineEdit
}

QString Dialogue::getSearchCriteria() const
{
    // Retourner le critère de recherche sélectionné
    if (radioType->isChecked())
        return "Type";
    else if (radioSponsor->isChecked())
        return "Sponsor";
    else if (radioTitle->isChecked())
        return "Title";
    return QString(); // Retourner une chaîne vide si aucun critère n'est sélectionné
}
