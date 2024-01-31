#ifndef SERIALHANDLE_H
#define SERIALHANDLE_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QDebug>

class SerialHandle : public QObject
{
    Q_OBJECT

public:

    enum Mode {
        Read,
        Write,
        ReadWrite
    };

    //Constructors
    explicit SerialHandle(QObject *parent = nullptr);
    ~SerialHandle();

    // Functions to handle serial port
    Q_INVOKABLE bool openSerialPort(const QString &portName, Mode mode, QSerialPort::BaudRate baudRate);
    Q_INVOKABLE void closeSerialPort();
    Q_INVOKABLE QStringList availablePorts() const;

    // Functions for communication
    Q_INVOKABLE QString readLine();
    Q_INVOKABLE bool writeData(const QByteArray &data);

    // Functions to set properties of serial communication
    Q_INVOKABLE void setBaudRate(QString baudRate);
    Q_INVOKABLE void setComPort(QString port);

signals:

    // signals emit
    void dataReceived(const QString &data);
    void errorOccurred(const QString &errorString);
    void serialPortClosed();

private:

    // Objects and properties atributes
    QSerialPort *serialPort;
    QSerialPort::BaudRate selectedBaudRate;
    QString selectedCOM;

    // Helper functions
    void setupSerialPort(Mode mode, QSerialPort::BaudRate baudRate);

    // Private slots for handling serial port events
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError serialPortError);

};

#endif // SERIALHANDLE_H
