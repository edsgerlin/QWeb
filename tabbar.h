#ifndef TABBAR_H
#define TABBAR_H
#include <QtWidgets/QTabBar>
class TabBar : public QTabBar
{
    Q_OBJECT
public:
    TabBar(QWidget *parent = Q_NULLPTR);
};

#endif // TABBAR_H
