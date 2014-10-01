#include <QApplication>
#include <QTextCodec>
#include "fenetre.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QTranslator translator;
    QSettings settings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    qDebug() << translator.load("langue_" + settings.value("Langue/" + settings.value("Langue/default").toString()).toString().left(2).toLower() +".qm", app.applicationDirPath());
    app.installTranslator(&translator);
    app.setApplicationName("WordBook");
    QIcon icone;
    icone.addPixmap(QPixmap(":/images/icone.png").scaled(120,150));
    app.setWindowIcon(icone);
    Fenetre test;
    test.show();
    //QString locale = QLocale::system().name().section('_', 0, 0);

    return app.exec();
}
