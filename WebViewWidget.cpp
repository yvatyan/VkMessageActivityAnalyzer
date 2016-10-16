#include "WebViewWidget.h"
#include <QDebug>
void WebViewWidget::reload() const {

}
void WebViewWidget::loadWebPage(const QString& url) {
    qDebug() << url;
    load(url);
}
void WebViewWidget::loadHtmPage(const QString& filePath) {

}
WebViewWidget::WebViewWidget(QWidget* parent)
	: QWebEngineView(parent)
{
    this->load(QUrl("google.ru"));
}
WebViewWidget::~WebViewWidget(){
}
void WebViewWidget::loadPage(const QString& address) {
    loadWebPage(address);
}
