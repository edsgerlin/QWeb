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
