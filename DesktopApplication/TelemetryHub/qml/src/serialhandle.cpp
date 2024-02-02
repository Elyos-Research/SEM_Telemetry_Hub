#include "../inc/serialhandle.h"

/*////////////////////////////////////
    Constructors
////////////////////////////////////*/

SerialHandle::SerialHandle(QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this))
{
    // Connect signals for serial port
    connect(serialPort, &QSerialPort::readyRead, this, &SerialHandle::handleReadyRead);
    connect(serialPort, &QSerialPort::errorOccurred, this, &SerialHandle::handleError);
}

SerialHandle::~SerialHandle()
{
    closeSerialPort();
}

/*////////////////////////////////////
    Serial port handlers
////////////////////////////////////*/

bool SerialHandle::openSerialPort(const QString &portName, Mode mode, QSerialPort::BaudRate baudRate)
{
    closeSerialPort();  // Ensure any existing port is closed

    serialPort->setPortName(portName);
    setupSerialPort(mode, baudRate);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        emit errorOccurred(serialPort->errorString());
        return false;
    }

    return true;
}

void SerialHandle::closeSerialPort()
{
    if (serialPort->isOpen())
        serialPort->close();
    emit serialPortClosed();
}

QStringList SerialHandle::availablePorts() const
{
    QStringList portList;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        portList.append(info.portName());
    }
    return portList;
}

/*////////////////////////////////////
    Communication functions
////////////////////////////////////*/

QString SerialHandle::readLine()
{
    return serialPort->readLine();
}

bool SerialHandle::writeData(const QByteArray &data)
{
    if (serialPort->write(data) == -1) {
        emit errorOccurred(serialPort->errorString());
        return false;
    }
    return true;
}

/*////////////////////////////////////
    Communication configurations
////////////////////////////////////*/

void SerialHandle::setBaudRate(QString baudRate) {
    bool ok;
    int baudRateValue = baudRate.toInt(&ok);
    if (ok) {
        // Check if baudRateValue is a valid QSerialPort::BaudRate
        switch (baudRateValue) {
        case QSerialPort::Baud1200:
        case QSerialPort::Baud2400:
        case QSerialPort::Baud4800:
        case QSerialPort::Baud9600:
        case QSerialPort::Baud19200:
        case QSerialPort::Baud38400:
        case QSerialPort::Baud57600:
        case QSerialPort::Baud115200:
            selectedBaudRate = static_cast<QSerialPort::BaudRate>(baudRateValue);
            break;
        default:
            // Handle invalid baud rate
            emit errorOccurred("Invalid baud rate");
            break;
        }
    } else {
        // Handle conversion error
        emit errorOccurred("Invalid baud rate format");
    }
}

void SerialHandle::setComPort(QString port) {
    selectedCOM = port;
}


/*////////////////////////////////////
    Slots functions to handle clasees
////////////////////////////////////*/

void SerialHandle::setupSerialPort(Mode mode, QSerialPort::BaudRate baudRate)
{
    switch (mode) {
    case Read:
        serialPort->setReadBufferSize(1024);
        break;
    case Write:
        // Specific configurations for write mode, if any any idea jsjs
        break;
    case ReadWrite:
        // Specific configurations for read-write mode, if any idea jsjs
        break;
    }

    serialPort->setBaudRate(baudRate);
    // Other configurations can be set here (parity, data bits, stop bits, etc.) but didnt had time
}

void SerialHandle::handleReadyRead()
{
    emit dataReceived(serialPort->readAll());
}

void SerialHandle::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        emit errorOccurred(serialPort->errorString());
    }
}

