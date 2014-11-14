#include <QVBoxLayout>

#include "aide.h"

Aide::Aide()
{
    texte_aide = new QLabel;
    qt_about = new QPushButton(tr("A propos de la bibliothèque de développement (Qt)"));
    texte_aide->setText(tr("<h1 style=\"text-align: center; margin-left: auto; margin-right: auto; white-space: pre-wrap;\">                               Aide</h1><h2 style=\"margin-bottom: 0px; margin-top: 0px; text-decoration: underline;\">1) Présentation</h2><p style=\"white-space: pre-wrap; margin-bottom: 0px; margin-top: 0px;\">Ce programme est conçu pour la numérisation de fiches de vocabulaires bilingues. Ce programme est<br/>très simple d'utilisation, en plus, l'interface est entièrement personnalisable ! Il permet de stocker<br/>jusqu'à 100 mots par fiche de vocabulaires. Ce programme est disponible en plusieurs langues.</p><br/><h2 style=\"margin-bottom: 0px; text-decoration: underline; margin-top: 0px;\">2) Infos Diverses</h2><p style=\"white-space: pre-wrap; margin-bottom: 0px; margin-top: 0px;\">Lorsque des dimensions/tailles sont demandées, il faut les donner en pixels.<br/>Lors d'un changement de langue, il est nécessaire de redémarrer l'application pour appliquer la<br/>nouvelle langue.</p>"));
    QVBoxLayout *layout_aide = new QVBoxLayout;

    layout_aide->addWidget(texte_aide);
    layout_aide->addWidget(qt_about);

    setLayout(layout_aide);
    setFixedSize(640, 280);

    QObject::connect(qt_about, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
}
