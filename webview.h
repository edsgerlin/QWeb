#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QVBoxLayout>
class WebView : public QWidget
{

public:
    explicit WebView(QWidget *parent = Q_NULLPTR);
    QString title() const;

signals:
    void titleChanged(QString);
public slots:
    void changeTitle();
    void changeUrl();
    void back();
    void forward();
    void reload();
    void increaseZoomFactor();
    void decreaseZoomFactor();
    void resetZoomFactor();
private:
    QLineEdit *m_lineEdit;
    QWebEngineView *m_webEngineView;
    QVBoxLayout *m_layout;
    QString *m_title;
    Q_OBJECT
};

#endif // WEBVIEW_H
