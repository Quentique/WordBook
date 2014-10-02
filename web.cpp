#include "fenetre.h"
#include "web.h"

Web::Web(QString nomfichier)
{
  principale = new QWidget;
  vue = new QWebView(principale);
  QUrl chemin;
  chemin.setUrl("file:///" + QCoreApplication::applicationDirPath() + "/data/" + nomfichier.toLower() + ".html");
  vue->setUrl(chemin);

  principale->show();
  QSettings *settings = new QSettings(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);;
  principale->setMaximumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  principale->setMinimumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  vue->setZoomFactor(2);
  vue->setMaximumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  vue->setMinimumSize(settings->value("Taille/x", 500).toInt(), settings->value("Taille/y", 600).toInt());
  principale->setWindowTitle(tr("Affichage"));
  delete settings;
}
