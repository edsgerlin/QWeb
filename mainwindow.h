#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "webtabwidget.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~MainWindow();
private:
    WebTabWidget *m_webTabWidget;
};

#endif // MAINWINDOW_H
