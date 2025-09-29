#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AutoHideDockWidget.h"
#include "Microorganisme.h"
#include "PredictionEvolution.h"
#include <QTimer>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPainter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPrinter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarCategoryAxis>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Nom" << "Type" << "Date" << "Caractéristique");


    QTimer::singleShot(500, this, [this]() {
        populateTable(ui->tableWidget);
    });

    // Sidebar setup (AutoHideDockWidget)
    QDockWidget *oldDockWidget = ui->dockWidget;
    if (oldDockWidget) {
        AutoHideDockWidget *autoHideDockWidget = new AutoHideDockWidget(this);
        autoHideDockWidget->setFeatures(oldDockWidget->features());
        autoHideDockWidget->setWidget(oldDockWidget->widget());

        removeDockWidget(oldDockWidget);
        oldDockWidget->setParent(nullptr);
        delete oldDockWidget;

        addDockWidget(Qt::LeftDockWidgetArea, autoHideDockWidget);
        ui->dockWidget = autoHideDockWidget;
    }


    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_tableWidget_itemSelectionChanged);

    connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::on_pushButton_17_clicked);
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::on_searchButtonClicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::trierMicroorganismes);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::afficherStatistiques);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::populateTable(QTableWidget* tableWidget)
{

    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));


    query.prepare("SELECT * FROM ADMIN.MICROORGANISME");

    if (!query.exec()) {
        qDebug() << "Error fetching data from the database: " << query.lastError().text();
        return;
    }


    int row = 0;
    while (query.next()) {

        tableWidget->insertRow(row);


        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));  // ID
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));  // Nom
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));  // Type
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));  // Date
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));  // Caractéristique
        row++;
    }
}

// Add a microorganism + ID Autoincrement
void MainWindow::on_pushButton_12_clicked()
{
    QString nom = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QDate datem = ui->calendarWidget->selectedDate();
    QString caracteristique = ui->lineEdit_6->text();

    // Obtenir la date d'aujourd'hui
    QDate today = QDate::currentDate();
    QDate minDate(2020, 1, 1);  // Date minimale : 1er janvier 2020

    // Vérification des contraintes sur la date
    if (datem > today) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être dans le futur !");
        return;
    }
    if (datem < minDate) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être avant 2020 !");
        return;
    }

    // Création de l'objet Microorganisme après validation de la date
    Microorganisme m(nom, type, datem, caracteristique);
    if (m.create()) {
        QMessageBox::information(this, "Succès", "Microorganisme ajouté !");
        populateTable(ui->tableWidget);  // Rafraîchir le tableau
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du microorganisme.");
    }
}




// Update a selected microorganism
void MainWindow::on_pushButton_14_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
    QString nom = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QDate datem = ui->calendarWidget->selectedDate();
    QString caracteristique = ui->lineEdit_6->text();

    // Obtenir la date d'aujourd'hui
    QDate today = QDate::currentDate();
    QDate minDate(2020, 1, 1);  // Date minimale : 1er janvier 2020

    // Vérification des contraintes sur la date
    if (datem > today) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être dans le futur !");
        return;
    }
    if (datem < minDate) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être avant 2020 !");
        return;
    }

    // Mise à jour après validation de la date
    Microorganisme m(nom, type, datem, caracteristique);
    m.setId(id);

    if (m.update()) {
        QMessageBox::information(this, "Succès", "Microorganisme mis à jour !");
        populateTable(ui->tableWidget);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour.");
    }
}


// Remove a selected microorganism
void MainWindow::on_pushButton_13_clicked()
{
    int id = ui->lineEdit_2->text().toInt();

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT COUNT(*) FROM ADMIN.MICROORGANISME WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count == 0) {
            QMessageBox::warning(this, "Erreur", "L'ID spécifié n'existe pas !");
            return;
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID !");
        return;
    }

    // L'ID existe, on peut supprimer
    Microorganisme m;
    m.setId(id);

    if (m.remove()) {
        QMessageBox::information(this, "Succès", "Microorganisme supprimé !");
        populateTable(ui->tableWidget);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}


