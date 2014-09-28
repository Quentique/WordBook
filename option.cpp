#include "option.h"

Option::Option()
{
    langue = new QGroupBox("Langue");
    option_taille = new QGroupBox("Taille d'affichage");

    choix_langue = new QComboBox;

    taille_x = new QSpinBox;
    taille_y = new QSpinBox;

    sauvegarder_opt = new QPushButton(tr("Enregistrer"));

    settings = new QSettings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    int a = 0;
    while(!settings->value("Langue/" + QString::number(a)).toString().isNull())
    {
        choix_langue->addItem(settings->value("Langue/" + QString::number(a)).toString());
        a++;
    }
    choix_langue->setCurrentIndex(settings->value("Langue/default", 1).toInt());
    taille_x->setMaximum(1000);
    taille_y->setMaximum(1000);
    taille_x->setMinimum(100);
    taille_y->setMinimum(100);
    taille_x->setValue(settings->value("Taille/x").toInt());
    taille_y->setValue(settings->value("Taille/y").toInt());

    QVBoxLayout *langue_layout = new QVBoxLayout;
    QFormLayout *taille_layout = new QFormLayout;
    QVBoxLayout *final = new QVBoxLayout;
    langue_layout->addWidget(choix_langue);
    taille_layout->addRow("Largeur : ", taille_x);
    taille_layout->addRow("Longueur :", taille_y);

    langue->setLayout(langue_layout);
    option_taille->setLayout(taille_layout);

    final->addWidget(langue);
    final->addWidget(option_taille);
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
    QTranslator *traducteur = new QTranslator;
    traducteur->load("langue_"+choix_langue->currentText().left(2).toLower());
    qApp->installTranslator(traducteur);
    if(test == true)
    {
        QMessageBox::information(this, "Information", "Modification effectuée");
    }
    close();
}
void Option::closeEvent(QCloseEvent *event)
{
    if (faux != 1)
    {
    QMessageBox message;
    message.setWindowTitle("Confirmation");
    message.setText("Sauvegarder ?");
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
