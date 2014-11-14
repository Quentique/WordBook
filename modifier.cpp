#include <QMessageBox>
#include <QtXml>

#include "modifier.h"
#include "ajout.h"
#include "fenetre.h"

Modifier::Modifier() : Ajout()
{
    setWindowTitle(tr("Modification d'une fiche"));
}

bool Modifier::affdonne(QString nomfich)
{
    QFile fichierd(QCoreApplication::applicationDirPath() + "/data/" + nomfich.toLower() + ".html");
    if (!fichierd.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier !"));
        return false;
    }

    QDomDocument *dom = new QDomDocument("xml");
    if (!dom->setContent(&fichierd))
    {
        fichierd.close();
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'attribuer le fichier"));
    }

    QDomElement doc_elements = dom->documentElement();
    doc_elements = doc_elements.firstChildElement();
    doc_elements = doc_elements.nextSiblingElement();

    QDomElement tableau_donnes = doc_elements.firstChildElement();
    titre->setText(mag(tableau_donnes.text()));
    nomfic = new QString(tableau_donnes.text());
    tableau_donnes = tableau_donnes.nextSiblingElement();

    if(tableau_donnes.attribute("id") == "1")
    {
    soustitre->setText(mag(tableau_donnes.text()));
    tableau_donnes.text();
    }

    tableau_donnes = tableau_donnes.nextSiblingElement();
    langue->setText(mag(tableau_donnes.text().right(tableau_donnes.text().size() - 9)));
    tableau_donnes = tableau_donnes.nextSiblingElement();

    QDomElement tableau_interne = tableau_donnes.firstChildElement();
    tableau_interne = tableau_interne.nextSiblingElement();

    QDomElement tr_donnes = tableau_interne.firstChildElement();
    tr_donnes.tagName();

    int j = 0;
    while (!tr_donnes.isNull())
    {
        QDomElement td = tr_donnes.firstChildElement();
        QTableWidgetItem *itemt = new QTableWidgetItem(td.text());
        tableau->setItem(j, 0, itemt);
        td = td.nextSiblingElement();

        QTableWidgetItem *itemt1 = new QTableWidgetItem(td.text());
        tableau->setItem(j, 1, itemt1);

        tr_donnes = tr_donnes.nextSiblingElement();
        j++;
    }

    fichierd.close();
    return true;
}
QString Modifier::mag(QString machin)
{
    QChar lettre = machin.at(0).toUpper();
    machin.replace(0, 1,  lettre);

    return machin;
}
void Modifier::enregistre()
{
   QFile::remove(QCoreApplication::applicationDirPath() + "/data/" + nomfic->toLower() + ".html");
   Ajout::enregistre();
}
