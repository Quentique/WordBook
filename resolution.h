#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <QDialog>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QSignalMapper>

class Resolution : public QDialog
{
    Q_OBJECT
public:
    Resolution();
private:
    QSlider *slider;
    QPushButton *ok;
    QPushButton *cancel;
    QLabel *progression, *titre1, *titre2;
    QSignalMapper *mapper;
public slots:
    void slider_slot(int valuech);
};

#endif // RESOLUTION_H
