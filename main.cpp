#include <QApplication>
#include <QTextCodec>
#include "fenetre.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Fenetre test;
    test.show();
    /*QString locale = QLocale::system().name().section('_', 0, 0);
       QTranslator translator;
       translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
       app.installTranslator(&translator);*/
    return app.exec();
}
