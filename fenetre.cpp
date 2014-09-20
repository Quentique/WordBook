#include "fenetre.h"
#include <iostream>


Fenetre::Fenetre()
{

   zoneprincipale = new QWidget;
   afficher = new QPushButton("test");
   ajout = new QPushButton("testd");
   modifier = new QPushButton("tedst");
   QVBoxLayout *layoutv = new QVBoxLayout;
   QHBoxLayout *layouth = new QHBoxLayout;
   arbre = new QTreeWidget;

   layoutv->addWidget(ajout);
   layoutv->addWidget(modifier);
   layoutv->addWidget(afficher);

   layouth->addWidget(arbre);
   layouth->addLayout(layoutv);

   zoneprincipale->setLayout(layouth);
   setCentralWidget(zoneprincipale);

   QStringList liste;
   liste << "Nom";
   arbre->setHeaderLabels(liste);
   QTreeWidgetItem *test = new QTreeWidgetItem;
   test->setText(0, "Hello");
   arbre->addTopLevelItem(test);

   lister();
   QObject::connect(arbre, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(test(QTreeWidgetItem*,int)));
}
void Fenetre::test(QTreeWidgetItem* slot, int te)
{

}
void Fenetre::lister()
{
    QString path = QCoreApplication::applicationDirPath();
    path += "/data/";

    QDir *flux = new QDir(path);
    QStringList listes;
    listes << flux->entryList();
    int i, a;

    listes.removeFirst();
    listes.removeFirst();
    i = listes.count();
    for (a = 0 ; a < i ; a++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        QString affichage = listes.at(a);
        QChar lettre = affichage.at(0).toUpper();
        affichage.replace(0, 1,  lettre);
         if (affichage.endsWith(".html"))
         {
          affichage.truncate(affichage.size() - 5);
          item->setText(0, affichage);
          arbre->addTopLevelItem(item);
         }
    }
}
