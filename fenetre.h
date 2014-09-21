#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtWidgets>


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
private:
   QTreeWidget *arbre;
    QWidget *zoneprincipale;
    QPushButton *ajout, *modifier, *afficher, *supprimer;

};

#endif // FENETRE_H
