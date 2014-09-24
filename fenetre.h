#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtWidgets>
#include "ajout.h"
#include "modifier.h"


class Fenetre : public QMainWindow
{
    Q_OBJECT
public:
    Fenetre();
    void lister();

public slots:
    void affich(QTreeWidgetItem* slot, int te);
    void affiche();
    void supprime();
    void ajouter();
    void rafraichir();
    void changer();
    void rafraichir2();
private:
   QTreeWidget *arbre;
   QWidget *zoneprincipale;
   QPushButton *ajout, *modifier, *afficher, *supprimer;
   Ajout *fenajout;
   Modifier *modif;
};

#endif // FENETRE_H
