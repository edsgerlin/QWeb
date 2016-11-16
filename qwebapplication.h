#ifndef QWEBAPPLICATION_H
#define QWEBAPPLICATION_H
#include <QApplication>

class QWebApplication : public QApplication
{
    Q_OBJECT
public:
    QWebApplication(int &argc, char **argv);
    ~QWebApplication();

};

#endif // QWEBAPPLICATION_H
