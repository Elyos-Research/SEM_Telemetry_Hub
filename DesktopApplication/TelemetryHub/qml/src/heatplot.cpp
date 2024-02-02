#include "../inc/heatplot.h"

HeatPlot::HeatPlot(QQuickItem *parent)
    : QQuickPaintedItem(parent),
    m_minX(0), m_maxX(0), m_minY(0),
    m_maxY(0), m_minHeat(0), m_maxHeat(0),
    m_pointSize(2.0),
    m_scalingFactor(1.0),
    m_padding(10.0) {
    setFlag(ItemHasContents, true);
}

double HeatPlot::pointSize() const {
    return m_pointSize;
}

void HeatPlot::setPointSize(double size) {
    if (m_pointSize == size)
        return;

    m_pointSize = size;
    emit pointSizeChanged();
    update();
}

double HeatPlot::scalingFactor() const {
    return m_scalingFactor;
}

void HeatPlot::setScalingFactor(double factor) {
    if (m_scalingFactor == factor)
        return;

    m_scalingFactor = factor;
    emit scalingFactorChanged();
    update();
}

double HeatPlot::padding() const {
    return m_padding;
}

void HeatPlot::setPadding(double pad) {
    if (m_padding == pad)
        return;

    m_padding = pad;
    emit paddingChanged();
    update();
}

void HeatPlot::paint(QPainter *painter) {
    painter->setRenderHint(QPainter::Antialiasing);

    // Check for empty data
    if (data.isEmpty()) {
        return;
    }

    double paddedWidth = width() - 2 * m_padding;
    double paddedHeight = height() - 2 * m_padding;

    double scaleX = paddedWidth / (m_maxX - m_minX);
    double scaleY = paddedHeight / (m_maxY - m_minY);
    double uniformScale = qMin(scaleX, scaleY) * m_scalingFactor;

    painter->setPen(Qt::NoPen);

    // Draw each data point
    for (const HeatPoint &point : std::as_const(data)) {
        // Convert coordinates to canvas space
        double x = m_padding + (point.x - m_minX) * uniformScale;
        double y = m_padding + (point.y - m_minY) * uniformScale;

        QColor color = HeatToColor(point.heat);
        painter->setBrush(color);
        painter->drawEllipse(QPointF(x, y), 2, 2); // Adjust the size as needed
    }
}

void HeatPlot::setHeatData(const QVariantList &heatData) {
    data.clear();

    // Reset bounds
    m_minX = m_minY = m_minHeat = std::numeric_limits<double>::max();
    m_maxX = m_maxY = m_maxHeat = std::numeric_limits<double>::lowest();

    for (const QVariant &item : heatData) {
        QVariantMap map = item.toMap();
        HeatPoint point;
        point.x = map["x"].toDouble();
        point.y = map["y"].toDouble();
        point.heat = map["heat"].toDouble();
        data.append(point);

        // Update bounds
        m_minX = qMin(m_minX, point.x);
        m_maxX = qMax(m_maxX, point.x);
        m_minY = qMin(m_minY, point.y);
        m_maxY = qMax(m_maxY, point.y);
        m_minHeat = qMin(m_minHeat, point.heat);
        m_maxHeat = qMax(m_maxHeat, point.heat);
    }

    update(); // Trigger a repaint
}

void HeatPlot::updatePlot() {
    update(); // Trigger a repaint
}

void HeatPlot::calculateBounds() {
    m_minX = std::numeric_limits<double>::max();
    m_maxX = std::numeric_limits<double>::lowest();
    m_minY = std::numeric_limits<double>::max();
    m_maxY = std::numeric_limits<double>::lowest();
    m_minHeat = std::numeric_limits<double>::max();
    m_maxHeat = std::numeric_limits<double>::lowest();

    for (const HeatPoint &point : data) {
        m_minX = qMin(m_minX, point.x);
        m_maxX = qMax(m_maxX, point.x);
        m_minY = qMin(m_minY, point.y);
        m_maxY = qMax(m_maxY, point.y);
        m_minHeat = qMin(m_minHeat, point.heat);
        m_maxHeat = qMax(m_maxHeat, point.heat);
    }
}

QColor HeatPlot::HeatToColor(double heat) const {
    // Map heat value to color
    double normalizedHeat = (heat - m_minHeat) / (m_maxHeat - m_minHeat);
    int red = qBound(0, static_cast<int>(normalizedHeat * 255), 255);
    int green = 255 - red;
    int blue = 0;
    return QColor(red, green, blue);
}
