#include "fenetre.h"
#include "web.h"
#include "ajout.h"
#include "modifier.h"

Fenetre::Fenetre()
{

   zoneprincipale = new QWidget;
   ajout = new QPushButton("Ajouter");
   modifier = new QPushButton("Modifier");
   afficher = new QPushButton("Afficher");
   supprimer = new QPushButton("Supprimer");
   QVBoxLayout *layoutv = new QVBoxLayout;
   QHBoxLayout *layouth = new QHBoxLayout;
   arbre = new QTreeWidget;

   layoutv->addWidget(ajout);
   layoutv->addWidget(modifier);
   layoutv->addWidget(afficher);
   layoutv->addWidget(supprimer);

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
   QObject::connect(arbre, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(affich(QTreeWidgetItem*,int)));
   QObject::connect(afficher, SIGNAL(clicked()), this, SLOT(affiche()));
   QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(supprime()));
   QObject::connect(ajout, SIGNAL(clicked()), this, SLOT(ajouter()));
   QObject::connect(modifier, SIGNAL(clicked()), this, SLOT(changer()));
}
void Fenetre::affich(QTreeWidgetItem* slot, int te)
{
  Web testg(slot->text(te));
}
void Fenetre::affiche()
{
    Web testf(arbre->selectedItems().at(0)->text(0));
    qDebug() << arbre->selectedItems().at(0)->text(0);
}
void Fenetre::supprime()
{
    int reponse = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cette fiche : " + arbre->selectedItems().at(0)->text(0), QMessageBox ::Yes | QMessageBox::No);
       if (reponse == QMessageBox::Yes)
       {
           QFile::remove(QCoreApplication::applicationDirPath() + "/data/" + arbre->selectedItems().at(0)->text(0).toLower() + ".html");
           arbre->clear();
           lister();
       }
}
void Fenetre::ajouter()
{
    fenajout = new Ajout;
    fenajout->show();
    QObject::connect(fenajout, SIGNAL(fini()), this, SLOT(rafraichir()));

}
void Fenetre::rafraichir()
{
   arbre->clear();
   lister();
   delete fenajout;
}
void Fenetre::rafraichir2()
{
    arbre->clear();
    lister();
    delete modif;
}

void Fenetre::changer()
{

    modif = new Modifier;
    modif->show();
    modif->affdonne(arbre->selectedItems().at(0)->text(0));
    QObject::connect(modif, SIGNAL(fini()), this, SLOT(rafraichir2()));
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
