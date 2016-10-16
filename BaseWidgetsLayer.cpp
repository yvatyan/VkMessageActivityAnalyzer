#include "BaseWidgetsLayer.h"
#include <QPalette>
#include <QPainter>

void BaseWidgetsLayer::init(QMainWindow* main_class) {

    if (main_class->objectName().isEmpty()) {
        main_class->setObjectName(QStringLiteral("VkMessageAnalyzerClass"));
    }
    main_class->setMouseTracking(true);

    centralWidget = new WidgetsWithCustomizedEventHandlers(main_class);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    centralWidget->setMouseTracking(true);
    centralWidget->setFocusPolicy(Qt::NoFocus);
#ifdef SHOW_WIDGETS_LAYOUT
    centralWidget->setPalette(QPalette(Qt::blue));
#endif
    main_class->setCentralWidget(centralWidget);
}

BaseWidgetsLayer::BaseWidgetsLayer(QMainWindow* main_class, QSize initial_size) {
    init(main_class);
    DistributeLayerContents(initial_size, INITIAL_POINT);
}
void BaseWidgetsLayer::DistributeLayerContents(const QSize& layer_new_size,
                                               const QPoint& layer_new_offset) {
    int height = layer_new_size.height();
    int width = layer_new_size.width();
    int offsetX = layer_new_offset.x();
    int offsetY = layer_new_offset.y();

    QWidget* widget = this->centralWidget->parentWidget();
    widget->setGeometry(offsetX, offsetY, width, height);
    widget = this->centralWidget;
    widget->setGeometry(offsetX, offsetY, width, height);
}
QWidget* BaseWidgetsLayer::GetCentralWidget() const {
    return centralWidget;
}
