/********************************************************************************
** Form generated from reading UI file 'VkMessageAnalyzer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VKMESSAGEANALYZER_H
#define UI_VKMESSAGEANALYZER_H

#include <AddressLineEdit.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "centralwidget.h"
#include "webviewwidget.h"

QT_BEGIN_NAMESPACE

class Ui_VkMessageAnalyzerClass
{
public:
    CentralWidget *centralWidget;
    QWidget *backgroundWidget;
    QPushButton *quitButton;
    QPushButton *fullScreenButton;
    QPushButton *maximizeButton;
    QPushButton *minimizeButton;
    QTabWidget *tabWidget;
    QWidget *browserTab;
    WebViewWidget *webPage;
    QPushButton *reloadButton;
    AddressLineEdit *addressLine;
    QWidget *transcriptTab;
    QPlainTextEdit *tanscript;
    QWidget *controlTab;
    QPushButton *login;
    QPushButton *inputToken;
    QPushButton *loadDatabase;
    QTextEdit *authorArea;
    QFrame *frame;

    void setupUi(QMainWindow *VkMessageAnalyzerClass)
    {
        if (VkMessageAnalyzerClass->objectName().isEmpty())
            VkMessageAnalyzerClass->setObjectName(QStringLiteral("VkMessageAnalyzerClass"));
        VkMessageAnalyzerClass->resize(600, 450);
        VkMessageAnalyzerClass->setMouseTracking(true);
        centralWidget = new CentralWidget(VkMessageAnalyzerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(true);
        centralWidget->setFocusPolicy(Qt::NoFocus);



        backgroundWidget = new QWidget(centralWidget);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        backgroundWidget->setGeometry(QRect(5, 5, 590, 440));
        backgroundWidget->setMouseTracking(true);

        quitButton = new QPushButton(backgroundWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(559, 1, 30, 20));
        quitButton->setMouseTracking(true);
        quitButton->setToolTipDuration(5);
        fullScreenButton = new QPushButton(backgroundWidget);
        fullScreenButton->setObjectName(QStringLiteral("fullScreenButton"));
        fullScreenButton->setGeometry(QRect(529, 1, 30, 20));
        fullScreenButton->setMouseTracking(true);
        fullScreenButton->setToolTipDuration(5);
        maximizeButton = new QPushButton(backgroundWidget);
        maximizeButton->setObjectName(QStringLiteral("maximizeButton"));
        maximizeButton->setGeometry(QRect(499, 1, 30, 20));
        maximizeButton->setMouseTracking(true);
        maximizeButton->setToolTipDuration(5);
        minimizeButton = new QPushButton(backgroundWidget);
        minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
        minimizeButton->setGeometry(QRect(469, 1, 30, 20));
        minimizeButton->setMouseTracking(true);
        minimizeButton->setToolTipDuration(5);
        tabWidget = new QTabWidget(backgroundWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(1, 1, 588, 440));
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
        webPage->setGeometry(QRect(0, 23, 582, 391));
        reloadButton = new QPushButton(browserTab);
        reloadButton->setObjectName(QStringLiteral("reloadButton"));
        reloadButton->setGeometry(QRect(250, 1, 25, 25));
        addressLine = new AddressLineEdit(browserTab);
        addressLine->setObjectName(QStringLiteral("addressLine"));
        addressLine->setGeometry(QRect(280, 0, 301, 25));
        addressLine->setInputMethodHints(Qt::ImhUrlCharactersOnly);
        addressLine->setUndoRedoEnabled(false);
        tabWidget->addTab(browserTab, QString());
        transcriptTab = new QWidget();
        transcriptTab->setObjectName(QStringLiteral("transcriptTab"));
        transcriptTab->setMouseTracking(true);
        tanscript = new QPlainTextEdit(transcriptTab);
        tanscript->setObjectName(QStringLiteral("tanscript"));
        tanscript->setGeometry(QRect(0, 0, 582, 414));
        tabWidget->addTab(transcriptTab, QString());
        controlTab = new QWidget();
        controlTab->setObjectName(QStringLiteral("controlTab"));
        controlTab->setMouseTracking(true);
        login = new QPushButton(controlTab);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(216, 123, 150, 50));
        QFont font;
        font.setFamily(QStringLiteral("MS Sans Serif"));
        font.setPointSize(14);
        login->setFont(font);
        inputToken = new QPushButton(controlTab);
        inputToken->setObjectName(QStringLiteral("inputToken"));
        inputToken->setGeometry(QRect(216, 182, 150, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Sans Serif"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        inputToken->setFont(font1);
        loadDatabase = new QPushButton(controlTab);
        loadDatabase->setObjectName(QStringLiteral("loadDatabase"));
        loadDatabase->setGeometry(QRect(216, 242, 150, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Sans Serif"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        loadDatabase->setFont(font2);
        authorArea = new QTextEdit(controlTab);
        authorArea->setObjectName(QStringLiteral("authorArea"));
        authorArea->setGeometry(QRect(400, 10, 171, 141));
        tabWidget->addTab(controlTab, QString());
        frame = new QFrame(backgroundWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(false);
        frame->setGeometry(QRect(0, 0, 590, 440));
        frame->setMouseTracking(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->raise();
        tabWidget->raise();
        fullScreenButton->raise();
        maximizeButton->raise();
        minimizeButton->raise();
        quitButton->raise();
        VkMessageAnalyzerClass->setCentralWidget(centralWidget);

        retranslateUi(VkMessageAnalyzerClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(VkMessageAnalyzerClass);
    } // setupUi

    void retranslateUi(QMainWindow *VkMessageAnalyzerClass)
    {
        VkMessageAnalyzerClass->setWindowTitle(QApplication::translate("VkMessageAnalyzerClass", "VkMessageAnalyzer", 0));
#ifndef QT_NO_TOOLTIP
        quitButton->setToolTip(QApplication::translate("VkMessageAnalyzerClass", "Close", 0));
#endif // QT_NO_TOOLTIP
        quitButton->setText(QApplication::translate("VkMessageAnalyzerClass", "X", 0));
#ifndef QT_NO_TOOLTIP
        fullScreenButton->setToolTip(QApplication::translate("VkMessageAnalyzerClass", "Fullscreen", 0));
#endif // QT_NO_TOOLTIP
        fullScreenButton->setText(QApplication::translate("VkMessageAnalyzerClass", "X", 0));
#ifndef QT_NO_TOOLTIP
        maximizeButton->setToolTip(QApplication::translate("VkMessageAnalyzerClass", "Maximize", 0));
#endif // QT_NO_TOOLTIP
        maximizeButton->setText(QApplication::translate("VkMessageAnalyzerClass", "X", 0));
#ifndef QT_NO_TOOLTIP
        minimizeButton->setToolTip(QApplication::translate("VkMessageAnalyzerClass", "Minimize", 0));
#endif // QT_NO_TOOLTIP
        minimizeButton->setText(QApplication::translate("VkMessageAnalyzerClass", "X", 0));
        reloadButton->setText(QApplication::translate("VkMessageAnalyzerClass", "O", 0));
        tabWidget->setTabText(tabWidget->indexOf(browserTab), QApplication::translate("VkMessageAnalyzerClass", "Browser", 0));
        tabWidget->setTabText(tabWidget->indexOf(transcriptTab), QApplication::translate("VkMessageAnalyzerClass", "Transcript", 0));
        login->setText(QApplication::translate("VkMessageAnalyzerClass", "Log In Vk", 0));
        inputToken->setText(QApplication::translate("VkMessageAnalyzerClass", "Enter Token", 0));
        loadDatabase->setText(QApplication::translate("VkMessageAnalyzerClass", "Open Database", 0));
        tabWidget->setTabText(tabWidget->indexOf(controlTab), QApplication::translate("VkMessageAnalyzerClass", "Control", 0));
    } // retranslateUi

};

namespace Ui {
    class VkMessageAnalyzerClass: public Ui_VkMessageAnalyzerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VKMESSAGEANALYZER_H
