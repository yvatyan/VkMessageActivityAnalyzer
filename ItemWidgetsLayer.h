#ifndef ITEMWIDGETSLAYER_H
#define ITEMWIDGETSLAYER_H

#define SHOW_WIDGETS_LAYOUT

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
        QWidget* browserTab;
        WebViewWidget* webPage;
        QPushButton* reloadButton;
        AddressLineEdit* addressLine;
        /**** Transcript ****/
        QWidget* transcriptTab;
        QPlainTextEdit* transcript;
        /**** Control ****/
        QWidget* controlTab;
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
};

#endif // ITEMWIDGETSLAYER_H
