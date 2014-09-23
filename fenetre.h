#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtWidgets>
#include "ajout.h"


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
private:
   QTreeWidget *arbre;
   QWidget *zoneprincipale;
   QPushButton *ajout, *modifier, *afficher, *supprimer;
   Ajout *fenajout;

};

#endif // FENETRE_H