// Fill the fields based on the selected row in the table
void MainWindow::on_tableWidget_itemSelectionChanged()
{
    QList<QTableWidgetItem *> selection = ui->tableWidget->selectedItems();
    if (!selection.isEmpty()) {
        ui->lineEdit_2->setText(selection.at(0)->text());
        ui->lineEdit_3->setText(selection.at(1)->text());
        ui->comboBox->setCurrentText(selection.at(2)->text());  // Set the selected type in comboBox
        ui->calendarWidget->setSelectedDate(QDate::fromString(selection.at(3)->text(), "yyyy-MM-dd"));
        ui->lineEdit_6->setText(selection.at(4)->text());
    }
}

// Function to handle search when the search button is clicked
void MainWindow::on_searchButtonClicked()
{
    QString searchText = ui->lineEdit->text();

    // Clear the existing data in the table
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));

    // fetch data based on search text
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME WHERE NOM LIKE :searchText");
    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Error fetching data from the database: " << query.lastError().text();
        return;
    }


    int row = 0;
    while (query.next()) {
        // Insert a new row in the table widget
        ui->tableWidget->insertRow(row);

        // Insert the microorganism data into the respective columns
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));
        row++;
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPrinter printer(QPrinter::ScreenResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Échec de la création du PDF.");
        return;
    }

    int margin = 50;
    int rowHeight = 30;
    int columnWidths[] = {50, 150, 150, 100, 200};
    int tableWidth = columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4];
    int yOffset = margin;

    // Titre
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(margin, yOffset, "Liste des Microorganismes");
    yOffset += 40;

    // En-têtes
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    int xOffset = margin;
    QStringList headers = {"ID", "Nom", "Type", "Date", "Caractéristique"};
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(xOffset, yOffset, headers[i]);
        xOffset += columnWidths[i];
    }
    yOffset += rowHeight;
    painter.drawLine(margin, yOffset, margin + tableWidth, yOffset);

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des données : " << query.lastError().text();
        painter.end();
        return;
    }

    painter.setFont(QFont("Arial", 10));
    int total = 0;
    QMap<QString, int> typeCounts;
    QMap<QDate, int> dateCounts;

    while (query.next()) {
        xOffset = margin;
        painter.drawText(xOffset, yOffset, query.value("ID").toString());
        xOffset += columnWidths[0];
        painter.drawText(xOffset, yOffset, query.value("NOM").toString());
        xOffset += columnWidths[1];
        QString type = query.value("TYPE").toString();
        painter.drawText(xOffset, yOffset, type);
        typeCounts[type]++;
        xOffset += columnWidths[2];
        QDate date = query.value("DATEM").toDate();
        painter.drawText(xOffset, yOffset, date.toString("yyyy-MM-dd"));
        dateCounts[date]++;
        xOffset += columnWidths[3];
        painter.drawText(xOffset, yOffset, query.value("CARACTERISTIQUE").toString());

        yOffset += rowHeight;
        painter.drawLine(margin, yOffset, margin + tableWidth, yOffset);
        total++;
    }

    yOffset += 40;
    painter.setFont(QFont("Arial", 11, QFont::Bold));
    painter.drawText(margin, yOffset, "Statistiques :");
    yOffset += rowHeight;
    painter.setFont(QFont("Arial", 10));

    painter.drawText(margin, yOffset, "Nombre total : " + QString::number(total));
    yOffset += rowHeight;

    for (auto it = typeCounts.begin(); it != typeCounts.end(); ++it) {
        painter.drawText(margin, yOffset, QString("Type %1 : %2").arg(it.key()).arg(it.value()));
        yOffset += rowHeight;
    }

    // Nouvelle page pour graphiques
    printer.newPage();
    yOffset = margin;

    // Taille adaptée à la largeur de page PDF
    int pageWidth = printer.pageRect(QPrinter::Point).width();
    QSize imageSize(pageWidth - 2 * margin, 400);  // Hauteur fixe

    auto renderChartToImage = [](QChart* chart, QSize size) {
        QPixmap pixmap(size);
        pixmap.fill(Qt::white);

        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        QChartView chartView(chart);
        chartView.resize(size);
        chartView.render(&painter);
        return pixmap;
    };

    // PIE chart
    QPieSeries* pieSeries = new QPieSeries();
    for (auto it = typeCounts.begin(); it != typeCounts.end(); ++it)
        pieSeries->append(it.key(), it.value());

    QChart* pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition par type");

    QPixmap piePixmap = renderChartToImage(pieChart, imageSize);

    // BAR chart
    QBarSet* set = new QBarSet("Types");
    QStringList categories;
    for (auto it = typeCounts.begin(); it != typeCounts.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    QBarSeries* barSeries = new QBarSeries();
    barSeries->append(set);

    QChart* barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Types de micro-organismes");

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    QPixmap barPixmap = renderChartToImage(barChart, imageSize);

    // LINE chart
    QLineSeries* lineSeries = new QLineSeries();
    QList<QDate> sortedDates = dateCounts.keys();
    std::sort(sortedDates.begin(), sortedDates.end());
    for (const QDate& d : sortedDates)
        lineSeries->append(d.toJulianDay(), dateCounts[d]);

    QChart* lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Évolution par date de découverte");

    QValueAxis* axisXLine = new QValueAxis();
    axisXLine->setLabelFormat("%d");
    lineChart->addAxis(axisXLine, Qt::AlignBottom);
    lineSeries->attachAxis(axisXLine);

    QValueAxis* axisYLine = new QValueAxis();
    lineChart->addAxis(axisYLine, Qt::AlignLeft);
    lineSeries->attachAxis(axisYLine);

    QPixmap linePixmap = renderChartToImage(lineChart, imageSize);

    // Dessin dans le PDF
    painter.setFont(QFont("Arial", 11, QFont::Bold));
    painter.drawText(margin, yOffset, "Graphiques statistiques :");
    yOffset += rowHeight;

    painter.drawPixmap(margin, yOffset, piePixmap);
    yOffset += piePixmap.height() + 20;
    painter.drawPixmap(margin, yOffset, barPixmap);
    yOffset += barPixmap.height() + 20;
    painter.drawPixmap(margin, yOffset, linePixmap);

    painter.end();
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec les statistiques et graphiques.");
}








