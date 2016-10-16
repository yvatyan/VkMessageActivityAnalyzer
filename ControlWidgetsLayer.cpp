#include "ControlWidgetsLayer.h"
#include <QPalette>
#include <QBrush>
#include <QDebug>

void ControlWidgetsLayer::init(QWidget* parent) {
    quitButton = new QPushButton(parent);
    quitButton->setObjectName(QStringLiteral("quitButton"));
    quitButton->setMouseTracking(true);

    fullScreenButton = new QPushButton(parent);
    fullScreenButton->setObjectName(QStringLiteral("fullScreenButton"));
    fullScreenButton->setMouseTracking(true);

    maximizeButton = new QPushButton(parent);
    maximizeButton->setObjectName(QStringLiteral("maximizeButton"));
    maximizeButton->setMouseTracking(true);

    minimizeButton = new QPushButton(parent);
    minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
    minimizeButton->setMouseTracking(true);

#ifdef SHOW_WIDGETS_LAYOUT
    QPalette palette = quitButton->palette();
    palette.setColor( QPalette::Button, Qt::green);

    quitButton->setAutoFillBackground(true);
    quitButton->setPalette(palette);
    quitButton->setFlat(true);

    fullScreenButton->setAutoFillBackground(true);
    fullScreenButton->setPalette(palette);
    fullScreenButton->setFlat(true);

    maximizeButton->setAutoFillBackground(true);
    maximizeButton->setPalette(palette);
    maximizeButton->setFlat(true);

    minimizeButton->setAutoFillBackground(true);
    minimizeButton->setPalette(palette);
    minimizeButton->setFlat(true);
#endif
}

ControlWidgetsLayer::ControlWidgetsLayer(QWidget* parent,
                                         QSize initial_size,
                                         BorderSize rs_border,
                                         int move_border_height)
    : border(rs_border)
{
    init(parent);
    ResizeWidgetsCollection::GetInstance().SetMainWindow(parent->parentWidget());
    WindowParameters winParams;
    winParams.windowSize = initial_size;
    winParams.windowUpperCorner = QPoint(0, 0);
    ResizeWidgetsCollection::GetInstance().Configure(winParams, rs_border);
    moveBorderHeight = move_border_height;
    DistributeLayerContents(initial_size, QPoint(0, 0));
}
ControlWidgetsLayer::~ControlWidgetsLayer() {
}
void ControlWidgetsLayer::DistributeLayerContents(const QSize& layer_new_size,
                                                  const QPoint& layer_new_offset) {
    int height = layer_new_size.height();
    int width = layer_new_size.width();
    int offsetX = layer_new_offset.x();
    int offsetY = layer_new_offset.y();
    int buttonWidth = 35;
    int buttonHeight = 25;
    int buttonUpperOffset = 10;
    int buttonRightOffset = 10;
    int buttonInterOffset = 2;

    QWidget* widget = this->quitButton;
    widget->setGeometry(offsetX + width - buttonWidth - border.TotalWidth() - buttonRightOffset,
                        offsetY + border.TotalWidth() + buttonUpperOffset,
                        buttonWidth,
                        buttonHeight);
    widget = this->fullScreenButton;
    widget->setGeometry(offsetX + width - buttonWidth*2 - border.TotalWidth() - buttonRightOffset - buttonInterOffset,
                        offsetY + border.TotalWidth() + buttonUpperOffset,
                        buttonWidth,
                        buttonHeight);
    widget = this->maximizeButton;
    widget->setGeometry(offsetX + width - buttonWidth*3 - border.TotalWidth() - buttonRightOffset - buttonInterOffset*2,
                        offsetY + border.TotalWidth() + buttonUpperOffset,
                        buttonWidth,
                        buttonHeight);
    widget = this->minimizeButton;
    widget->setGeometry(offsetX + width - buttonWidth*4 - border.TotalWidth() - buttonRightOffset - buttonInterOffset*3,
                        offsetY + border.TotalWidth() + buttonUpperOffset,
                        buttonWidth,
                        buttonHeight);
}
