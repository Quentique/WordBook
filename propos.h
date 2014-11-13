#ifndef PROPOS_H
#define PROPOS_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

class Propos : public QWidget
{
    Q_OBJECT

public:
    Propos();

public slots:
    void ouvrir_url(QString url);
    void openlicencefile();

private:
    QLabel *label, *licence, *icone;
    QPushButton *openlicence;
    QWidget *licence_principale;
    QTextEdit *licence_texte;
};

#endif // PROPOS_H
