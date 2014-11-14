#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QPrinter>
#include <QPushButton>
#include <QTreeWidget>
#include <QWidget>

#include "ajout.h"
#include "modifier.h"
#include "style.h"


class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    Fenetre();
    void lister();
    void export_pdf(QString chemin);
    void export_image(QString chemini);

public slots:
    void affiche_page(QTreeWidgetItem* slot, int te);
    void affiche();
    void supprime();
    void ajouter();
    void rafraichir();
    void changer();
    void rafraichir2();
    void degriser();
    void css();
    void options();
    void aide_aff();
    void apropos();
    void pdf();
    void maj(QString demarrage);
    void clicPrint();
    void apercu();
    void print(QPrinter *imprimante);

private:
   QTreeWidget *arbre;
   QWidget *zoneprincipale;
   QPushButton *ajout, *modifier, *afficher, *supprimer;
   Ajout *fenajout;
   Modifier *modif;
   Style *style;
   QNetworkReply *reply;
   QAction *exportation, *impression, *apercuavant;

};

#endif // FENETRE_H
