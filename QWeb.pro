TEMPLATE = app
TARGET   = QWeb
QT      += core gui widgets webenginewidgets network
CONFIG  += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    tabbar.cpp \
    webtabwidget.cpp \
    qwebapplication.cpp \
    webview.cpp

HEADERS += mainwindow.h \
    tabbar.h \
    webtabwidget.h \
    qwebapplication.h \
    webview.h
