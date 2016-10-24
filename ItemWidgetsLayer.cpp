#include "ItemWidgetsLayer.h"
#include <QApplication>

void ItemWidgetsLayer::init(QWidget* parent) {

    QString buttonTranspStyleSheet(
    "QPushButton\
    {\
        background: transparent;\
        border: 0px;\
    }\
    QPushButton:hover:!pressed\
    {\
      border: 1px solid black;\
      border-radius: 4px 4px 4px 4px;\
    }\
    QPushButton:pressed\
    {\
      border: 1px solid black;\
      border-radius: 4px 4px 4px 4px;\
      background: #a0a0ff;\
    }");
    QString controlButtonsStyleSheet(
    "QPushButton\
    {\
        background: #545490;\
        border: 1px solid #000040;\
    }\
    QPushButton:hover:!pressed\
    {\
      border: 3px solid #000040;\
      border-radius: 4px 4px 4px 4px;\
    }\
    QPushButton:pressed\
    {\
      border: 1px solid #000040;\
      border-radius: 2px 2px 2px 2px;\
      background: #a0a0ff;\
    }");


    backgroundWidget = new QtWidget(parent);
    backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
    backgroundWidget->setPalette(QPalette(QPalette::Background, QColor(0, 0, 64)));

    frame = new QFrame(parent);
    frame->setObjectName(QStringLiteral("backgroundFrame"));
    frame->setEnabled(false);
    frame->setMouseTracking(true);
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Plain);
    frame->setAttribute(Qt::WA_TransparentForMouseEvents);
    frame->setPalette(QPalette(QPalette::Background, QColor(0, 0, 255)));

    tabWidget = new QTabWidget(backgroundWidget);
    tabWidget->setObjectName(QStringLiteral("tabWidget"));
    tabWidget->setMouseTracking(true);
    tabWidget->setTabPosition(QTabWidget::North);
    tabWidget->setTabShape(QTabWidget::Rounded);
    tabWidget->setIconSize(QSize(16, 16));
    tabWidget->setElideMode(Qt::ElideNone);
    tabWidget->setStyleSheet(
    "QTabBar::tab:first {\
        border: 1px solid #000040;\
        border-bottom-color: #000000;\
        border-top-left-radius: 4px;\
        border-top-right-radius: 4px;\
        height: 26px;\
        width: 80px;\
        margin-left: 2px;\
        background-color: #545490;\
        border-bottom-style: solid;\
    }\
    QTabBar::tab {\
        border: 1px solid #000040;\
        border-bottom-color: #000000;\
        border-top-left-radius: 4px;\
        border-top-right-radius: 4px;\
        height: 26px;\
        width: 80px;\
        font-weight:900;\
        background-color: #545490;\
        border-bottom-style: solid;\
    }\
    QTabBar::tab:selected {\
        border: 1px solid #ccccff;\
        background-color: #a0a0ff;\
        border-bottom-color: #a0a0ff;\
    }\
    QTabWidget::pane {\
        border-top-color: #000000;\
        border-style: none;\
    }\
    ");
    // height = buttonHeight{24} - (tabWidgetTopOffset{3} + borderWidth{1}) + extraSelfHeight{6}

    browserTab = new QtWidget();
    browserTab->setObjectName(QStringLiteral("browserTab"));
    browserTab->setPalette(QPalette(QPalette::Background, QColor(0xA0, 0xA0, 0xFF)));
    browserTab->setMouseTracking(true);
    webPage = new WebViewWidget(browserTab);
    webPage->setObjectName(QStringLiteral("webPage"));

    reloadButton = new QPushButton(browserTab);
    reloadButton->setObjectName(QStringLiteral("reloadButton"));
    reloadButton->setMouseTracking(true);
    QPixmap buttonTexture;
    buttonTexture = QPixmap("D:\\BinaryMind\\Documents\\QtProjects\\VkMessageAnalyzer_2\\reload.png");
    QIcon ic(buttonTexture);
    reloadButton->setIcon(ic);
    reloadButton->setIconSize(buttonTexture.size());
    reloadButton->setStyleSheet(buttonTranspStyleSheet);

    addressLine = new AddressLineEdit(browserTab);
    addressLine->setObjectName(QStringLiteral("addressLine"));
    addressLine->setUndoRedoEnabled(false);
    tabWidget->addTab(browserTab, QString());
    tabWidget->setTabText(tabWidget->indexOf(browserTab), QApplication::translate("VkMessageAnalyzer", "Browser", 0));

    transcriptTab = new QtWidget();
    transcriptTab->setObjectName(QStringLiteral("transcriptTab"));
    transcriptTab->setPalette(QPalette(QPalette::Background, QColor(0xA0, 0xA0, 0xFF)));
    transcriptTab->setMouseTracking(true);
    transcript = new QPlainTextEdit(transcriptTab);
    transcript->setObjectName(QStringLiteral("tanscript"));
    tabWidget->addTab(transcriptTab, QString());
    tabWidget->setTabText(tabWidget->indexOf(transcriptTab), QApplication::translate("VkMessageAnalyzer", "Transcript", 0));

    controlTab = new QtWidget();
    controlTab->setObjectName(QStringLiteral("controlTab"));
    controlTab->setPalette(QPalette(QPalette::Background, QColor(0xA0, 0xA0, 0xFF)));
    controlTab->setMouseTracking(true);
    loginButton = new QPushButton(controlTab);
    loginButton->setObjectName(QStringLiteral("login"));
    loginButton->setText("Login");
    loginButton->setFont(QFont("Times New Roman", 16, QFont::Normal));
    loginButton->setStyleSheet(controlButtonsStyleSheet);
    inputTokenButton = new QPushButton(controlTab);
    inputTokenButton->setObjectName(QStringLiteral("inputToken"));
    inputTokenButton->setText("Enter token");
    inputTokenButton->setFont(QFont("Times New Roman", 16, QFont::Normal));
    inputTokenButton->setStyleSheet(controlButtonsStyleSheet);
    loadDatabaseButton = new QPushButton(controlTab);
    loadDatabaseButton->setObjectName(QStringLiteral("loadDatabase"));
    loadDatabaseButton->setText("Load database");
    loadDatabaseButton->setFont(QFont("Times New Roman", 16, QFont::Normal));
    loadDatabaseButton->setStyleSheet(controlButtonsStyleSheet);
    authorArea = new QTextEdit(controlTab);
    authorArea->setObjectName(QStringLiteral("authorArea"));
    authorArea->setStyleSheet("\
        border: 1px;\
        border-radius: 5px 5px 5px 5px;\
        background: #c0c0ff;\
    ");
    tabWidget->addTab(controlTab, QString());
    tabWidget->setTabText(tabWidget->indexOf(controlTab), QApplication::translate("VkMessageAnalyzer", "Control", 0));


