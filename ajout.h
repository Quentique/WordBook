#ifndef AJOUT_H
#define AJOUT_H

#include <QWidget>
#include <QtWidgets>

class Ajout : public QWidget
{
public:
    Ajout();
private:
    QWidget *fenajout;
    QTableWidget *tableau;
    QLineEdit *titre, *soustitre;
    QPushButton *record;
};

#endif // AJOUT_H
