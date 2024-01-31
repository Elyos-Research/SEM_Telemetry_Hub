#include "track.h"

Track* Track::_instance = nullptr;

Track::Track(QObject *parent)
    : QObject{parent}
{}

Track* Track::instance() {
    if (!_instance) {
        _instance = new Track();
    }
    return _instance;
}

void Track::loadData(const QUrl &fileUrl) {
    QString localPath = fileUrl.toLocalFile();
    QFile file(localPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    // Skip the header line
    in.readLine();

    data.clear(); // Clear existing data
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        // Assuming each line has latitude, longitude, and elevation
        if (fields.size() == 3) {
            DataEntry entry;
            entry.latitude = fields[0].toDouble();
            entry.longitude = fields[1].toDouble();
            entry.elevation = fields[2].toDouble();
            data.append(entry);
        }
    }

    emit dataLoaded();
}

QVariantList Track::getTableModel() const {
    QVariantList tableModel;
    for (const auto& entry : data) {
        QVariantMap row;
        row["latitude"] = entry.latitude;
        row["longitude"] = entry.longitude;
        row["elevation"] = entry.elevation;
        tableModel.append(row);
    }

    /*
    for (const auto& row : tableModel) {
        qDebug() << row;
    }
    */

    return tableModel;
}

    // Emit a signal or update the model to notify QML about the data change
    // This part depends on how you implement the model exposure in Track class