void MainWindow::on_pushButton_11_clicked()
{
    QString critere = ui->comboBox_2->currentText();
    QString ordre = ui->comboBox_3->currentText();


    QString queryStr = "SELECT * FROM ADMIN.MICROORGANISME ORDER BY ";

    if (critere == "Nom") {
        queryStr += "NOM";
    } else if (critere == "Type") {
        queryStr += "TYPE";
    } else if (critere == "DateM") {
        queryStr += "DATEM";
    } else {
        QMessageBox::warning(this, "Erreur", "Critère de tri invalide.");
        return;
    }

    if (ordre == "Descending") {
        queryStr += " DESC";
    } else if (ordre == "Ascending") {
        queryStr += " ASC";
    } else {
        QMessageBox::warning(this, "Erreur", "Ordre de tri invalide.");
        return;
    }

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare(queryStr);

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Échec du tri.");
        return;
    }

    // Vider et remplir le tableau avec les résultats triés
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));
        row++;
    }
}


void MainWindow::trierMicroorganismes()
{
    QString critere = ui->comboBox_2->currentText();
    QString ordre = ui->comboBox_3->currentText();

    QString colonne;
    if (critere == "Nom")
        colonne = "NOM";
    else if (critere == "Type")
        colonne = "TYPE";
    else if (critere == "DateM")
        colonne = "DATEM";
    else
        return;

    QString ordreSQL = (ordre == "Ascending") ? "ASC" : "DESC";

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME ORDER BY " + colonne + " " + ordreSQL);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri : " + query.lastError().text());
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));
        row++;
    }
}

