#include "propos.h"

Propos::Propos()
{
   licence = new QLabel;
   icone = new QLabel;
   licence->setPixmap(QPixmap(":images/licence.png"));
   icone->setPixmap(QPixmap(":images/icone.png").scaled(100, 75));

   label = new QLabel(tr("<h2>Lexic</h2><p>Ce programme est diffusé selon les termes de la licence Creative Commons : <a href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/fr/legalcode\">http://creativecommons.org/licenses/by-nc-sa/3.0/fr/legalcode</a>.<br/>Ce programme a été créé et publié par Quentin DE MUYNCK."));
    QHBoxLayout *layout1 = new QHBoxLayout;
    QVBoxLayout *layout2 = new QVBoxLayout;
    layout1->addWidget(icone);
    layout1->addWidget(label);

    layout2->addLayout(layout1);
    layout2->addWidget(licence, 0, Qt::AlignLeft);
    setLayout(layout2);
    setWindowTitle(tr("A propos de l'auteur"));
    QObject::connect(label, SIGNAL(linkActivated(QString)), this, SLOT(ouvrir_url(QString)));
}
void Propos::ouvrir_url(QString url)
{
    QDesktopServices::openUrl(QUrl(url));
}