#ifdef SHOW_WIDGETS_LAYOUT
    frame->setPalette(QPalette(QPalette::Background, Qt::darkRed));
    backgroundWidget->setPalette(QPalette(QPalette::Background, Qt::darkYellow));
#endif
}
ItemWidgetsLayer::ItemWidgetsLayer(QWidget* parent, int bg_offset) {
    bgOffset = bg_offset;
    init(parent);
    addressLine->connectToWebView(webPage);
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
    int authorAreaHeight = 100;
    int authorAreaWidth = 200;
    int authorAreaRightOffset = 10;
    int frameWidth = 1;

    QWidget* widget = frame;
    widget->setGeometry(bgOffset, bgOffset, width - 2*bgOffset, height - 2*bgOffset);

    widget = backgroundWidget;
    widget->setGeometry(bgOffset + 1, bgOffset + 1, width - 2*bgOffset - 1, height - 2*bgOffset - 1);

    widget = tabWidget;
    widget->setGeometry(0, 3, width - 2*bgOffset, height - 2*bgOffset);

    widget = webPage;
    widget->setGeometry(2, 2, width - 2*bgOffset - 6, height - 2*bgOffset - 4);

    widget = reloadButton;
    reloadButton->setGeometry(width/2 - addresslineHeight - resizeButtonHorOffset,
                              addressLineVerOffset,
                              addresslineHeight,
                              addresslineHeight);

    widget = addressLine;
    addressLine->setGeometry(width/2, addressLineVerOffset, width/2 - bgOffset - 10, addresslineHeight);

    widget = transcript;
    transcript->setGeometry(transcriptHorOffset,
                            transcriptVerOffset,
                            width - 2*bgOffset - 2*transcriptHorOffset - 2*frameWidth,
                            height - 2*transcriptVerOffset);

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
