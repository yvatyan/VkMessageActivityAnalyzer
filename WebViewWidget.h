#ifndef WEBVIEWWIDGET_H_
#define WEBVIEWWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QUrl>
#include <QtWebEngineWidgets/QWebEngineView>

class WebViewWidget : public QWebEngineView {
Q_OBJECT
    private:
        QString currentAddress;

        bool isWebAddress() const;
        void reload() const;
        void loadWebPage(const QUrl &url);
        void loadHtmPage(const QString& filePath);
	public:
		WebViewWidget(QWidget* parent);
        ~WebViewWidget();
    public slots:
        void LoadPage(const QString& address);
};

#endif
