#ifndef OPTION_H
#define OPTION_H

#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QSettings>
#include <QPushButton>
#include <QCheckBox>

class Option : public QWidget
{
    Q_OBJECT

public:
    Option();
    void closeEvent(QCloseEvent *event);

public slots:
    void record_opt(bool test);

private:
    QGroupBox *langue, *option_taille, *majgroup;
    QComboBox *choix_langue;
    QSpinBox *taille_x, *taille_y;
    QCheckBox *majact;
    QSettings *settings;
    QPushButton *sauvegarder_opt;
    int faux;
};

#endif // OPTION_H
