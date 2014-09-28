#include "aide.h"

Aide::Aide()
{
    texte_aide = new QLabel;
    qt_about = new QPushButton("A propos de la bibliothèque de développement (Qt)");
    QVBoxLayout *layout_aide = new QVBoxLayout;
    QFile texte(":/texte/aide.txt");
    texte.open(QIODevice::ReadOnly);
    texte_aide->setText(texte.readAll());
    layout_aide->addWidget(texte_aide);
    layout_aide->addWidget(qt_about);
    setLayout(layout_aide);

    QObject::connect(qt_about, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
}
