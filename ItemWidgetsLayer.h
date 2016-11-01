#ifndef ITEMWIDGETSLAYER_H
#define ITEMWIDGETSLAYER_H

#undef SHOW_WIDGETS_LAYOUT

#include "AddressLineEdit.h"
#include "WebViewWidget.h"
#include "Utilities.h"
#include "QtWidget.h"
#include <QPalette>
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QPoint>

class ItemWidgetsLayer {
    private:
        /**** Main items ****/
        QtWidget* backgroundWidget;
        QTabWidget* tabWidget;
        QFrame* frame;
        /**** Brower ****/
        QtWidget* browserTab;
        WebViewWidget* webPage;
        QPushButton* reloadButton;
        AddressLineEdit* addressLine;
        /**** Transcript ****/
        QtWidget* transcriptTab;
        QPlainTextEdit* transcript;
        /**** Control ****/
        QtWidget* controlTab;
        QPushButton* loginButton;
        QPushButton* inputTokenButton;
        QPushButton* loadDatabaseButton;
        QTextEdit* authorArea;
        /**** Parameters ****/
        int bgOffset;

        void init(QWidget *parent);
    public:
        ItemWidgetsLayer(QWidget* parent, int bg_offset);

        void DistributeLayerContents(const WindowParameters winParams);
        void SwitchTab(short tabNum);
        WebViewWidget* Browser();
        QPushButton* LogInButton();
        QPushButton* TokenButton();
        QPushButton* DatabaseButton();

};

#endif // ITEMWIDGETSLAYER_H
