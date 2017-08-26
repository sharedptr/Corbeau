#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "documenthandler.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  qmlRegisterType<DocumentHandler>("org.Qotes", 1, 0, "DocumentHandler");

  QQmlApplicationEngine engine;
  engine.addImportPath((QLatin1String("qrc:///")));
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty()) {
    return EXIT_FAILURE;
  }

  return app.exec();
}
