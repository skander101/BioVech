#ifndef AUTOHIDEDOCKWIDGET_H
#define AUTOHIDEDOCKWIDGET_H

#include <QDockWidget>
#include <QEnterEvent>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QWidget>
#include <QPalette>
#include <QDebug>

class AutoHideDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit AutoHideDockWidget(QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    int currentWidth = 20;
};

#endif






