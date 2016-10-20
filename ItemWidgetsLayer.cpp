#include "ItemWidgetsLayer.h"
#include <QApplication>

/*
class ItemWidgetsLayer {
    private:
        **** Main items ****
        QWidget* backgroundWidget;
        QTabWidget* tabWidget;
        **** Brower ****
        QWidget* browserTab;
        WebViewWidget* webPage;
        QPushButton* reloadButton;
        AddressLineEdit* addressLine;
        **** Transcript ****
        QWidget* transcriptTab;
        QPlainTextEdit* tanscript;
        **** Control ****
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
*/
void ItemWidgetsLayer::init(QWidget* parent) {

    backgroundWidget = new QtWidget(parent);
    backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));

    frame = new QFrame(parent);
    frame->setObjectName(QStringLiteral("backgroundFrame"));
    frame->setEnabled(false);
    frame->setMouseTracking(true);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Sunken);
    frame->setAttribute(Qt::WA_TransparentForMouseEvents);

    tabWidget = new QTabWidget(backgroundWidget);
    tabWidget->setObjectName(QStringLiteral("tabWidget"));
    tabWidget->setMouseTracking(true);
    tabWidget->setTabPosition(QTabWidget::North);
    tabWidget->setTabShape(QTabWidget::Rounded);
    tabWidget->setIconSize(QSize(16, 16));
    tabWidget->setElideMode(Qt::ElideNone);

    browserTab = new QWidget();
    browserTab->setObjectName(QStringLiteral("browserTab"));
    browserTab->setMouseTracking(true);
    webPage = new WebViewWidget(browserTab);
    webPage->setObjectName(QStringLiteral("webPage"));
    reloadButton = new QPushButton(browserTab);
    reloadButton->setObjectName(QStringLiteral("reloadButton"));
    addressLine = new AddressLineEdit(browserTab);
    addressLine->setObjectName(QStringLiteral("addressLine"));
    addressLine->setUndoRedoEnabled(false);
    tabWidget->addTab(browserTab, QString());
    tabWidget->setTabText(tabWidget->indexOf(browserTab), QApplication::translate("VkMessageAnalyzer", "Browser", 0));

    transcriptTab = new QWidget();
    transcriptTab->setObjectName(QStringLiteral("transcriptTab"));
    transcriptTab->setMouseTracking(true);
    transcript = new QPlainTextEdit(transcriptTab);
    transcript->setObjectName(QStringLiteral("tanscript"));
    tabWidget->addTab(transcriptTab, QString());
    tabWidget->setTabText(tabWidget->indexOf(transcriptTab), QApplication::translate("VkMessageAnalyzer", "Transcript", 0));

    controlTab = new QWidget();
    controlTab->setObjectName(QStringLiteral("controlTab"));
    controlTab->setMouseTracking(true);
    loginButton = new QPushButton(controlTab);
    loginButton->setObjectName(QStringLiteral("login"));
    inputTokenButton = new QPushButton(controlTab);
    inputTokenButton->setObjectName(QStringLiteral("inputToken"));
    loadDatabaseButton = new QPushButton(controlTab);
    loadDatabaseButton->setObjectName(QStringLiteral("loadDatabase"));
    authorArea = new QTextEdit(controlTab);
    authorArea->setObjectName(QStringLiteral("authorArea"));
    tabWidget->addTab(controlTab, QString());
    tabWidget->setTabText(tabWidget->indexOf(controlTab), QApplication::translate("VkMessageAnalyzer", "Browser", 0));


#ifdef SHOW_WIDGETS_LAYOUT
    frame->setPalette(QPalette(QPalette::Background, Qt::darkRed));
    backgroundWidget->setPalette(QPalette(QPalette::Background, Qt::darkYellow));
#endif
}
ItemWidgetsLayer::ItemWidgetsLayer(QWidget* parent, int bg_offset) {
    bgOffset = bg_offset;
    init(parent);
}
void ItemWidgetsLayer::DistributeLayerContents(const WindowParameters winParams) {
    int height = winParams.windowSize.height();
    int width = winParams.windowSize.width();
    int addresslineHeight = 25;
    int addressLineVerOffset = 5;
    int resizeButtonHorOffset = 3;
    int transcriptVerOffset = 10;
    int transcriptHorOffset = 2;
    int controlTabButtonsHeight = 45;
    int controlTabButtonsWidth = 150;
    int controlTabButtonsOffset = 15;
    int authorAreaHeight = 300;
    int authorAreaWidth = 200;
    int authorAreaRightOffset = 10;

    QWidget* widget = frame;
    widget->setGeometry(bgOffset, bgOffset, width - 2*bgOffset, height - 2*bgOffset);

    widget = backgroundWidget;
    widget->setGeometry(bgOffset + 1, bgOffset + 1, width - 2*bgOffset - 1, height - 2*bgOffset - 1);

    widget = tabWidget;
    widget->setGeometry(0, 0, width - 2*bgOffset, height - 2*bgOffset);

    widget = webPage;
    widget->setGeometry(2, 2, width - 2*bgOffset - 4, height - 2*bgOffset - 4);

    widget = reloadButton;
    reloadButton->setGeometry(width/2 - addresslineHeight - resizeButtonHorOffset,
                              addressLineVerOffset,
                              addresslineHeight,
                              addresslineHeight);

    widget = addressLine;
    addressLine->setGeometry(width/2, addressLineVerOffset, width/2 - bgOffset, addresslineHeight);

    widget = transcript;
    transcript->setGeometry(transcriptHorOffset,
                            transcriptVerOffset,
                            width - 2*bgOffset - 2*transcriptHorOffset,
                            height - transcriptVerOffset);

    widget = loginButton;
    loginButton->setGeometry(width/2 - bgOffset - controlTabButtonsWidth/2,
                             height/3,
                             controlTabButtonsWidth,
                             controlTabButtonsHeight);

    widget = inputTokenButton;
    inputTokenButton->setGeometry(width/2 - bgOffset - controlTabButtonsWidth/2,
                                  height/3 + (controlTabButtonsHeight + controlTabButtonsOffset),
                                  controlTabButtonsWidth,
                                  controlTabButtonsHeight);

    widget = loadDatabaseButton;
    loadDatabaseButton->setGeometry(width/2 - bgOffset - controlTabButtonsWidth/2,
                                    height/3 + 2*(controlTabButtonsHeight + controlTabButtonsOffset),
                                    controlTabButtonsWidth,
                                    controlTabButtonsHeight);

    widget = authorArea;
    authorArea->setGeometry(width - 2*bgOffset - authorAreaRightOffset - authorAreaWidth,
                            5,
                            authorAreaWidth,
                            authorAreaHeight);
}
