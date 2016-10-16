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
        int innerWidth;
        int outerWidth;

        void init();
        ResizeWidgetsCollection();
        ResizeWidgetsCollection(const ResizeWidgetsCollection&){}
        ResizeWidgetsCollection& operator=(const ResizeWidgetsCollection&){}

        static bool enterEventHandler(QEvent* event);
        static bool leaveEventHandler(QEvent* event);
        static bool mouseMoveEventHandler(QMouseEvent* event);
        static bool mousePressEventHandler(QMouseEvent* event);
    public:
        static ResizeWidgetsCollection& GetInstance() {
            static ResizeWidgetsCollection instance;
            return instance;
        }

        void Configure(WindowParameters win_params, BorderSize border);
        WindowParameters GetWindowParameters() const;
        void SetMainWindow(QWidget* win);

        friend class ControlWidgetsLayer;
    signals:
        void windowResized();
};

#endif // RESIZEWIDGETSCOLLECTION_H
