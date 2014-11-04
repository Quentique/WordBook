#include "resolution.h"
#include <QSignalMapper>

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

    QSignalMapper *mapper = new QSignalMapper;
    mapper->setMapping(ok, slider->value());

    QObject::connect(ok, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(mapper, SIGNAL(mapped(int)), this, SLOT(done(int)));
    QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slider_slot(int)));

}
void Resolution::slider_slot(int valuech)
{
    progression->setText(QString::number(valuech));
}
