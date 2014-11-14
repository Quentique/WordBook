#include <QCloseEvent>
#include <QColorDialog>
#include <QCoreApplication>
#include <QFile>
#include <QLayout>
#include <QMessageBox>
#include <QTextStream>

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
    style_enregistrer = new QPushButton(tr("Enregistrer"));

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

    style_soustitre_gras1 = new QCheckBox(tr("Gras"));
    style_soustitre_gras2 = new QCheckBox(tr("Gras"));
    style_tableau_gras1 = new QCheckBox(tr("Gras"));
    style_tableau_gras2 = new QCheckBox(tr("Gras"));
    style_tableau_gras3 = new QCheckBox(tr("Gras"));
    style_titre_gras = new QCheckBox(tr("Gras"));

    style_soustitre_italique1 = new QCheckBox(tr("Italique"));
    style_soustitre_italique2 = new QCheckBox(tr("Italique"));
    style_tableau_italique1 = new QCheckBox(tr("Italique"));
    style_tableau_italique2 = new QCheckBox(tr("Italique"));
    style_tableau_italique3 = new QCheckBox(tr("Italique"));
    style_titre_italique = new QCheckBox(tr("Italique"));

    style_soustitre_souligne1 = new QCheckBox(tr("Souligné"));
    style_soustitre_souligne2 = new QCheckBox(tr("Souligné"));
    style_tableau_souligne1 = new QCheckBox(tr("Souligné"));
    style_tableau_souligne2 = new QCheckBox(tr("Souligné"));
    style_tableau_souligne3 = new QCheckBox(tr("Souligné"));
    style_titre_souligne = new QCheckBox(tr("Souligné"));

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

    style_soustitre1 = new QGroupBox(tr("Sous Titre"));
    style_soustitre2 = new QGroupBox(tr("Langue"));
    style_tableau1 = new QGroupBox(tr("En-tête"));
    style_tableau2 = new QGroupBox(tr("Termes"));
    style_tableau3 = new QGroupBox(tr("Traductions"));
    style_tableau = new QGroupBox(tr("Tableau"));
    style_titre = new QGroupBox(tr("Titre"));

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
    QObject::connect(style_enregistrer, SIGNAL(clicked()), this, SLOT(sauvegarder()));

    setWindowTitle("Style");
}

void Style::lister_parametre()
{
    settings = new QSettings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    style_titre_font->setCurrentFont(settings->value("Title/font", QFont("Arial")).value<QFont>());
    style_titre_gras->setChecked(settings->value("Title/bold", "false").toBool());
    style_titre_italique->setChecked(settings->value("Title/italic", "false").toBool());
    style_titre_souligne->setChecked(settings->value("Title/underline", "false").toBool());
    style_titre_taille->setValue(settings->value("Title/size", "20").toInt());
    style_titre_couleur->setPalette(QPalette(settings->value("Title/color", QColor("red")).value<QColor>()));

    style_soustitre_font1->setCurrentFont(settings->value("SubTitle/font", QFont("Arial")).value<QFont>());
    style_soustitre_gras1->setChecked(settings->value("SubTitle/bold", "false").toBool());
    style_soustitre_italique1->setChecked(settings->value("SubTitle/italic", "false").toBool());
    style_soustitre_souligne1->setChecked(settings->value("SubTitle/underline", "false").toBool());
    style_soustitre_taille1->setValue(settings->value("SubTitle/size", "15").toInt());
    style_soustitre_couleur1->setPalette(QPalette(settings->value("SubTitle/color", QColor("black")).value<QColor>()));

    style_soustitre_font2->setCurrentFont(settings->value("Language/font", QFont("Arial")).value<QFont>());
    style_soustitre_gras2->setChecked(settings->value("Language/bold", "false").toBool());
    style_soustitre_italique2->setChecked(settings->value("Language/italic", "false").toBool());
    style_soustitre_souligne2->setChecked(settings->value("Language/underline", "false").toBool());
    style_soustitre_taille2->setValue(settings->value("Language/size", "12").toInt());
    style_soustitre_couleur2->setPalette(QPalette(settings->value("Language/color", QColor("green")).value<QColor>()));

    style_tableau_font1->setCurrentFont(settings->value("Header/font", QFont("Arial")).value<QFont>());
    style_tableau_gras1->setChecked(settings->value("Header/bold", "false").toBool());
    style_tableau_italique1->setChecked(settings->value("Header/italic", "false").toBool());
    style_tableau_souligne1->setChecked(settings->value("Header/underline", "false").toBool());
    style_tableau_taille1->setValue(settings->value("Header/size", "12").toInt());
    style_tableau_couleur1->setPalette(QPalette(settings->value("Header/color", QColor("blue")).value<QColor>()));

    style_tableau_font2->setCurrentFont(settings->value("Terme/font", QFont("Arial")).value<QFont>());
    style_tableau_gras2->setChecked(settings->value("Terme/bold", "false").toBool());
    style_tableau_italique2->setChecked(settings->value("Terme/italic", "false").toBool());
    style_tableau_souligne2->setChecked(settings->value("Terme/underline", "false").toBool());
    style_tableau_taille2->setValue(settings->value("Terme/size", "10").toInt());
    style_tableau_couleur2->setPalette(QPalette(settings->value("Terme/color", QColor("orange")).value<QColor>()));

    style_tableau_font3->setCurrentFont(settings->value("Translation/font", QFont("Arial")).value<QFont>());
    style_tableau_gras3->setChecked(settings->value("Translation/bold", "false").toBool());
    style_tableau_italique3->setChecked(settings->value("Translation/italic", "false").toBool());
    style_tableau_souligne3->setChecked(settings->value("Translation/underline", "false").toBool());
    style_tableau_taille3->setValue(settings->value("Translation/size", "10").toInt());
    style_tableau_couleur3->setPalette(QPalette(settings->value("Translation/color", QColor("yellow")).value<QColor>()));
}
void Style::couleur(QWidget *bouton)
{
    QColor couleurchange = QColorDialog::getColor(Qt::white, this);
    qobject_cast<QPushButton*>(bouton)->setPalette(QPalette(couleurchange));
}
QString Style::retour_couleur(QPushButton *bouton)
{
    QString string_couleur;
    string_couleur += "color: rgba(";
    string_couleur += QString::number(bouton->palette().background().color().red());
    string_couleur += ", ";
    string_couleur += QString::number(bouton->palette().background().color().green());
    string_couleur += ", ";
    string_couleur += QString::number(bouton->palette().background().color().blue());
    string_couleur += ", ";
    string_couleur += QString::number(bouton->palette().background().color().alpha());
    string_couleur += ");\n";
    return string_couleur;
}
QString Style::transfo_bool(QCheckBox *box)
{
    if (box->isChecked()) { return "true";} else { return "false";}
}
QString Style::souligne(QCheckBox *boxline)
{
    if(boxline->isChecked()) { return "text-decoration: underline;\n";} else {return "";}
}

