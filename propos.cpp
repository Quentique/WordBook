#include "propos.h"
#include <QLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

Propos::Propos()
{
    licence = new QLabel;
    icone = new QLabel;
    licence->setPixmap(QPixmap(":images/licence.png"));
    icone->setPixmap(QPixmap(":images/icone.png").scaled(80, 100));

    label = new QLabel(tr("<h2>WordBook</h2><p>Ce programme est diffusé selon les termes de la licence Creative Commons : <a href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/fr/legalcode\">http://creativecommons.org/licenses/by-nc-sa/3.0/fr/legalcode</a>.<br/>Ce programme a été créé et publié par Quentin DE MUYNCK.</p>"));
    openlicence = new QPushButton(tr("Licence"));

    QHBoxLayout *layout1 = new QHBoxLayout;
    QVBoxLayout *layout2 = new QVBoxLayout;
    layout1->addWidget(icone);
    layout1->addWidget(label);

    layout2->addLayout(layout1);
    layout2->addWidget(licence, 0, Qt::AlignLeft);
    layout2->addWidget(openlicence, Qt::AlignHCenter);

    setLayout(layout2);
    setWindowTitle(tr("A propos de l'auteur"));

    QObject::connect(label, SIGNAL(linkActivated(QString)), this, SLOT(ouvrir_url(QString)));
    QObject::connect(openlicence, SIGNAL(clicked()), this, SLOT(openlicencefile()));
}
void Propos::ouvrir_url(QString url)
{
    QDesktopServices::openUrl(QUrl(url));
}
void Propos::openlicencefile()
{
    licence_principale = new QWidget;
    licence_texte = new QTextEdit(licence_principale);

    QVBoxLayout *layout = new QVBoxLayout;

    QFile fichier(":/texte/licence.txt");
    if (!fichier.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Erreur", "Erreur");
    }

    fichier.seek(1);
    QTextStream entre(&fichier);
    entre.setCodec("UTF-8");

    licence_texte->setText(entre.readAll());
    licence_texte->setReadOnly(true);

    layout->addWidget(licence_texte);

    licence_principale->setFixedSize(500, 700);
    licence_principale->setLayout(layout);
    licence_principale->show();

    fichier.close();
}
