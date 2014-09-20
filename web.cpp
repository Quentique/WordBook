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
}
