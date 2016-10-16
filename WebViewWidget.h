#ifndef WEBVIEWWIDGET_H_
#define WEBVIEWWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>

class WebViewWidget : public QWebEngineView {
Q_OBJECT
    private:
        QString currentAddress;

        bool isWebAddress() const;
        void reload() const;
        void loadWebPage(const QString& url);
        void loadHtmPage(const QString& filePath);
	public:
		WebViewWidget(QWidget* parent);
        ~WebViewWidget();
    public slots:
        void loadPage(const QString& address);
};

#endif
