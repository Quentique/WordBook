#include "option.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QLayout>
#include <QFormLayout>
#include <QCloseEvent>

Option::Option()
{
    langue = new QGroupBox(tr("Langue"));
    option_taille = new QGroupBox(tr("Taille d'affichage"));
    majgroup = new QGroupBox(tr("Mises à Jour"));

    choix_langue = new QComboBox;

    taille_x = new QSpinBox;
    taille_y = new QSpinBox;

    sauvegarder_opt = new QPushButton(tr("Enregistrer"));

    majact = new QCheckBox(tr("Vérifier les mises à jour au démarrage"));

    settings = new QSettings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    int a = 1;
    if (!settings->childGroups().contains("Langue",Qt::CaseInsensitive))
    {
        settings->setValue("Langue/default", 1);
        settings->setValue("Langue/1", "Français");
        settings->setValue("Langue/2", "English");
        settings->setValue("Langue/3", "Deutsch");

    }
    while(!settings->value("Langue/" + QString::number(a)).toString().isNull())
    {
        choix_langue->addItem(settings->value("Langue/" + QString::number(a)).toString().toUtf8());

        a++;
    }
    choix_langue->setCurrentIndex(settings->value("Langue/default", 1).toInt());

    taille_x->setMaximum(1000);
    taille_y->setMaximum(1000);
    taille_x->setMinimum(100);
    taille_y->setMinimum(100);
    taille_x->setValue(settings->value("Taille/x").toInt());
    taille_y->setValue(settings->value("Taille/y").toInt());

    majact->setChecked(settings->value("MAJ").toBool());

    QVBoxLayout *langue_layout = new QVBoxLayout;
    QVBoxLayout *maj_layout = new QVBoxLayout;
    QFormLayout *taille_layout = new QFormLayout;
    QVBoxLayout *final = new QVBoxLayout;
    langue_layout->addWidget(choix_langue);
    taille_layout->addRow(tr("Largeur : "), taille_x);
    taille_layout->addRow(tr("Longueur :"), taille_y);
    maj_layout->addWidget(majact);

    langue->setLayout(langue_layout);
    option_taille->setLayout(taille_layout);
    majgroup->setLayout(maj_layout);

    final->addWidget(langue);
    final->addWidget(option_taille);
    final->addWidget(majgroup);
    final->addWidget(sauvegarder_opt);

    setLayout(final);
    setWindowTitle("Options");
    setMinimumSize(250, 275);
    QObject::connect(sauvegarder_opt, SIGNAL(clicked(bool)), this, SLOT(record_opt(bool)));
}
void Option::record_opt(bool test)
{
    faux = 1;
    settings->setValue("Taille/x", taille_x->value());
    settings->setValue("Taille/y", taille_y->value());
    settings->setValue("Langue/default", choix_langue->currentIndex());
    if (majact->isChecked())
    {
        settings->setValue("MAJ", true);
    }
    else
    {
        settings->setValue("MAJ", false);
    }

    if(test == true)
    {
        QMessageBox::information(this, tr("Information"), tr("Modification effectuée"));
    }
    close();
}
void Option::closeEvent(QCloseEvent *event)
{
    if (faux != 1)
    {
    QMessageBox message;
    message.setWindowTitle(tr("Confirmation"));
    message.setText(tr("Sauvegarder ?"));
    message.addButton(QMessageBox::Yes);
    message.addButton(QMessageBox::No);
    message.setButtonText(QMessageBox::Yes, tr("Oui"));
    message.setButtonText(QMessageBox::No, tr("Non"));
    int reponse = message.exec();
       if (reponse == QMessageBox::Yes)
       {
           record_opt(false);
           event->accept();
       }
       else
       {
           event->accept();
       }
    }
    else
    {
        event->accept();
    }
}
