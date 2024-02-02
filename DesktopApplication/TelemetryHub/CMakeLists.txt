cmake_minimum_required(VERSION 3.16)

project(TelemetryHub VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS
    Quick
    QuickControls2
    SerialPort
    Quick3D
)

qt_standard_project_setup()

qt_add_executable(appTelemetryHub
    main.cpp
)

qt_add_qml_module(appTelemetryHub
    URI TelemetryHub
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES
            qml/inc/dataparser.h
            qml/inc/heatplot.h
            qml/inc/serialhandle.h
            qml/inc/track.h
            qml/inc/windowmanager.h

    SOURCES
            qml/src/dataparser.cpp
            qml/src/heatplot.cpp
            qml/src/serialhandle.cpp
            qml/src/track.cpp
            qml/src/windowmanager.cpp

    QML_FILES
            qml/Views/serialMonitorWindow.qml
            qml/Components/OrbitVisualization.qml

    RESOURCES
            qml/Resources/elyos_athon.glb
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTelemetryHub PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTelemetryHub
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTelemetryHub
    PRIVATE Qt6::Quick
    Qt6::QuickControls2
    Qt6::SerialPort
    Qt6::Quick3D
)

include(GNUInstallDirs)
install(TARGETS appTelemetryHub
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
