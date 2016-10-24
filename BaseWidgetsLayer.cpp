#include "BaseWidgetsLayer.h"
#include <QPalette>
#include <QPainter>

void BaseWidgetsLayer::init(QMainWindow* main_class) {

    if (main_class->objectName().isEmpty()) {
        main_class->setObjectName(QStringLiteral("VkMessageAnalyzer"));
    }
    main_class->setMouseTracking(true);
    main_class->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main_class->setAttribute(Qt::WA_NoSystemBackground);
    //main_class->setAttribute(Qt::WA_TranslucentBackground);
    main_class->setAttribute(Qt::WA_PaintOnScreen);

    centralWidget = new QtWidget(main_class);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    centralWidget->setAutoFillBackground(false);
#ifdef SHOW_WIDGETS_LAYOUT
    centralWidget->setPalette(QPalette(Qt::blue));
#endif
    main_class->setCentralWidget(centralWidget);
}

BaseWidgetsLayer::BaseWidgetsLayer(QMainWindow* main_class, QPoint initial_point, QSize initial_size) {
    init(main_class);
}
void BaseWidgetsLayer::DistributeLayerContents(const WindowParameters winParams) {
    int height = winParams.windowSize.height();
    int width = winParams.windowSize.width();
    int offsetX = winParams.windowUpperCorner.x();
    int offsetY = winParams.windowUpperCorner.y();
	
    QWidget* widget = this->centralWidget->parentWidget();
    widget->setGeometry(offsetX, offsetY, width, height);
}
QWidget* BaseWidgetsLayer::GetCentralWidget() const {
    return centralWidget;
}
