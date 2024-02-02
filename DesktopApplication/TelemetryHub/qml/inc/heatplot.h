#ifndef HEATPLOT_H
#define HEATPLOT_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QObject>
#include <QVariantList>
#include <QVector>
#include <QtMath>
#include <QDebug>
#include <utility>


struct HeatPoint {
    double x;
    double y;
    double heat;
};

class HeatPlot : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(double pointSize READ pointSize WRITE setPointSize NOTIFY pointSizeChanged)
    Q_PROPERTY(double scalingFactor READ scalingFactor WRITE setScalingFactor NOTIFY scalingFactorChanged)
    Q_PROPERTY(double padding READ padding WRITE setPadding NOTIFY paddingChanged)

public:
    explicit HeatPlot(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

    // Add functions to set data and calculate min/max ranges
    Q_INVOKABLE void setHeatData(const QVariantList &data);
    Q_INVOKABLE void updatePlot();

    double pointSize() const;
    void setPointSize(double size);

    double scalingFactor() const;
    void setScalingFactor(double factor);

    double padding() const;
    void setPadding(double pad);

signals:
    void pointSizeChanged();
    void scalingFactorChanged();
    void paddingChanged();

private:
    QVector<HeatPoint> data;
    double m_minX;
    double m_maxX;
    double m_minY;
    double m_maxY;
    double m_minHeat;
    double m_maxHeat;

    double m_pointSize;
    double m_scalingFactor;
    double m_padding;

    // Utility functions
    void calculateBounds();
    QColor HeatToColor(double heat) const;
};

#endif // HEATPLOT_H