void Style::sauvegarder()
{
    vrai = 1;
    QFile::remove(QCoreApplication::applicationDirPath() + "/style.css");

    settings->setValue("Title/font", style_titre_font->currentFont());
    settings->setValue("Title/size", style_titre_taille->value());
    settings->setValue("Title/bold", style_titre_gras->isChecked());
    settings->setValue("Title/italic", style_titre_italique->isChecked());
    settings->setValue("Title/underline", style_titre_souligne->isChecked());
    settings->setValue("Title/color", style_titre_couleur->palette().background().color());

    settings->setValue("SubTitle/font", style_soustitre_font1->currentFont());
    settings->setValue("SubTitle/size", style_soustitre_taille1->value());
    settings->setValue("SubTitle/bold", style_soustitre_gras1->isChecked());
    settings->setValue("SubTitle/italic", style_soustitre_italique1->isChecked());
    settings->setValue("SubTitle/underline", style_soustitre_souligne1->isChecked());
    settings->setValue("SubTitle/color", style_soustitre_couleur1->palette().background().color());

    settings->setValue("Language/font", style_soustitre_font2->currentFont());
    settings->setValue("Language/size", style_soustitre_taille2->value());
    settings->setValue("Language/bold", style_soustitre_gras2->isChecked());
    settings->setValue("Language/italic", style_soustitre_italique2->isChecked());
    settings->setValue("Language/underline", style_soustitre_souligne2->isChecked());
    settings->setValue("Language/color", style_soustitre_couleur2->palette().background().color());

    settings->setValue("Header/font", style_tableau_font1->currentFont());
    settings->setValue("Header/size", style_tableau_taille1->value());
    settings->setValue("Header/bold", style_tableau_gras1->isChecked());
    settings->setValue("Header/italic", style_tableau_italique1->isChecked());
    settings->setValue("Header/underline", style_tableau_souligne1->isChecked());
    settings->setValue("Header/color", style_tableau_couleur1->palette().background().color());

    settings->setValue("Terme/font", style_tableau_font2->currentFont());
    settings->setValue("Terme/size", style_tableau_taille2->value());
    settings->setValue("Terme/bold", style_tableau_gras2->isChecked());
    settings->setValue("Terme/italic", style_tableau_italique2->isChecked());
    settings->setValue("Terme/underline", style_tableau_souligne2->isChecked());
    settings->setValue("Terme/color", style_tableau_couleur2->palette().background().color());

    settings->setValue("Translation/font", style_tableau_font3->currentFont());
    settings->setValue("Translation/size", style_tableau_taille3->value());
    settings->setValue("Translation/bold", style_tableau_gras3->isChecked());
    settings->setValue("Translation/italic", style_tableau_italique3->isChecked());
    settings->setValue("Translation/underline", style_tableau_souligne3->isChecked());
    settings->setValue("Translation/color", style_tableau_couleur3->palette().background().color());

    QFile fichierstyle(QCoreApplication::applicationDirPath() + "/style.css");

    if (fichierstyle.exists())
    {
        fichierstyle.remove();
    }

    if(!fichierstyle.open(QIODevice::WriteOnly | QIODevice::Text))
    {
       QMessageBox::critical(this, tr("Erreur Critique"), tr("Erreur lors de l'ouverture du fichier\n Code de l'erreur : ") + fichierstyle.errorString());

    }

    QTextStream stream(&fichierstyle);
    stream.setCodec("UTF-8");
    stream << "h1\n{\nfont-size: " << style_titre_taille->value() << ";\n";
    stream << "font-family: " << style_titre_font->currentFont().toString().section(",",0,0) << ";\n";
    stream << "font-weight: " << transfo_bool(style_titre_gras) << ";\n";
    stream << "font-italic: " << transfo_bool(style_titre_italique) << ";\n";
    stream << souligne(style_titre_souligne);
    stream << retour_couleur(style_titre_couleur);
    stream << "text-align: center;\n";
    stream << "}\n";
    stream << "h2\n{\nfont-size: " << style_soustitre_taille1->value() << ";\n";
    stream << "font-family: " << style_soustitre_font1->currentFont().toString().section(",",0,0) << ";\n";
    stream << "font-weight: " << transfo_bool(style_soustitre_gras1) << ";\n";
    stream << "font-italic: " << transfo_bool(style_soustitre_italique1) << ";\n";
    stream << souligne(style_soustitre_souligne1);
    stream << retour_couleur(style_soustitre_couleur1);
    stream << "text-align: center;\n";
    stream << "}\n";
    stream << "div\n{\nfont-size: " << style_soustitre_taille2->value() << ";\n";
    stream << "font-family: " << style_soustitre_font2->currentFont().toString().section(",",0,0) << ";\n";
    stream << "font-weight: " << transfo_bool(style_soustitre_gras2) << ";\n";
    stream << "font-italic: " << transfo_bool(style_soustitre_italique2) << ";\n";
    stream << souligne(style_soustitre_souligne2);
    stream << retour_couleur(style_soustitre_couleur2);
    stream << "text-align: center;\nmargin-bottom: 1em;\n";
    stream << "}\n";
    stream << "th\n{\nfont-size: " << style_tableau_taille1->value() << ";\n";
    stream << "font-family: " << style_tableau_font1->currentFont().toString().section(",",0,0) << ";\n";
    stream << "font-weight: " << transfo_bool(style_tableau_gras1) << ";\n";
    stream << "font-italic: " << transfo_bool(style_tableau_italique1) << ";\n";
    stream << souligne(style_tableau_souligne1);
    stream << retour_couleur(style_tableau_couleur1);
    stream << "}\n";
    stream << "tbody tr td:first-child\n{\nfont-size: " << style_tableau_taille2->value() << ";\n";
    stream << "font-family: " << style_tableau_font2->currentFont().toString().section(",",0,0) << ";\n";
    stream << "font-weight: " << transfo_bool(style_tableau_gras2) << ";\n";
    stream << "font-italic: " << transfo_bool(style_tableau_italique2) << ";\n";
    stream << souligne(style_tableau_souligne2);
    stream << retour_couleur(style_tableau_couleur2);
    stream << "text-align: right;\n";
    stream << "}\n";
    stream << "tbody tr td:last-child\n{\nfont-size: " << style_tableau_taille3->value() << ";\n";
    stream << "font-family: " << style_tableau_font3->currentFont().toString().section(",",0,0) << ";\n";
    stream << "font-weight: " << transfo_bool(style_tableau_gras3) << ";\n";
    stream << "font-italic: " << transfo_bool(style_tableau_italique3) << ";\n";
    stream << souligne(style_tableau_souligne3);
    stream << retour_couleur(style_tableau_couleur3);
    stream << "}\n";
    stream << "td, th\n{\nborder: solid 1px blue;\n}\n";
    stream << "table\n{\nmargin-left: auto;\nmargin-right: auto;\nborder-collapse: collapse;\n}";
    fichierstyle.close();

    QMessageBox::information(this, tr("Information"), tr("La modification prendra effet après le redémarrage de l'application"));
    close();
}
void Style::closeEvent(QCloseEvent *event)
{
    if (vrai != 1)
    {
        QMessageBox message;
        message.setWindowTitle(tr("Confirmation"));
        message.setText(tr("Sauvegarder ?"));
        message.addButton(QMessageBox::Yes);
        message.addButton(QMessageBox::No);
        message.setButtonText(QMessageBox::Yes, tr("Oui"));
        message.setButtonText(QMessageBox::No, tr("Non"));
        int reponse = message.exec();
        if (reponse == QMessageBox::Yes)
        {
            sauvegarder();
            event->accept();
        }
        else
        {
            event->accept();
        }
    }
    else
    {
        event->accept();
    }
}
