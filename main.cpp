#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QIcon>
#include <QPixmap>
#include <QDebug>
#include "fenetre.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QTranslator translator;
    QSettings settings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    int defaut = settings.value("Langue/default").toInt();
    defaut++;
    qDebug() << translator.load(QCoreApplication::applicationDirPath() + "/langue_"  + settings.value("Langue/" + QString::number(defaut)).toString().toLower().left(2));
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
