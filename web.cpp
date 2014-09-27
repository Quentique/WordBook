#include "fenetre.h"
#include "web.h"

Web::Web(QString nomfichier)
{
  principale = new QWidget;
  vue = new QWebView(principale);
  QUrl chemin;
  chemin.setUrl("file:///" + QCoreApplication::applicationDirPath() + "/data/" + nomfichier.toLower() + ".html");
  vue->setUrl(chemin);
  vue->setMaximumSize(600, 700);
  vue->setMinimumSize(600, 700);
  vue->setZoomFactor(2);
  principale->show();
  principale->setMaximumSize(600, 700);
  principale->setMinimumSize(600, 700);
  principale->setWindowTitle("Affichage");
}
