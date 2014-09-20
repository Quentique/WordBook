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
    void test(QTreeWidgetItem* slot, int te);
private:
   QTreeWidget *arbre;
    QWidget *zoneprincipale;
    QPushButton *ajout, *modifier, *afficher;

};

#endif // FENETRE_H
