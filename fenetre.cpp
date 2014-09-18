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

}


