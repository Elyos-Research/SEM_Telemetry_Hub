#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQuickView>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "WindowManager.h"
#include "serialhandle.h"
#include "dataparser.h"
#include "heatplot.h"
#include "track.h"

static QObject* track_singleton_provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return Track::instance();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //Intances

    qmlRegisterSingletonType<SerialHandle>("com.Elyos.serial", 1, 0, "SerialHandle",
                                           [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
                                               Q_UNUSED(engine)
                                               Q_UNUSED(scriptEngine)
                                               return new SerialHandle();
                                           });

    qmlRegisterSingletonType<DataParser>("com.Elyos.parsers", 1, 0, "DataParser",
                                         [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
                                             Q_UNUSED(engine)
                                             Q_UNUSED(scriptEngine)
                                             return new DataParser();
                                         });
    qmlRegisterType<HeatPlot>("com.Elyos.heatPlot", 1, 0, "HeatPlot");
    qmlRegisterSingletonType<Track>("com.Elyos.track", 1, 0, "Track", track_singleton_provider);

    //Main qml load
    const QUrl url(u"qrc:/TelemetryHub/Main.qml"_qs);
    engine.load(url);

    //window manager handle
    auto rootObjects = engine.rootObjects();
    if (rootObjects.isEmpty()) {
        return -1; // Exit if no root object is loaded
    }
    QObject *mainWindow = rootObjects.first(); // Safely get the first root object
    WindowManager windowManager(&engine, mainWindow);
    engine.rootContext()->setContextProperty("windowManager", &windowManager);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    return app.exec();
}
