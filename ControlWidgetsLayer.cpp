#include "ControlWidgetsLayer.h"
#include <QPalette>
#include <QBrush>

void ControlWidgetsLayer::init(QWidget* parent) {

    mvb = new DisplaceBorder(parent);
    mvb->setObjectName(QStringLiteral("displaceBorder"));
    mvb->setMouseTracking(true);

    nb = new NorthBorder(parent);
    nb->setObjectName(QStringLiteral("northBorder"));
    nb->setMouseTracking(true);

    eb = new EastBorder(parent);
    eb->setObjectName(QStringLiteral("eastBorder"));
    eb->setMouseTracking(true);

    sb = new SouthBorder(parent);
    sb->setObjectName(QStringLiteral("southBorder"));
    sb->setMouseTracking(true);

    wb = new WestBorder(parent);
    wb->setObjectName(QStringLiteral("westBorder"));
    wb->setMouseTracking(true);

    nwb = new NorthwestBorder(parent);
    nwb->setObjectName(QStringLiteral("northwestBorder"));
    nwb->setMouseTracking(true);

    neb = new NortheastBorder(parent);
    neb->setObjectName(QStringLiteral("northeastBorder"));
    neb->setMouseTracking(true);

    seb = new SoutheastBorder(parent);
    seb->setObjectName(QStringLiteral("southeastBorder"));
    seb->setMouseTracking(true);

    swb = new SouthwestBorder(parent);
    swb->setObjectName(QStringLiteral("southwestBorder"));
    swb->setMouseTracking(true);

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

    mvb->setPalette(QPalette(QPalette::Background, Qt::yellow));
    nb->setPalette(QPalette(QPalette::Background, Qt::red));
    eb->setPalette(QPalette(QPalette::Background, Qt::red));
    sb->setPalette(QPalette(QPalette::Background, Qt::red));
    wb->setPalette(QPalette(QPalette::Background, Qt::red));
    nwb->setPalette(QPalette(QPalette::Background, Qt::magenta));
    neb->setPalette(QPalette(QPalette::Background, Qt::magenta));
    seb->setPalette(QPalette(QPalette::Background, Qt::magenta));
    swb->setPalette(QPalette(QPalette::Background, Qt::magenta));

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
    moveBorderHeight = move_border_height;
    DistributeLayerContents(WindowParameters(initial_size, QPoint(0, 0)));
}
ControlWidgetsLayer::~ControlWidgetsLayer() {
}
void ControlWidgetsLayer::DistributeLayerContents(const WindowParameters winParams) {
    int height = winParams.windowSize.height();
    int width = winParams.windowSize.width();
    int borderWidth = border.TotalWidth();
    int offsetX = 0;
    int offsetY = 0;
    int buttonWidth = 35;
    int buttonHeight = 25;
    int buttonUpperOffset = 10;
    int buttonRightOffset = 10;
    int buttonInterOffset = 2;

    QWidget* widget = this->mvb;
    widget->setGeometry(borderWidth, borderWidth, width - 2*borderWidth, moveBorderHeight);

    widget = this->nb;
    widget->setGeometry(borderWidth, 0, width - 2*borderWidth, borderWidth);

    widget = this->eb;
    widget->setGeometry(width - borderWidth, borderWidth, borderWidth, height - 2*borderWidth);

    widget = this->sb;
    widget->setGeometry(borderWidth, height - borderWidth, width - 2*borderWidth, borderWidth);

    widget = this->wb;
    widget->setGeometry(0, borderWidth, borderWidth, height - 2*borderWidth);

    widget = this->nwb;
    widget->setGeometry(0, 0, borderWidth, borderWidth);

    widget = this->neb;
    widget->setGeometry(width - borderWidth, 0, borderWidth, borderWidth);

    widget = this->seb;
    widget->setGeometry(width - borderWidth, height - borderWidth, borderWidth, borderWidth);

    widget = this->swb;
    widget->setGeometry(0, height - borderWidth, borderWidth, borderWidth);

    widget = this->quitButton;
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
void ControlWidgetsLayer::MakeConnections(QMainWindow* main_class) {
    QObject::connect(nb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(eb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(sb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(wb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(nwb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(neb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(seb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(swb, SIGNAL(windowResized(WindowParameters&)), main_class, SLOT(Resize(WindowParameters&)));
    QObject::connect(mvb, SIGNAL(windowMoved(QPoint&)), main_class, SLOT(Move(QPoint&)));
}

