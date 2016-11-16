#include "webview.h"

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


}
void WebView::changeUrl()
{
    m_webEngineView->load(QUrl(m_lineEdit->text()));
}
void WebView::changeTitle()
{
    *this->m_title = m_webEngineView->title();
    emit titleChanged(*this->m_title);
}
QString WebView::title() const {
    return *this->m_title;
}
