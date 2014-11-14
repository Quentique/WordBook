#include "fenetre.h"
#include "web.h"
#include <QCoreApplication>

Web::Web(QString nomfichier)
{
  QUrl chemin;
  chemin.setUrl("file:///" + QCoreApplication::applicationDirPath() + "/data/" + nomfichier.toLower() + ".html");

  principale = new QWidget;
  vue = new QWebView(principale);
  vue->setUrl(chemin);

  QSettings *settings = new QSettings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);

  principale->setMaximumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  principale->setMinimumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  vue->setZoomFactor(2);
  vue->setMaximumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  vue->setMinimumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  principale->setWindowTitle(QObject::tr("Affichage"));
  principale->show();
  delete settings;
}
