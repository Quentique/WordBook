#include "fenetre.h"
#include "ajout.h"


Ajout::Ajout()
{
    titre = new QLineEdit;
    soustitre = new QLineEdit;
    langue = new QLineEdit;
    tableau = new QTableWidget;
    record = new QPushButton(tr("Enregistrer"));

    QFormLayout *form = new QFormLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layout2 = new QHBoxLayout;

    form->addRow(tr("Titre"), titre);
    form->addRow(tr("Sous-titre (optionnel)"), soustitre);
    form->addRow(tr("Langue"), langue);

    layout->addLayout(form);
    layout->addWidget(tableau);

    layout2->addLayout(layout);
    layout2->addWidget(record);

    tableau->setColumnCount(2);
    tableau->setRowCount(100);
    QStringList labels;
    labels << tr("Termes") << tr("Traduction");
    tableau->setHorizontalHeaderLabels(labels);
    tableau->setColumnWidth(0, 150);
    tableau->setColumnWidth(1, 150);

    setLayout(layout2);
    //resize(485, 500);
    setFixedSize(485, 500);
    setWindowTitle("Ajout d'une fiche");
    qDebug() << "test";
    QObject::connect(record, SIGNAL(clicked()), this, SLOT(enregistre()));

}
void Ajout::enregistre()
{
    qDebug() << "enregistrer";
    if (langue->text() == "" || titre->text() == "")
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Il manque des informations !"));

    }
    else
    {

    QFile fichier(QCoreApplication::applicationDirPath() + "/data/" + titre->text().toLower() + ".html");

    if (fichier.exists())
    {
        QMessageBox message;
        message.setWindowTitle("Confirmation");
        message.setText(tr("Cette fiche est déjà existante. Voulez-vous la remplacer ?"));
        message.addButton(QMessageBox::Yes);
        message.addButton(QMessageBox::No);
        message.setButtonText(QMessageBox::Yes, tr("Oui"));
        message.setButtonText(QMessageBox::No, tr("Non"));
        int reponse = message.exec();
        if (reponse == QMessageBox::Yes)
           {
               QFile::remove(QCoreApplication::applicationDirPath() + "/data/" + titre->text().toLower() + ".html");
           }
           else
           {

           }
    }
    if (!tableau->item(0, 0))
    {

        QMessageBox::critical(this, tr("Erreur"), tr("Le tableau ne doit pas être vide !"));

    }
    else
    {
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text))
    {

    QMessageBox::critical(this, tr("Erreur"), tr("Impossibilité de créer le fichier pour l'enregistrement !"));
    }
    else
    {
    QTextStream texte(&fichier);
    texte.setCodec("UTF-8");
    texte << "<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"utf-8\" http-equiv=\"Content-Type\" content=\"text/html\"/>\n<link rel=\"stylesheet\" content=\"text/css\" href=\"..\\style.css\"/>\n</head>\n";
    texte << "<body>\n<h1>" << titre->text() << "</h1>\n";
    if (soustitre->text() != "")
    {
        texte << "<h2 id=\"1\">" << soustitre->text() << "</h2>\n";
    }
    else
    {
        texte << "<h2 id=\"0\"></h2>\n";
    }
    texte << "<div>Langue : " << langue->text() << "</div>\n";
    texte << "<table>\n<thead>\n<tr>\n<th>Termes</th>\n<th>Traductions</th>\n</tr>\n</thead>\n<tbody>\n";
    int i;
    qDebug() << "Avant for";
    for (i = 0 ; i != 99 ; i++)
    {
        qDebug() << "Dans For";
        QTableWidgetItem *item = tableau->item(i,0);
        QTableWidgetItem *item2 = tableau->item(i, 1);
        if (item && item2)
        {
            texte << "<tr>\n<td>" << tableau->item(i, 0)->text() << "</td>\n<td>" << tableau->item(i, 1)->text() << "</td>\n</tr>";
            qDebug() << tableau->item(i, 0)->text();
            qDebug() << tableau->item(i, 1)->text();
            qDebug() << "Dans if";
        }
        else if (!item && item2)
        {
            texte << "<tr>\n<td></td>\n<td>" << tableau->item(i, 1)->text() << "</td>\n</tr>";
            qDebug() << tableau->item(i, 1)->text();
            qDebug() << "Dans if";
        }
        else if (item && !item2)
        {
            texte << "<tr>\n<td>" << tableau->item(i, 0)->text() << "</td>\n<td> </td>\n</tr>\n";
            qDebug() << tableau->item(i, 0)->text();
            qDebug() << "Dans if";
        }
        else
        {
            qDebug() << "Rien";
        }
    }
    texte << "</tbody>\n</table>\n</body>\n</html>";
    fichier.close();
    emit fini();
    }
    }
    }
}
