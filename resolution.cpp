#include "resolution.h"

Resolution::Resolution() : QDialog()
{
   // setModal(true);

    progression = new QLabel("94");
    slider = new QSlider(Qt::Horizontal, this);

    ok = new QPushButton(tr("Ok"));
    cancel = new QPushButton(tr("Annuler"));

    slider->setMaximum(100);
    slider->setMinimum(1);
    slider->setValue(94);

    QHBoxLayout *compteur = new QHBoxLayout;
    compteur->addWidget(slider);
    compteur->addWidget(progression);

    QHBoxLayout *bouton = new QHBoxLayout;
    bouton->addWidget(ok, 0, Qt::AlignRight);
    bouton->addWidget(cancel, 0, Qt::AlignRight);

    QVBoxLayout *final = new QVBoxLayout;
    final->addLayout(compteur);
    final->addLayout(bouton);

    setLayout(final);
    show();
}
void Resolution::ok_bouton()
{
    accept();
    return slider->value();
}
void Resolution::cancel_bouton()
{
    reject();
}
void Resolution::slider_slot(int valuech)
{
    progression->setText(QString::number(valuech));
}
