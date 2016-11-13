#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T01:49:33
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VkMessageAnalyzer_2
TEMPLATE = app


SOURCES += \
    Main.cpp \
    AddressLineEdit.cpp \
    BaseWidgetsLayer.cpp \
    ControlWidgetsLayer.cpp \
    ItemWidgetsLayer.cpp \
    VkMessageAnalyzer.cpp \
    VkMessageAnalyzerCore.cpp \
    VkMessageAnalyzerGui.cpp \
    WebViewWidget.cpp \
    VkAccount.cpp \
    TcpSecureConnector.cpp

HEADERS  += \
    BaseWidgetsLayer.h \
    ControlWidgetsLayer.h \
    ItemWidgetsLayer.h \
    VkMessageAnalyzer.h \
    VkMessageAnalyzerCore.h \
    VkMessageAnalyzerGui.h \
    AddressLineEdit.h \
    WebViewWidget.h \
    Utilities.h \
    QtWidget.h \
    StretchBordersCollection.h \
    DisplaceBordersCollection.h \
    VkAccount.h \
    VkSettings.h \
    TcpSecureConnector.h

DISTFILES += \
	TODO

win32:LIBS += -luser32
