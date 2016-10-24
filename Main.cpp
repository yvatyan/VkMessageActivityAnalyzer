#include "VkMessageAnalyzer.h"
#include <QApplication>

#pragma comment(lib, "Qt5WebEngineWidgetsd.lib")

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    VkMessageAnalyzer w(QPoint(100, 100), QSize(700, 500));
    w.show();
    return a.exec();
}
