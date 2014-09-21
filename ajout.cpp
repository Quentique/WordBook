#include "fenetre.h"
#include "ajout.h"

Ajout::Ajout()
{
    fenajout = new QWidget;
    titre = new QLineEdit;
    soustitre = new QLineEdit;
    tableau = new QTableWidget;
    record = new QPushButton("Enregistrer");

    QFormLayout *form = new QFormLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layout2 = new QHBoxLayout;

    form->addRow("Titre", titre);
    form->addRow("Sous-titre (optionnel)", soustitre);

    layout->addLayout(form);
    layout->addWidget(tableau);

    layout2->addLayout(layout);
    layout2->addWidget(record);

    tableau->setColumnCount(2);
    tableau->setRowCount(100);
    QStringList labels;
    labels << "Termes" << "Traduction";
    tableau->setHorizontalHeaderLabels(labels);
    tableau->setColumnWidth(0, 150);
    tableau->setColumnWidth(1, 150);

    fenajout->setLayout(layout2);
    fenajout->resize(400, 500);
    fenajout->show();

}
