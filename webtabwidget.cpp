#include "webtabwidget.h"
#include "webview.h"
WebTabWidget::WebTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    setTabsClosable(true);
    WebView* webView = new WebView;
    addTab(webView, "Untitled");
    connect(webView, SIGNAL(titleChanged(QString)),
            this, SLOT(updateTexts()));

}
WebTabWidget::~WebTabWidget() {

}

void WebTabWidget::updateTexts() {
    for (int i = 0; i < this->count(); ++i) {
        setTabText(i, qobject_cast<WebView*>(widget(i))->title());
    }
}
