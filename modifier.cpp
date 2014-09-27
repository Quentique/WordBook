#include "modifier.h"
#include "ajout.h"
#include "fenetre.h"
#include <QtXml>

Modifier::Modifier() : Ajout()
{
  setWindowTitle("Modification d'une fiche");
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
    qDebug() << tableau_donnes.text();
    }
    tableau_donnes = tableau_donnes.nextSiblingElement();
    langue->setText(mag(tableau_donnes.text().right(tableau_donnes.text().size() - 9)));
    qDebug() << tableau_donnes.text();
    tableau_donnes = tableau_donnes.nextSiblingElement();
    qDebug() << tableau_donnes.text();
    QDomElement tableau_interne = tableau_donnes.firstChildElement();
    qDebug() << tableau_interne.text();
    tableau_interne = tableau_interne.nextSiblingElement();
    qDebug() << tableau_interne.text();
    QDomElement tr_donnes = tableau_interne.firstChildElement();
    qDebug() << tr_donnes.tagName();
    int j = 0;
    while (!tr_donnes.isNull())
    {
        QDomElement td = tr_donnes.firstChildElement();
        QTableWidgetItem *itemt = new QTableWidgetItem(td.text());
        tableau->setItem(j, 0, itemt);
        qDebug() << td.text();
        td = td.nextSiblingElement();
        QTableWidgetItem *itemt1 = new QTableWidgetItem(td.text());
        tableau->setItem(j, 1, itemt1);
        qDebug() << td.text();

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
    qDebug() << "enregistre2";
   QFile::remove(QCoreApplication::applicationDirPath() + "/data/" + nomfic->toLower() + ".html");
   Ajout::enregistre();
}
