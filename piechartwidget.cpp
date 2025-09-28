#include "piechartwidget.h"
#include <QPainter>
#include <numeric>

PieChartWidget::PieChartWidget(QWidget *parent)
    : QWidget(parent)
{
}

void PieChartWidget::setData(const QVector<QPair<QString, int>> &data, const QVector<QColor> &colors)
{
    m_data = data;
    m_colors = colors;
    update();  // Trigger repaint
}

void PieChartWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int total = std::accumulate(m_data.begin(), m_data.end(), 0,
                                [](int sum, const QPair<QString, int> &pair) {
                                    return sum + pair.second;
                                });

    if (total == 0)
        return;

    const int margin = 20;
    const int pieSize = qMin(width(), height()) - 2 * margin;
    QRectF pieRect(margin, margin, pieSize, pieSize);

    // Draw pie
    double startAngle = 0;
    for (int i = 0; i < m_data.size(); ++i) {
        double angle = (m_data[i].second * 360.0) / total;
        painter.setPen(Qt::black);
        painter.setBrush(m_colors[i % m_colors.size()]);
        painter.drawPie(pieRect, startAngle * 16, angle * 16);
        startAngle += angle;
    }

    // Draw legend
    const int legendX = pieRect.right() + margin;
    const int legendY = margin;
    const int legendItemHeight = 20;
    const int colorBoxSize = 15;

    painter.setFont(QFont("Arial", 9));

    for (int i = 0; i < m_data.size(); ++i) {
        double percentage = (m_data[i].second * 100.0) / total;
        QString label = QString("%1: %2 (%3%)")
                            .arg(m_data[i].first)
                            .arg(m_data[i].second)
                            .arg(percentage, 0, 'f', 1);

        painter.setPen(Qt::black);
        painter.setBrush(m_colors[i % m_colors.size()]);
        painter.drawRect(legendX, legendY + i * legendItemHeight, colorBoxSize, colorBoxSize);

        painter.setBrush(Qt::NoBrush);
        painter.drawText(legendX + colorBoxSize + 5,
                         legendY + i * legendItemHeight + colorBoxSize - 3,
                         label);
    }
}
