#include "ResizeWidgetsCollection.h"

bool ResizeWidgetsCollection::MLBpressed = false;

void ResizeWidgetsCollection::init(QWidget* parent) {
    WidgetsWithCustomizedEventHandlers temp(parent);
    temp.RegisterEnterEventHandler(&ResizeWidgetsCollection::enterEventHandler);
    temp.RegisterLeaveEventHandler(&ResizeWidgetsCollection::leaveEventHandler);
    temp.RegisterMouseMoveEvent(&ResizeWidgetsCollection::mouseMoveEventHandler);
    temp.RegisterMousePressEvent(&ResizeWidgetsCollection::mousePressEventHandler);
    temp.RegisterMouseReleaseEvent(&ResizeWidgetsCollection::mouseReleaseEventHandler);

    northBorder = new WidgetsWithCustomizedEventHandlers(temp);
    northBorder->setObjectName(QStringLiteral("northBorder"));
    northBorder->setMouseTracking(true);

    eastBorder = new WidgetsWithCustomizedEventHandlers(temp);
    eastBorder->setObjectName(QStringLiteral("eastBorder"));
    eastBorder->setMouseTracking(true);

    southBorder = new WidgetsWithCustomizedEventHandlers(temp);
    southBorder->setObjectName(QStringLiteral("southBorder"));
    southBorder->setMouseTracking(true);

    westBorder = new WidgetsWithCustomizedEventHandlers(temp);
    westBorder->setObjectName(QStringLiteral("westBorder"));
    westBorder->setMouseTracking(true);

    northwestBorder = new WidgetsWithCustomizedEventHandlers(temp);
    northwestBorder->setObjectName(QStringLiteral("northwestBorder"));
    northwestBorder->setMouseTracking(true);

    northeastBorder = new WidgetsWithCustomizedEventHandlers(temp);
    northeastBorder->setObjectName(QStringLiteral("northeastBorder"));
    northeastBorder->setMouseTracking(true);

    southeastBorder = new WidgetsWithCustomizedEventHandlers(temp);
    southeastBorder->setObjectName(QStringLiteral("southeastBorder"));
    southeastBorder->setMouseTracking(true);

    southwestBorder = new WidgetsWithCustomizedEventHandlers(temp);
    southwestBorder->setObjectName(QStringLiteral("southwestBorder"));
    southwestBorder->setMouseTracking(true);

#ifdef SHOW_WIDGETS_LAYOUT
    northBorder->setPalette(QPalette(Qt::red));
    northeastBorder->setPalette(QPalette(Qt::magenta));
    eastBorder->setPalette(QPalette(Qt::red));
    southeastBorder->setPalette(QPalette(Qt::magenta));
    southBorder->setPalette(QPalette(Qt::red));
    southwestBorder->setPalette(QPalette(Qt::magenta));
    westBorder->setPalette(QPalette(Qt::red));
    northwestBorder->setPalette(QPalette(Qt::magenta));
#endif
}
ResizeWidgetsCollection::ResizeWidgetsCollection(BorderSize bSize, QWidget *parent) {
    border = bSize;
    init(parent);
}
bool ResizeWidgetsCollection::enterEventHandler(QEvent* event) {
    return false;
}
bool ResizeWidgetsCollection::leaveEventHandler(QEvent* event) {
    return false;
}
bool ResizeWidgetsCollection::mouseMoveEventHandler(QMouseEvent* event) {/*
    if(ResizeWidgetsCollection::MLBpressed) {
        qDebug() << event->globalX() << ", " << event->globalY() << " ::: " << event->windowPos().y();
        ResizeWidgetsCollection::GetInstance().GetWindowParameters().windowSize =
                QSize(ResizeWidgetsCollection::GetInstance().GetWindowParameters().windowSize.width(),
                      event->windowPos().y());

        emit ResizeWidgetsCollection::GetInstance().windowResized();
        return true;
    }*/
    return false;
}
bool ResizeWidgetsCollection::mousePressEventHandler(QMouseEvent* event) {
    if(event->button() == Qt::LeftButton) {
        MLBpressed = true;
        return true;
    }
    return false;
}
bool ResizeWidgetsCollection::mouseReleaseEventHandler(QMouseEvent* event) {
    if(event->button() == Qt::LeftButton) {
        MLBpressed = false;
        return true;
    }
    return false;
}
void ResizeWidgetsCollection::DistributeContents(WindowParameters win_params) {
    winParams = win_params;
    int winHeight = win_params.windowSize.height();
    int winWidth = win_params.windowSize.width();
    int borderWidth = border.TotalWidth();

    QWidget* widget = northBorder;
    widget->setGeometry(borderWidth, 0, winWidth - borderWidth, borderWidth);
    widget = eastBorder;
    widget->setGeometry(winWidth - borderWidth, borderWidth, borderWidth, winHeight - borderWidth);
    widget = southBorder;
    widget->setGeometry(borderWidth, winHeight - borderWidth, winWidth - borderWidth, borderWidth);
    widget = westBorder;
    widget->setGeometry(0, borderWidth, borderWidth, winHeight - borderWidth);
    widget = northwestBorder;
    widget->setGeometry(0, 0, borderWidth, borderWidth);
    widget = northeastBorder;
    widget->setGeometry(winWidth - borderWidth, 0, borderWidth, borderWidth);
    widget = southeastBorder;
    widget->setGeometry(winWidth - borderWidth, winHeight - borderWidth, borderWidth, borderWidth);
    widget = southwestBorder;
    widget->setGeometry(0, winHeight - borderWidth, borderWidth, borderWidth);
}
