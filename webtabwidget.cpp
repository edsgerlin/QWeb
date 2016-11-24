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
    new QShortcut(QKeySequence("Ctrl+0"), this, SLOT(resetZoomFactorForCurrentTab()));
    new QShortcut(QKeySequence("Ctrl+="), this, SLOT(increaseZoomFactorForCurrentTab()));
    new QShortcut(QKeySequence::ZoomOut, this, SLOT(decreaseZoomFactorForCurrentTab()));
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

    this->setCurrentIndex(qMax(0, currentIndex() - 1));
}

void WebTabWidget::nextTab() {
    this->setCurrentIndex(qMin(currentIndex() + 1, count() - 1));
}

void WebTabWidget::increaseZoomFactorForCurrentTab() {
    qobject_cast<WebView*>(currentWidget())->increaseZoomFactor();
}

void WebTabWidget::decreaseZoomFactorForCurrentTab() {
    qobject_cast<WebView*>(currentWidget())->decreaseZoomFactor();
}

void WebTabWidget::resetZoomFactorForCurrentTab() {
    qobject_cast<WebView*>(currentWidget())->resetZoomFactor();
}
