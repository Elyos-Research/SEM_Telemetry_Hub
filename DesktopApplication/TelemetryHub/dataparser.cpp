#include "dataparser.h"

/*////////////////////////////////////
    Constructors
////////////////////////////////////*/

DataParser::DataParser(QObject *parent) : QObject(parent) {
}

/*////////////////////////////////////
    Parse functions
////////////////////////////////////*/

void DataParser::parseLabelData(const QString &dataString) {
    QStringList elements = dataString.split(',');

    for (const QString &element : elements) {
        QStringList parts = element.trimmed().split(':');
        if (parts.length() == 2) {
            QString label = parts[0].trimmed();
            QVariant value = parts[1].trimmed();

            // Check if the label is new
            if (!parsedData.contains(label)) {
                emit newLabelAdded(); // Emit signal for new label
            }

            parsedData[label] = value;
        }
    }
    emit dataUpdated();
}

/*////////////////////////////////////
    Map getters
////////////////////////////////////*/

QVariant DataParser::getLabelData(const QString &label) const {
    return parsedData.value(label).toString();
}

QStringList DataParser::getLabels() const {
    return parsedData.keys();
}
