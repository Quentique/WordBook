#include <QApplication>
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QTextCodec>
#include <QTranslator>
#include <QSplashScreen>
#include "fenetre.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QPixmap pixmap(QCoreApplication::applicationDirPath() + "/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();


    QSettings settings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    int defaut = settings.value("Langue/default").toInt();
    defaut++;

    QTranslator translator;
    translator.load(QCoreApplication::applicationDirPath() + "/langue_"  + settings.value("Langue/" + QString::number(defaut)).toString().toLower().left(2));

    QIcon icone;
    icone.addPixmap(QPixmap(":/images/icone.png").scaled(120,150));
    app.setWindowIcon(icone);
    app.installTranslator(&translator);
    app.setApplicationName("WordBook");

    Fenetre test;
    if (settings.value("MAJ").toBool())
    {
        test.maj("true");
    }

    test.show();
    splash.finish(&test);

    return app.exec();
}
