#include "fenetre.h"
#include "web.h"
#include "ajout.h"
#include "modifier.h"
#include <QtXml>
#include "style.h"
#include "option.h"
#include "aide.h"

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

   QMenu *menufichier = menuBar()->addMenu(tr("&Fichier"));
   QMenu *menuoption = menuBar()->addMenu(tr("&Options"));
   QMenu *menuaide = menuBar()->addMenu(tr("&Aide"));


   QAction *quitter = new QAction(tr("&Quitter"), this);

   QAction *parametre = new QAction(tr("&Options"), this);
   QAction *stylegestion = new QAction(tr("Gérer le style"), this);
   QAction *aide = new QAction(tr("&Aide"), this);
   QAction *about = new QAction(tr("A propos..."), this);
   QAction *qt = new QAction(tr("A propos de..."), this);


   menufichier->addAction(quitter);

   menuoption->addAction(stylegestion);
   menuoption->addAction(parametre);

   menuaide->addAction(aide);
   menuaide->addAction(about);
   menuaide->addAction(qt);


   zoneprincipale->setLayout(layouth);
   setCentralWidget(zoneprincipale);
   setWindowTitle("Lexic");

   QStringList liste;
   liste << tr("Nom") << tr("Langue");
   arbre->setHeaderLabels(liste);
   arbre->setColumnWidth(0, 200);
   arbre->setColumnWidth(1, 150);
   qDebug() << "Langue : " + QLocale::system().name();//.section('_', 0, 0);
   lister();
   QObject::connect(arbre, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(affiche_page(QTreeWidgetItem*,int)));
   QObject::connect(afficher, SIGNAL(clicked()), this, SLOT(affiche()));
   QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(supprime()));
   QObject::connect(ajout, SIGNAL(clicked()), this, SLOT(ajouter()));
   QObject::connect(modifier, SIGNAL(clicked()), this, SLOT(changer()));
   QObject::connect(arbre, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(degriser()));
   QObject::connect(qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
   QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
   QObject::connect(stylegestion, SIGNAL(triggered()), this, SLOT(css()));
   QObject::connect(parametre, SIGNAL(triggered()), this, SLOT(options()));
   QObject::connect(aide, SIGNAL(triggered()), this, SLOT(aide_aff()));
}
void Fenetre::affiche_page(QTreeWidgetItem* slot, int te)
{
  Web testg(slot->text(0));
}
void Fenetre::aide_aff()
{
    Aide *aideaff = new Aide;
    aideaff->show();
}

void Fenetre::options()
{
    Option *fen_options = new Option;
    fen_options->show();
}

void Fenetre::affiche()
{
    Web testf(arbre->selectedItems().at(0)->text(0));
    qDebug() << arbre->selectedItems().at(0)->text(0);
}
void Fenetre::supprime()
{

    QMessageBox message;
    message.setWindowTitle(tr("Confirmation"));
    message.setText(tr("Êtes-vous sûr de vouloir supprimer cette fiche : ") + arbre->selectedItems().at(0)->text(0));
    message.addButton(QMessageBox::Yes);
    message.addButton(QMessageBox::No);
    message.setButtonText(QMessageBox::Yes, tr("Oui"));
    message.setButtonText(QMessageBox::No, tr("Non"));
    int reponse = message.exec();
       if (reponse == QMessageBox::Yes)
       {
           QFile::remove(QCoreApplication::applicationDirPath() + "/data/" + arbre->selectedItems().at(0)->text(0).toLower() + ".html");
           arbre->clear();
           lister();
       }
}
void Fenetre::css()
{
    style = new Style;
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
}

void Fenetre::changer()
{

    modif = new Modifier;
    modif->show();
    modif->affdonne(arbre->selectedItems().at(0)->text(0));
    QObject::connect(modif, SIGNAL(fini()), this, SLOT(rafraichir2()));
}
void Fenetre::rafraichir2()
{
    arbre->clear();
    lister();
    delete modif;
    modifier->setEnabled(false);
    afficher->setEnabled(false);
    supprimer->setEnabled(false);

}

void Fenetre::degriser()
{
    modifier->setEnabled(true);
    afficher->setEnabled(true);
    supprimer->setEnabled(true);


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

          QFile fichierla(path + listes.at(a));
          if (!fichierla.open(QIODevice::ReadOnly))
          {
              QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier !"));
              fichierla.close();
          }
          QDomDocument *dom = new QDomDocument("xml");
          if (!dom->setContent(&fichierla))
          {
              fichierla.close();
              QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'attribuer le fichier"));
          }
          QDomElement doc_elements = dom->documentElement();
          doc_elements = doc_elements.firstChildElement();
          doc_elements = doc_elements.nextSiblingElement();

          QDomElement tableau_donnes = doc_elements.firstChildElement();
          tableau_donnes = tableau_donnes.nextSiblingElement();
          tableau_donnes = tableau_donnes.nextSiblingElement();
          item->setText(1, tableau_donnes.text().right(tableau_donnes.text().size() - 9));
          fichierla.close();
          item->setTextAlignment(1, Qt::AlignRight);
          arbre->addTopLevelItem(item);

         }
    }
}
