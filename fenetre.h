#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtWidgets>
#include "ajout.h"
#include "modifier.h"
#include "style.h"


class Fenetre : public QMainWindow
{
    Q_OBJECT
public:
    Fenetre();
    void lister();

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

private:
   QTreeWidget *arbre;
   QWidget *zoneprincipale;
   QPushButton *ajout, *modifier, *afficher, *supprimer;
   Ajout *fenajout;
   Modifier *modif;
   Style *style;

};

#endif // FENETRE_H
