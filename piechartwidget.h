#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <QString>
#include <QColor>

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    void setData(const QVector<QPair<QString, int>> &data, const QVector<QColor> &colors);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPair<QString, int>> m_data;
    QVector<QColor> m_colors;
signals:
};

#endif // PIECHARTWIDGET_H
