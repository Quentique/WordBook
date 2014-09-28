#ifndef AIDE_H
#define AIDE_H

#include <QtWidgets>

class Aide : public QWidget
{
public:
    Aide();
private:
    QLabel *texte_aide;
    QPushButton *qt_about;
};

#endif // AIDE_H
