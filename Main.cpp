#include "VkMessageAnalyzer.h"
#include <QApplication>

#pragma comment(lib, "Qt5WebEngineWidgetsd.lib")

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    //a.setStyle("fusion");

    VkMessageAnalyzer w(QPoint(100, 100), QSize(700, 500));
/*
    QObject::connect(w.GetQuitButton(), SIGNAL(clicked()), &a, SLOT(quit()));
    QObject::connect(w.GetMaximizeButton(), SIGNAL(clicked()), &w, SLOT(MaximizeApplication()));*/

    w.show();
    return a.exec();
}
