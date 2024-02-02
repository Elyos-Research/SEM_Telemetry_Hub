#include "../inc/windowmanager.h"


/*Constructors*/
WindowManager::WindowManager(QQmlEngine *engine, QObject *mainWindow, QObject *parent)
    : QObject(parent), m_mainWindow(mainWindow), m_engine(engine), m_darkMode(false) {}


/*New window creation*/
void WindowManager::createWindow(const QString &windowType, const QUrl &qmlUrl) {
    if (m_windows.contains(windowType) && !m_windows[windowType].isNull()) {
        // update status to Window of this type is already open
        m_windows[windowType]->setProperty("visible", true);
        m_windows[windowType]->setProperty("active", true);
        return;
    }

    QQmlComponent component(m_engine, qmlUrl);
    if (component.isReady()) {
        QObject *window = component.create();
        if (window) {
            window->setParent(m_mainWindow); // Set main window as parent
            window->setProperty("darkMode", m_darkMode);
            m_windows[windowType] = window;
        } else {
            qWarning() << "Failed to create window:" << component.errorString();
        }
    } else {
        qWarning() << "Failed to load component:" << component.errorString();
    }
}

/*Dark Mode setting*/
bool WindowManager::darkMode() const {
    return m_darkMode;
}

void WindowManager::setDarkMode(bool darkMode) {
    if (m_darkMode != darkMode) {
        m_darkMode = darkMode;
        emit darkModeChanged(darkMode);
    }
}
