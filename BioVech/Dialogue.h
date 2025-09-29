#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <QVBoxLayout>
#include <QDialog>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>

class Dialogue : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogue(QWidget *parent = nullptr);
    QString getSearchText() const;
    QString getSearchCriteria() const;

private:
    QRadioButton *radioType;
    QRadioButton *radioSponsor;
    QRadioButton *radioTitle;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QPushButton *cancelButton;
};

#endif // DIALOGUE_H
