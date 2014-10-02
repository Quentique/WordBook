#ifndef AJOUT_H
#define AJOUT_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

class Ajout : public QWidget
{
    Q_OBJECT
public:
    Ajout();
public slots:
    virtual void enregistre();
signals:
    void fini();
protected:
    QTableWidget *tableau;
    QLineEdit *titre, *soustitre, *langue;
    QPushButton *record;
};

#endif // AJOUT_H
