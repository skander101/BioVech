#include "autohidedockwidget.h"
#include <QEnterEvent>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>

AutoHideDockWidget::AutoHideDockWidget(QWidget *parent)
    : QDockWidget(parent)
{
    // Force QDockWidget to update its background
    setAttribute(Qt::WA_StyledBackground, true);
    setAutoFillBackground(true);


    // Apply global style
    setStyleSheet(
        "QDockWidget {"
        "border: 2px solid #208c54;"
        "border-radius: 10px;"
        "background-color: #208c54;"
        "}"
        "QDockWidget::title {"
        "background-color: #208c54;"
        "color: white;"
        "padding: 5px;"
        "font-size: 18px;"
        "border-radius: 15px;"
        "}"
        );

    // Ensure the main widget inside the dock gets the background
    QWidget *container = new QWidget(this);
    container->setAttribute(Qt::WA_StyledBackground, true);  // Force background paint
    container->setAutoFillBackground(true);
    container->setStyleSheet("background-color: #27ae60;");  // Green background inside

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    container->setLayout(layout);

    setWidget(container);  // Set container to apply styles inside
}

void AutoHideDockWidget::enterEvent(QEnterEvent *event)
{
    QDockWidget::enterEvent(event);

    for (int i = currentWidth; i < 280; i += 20) {
        QTimer::singleShot((i - 100) * 0.5, this, [this, i]() {
            this->setFixedWidth(i);
            this->setVisible(true);
            currentWidth = i;
        });
    }

    Q_UNUSED(event);
}

void AutoHideDockWidget::leaveEvent(QEvent *event)
{
    QDockWidget::leaveEvent(event);

    for (int i = currentWidth; i >100; i -= 20) {
        QTimer::singleShot((300 - i) * 0.5, this, [this, i]() {
            this->setFixedWidth(i);
            this->setVisible(true);
            currentWidth = i;
        });
    }

    Q_UNUSED(event);
}

void AutoHideDockWidget::closeEvent(QCloseEvent *event)
{
    qDebug() << "A dock widget has been closed!";
    QMessageBox::information(this, "Dock Widget Closed", "A dock widget has been closed!");

    event->accept();
}
