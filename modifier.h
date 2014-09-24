#ifndef MODIFIER_H
#define MODIFIER_H

#include "ajout.h"
#include <QtWidgets>

class Modifier : public Ajout
{
    Q_OBJECT
public:
    Modifier();
    bool affdonne(QString nomfich);
    QString mag(QString machin);
public slots:
    virtual void enregistre();
private:
    QString *nomfic;
};

#endif // MODIFIER_H
