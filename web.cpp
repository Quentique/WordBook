#include "fenetre.h"
#include "web.h"

Web::Web(QString nomfichier)
{
  principale = new QWidget;
  vue = new QWebView(principale);
  QUrl chemin;
  chemin.setUrl("file:///" + QCoreApplication::applicationDirPath() + "/data/" + nomfichier.toLower() + ".html");
  vue->setUrl(chemin);
  vue->setMaximumSize(300, 500);
  principale->show();
  principale->setMaximumSize(300, 600);
  principale->setMinimumSize(300, 600);

}
