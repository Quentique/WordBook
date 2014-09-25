#include "style.h"

Style::Style()
{
    style_soustitre_font1 = new QFontComboBox;
    style_soustitre_font2 = new QFontComboBox;
    style_tableau_font1 = new QFontComboBox;
    style_tableau_font2 = new QFontComboBox;
    style_tableau_font3 = new QFontComboBox;
    style_titre_font = new QFontComboBox;

    style_soustitre_couleur1 = new QPushButton("Couleur");
    style_soustitre_couleur2 = new QPushButton("Couleur");
    style_tableau_couleur1 = new QPushButton("Couleur");
    style_tableau_couleur2 = new QPushButton("Couleur");
    style_tableau_couleur3 = new QPushButton("Couleur");
    style_titre_couleur = new QPushButton("Couleur");

    style_soustitre_gras1 = new QCheckBox("Gras");
    style_soustitre_gras2 = new QCheckBox("Gras");
    style_tableau_gras1 = new QCheckBox("Gras");
    style_tableau_gras2 = new QCheckBox("Gras");
    style_tableau_gras3 = new QCheckBox("Gras");
    style_titre_gras = new QCheckBox("Gras");

    style_soustitre_italique1 = new QCheckBox("Italique");
    style_soustitre_italique2 = new QCheckBox("Italique");
    style_tableau_italique1 = new QCheckBox("Italique");
    style_tableau_italique2 = new QCheckBox("Italique");
    style_tableau_italique3 = new QCheckBox("Italique");
    style_titre_italique = new QCheckBox("Italique");

    style_soustitre_souligne1 = new QCheckBox("Souligné");
    style_soustitre_souligne2 = new QCheckBox("Souligné");
    style_tableau_souligne1 = new QCheckBox("Souligné");
    style_tableau_souligne2 = new QCheckBox("Souligné");
    style_tableau_souligne3 = new QCheckBox("Souligné");
    style_titre_souligne = new QCheckBox("Souligné");

    style_soustitre_taille1 = new QSpinBox;
    style_soustitre_taille2 = new QSpinBox;
    style_tableau_taille1 = new QSpinBox;
    style_tableau_taille2 = new QSpinBox;
    style_tableau_taille3 = new QSpinBox;
    style_titre_taille = new QSpinBox;

    style_soustitre = new QGroupBox("Sous Titre");
    style_tableau1 = new QGroupBox("En-tête");
    style_tableau2 = new QGroupBox("Termes");
    style_tableau3 = new QGroupBox("Traduction");
    style_tableau = new QGroupBox("Tableau");
    style_titre = new QGroupBox("Titre");

    QVBoxLayout *style_soustitre_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau1_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau2_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau3_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau_layout = new QVBoxLayout;
    QVBoxLayout *style_titre_layout = new QVBoxLayout;

    QHBoxLayout *style_soustitre_font_layout = new QHBoxLayout;
    QHBoxLayout *style_soustitre_color_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau1_font_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau1_color_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau2_font_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau2_color_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau3_font_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau3_color_layout = new QHBoxLayout;
    QHBoxLayout *style_titre_font_layout = new QHBoxLayout;
    QHBoxLayout *style_titre_color_layout = new QHBoxLayout;
}
