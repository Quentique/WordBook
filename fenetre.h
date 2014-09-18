#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtWidgets>

class Fenetre : public QMainWindow
{
public:
    Fenetre();
private:
   QTreeWidget *arbre;
    QWidget *zoneprincipale;
    QPushButton *ajout, *modifier, *afficher;

};

#endif // FENETRE_H
