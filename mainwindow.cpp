#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags),
      m_webTabWidget(new WebTabWidget(this))
{
    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // TODO
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(m_webTabWidget);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow()
{

}
