#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QUrl>
#include <QVariantList>
#include <QDebug>


struct DataEntry {
    double latitude;
    double longitude;
    double elevation;
};

class Track : public QObject
{
    Q_OBJECT
public:

    static Track* instance();
    Q_INVOKABLE void loadData(const QUrl &fileUrl);
    Q_INVOKABLE QVariantList getTableModel() const;

signals:
    void dataLoaded();

private:
    explicit Track(QObject *parent = nullptr);
    static Track* _instance;
    QVector<DataEntry> data;

signals:
};

#endif // TRACK_H
