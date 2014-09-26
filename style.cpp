#include "style.h"

Style::Style()
{
    style_soustitre_font1 = new QFontComboBox;
    style_soustitre_font2 = new QFontComboBox;
    style_tableau_font1 = new QFontComboBox;
    style_tableau_font2 = new QFontComboBox;
    style_tableau_font3 = new QFontComboBox;
    style_titre_font = new QFontComboBox;

    style_soustitre_couleur1 = new QPushButton;
    style_soustitre_couleur2 = new QPushButton;
    style_tableau_couleur1 = new QPushButton;
    style_tableau_couleur2 = new QPushButton;
    style_tableau_couleur3 = new QPushButton;
    style_titre_couleur = new QPushButton;
    style_enregistrer = new QPushButton("Enregistrer");

    style_soustitre_couleur1->setFlat(true);
    style_soustitre_couleur2->setFlat(true);
    style_tableau_couleur1->setFlat(true);
    style_tableau_couleur2->setFlat(true);
    style_tableau_couleur3->setFlat(true);
    style_titre_couleur->setFlat(true);
    style_soustitre_couleur1->setAutoFillBackground(true);
    style_soustitre_couleur2->setAutoFillBackground(true);
    style_tableau_couleur1->setAutoFillBackground(true);
    style_tableau_couleur2->setAutoFillBackground(true);
    style_tableau_couleur3->setAutoFillBackground(true);
    style_titre_couleur->setAutoFillBackground(true);

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

    style_soustitre_taille1->setMinimum(1);
    style_soustitre_taille2->setMinimum(1);
    style_tableau_taille1->setMinimum(1);
    style_tableau_taille2->setMinimum(1);
    style_tableau_taille3->setMinimum(1);
    style_titre_taille->setMinimum(1);

    style_soustitre1 = new QGroupBox("Sous Titre");
    style_soustitre2 = new QGroupBox("Langue");
    style_tableau1 = new QGroupBox("En-tête");
    style_tableau2 = new QGroupBox("Termes");
    style_tableau3 = new QGroupBox("Traduction");
    style_tableau = new QGroupBox("Tableau");
    style_titre = new QGroupBox("Titre");

    QVBoxLayout *style_soustitre_layout1 = new QVBoxLayout;
    QVBoxLayout *style_soustitre_layout2 = new QVBoxLayout;
    QVBoxLayout *style_tableau1_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau2_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau3_layout = new QVBoxLayout;
    QVBoxLayout *style_tableau_layout = new QVBoxLayout;
    QVBoxLayout *style_titre_layout = new QVBoxLayout;
    QVBoxLayout *style_final = new QVBoxLayout;

    QHBoxLayout *style_soustitre_font_layout1 = new QHBoxLayout;
    QHBoxLayout *style_soustitre_font_layout2 = new QHBoxLayout;
    QHBoxLayout *style_soustitre_color_layout1 = new QHBoxLayout;
    QHBoxLayout *style_soustitre_color_layout2 = new QHBoxLayout;
    QHBoxLayout *style_tableau1_font_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau1_color_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau2_font_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau2_color_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau3_font_layout = new QHBoxLayout;
    QHBoxLayout *style_tableau3_color_layout = new QHBoxLayout;
    QHBoxLayout *style_titre_font_layout = new QHBoxLayout;
    QHBoxLayout *style_titre_color_layout = new QHBoxLayout;

    style_soustitre_font_layout1->addWidget(style_soustitre_font1);
    style_soustitre_font_layout1->addWidget(style_soustitre_taille1);
    style_soustitre_font_layout2->addWidget(style_soustitre_font2);
    style_soustitre_font_layout2->addWidget(style_soustitre_taille2);
    style_soustitre_color_layout1->addWidget(style_soustitre_gras1);
    style_soustitre_color_layout1->addWidget(style_soustitre_italique1);
    style_soustitre_color_layout1->addWidget(style_soustitre_souligne1);
    style_soustitre_color_layout1->addWidget(style_soustitre_couleur1);
    style_soustitre_color_layout2->addWidget(style_soustitre_gras2);
    style_soustitre_color_layout2->addWidget(style_soustitre_italique2);
    style_soustitre_color_layout2->addWidget(style_soustitre_souligne2);
    style_soustitre_color_layout2->addWidget(style_soustitre_couleur2);

    style_tableau1_font_layout->addWidget(style_tableau_font1);
    style_tableau1_font_layout->addWidget(style_tableau_taille1);
    style_tableau1_color_layout->addWidget(style_tableau_gras1);
    style_tableau1_color_layout->addWidget(style_tableau_italique1);
    style_tableau1_color_layout->addWidget(style_tableau_souligne1);
    style_tableau1_color_layout->addWidget(style_tableau_couleur1);

    style_tableau2_font_layout->addWidget(style_tableau_font2);
    style_tableau2_font_layout->addWidget(style_tableau_taille2);
    style_tableau2_color_layout->addWidget(style_tableau_gras2);
    style_tableau2_color_layout->addWidget(style_tableau_italique2);
    style_tableau2_color_layout->addWidget(style_tableau_souligne2);
    style_tableau2_color_layout->addWidget(style_tableau_couleur2);

    style_tableau3_font_layout->addWidget(style_tableau_font3);
    style_tableau3_font_layout->addWidget(style_tableau_taille3);
    style_tableau3_color_layout->addWidget(style_tableau_gras3);
    style_tableau3_color_layout->addWidget(style_tableau_italique3);
    style_tableau3_color_layout->addWidget(style_tableau_souligne3);
    style_tableau3_color_layout->addWidget(style_tableau_couleur3);

    style_titre_font_layout->addWidget(style_titre_font);
    style_titre_font_layout->addWidget(style_titre_taille);
    style_titre_color_layout->addWidget(style_titre_gras);
    style_titre_color_layout->addWidget(style_titre_italique);
    style_titre_color_layout->addWidget(style_titre_souligne);
    style_titre_color_layout->addWidget(style_titre_couleur);

    style_soustitre_layout1->addLayout(style_soustitre_font_layout1);
    style_soustitre_layout1->addLayout(style_soustitre_color_layout1);
    style_soustitre_layout2->addLayout(style_soustitre_font_layout2);
    style_soustitre_layout2->addLayout(style_soustitre_color_layout2);

    style_tableau1_layout->addLayout(style_tableau1_font_layout);
    style_tableau1_layout->addLayout(style_tableau1_color_layout);
    style_tableau2_layout->addLayout(style_tableau2_font_layout);
    style_tableau2_layout->addLayout(style_tableau2_color_layout);
    style_tableau3_layout->addLayout(style_tableau3_font_layout);
    style_tableau3_layout->addLayout(style_tableau3_color_layout);

    style_soustitre_layout1->addLayout(style_soustitre_font_layout1);
    style_soustitre_layout1->addLayout(style_soustitre_color_layout1);
    style_soustitre_layout2->addLayout(style_soustitre_font_layout2);
    style_soustitre_layout2->addLayout(style_soustitre_color_layout2);

    style_tableau1_layout->addLayout(style_tableau1_font_layout);
    style_tableau1_layout->addLayout(style_tableau1_color_layout);
    style_tableau2_layout->addLayout(style_tableau2_font_layout);
    style_tableau2_layout->addLayout(style_tableau2_color_layout);
    style_tableau3_layout->addLayout(style_tableau3_font_layout);
    style_tableau3_layout->addLayout(style_tableau3_color_layout);

    style_titre_layout->addLayout(style_titre_font_layout);
    style_titre_layout->addLayout(style_titre_color_layout);

    style_soustitre1->setLayout(style_soustitre_layout1);
    style_soustitre2->setLayout(style_soustitre_layout2);
    style_tableau1->setLayout(style_tableau1_layout);
    style_tableau2->setLayout(style_tableau2_layout);
    style_tableau3->setLayout(style_tableau3_layout);
    style_titre->setLayout(style_titre_layout);

    style_tableau_layout->addWidget(style_tableau1);
    style_tableau_layout->addWidget(style_tableau2);
    style_tableau_layout->addWidget(style_tableau3);

    style_tableau->setLayout(style_tableau_layout);

    style_final->addWidget(style_titre);
    style_final->addWidget(style_soustitre1);
    style_final->addWidget(style_soustitre2);
    style_final->addWidget(style_tableau);
    style_final->addWidget(style_enregistrer);
    setLayout(style_final);

    mapper = new QSignalMapper;

    QObject::connect(style_titre_couleur, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(style_titre_couleur, style_titre_couleur);

    QObject::connect(style_soustitre_couleur1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(style_soustitre_couleur1, style_soustitre_couleur1);

    QObject::connect(style_soustitre_couleur2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(style_soustitre_couleur2, style_soustitre_couleur2);

    QObject::connect(style_tableau_couleur1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(style_tableau_couleur1, style_tableau_couleur1);

    QObject::connect(style_tableau_couleur2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(style_tableau_couleur2, style_tableau_couleur2);

    QObject::connect(style_tableau_couleur3, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(style_tableau_couleur3, style_tableau_couleur3);

    QObject::connect(mapper, SIGNAL(mapped(QWidget*)), this, SLOT(couleur(QWidget*)));
}
void Style::lister_parametre()
{
    QSettings settings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    style_titre_font->setCurrentFont(settings.value("Title/font", QFont("Arial")).value<QFont>());
    style_titre_gras->setChecked(settings.value("Title/bold", "false").toBool());
    style_titre_italique->setChecked(settings.value("Title/italic", "false").toBool());
    style_titre_souligne->setChecked(settings.value("Title/underline", "false").toBool());
    style_titre_taille->setValue(settings.value("Title/size", "20").toInt());
    style_titre_couleur->setPalette(QPalette(settings.value("Title/color", QColor("red")).value<QColor>()));

    style_soustitre_font1->setCurrentFont(settings.value("SubTitle/font", QFont("Arial")).value<QFont>());
    style_soustitre_gras1->setChecked(settings.value("SubTitle/bold", "false").toBool());
    style_soustitre_italique1->setChecked(settings.value("SubTitle/italic", "false").toBool());
    style_soustitre_souligne1->setChecked(settings.value("SubTitle/underline", "false").toBool());
    style_soustitre_taille1->setValue(settings.value("SubTitle/size", "15").toInt());
    style_soustitre_couleur1->setPalette(QPalette(settings.value("SubTitle/color", QColor("black")).value<QColor>()));

    style_soustitre_font2->setCurrentFont(settings.value("Language/font", QFont("Arial")).value<QFont>());
    style_soustitre_gras2->setChecked(settings.value("Language/bold", "false").toBool());
    style_soustitre_italique2->setChecked(settings.value("Language/italic", "false").toBool());
    style_soustitre_souligne2->setChecked(settings.value("Language/underline", "false").toBool());
    style_soustitre_taille2->setValue(settings.value("Language/size", "12").toInt());
    style_soustitre_couleur2->setPalette(QPalette(settings.value("Language/color", QColor("green")).value<QColor>()));

    style_tableau_font1->setCurrentFont(settings.value("Header/font", QFont("Arial")).value<QFont>());
    style_tableau_gras1->setChecked(settings.value("Header/bold", "false").toBool());
    style_tableau_italique1->setChecked(settings.value("Header/italic", "false").toBool());
    style_tableau_souligne1->setChecked(settings.value("Header/underline", "false").toBool());
    style_tableau_taille1->setValue(settings.value("Header/size", "12").toInt());
    style_tableau_couleur1->setPalette(QPalette(settings.value("Header/color", QColor("blue")).value<QColor>()));

    style_tableau_font2->setCurrentFont(settings.value("Terme/font", QFont("Arial")).value<QFont>());
    style_tableau_gras2->setChecked(settings.value("Terme/bold", "false").toBool());
    style_tableau_italique2->setChecked(settings.value("Terme/italic", "false").toBool());
    style_tableau_souligne2->setChecked(settings.value("Terme/underline", "false").toBool());
    style_tableau_taille2->setValue(settings.value("Terme/size", "10").toInt());
    style_tableau_couleur2->setPalette(QPalette(settings.value("Terme/color", QColor("orange")).value<QColor>()));

    style_tableau_font3->setCurrentFont(settings.value("Translation/font", QFont("Arial")).value<QFont>());
    style_tableau_gras3->setChecked(settings.value("Translation/bold", "false").toBool());
    style_tableau_italique3->setChecked(settings.value("Translation/italic", "false").toBool());
    style_tableau_souligne3->setChecked(settings.value("Translation/underline", "false").toBool());
    style_tableau_taille3->setValue(settings.value("Translation/size", "10").toInt());
    style_tableau_couleur3->setPalette(QPalette(settings.value("Translation/color", QColor("yellow")).value<QColor>()));
}
void Style::couleur(QWidget *bouton)
{
    QColor couleurchange = QColorDialog::getColor(Qt::white, this);
    qobject_cast<QPushButton*>(bouton)->setPalette(QPalette(couleurchange));
}
