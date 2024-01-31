#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariantList>
#include <QDebug>

class DataParser : public QObject {
    Q_OBJECT
public:

    // Constructors
    explicit DataParser(QObject *parent = nullptr);

    // Parse functions
    Q_INVOKABLE void parseLabelData(const QString &dataString);

    // Map getters
    Q_INVOKABLE QVariant getLabelData(const QString &label) const;
    Q_INVOKABLE QStringList getLabels() const;

signals:
    void newLabelAdded();
    void dataUpdated();

private:
    QVariantMap parsedData;

};

#endif // DATAPARSER_H
