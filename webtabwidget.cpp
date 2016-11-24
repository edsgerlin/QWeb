#include "webtabwidget.h"
#include "webview.h"
#include <QShortcut>
WebTabWidget::WebTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    new QShortcut(QKeySequence("Ctrl+W"), this, SLOT(closeCurrentTab()));
    new QShortcut(QKeySequence::Back, this, SLOT(backCurrentTab()));
    new QShortcut(QKeySequence::Forward, this, SLOT(forwardCurrentTab()));
    new QShortcut(QKeySequence::Refresh, this, SLOT(reloadCurrentTab()));
    new QShortcut(QKeySequence("Ctrl+H"), this, SLOT(previousTab()));
    new QShortcut(QKeySequence("Ctrl+L"), this, SLOT(nextTab()));
    new QShortcut(QKeySequence::AddTab, this, SLOT(newTab()));
    newTab();
}
WebTabWidget::~WebTabWidget() {

}

void WebTabWidget::updateTexts() {
    for (int i = 0; i < this->count(); ++i) {
        setTabText(i, qobject_cast<WebView*>(widget(i))->title());
    }
}

void WebTabWidget::newTab() {
    WebView* webView = new WebView;
    addTab(webView, "Untitled");
    connect(webView, SIGNAL(titleChanged(QString)),
            this, SLOT(updateTexts()));
}

void WebTabWidget::closeTab(int index) {
    if (this->count() <= 1) {
        exit(EXIT_SUCCESS);
    }
    else {
        this->removeTab(index);
    }
}

void WebTabWidget::closeCurrentTab() {
    closeTab(currentIndex());
}

void WebTabWidget::backCurrentTab() {
    qobject_cast<WebView*>(currentWidget())->back();
}
void WebTabWidget::forwardCurrentTab() {
    qobject_cast<WebView*>(currentWidget())->forward();
}

void WebTabWidget::reloadCurrentTab() {
    qobject_cast<WebView*>(currentWidget())->reload();
}

void WebTabWidget::previousTab() {
    this->setCurrentIndex(currentIndex() > 0 ? currentIndex() - 1: 0);
}

void WebTabWidget::nextTab() {
    this->setCurrentIndex((currentIndex() + 1) < count() ? currentIndex() + 1: count() - 1);
}