#include <QtCharts>

void MainWindow::afficherStatistiques()
{
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));

    // Compter par type
    query.prepare("SELECT TYPE, COUNT(*) FROM ADMIN.MICROORGANISME GROUP BY TYPE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de récupération des statistiques.");
        return;
    }

    // Création pie chart
    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        series->append(query.value(0).toString(), query.value(1).toInt());
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des micro-organismes par type");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage dans une nouvelle fenêtre
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(600, 400);
    dialog->exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données.");
        return;
    }

    int total = 0;
    QMap<QString, int> typeCount;
    QMap<QDate, int> dateCount;
    QMap<QString, int> nomCount;
    QDate minDate = QDate::currentDate();
    QDate maxDate(1900, 1, 1);

    while (query.next()) {
        total++;
        QString type = query.value("TYPE").toString();
        QString nom = query.value("NOM").toString();
        QDate date = query.value("DATEM").toDate();

        typeCount[type]++;
        nomCount[nom]++;
        dateCount[date]++;

        if (date < minDate) minDate = date;
        if (date > maxDate) maxDate = date;
    }

    // ---------- PIE CHART ----------
    QPieSeries* pieSeries = new QPieSeries();
    for (auto it = typeCount.begin(); it != typeCount.end(); ++it)
        pieSeries->append(it.key(), it.value());

    QChart* pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition par Type");

    QChartView* pieView = new QChartView(pieChart);
    pieView->setRenderHint(QPainter::Antialiasing);
    pieView->resize(500, 300);
    pieView->show();

    // ---------- BAR CHART ----------
    QBarSet* set = new QBarSet("Noms");
    QStringList categories;
    for (auto it = nomCount.begin(); it != nomCount.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    QBarSeries* barSeries = new QBarSeries();
    barSeries->append(set);

    QChart* barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Micro-organismes par nom");

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->createDefaultAxes();
    barChart->setAxisX(axisX, barSeries);

    QChartView* barView = new QChartView(barChart);
    barView->setRenderHint(QPainter::Antialiasing);
    barView->resize(500, 300);
    barView->show();

    // ---------- LINE CHART ----------
    QLineSeries* lineSeries = new QLineSeries();
    QList<QDate> dates = dateCount.keys();
    std::sort(dates.begin(), dates.end());

    for (const QDate& date : dates)
        lineSeries->append(date.toJulianDay(), dateCount[date]);

    QChart* lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Évolution par date de découverte");
    lineChart->createDefaultAxes();

    QChartView* lineView = new QChartView(lineChart);
    lineView->setRenderHint(QPainter::Antialiasing);
    lineView->resize(500, 300);
    lineView->show();

    // ---------- STATS TEXTE ----------
    QString statsText;
    statsText += "Total micro-organismes : " + QString::number(total) + "\n";
    statsText += "Date la plus ancienne : " + minDate.toString("dd/MM/yyyy") + "\n";
    statsText += "Date la plus récente  : " + maxDate.toString("dd/MM/yyyy") + "\n";
    statsText += "Nombre de types       : " + QString::number(typeCount.size()) + "\n";
    statsText += "Nombre de noms        : " + QString::number(nomCount.size()) + "\n";

    QMessageBox::information(this, "Statistiques globales", statsText);
}



void MainWindow::on_pushButton_16_clicked()
{
    int id = ui->lineEdit_2->text().toInt(); // Récupérer l'ID entré
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));

    query.prepare("SELECT NOM, TYPE, DATEM, CARACTERISTIQUE FROM ADMIN.MICROORGANISME WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Remplir directement les champs
        ui->lineEdit_3->setText(query.value("NOM").toString());  // Nom
        ui->comboBox->setCurrentText(query.value("TYPE").toString());  // Type
        ui->calendarWidget->setSelectedDate(query.value("DATEM").toDate());  // DateM
        ui->lineEdit_6->setText(query.value("CARACTERISTIQUE").toString());  // Caractéristique
    } else {
        QMessageBox::warning(this, "Erreur", "Microorganisme non trouvé !");
    }
}

