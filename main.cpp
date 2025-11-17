#include <QFile>
#include <QDebug>
#include <QLocale>
#include <QResource>
#include <QTranslator>
#include <QQmlContext>
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "main.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "qt_NoSelection_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    WindowAction WindowAction;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qt_NoSelection/main.qml"));
    engine.rootContext()->setContextProperty("WindowAction", &WindowAction);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
