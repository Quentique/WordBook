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

   QString path = QCoreApplication::applicationDirPath();
   path += "/data/";
   qDebug() << path;

   QDir *flux = new QDir(path);
   QStringList listes;
       listes << flux->entryList();
   qDebug() << listes.count();
   int i, a;

   listes.removeFirst();
   listes.removeFirst();
   i = listes.count();
   qDebug() << listes;
     qDebug() << listes.count();
     qDebug() << listes.at(0);
   QTreeWidgetItem *tests[i-1];
   for (a = 0 ; a < i ; a++)
   {
       qDebug() << a;
       QTreeWidgetItem *item = new QTreeWidgetItem;
       item->setText(0, listes.at(a));
        arbre->addTopLevelItem(item);
       qDebug() << listes.at(a);
       qDebug() << &item;
   }
   QObject::connect(arbre, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(test(QTreeWidgetItem*,int)));
}
void Fenetre::test(QTreeWidgetItem* slot, int te)
{
    qDebug() << slot;
    qDebug() << slot->text(te);
}
