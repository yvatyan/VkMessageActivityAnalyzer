#ifndef ITEMWIDGETSLAYER_H
#define ITEMWIDGETSLAYER_H

#include "AddressLineEdit.h"
#include "WebViewWidget.h"
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QPoint>

class ItemWidgetsLayer {
    private:
        /**** Main items ****/
        QWidget* backgroundWidget;
        QTabWidget* tabWidget;
        /**** Brower ****/
        QWidget* browserTab;
        WebViewWidget* webPage;
        QPushButton* reloadButton;
        AddressLineEdit* addressLine;
        /**** Transcript ****/
        QWidget* transcriptTab;
        QPlainTextEdit* tanscript;
        /**** Control ****/
        QWidget* controlTab;
        QPushButton* login;
        QPushButton* inputToken;
        QPushButton* loadDatabase;
        QTextEdit* authorArea;

        void init();
    public:
        ItemWidgetsLayer(QWidget* parent, int bg_offset);

        void DistributeLayerContents(const QSize& layer_new_size, const QPoint& layer_new_offset);
};

#endif // ITEMWIDGETSLAYER_H
