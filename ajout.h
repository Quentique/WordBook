#ifndef AJOUT_H
#define AJOUT_H

#include <QWidget>
#include <QtWidgets>

class Ajout : public QWidget
{
    Q_OBJECT
public:
    Ajout();
public slots:
    void enregistre();
signals:
    void fini();
private:
    QTableWidget *tableau;
    QLineEdit *titre, *soustitre, *langue;
    QPushButton *record;
};

#endif // AJOUT_H