void MainWindow::on_pushButton_17_clicked() {
    // Prédire l'évolution en utilisant l'ID du microorganisme sélectionné
    PredictionEvolution predictor;
    int idMicroorganisme = ui->lineEdit_2->text().toInt();

    if (idMicroorganisme <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un microorganisme valide.");
        return;
    }

    // Utiliser la classe PredictionEvolution pour prédire l'évolution
    QString evolution = predictor.PredictionEvolution::predireEvolution(idMicroorganisme);

    // Afficher l'évolution dans le lineEdit_4
    ui->lineEdit_4->setText(evolution);
}

void MainWindow::on_pushButton_18_clicked()
{
    QString texte = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QString date = ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");

    if (nom.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir le nom et le type.");
        return;
    }

    QStringList documents = texte.split("||", Qt::SkipEmptyParts);
    QMap<QString, QStringList> analyseParBloc;

    QStringList motsCles = { "mutation", "transmission", "symptôme", "symptomes", "résistance", "vaccin", "mortalité" };
    for (const QString& document : documents) {
        QStringList lignes = document.split(QRegularExpression("[\\n\\r]+"), Qt::SkipEmptyParts);
        for (const QString& ligne : lignes) {
            for (const QString& motCle : motsCles) {
                if (ligne.contains(motCle, Qt::CaseInsensitive)) {
                    QString motCleStandardise = motCle.toLower().replace("symptomes", "symptôme");
                    analyseParBloc[motCleStandardise] << ligne.trimmed();
                    break;
                }
            }
        }
    }

    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichier PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);
    QPainter painter(&writer);
    painter.setFont(QFont("Helvetica", 10));
    QRect rect = painter.viewport();

    int y = 100;
    int lineHeight = 40; // ✅ Espacement augmenté

    // En-tête
    painter.drawText(100, y, "Nom : " + nom);
    y += lineHeight;
    painter.drawText(100, y, "Type : " + type);
    y += lineHeight;
    painter.drawText(100, y, "Date de découverte : " + date);
    y += lineHeight * 2;

    for (const QString& motCle : analyseParBloc.keys()) {
        painter.drawText(100, y, "---- Analyse d'un bloc : " + motCle + " ----");
        y += lineHeight;

        double somme = 0;
        int count = 0;
        QRegularExpression regex(R"((\d+(?:[.,]\d+)?)(\s*%?)\b)");

        for (const QString& ligne : analyseParBloc[motCle]) {
            QRegularExpressionMatch match = regex.match(ligne);
            if (match.hasMatch()) {
                QString valeurStr = match.captured(1).replace(',', '.');
                somme += valeurStr.toDouble();
                count++;

                QString ligneModifiable = ligne;
                ligneModifiable.remove(match.captured(0));
                painter.drawText(100, y, ligneModifiable.trimmed());
            } else {
                painter.drawText(100, y, ligne.trimmed());
            }
            y += lineHeight;

            if (y > rect.height() - 100) {
                writer.newPage();
                y = 100;
            }
        }

        if (count > 0) {
            double moyenne = somme / count;
            QString suffixe = analyseParBloc[motCle].join(" ").contains('%') ? "%" : "";
            painter.drawText(100, y, "→ Moyenne détectée : " + QString::number(moyenne, 'f', 2) + suffixe);
            y += lineHeight;
        }

        y += lineHeight; // ✅ Espace entre blocs augmenté
    }

    painter.end();

    QMessageBox::information(this, "Analyse terminée", "Analyse sauvegardée dans le PDF avec succès !");
}

