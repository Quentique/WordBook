#ifndef MODIFIER_H
#define MODIFIER_H

#include "ajout.h"

class Modifier : public Ajout
{
    Q_OBJECT

public:
    Modifier();
    QString mag(QString machin);
    bool affdonne(QString nomfich);

public slots:
    virtual void enregistre();

private:
    QString *nomfic;
};

#endif // MODIFIER_H
