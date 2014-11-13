#ifndef STYLE_H
#define STYLE_H

#include <QGroupBox>
#include <QFontComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QSpinBox>
#include <QSignalMapper>
#include <QSettings>

class Style : public QWidget
{
    Q_OBJECT

public:
    Style();
    void lister_parametre();
    QString retour_couleur(QPushButton *bouton);
    QString transfo_bool(QCheckBox *box);
    QString souligne(QCheckBox *boxline);

public slots:
    void couleur(QWidget *bouton);
    void sauvegarder();

protected:
    void closeEvent(QCloseEvent *event);

private:
    QGroupBox *style_titre, *style_soustitre1, *style_soustitre2, *style_tableau, *style_tableau1, *style_tableau2, *style_tableau3;
    QFontComboBox *style_titre_font, *style_soustitre_font1, *style_soustitre_font2, *style_tableau_font1, *style_tableau_font2, *style_tableau_font3;
    QCheckBox *style_titre_gras, *style_titre_italique, *style_titre_souligne, *style_soustitre_gras1, *style_soustitre_italique1, *style_soustitre_souligne1, *style_soustitre_gras2, *style_soustitre_italique2, *style_soustitre_souligne2, *style_tableau_gras1, *style_tableau_italique1, *style_tableau_souligne1, *style_tableau_gras2, *style_tableau_italique2, *style_tableau_souligne2, *style_tableau_gras3, *style_tableau_italique3, *style_tableau_souligne3;
    QPushButton *style_titre_couleur, *style_soustitre_couleur1, *style_soustitre_couleur2, *style_tableau_couleur1, *style_tableau_couleur2, *style_tableau_couleur3, *style_enregistrer;
    QSpinBox *style_titre_taille, *style_soustitre_taille1, *style_soustitre_taille2, *style_tableau_taille1, *style_tableau_taille2, *style_tableau_taille3;
    QSignalMapper *mapper;
    QSettings *settings;
    int vrai;
};

#endif // STYLE_H
