#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QWidget>
#include <QTreeWidget>
#include <QPushButton>
#include <QNetworkReply>
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
private:
   QTreeWidget *arbre;
   QWidget *zoneprincipale;
   QPushButton *ajout, *modifier, *afficher, *supprimer;
   Ajout *fenajout;
   Modifier *modif;
   Style *style;
   QNetworkReply *reply;

};

#endif // FENETRE_H
