#ifndef ADDRESSLINEWIDGET_H
#define ADDRESSLINEWIDGET_H

#include "WebViewWidget.h"
#include <QTextEdit>
#include <QRegExp>
#include <QKeyEvent>

class AddressLineEdit : public QTextEdit {
Q_OBJECT
    private:
        QRegExp safeAddressRegExp;
        QRegExp trueAddressRegExp;

        bool isSafe();
        bool isCorrect();
    signals:
        void inputFinished(const QString& address);
    private slots:
        void setUrl(const QUrl& url);
    public slots:
        void decorateText();
    public:
        AddressLineEdit(QWidget* parent);
        void connectToWebView(const WebViewWidget* webView);
    protected:
        virtual void keyPressEvent(QKeyEvent* event);
};

#endif // ADDRESSLINEWIDGET_H
