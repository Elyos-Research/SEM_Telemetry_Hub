#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QMap>
#include <QPointer>

class WindowManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool darkMode READ darkMode WRITE setDarkMode NOTIFY darkModeChanged)

public:
    explicit WindowManager(QQmlEngine *engine, QObject *mainWindow, QObject *parent = nullptr);
    bool darkMode() const;
    
signals:
    void darkModeChanged(bool darkMode);

public slots:
    void createWindow(const QString &windowType, const QUrl &qmlUrl);
    void setDarkMode(bool darkMode);

private:
    bool m_darkMode;
    QQmlEngine *m_engine;
    QObject *m_mainWindow;
    QMap<QString, QPointer<QObject>> m_windows;
};

#endif // WINDOWMANAGER_H
