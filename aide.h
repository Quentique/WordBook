#ifndef AIDE_H
#define AIDE_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Aide : public QWidget
{
    Q_OBJECT

public:
    Aide();

private:
    QLabel *texte_aide;
    QPushButton *qt_about;
};

#endif // AIDE_H
