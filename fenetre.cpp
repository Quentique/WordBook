#include "fenetre.h"
#include "web.h"
#include "ajout.h"
#include "modifier.h"
#include "style.h"

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

   QMenu *menufichier = menuBar()->addMenu("&Fichier");
   QMenu *menuoption = menuBar()->addMenu("&Options");
   QMenu *menuaide = menuBar()->addMenu("&Aide");

   imprimer = new QAction("Im&primer", this);
   QAction *quitter = new QAction("&Quitter", this);
   exporter = new QAction("Exporter", this);
   QAction *parametre = new QAction("&Options", this);
   QAction *stylegestion = new QAction("Gérer le style", this);
   QAction *aide = new QAction("&Aide", this);
   QAction *about = new QAction("A propos...", this);
   QAction *qt = new QAction("A propos de...", this);

   menufichier->addAction(imprimer);
   menufichier->addAction(exporter);
   menufichier->addAction(quitter);

   menuoption->addAction(stylegestion);
   menuoption->addAction(parametre);

   menuaide->addAction(aide);
   menuaide->addAction(about);
   menuaide->addAction(qt);

   imprimer->setDisabled(true);
   exporter->setDisabled(true);

   zoneprincipale->setLayout(layouth);
   setCentralWidget(zoneprincipale);

   QStringList liste;
   liste << "Nom";
   arbre->setHeaderLabels(liste);
   QTreeWidgetItem *test = new QTreeWidgetItem;
   test->setText(0, "Hello");
   arbre->addTopLevelItem(test);
   qDebug() << "Langue : " + QLocale::system().name();//.section('_', 0, 0);
   lister();
   QObject::connect(arbre, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(affiche_page(QTreeWidgetItem*,int)));
   QObject::connect(afficher, SIGNAL(clicked()), this, SLOT(affiche()));
   QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(supprime()));
   QObject::connect(ajout, SIGNAL(clicked()), this, SLOT(ajouter()));
   QObject::connect(modifier, SIGNAL(clicked()), this, SLOT(changer()));
   QObject::connect(arbre, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(degriser()));
   QObject::connect(qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
   QObject::connect(stylegestion, SIGNAL(triggered()), this, SLOT(css()));
}
void Fenetre::affiche_page(QTreeWidgetItem* slot, int te)
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
void Fenetre::css()
{
    Style *style = new Style;
    style->show();
    style->lister_parametre();
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
   modifier->setEnabled(false);
   afficher->setEnabled(false);
   supprimer->setEnabled(false);
   imprimer->setDisabled(true);
   exporter->setDisabled(true);
}
void Fenetre::rafraichir2()
{
    arbre->clear();
    lister();
    delete modif;
    modifier->setEnabled(false);
    afficher->setEnabled(false);
    supprimer->setEnabled(false);
    imprimer->setDisabled(true);
    exporter->setDisabled(true);
}

void Fenetre::changer()
{

    modif = new Modifier;
    modif->show();
    modif->affdonne(arbre->selectedItems().at(0)->text(0));
    QObject::connect(modif, SIGNAL(fini()), this, SLOT(rafraichir2()));
}
void Fenetre::degriser()
{
    modifier->setEnabled(true);
    afficher->setEnabled(true);
    supprimer->setEnabled(true);
    imprimer->setDisabled(false);
    exporter->setDisabled(false);
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
