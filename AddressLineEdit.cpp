#include "AddressLineEdit.h"

bool AddressLineEdit::isSafe() {
    if(safeAddressRegExp.indexIn(toPlainText()) != 0) {
        return false;
    }
    return true;
}
bool AddressLineEdit::isCorrect() {
    if(trueAddressRegExp.indexIn(toPlainText()) != 0) {
        return false;
    }
    return true;
}
void AddressLineEdit::decorateText() {
    static bool called = false;
    if(called) {
        called = false;
        return;
    }

    int pos = textCursor().position();
    if(!isCorrect()) {
        called = true;
        setText(QString("<font color=\"red\">") + toPlainText() + QString("</font>"));
    }
    else {
        if(isSafe()) {
            called = true;
            setText(QString("<font color=\"green\">https</font>") + toPlainText().mid(5));
        }
        else {
            called = true;
            setText(QString("<font color=\"black\">") + toPlainText() + QString("</font>"));
        }
    }
    QTextCursor cursor(textCursor());
    cursor.setPosition(pos);
    setTextCursor(cursor);
}
AddressLineEdit::AddressLineEdit(QWidget* parent)
    : QTextEdit(parent)
    , safeAddressRegExp("https")
    , trueAddressRegExp("https://|http://|file://")
{
    setInputMethodHints(Qt::ImhUrlCharactersOnly);
    QObject::connect(this, SIGNAL(textChanged()), SLOT(decorateText()));
}
void AddressLineEdit::connectToWebView(const WebViewWidget* webView) {
    QObject::connect(this, SIGNAL(inputFinished(const QString&)), webView, SLOT(loadPage(const QString&)));
    QObject::connect(webView, SIGNAL(urlChanged(const QUrl&)), this, SLOT(setUrl(const QUrl&)));
}
void AddressLineEdit::setUrl(const QUrl& url) {
    setText(url.toString());
}
void AddressLineEdit::keyPressEvent(QKeyEvent* event) {
    if(event->key() == Qt::Key_Return) {
        if(isCorrect()) {
            emit inputFinished(toPlainText());
        }
    }
    else {
        QTextEdit::keyPressEvent(event);
    }
}
