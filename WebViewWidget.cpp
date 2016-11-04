#include "WebViewWidget.h"
#include "Utilities.h"

void WebViewWidget::reload() const {

}
void WebViewWidget::loadWebPage(const QUrl& url) {
    Logger::instance() << Logger::UserLevel << "Loading " << url.toString() << Logger::Endl;
    load(url);
}
void WebViewWidget::loadHtmPage(const QString& filePath) {

}
WebViewWidget::WebViewWidget(QWidget* parent)
	: QWebEngineView(parent)
{
    this->loadWebPage(QUrl("google.ru"));
}
WebViewWidget::~WebViewWidget(){
}
void WebViewWidget::LoadPage(const QString &address) {
    loadWebPage(address);
}
