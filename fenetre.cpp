#include "fenetre.h"
#include "web.h"
#include "ajout.h"

Fenetre::Fenetre()
{

   zoneprincipale = new QWidget;
   ajout = new QPushButton;
   modifier = new QPushButton;
   afficher = new QPushButton;
   supprimer = new QPushButton;
   QVBoxLayout *layoutv = new QVBoxLayout;
   QHBoxLayout *layouth = new QHBoxLayout;
   arbre = new QTreeWidget;

   ajout->setIcon(QIcon(":/images/ajouter.png"));
   ajout->setIconSize(QPixmap(":/images/modifier.png").size());
   ajout->setMinimumSize(50, 50);
   ajout->setMaximumSize(50, 50);

   modifier->setIcon(QIcon(":/images/modifier.png"));
   modifier->setIconSize(QSize(42, 42));
   modifier->setMinimumSize(50, 50);
   modifier->setMaximumSize(50, 50);

   afficher->setIcon(QIcon(":/images/afficher.png"));
   afficher->setIconSize(QPixmap(":images/modifier.png").size());
   afficher->setMinimumSize(50, 50);
   afficher->setMaximumSize(50, 50);

   supprimer->setIcon(QIcon(":/images/supprimer.png"));
   supprimer->setIconSize(QPixmap(":images/supprimer.png").size());
   supprimer->setMinimumSize(50, 50);
   supprimer->setMaximumSize(50, 50);

   modifier->setEnabled(false);
   afficher->setEnabled(false);
   supprimer->setEnabled(false);

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
    Ajout ajout;
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
