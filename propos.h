#ifndef PROPOS_H
#define PROPOS_H

#include <QtWidgets>

class Propos : public QWidget
{
    Q_OBJECT
public:
    Propos();
public slots:
    void ouvrir_url(QString url);
private:
    QLabel *label, *licence, *icone;
};

#endif // PROPOS_H
