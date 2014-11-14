#ifndef WEB_H
#define WEB_H

#include <QWebView>
#include <QWidget>

class Web : public QWidget
{

public:
    Web(QString nomfichier);

private:
    QWidget *principale;
    QWebView *vue;
};

#endif // WEB_H
