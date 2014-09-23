#ifndef MODIFIER_H
#define MODIFIER_H

#include "ajout.h"
#include <QtWidgets>

class Modifier : public Ajout
{

public:
    Modifier();
    bool affdonne(QString nomfich);
    QString mag(QString machin);
};

#endif // MODIFIER_H
