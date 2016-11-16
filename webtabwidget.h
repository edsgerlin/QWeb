#ifndef WEBTABWIDGET_H
#define WEBTABWIDGET_H
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QLineEdit>
class WebTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    WebTabWidget(QWidget *parent = Q_NULLPTR);
    ~WebTabWidget();
public slots:
    void updateTexts();
};

#endif // WEBTABWIDGET_H
