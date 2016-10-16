#include "ResizeWidgetsCollection.h"

/*
class ResizeWidgetsCollection {
Q_OBJECT
    private:
        WidgetsWithCustomizedEventHandlers* northBorder;
        WidgetsWithCustomizedEventHandlers* northeastBorder;
        WidgetsWithCustomizedEventHandlers* eastBorder;
        WidgetsWithCustomizedEventHandlers* southeastBorder;
        WidgetsWithCustomizedEventHandlers* southBorder;
        WidgetsWithCustomizedEventHandlers* southwestBorder;
        WidgetsWithCustomizedEventHandlers* westBorder;
        WidgetsWithCustomizedEventHandlers* northwestBorder;
        int innerWidth;
        int outerWidth;

        void init();
        ResizeWidgetsCollection();
        ResizeWidgetsCollection(const ResizeWidgetsCollection&){}
        ResizeWidgetsCollection& operator=(const ResizeWidgetsCollection&){}

        void enterEventHandler(QEvent* event);
        void leaveEventHandler(QEvent* event);
        void mouseMoveEventHandler(QMouseEvent* event);
        void mousePressEventHandler(QMouseEvent* event);
    public:
        static ResizeWidgetsCollection& GetInstance() {
            static ResizeWidgetsCollection instance;
            return instance;
        }

        void Configure(WindowParameters win_params, BorderSize border);
        WindowParameters GetWindowParameters() const;
        void SetMainWindow(QMainWindow* win);
    signals:
        void windowResized();
};

*/
void ResizeWidgetsCollection::init() {
    WidgetsWithCustomizedEventHandlers temp;
    temp.RegisterEnterEventHandler(&ResizeWidgetsCollection::enterEventHandler);
    temp.RegisterLeaveEventHandler(&ResizeWidgetsCollection::leaveEventHandler);
    temp.RegisterMouseMoveEvent(&ResizeWidgetsCollection::mouseMoveEventHandler);
    temp.RegisterMousePressEvent(&ResizeWidgetsCollection::mousePressEventHandler);

    northBorder = new WidgetsWithCustomizedEventHandlers(temp);
    northBorder->setObjectName(QStringLiteral("northBorder"));
    northBorder->setMouseTracking(true);

    northeastBorder = new WidgetsWithCustomizedEventHandlers(temp);
    northeastBorder->setObjectName(QStringLiteral("northeastBorder"));
    northeastBorder->setMouseTracking(true);

    eastBorder = new WidgetsWithCustomizedEventHandlers(temp);
    eastBorder->setObjectName(QStringLiteral("eastBorder"));
    eastBorder->setMouseTracking(true);

    southeastBorder = new WidgetsWithCustomizedEventHandlers(temp);
    southeastBorder->setObjectName(QStringLiteral("southeastBorder"));
    southeastBorder->setMouseTracking(true);

    southBorder = new WidgetsWithCustomizedEventHandlers(temp);
    southBorder->setObjectName(QStringLiteral("southBorder"));
    southBorder->setMouseTracking(true);

    southwestBorder = new WidgetsWithCustomizedEventHandlers(temp);
    southwestBorder->setObjectName(QStringLiteral("southwestBorder"));
    southwestBorder->setMouseTracking(true);

    westBorder = new WidgetsWithCustomizedEventHandlers(temp);
    westBorder->setObjectName(QStringLiteral("westBorder"));
    westBorder->setMouseTracking(true);

    northwestBorder = new WidgetsWithCustomizedEventHandlers(temp);
    northwestBorder->setObjectName(QStringLiteral("northwestBorder"));
    northwestBorder->setMouseTracking(true);

//#ifdef SHOW_WIDGETS_LAYOUT
    northBorder->setPalette(QPalette(Qt::red));
    northeastBorder->setPalette(QPalette(Qt::magenta));
    eastBorder->setPalette(QPalette(Qt::red));
    southeastBorder->setPalette(QPalette(Qt::magenta));
    southBorder->setPalette(QPalette(Qt::red));
    southwestBorder->setPalette(QPalette(Qt::magenta));
    westBorder->setPalette(QPalette(Qt::red));
    northwestBorder->setPalette(QPalette(Qt::magenta));
//#endif
}
ResizeWidgetsCollection::ResizeWidgetsCollection() {
    init();
}
bool ResizeWidgetsCollection::enterEventHandler(QEvent* event) {
    return false;
}
bool ResizeWidgetsCollection::leaveEventHandler(QEvent* event) {
    return false;
}
bool ResizeWidgetsCollection::mouseMoveEventHandler(QMouseEvent* event) {
    return false;
}
bool ResizeWidgetsCollection::mousePressEventHandler(QMouseEvent* event) {
    return false;
}
void ResizeWidgetsCollection::Configure(WindowParameters win_params, BorderSize border) {
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
WindowParameters ResizeWidgetsCollection::GetWindowParameters() const {
    return WindowParameters();
}
void ResizeWidgetsCollection::SetMainWindow(QWidget *win) {
    northBorder->setParent(win);    
    eastBorder->setParent(win);    
    southBorder->setParent(win);    
    westBorder->setParent(win);
    northwestBorder->setParent(win);
    northeastBorder->setParent(win);
    southeastBorder->setParent(win);
    southwestBorder->setParent(win);
}
