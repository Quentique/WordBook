#ifndef AIDE_H
#define AIDE_H

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

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
