#include <QApplication>
#include <QTextCodec>
#include "fenetre.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Fenetre test;
    test.show();
    return app.exec();
}
