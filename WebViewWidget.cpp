#include "WebViewWidget.h"
#include <QtWebEngineWidgets/QWebEngineHistory>

void WebViewWidget::reload() const {

}
void WebViewWidget::loadWebPage(const QUrl& url) {
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
    history()->clear();
}
void WebViewWidget::LoadPage(const QString &address) {
    loadWebPage(address);
}
