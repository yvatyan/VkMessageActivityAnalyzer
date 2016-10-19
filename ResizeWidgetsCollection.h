#ifndef RESIZEWIDGETSCOLLECTION_H
#define RESIZEWIDGETSCOLLECTION_H

#define SHOW_WIDGETS_LAYOUT

#include <QMainWindow>
#include "Utilities.h"
#include "WidgetsWithCustomizedEventHandlers.h"

struct WindowParameters;
class BorderSize;

class ResizeWidgetsCollection : public QObject{
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
        BorderSize border;
        static bool MLBpressed;
        WindowParameters winParams;

        void init(QWidget *parent);
        ResizeWidgetsCollection(const ResizeWidgetsCollection&){}
        ResizeWidgetsCollection& operator=(const ResizeWidgetsCollection&){}
    public:
        ResizeWidgetsCollection(BorderSize bSize, QWidget* parent = nullptr);

        static bool enterEventHandler(QEvent* event);
        static bool leaveEventHandler(QEvent* event);
        static bool mouseMoveEventHandler(QMouseEvent* event);
        static bool mousePressEventHandler(QMouseEvent* event);
        static bool mouseReleaseEventHandler(QMouseEvent*event);

        void DistributeContents(WindowParameters win_params);

    signals:
        void windowResized(WindowParameters winPar);
};

#endif // RESIZEWIDGETSCOLLECTION_H
