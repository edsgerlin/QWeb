#include "webview.h"
#include <QApplication>
WebView::WebView(QWidget *parent)
    : QWidget(parent),
      m_layout(new QVBoxLayout),
      m_webEngineView(new QWebEngineView(this)),
      m_lineEdit(new QLineEdit(this)),
      m_title(new QString("Untitled"))
{
    m_layout->setSpacing(0);
    m_layout->setMargin(0);
    m_layout->addWidget(m_lineEdit);
    m_layout->addWidget(m_webEngineView);
    setLayout(m_layout);
    connect(m_lineEdit, SIGNAL(returnPressed()),
            this, SLOT(changeUrl()));
    connect(m_webEngineView, SIGNAL(titleChanged(QString)),
            this, SLOT(changeTitle()));
    connect(m_webEngineView, &QWebEngineView::urlChanged,
            [=](const QUrl& newUrl)
    {
        m_lineEdit->setText(newUrl.toString());
    });
    m_webEngineView->setHtml("<!DOCTYPE html>\n<html>\n\n<head>\n    <title>Help</title>\n</head>\n\n<body>\n    <table>\n        <tr>\n            <th>Key</th>\n            <th>Function</th>\n        </tr>\n        <tr>\n            <th>Control + W</th>\n            <th>Close Tab</th>\n        </tr>\n        <tr>\n            <th>Control + T</th>\n            <th>New Tab</th>\n        </tr>\n        <tr>\n            <th>Control + =</th>\n            <th>Increase Zoom</th>\n        </tr>\n        <tr>\n            <th>Control + -</th>\n            <th>Decrease Zoom</th>\n        </tr>\n        <tr>\n            <th>Control + 0</th>\n            <th>Reset Zoom</th>\n        </tr>\n        <tr>\n            <th>Alt + Left Arrow Key</th>\n            <th>Back</th>\n        </tr>\n        <tr>\n            <th>Alt + Right Arrow Key</th>\n            <th>Forward</th>\n        </tr>\n        <tr>\n            <th>F5</th>\n            <th>Refresh Page</th>\n        </tr>\n        <tr>\n            <th>Control+H</th>\n            <th>Switch to Previous Page</th>\n        </tr>\n        <tr>\n            <th>Control+L</th>\n            <th>Switch to Next Page</th>\n        </tr>\n    </table>\n</body>\n\n</html>");
    resetZoomFactor();
}
void WebView::changeUrl()
{
    QString url = m_lineEdit->text();

    if (!(url.startsWith("http://") || url.startsWith("https://"))) {
        url = "http://" + url;
    }
    m_webEngineView->load(QUrl(url));
}
void WebView::changeTitle()
{
    *this->m_title = m_webEngineView->title();
    emit titleChanged(*this->m_title);
}
QString WebView::title() const {
    return *this->m_title;
}

void WebView::back() {
    this->m_webEngineView->back();
}

void WebView::forward() {
    this->m_webEngineView->forward();
}

void WebView::reload() {
    this->m_webEngineView->reload();
}
void WebView::increaseZoomFactor() {
    this->m_webEngineView->setZoomFactor(qMin(3.00, this->m_webEngineView->zoomFactor() + 0.25));
}

void WebView::decreaseZoomFactor() {
    this->m_webEngineView->setZoomFactor(qMax(0.5, this->m_webEngineView->zoomFactor() - 0.25));
}

void WebView::resetZoomFactor() {
    this->m_webEngineView->setZoomFactor(this->devicePixelRatioF());
}
