#ifndef WIDGETSWITHCUSTOMIZEDEVENTHANDLERS_H
#define WIDGETSWITHCUSTOMIZEDEVENTHANDLERS_H

#include <QWidget>
#include <QEvent>
#include <QPainter>
#include <QMouseEvent>

class WidgetsWithCustomizedEventHandlers : public QWidget {
    private:
        bool (*customizedEnterEventHandler) (QEvent*);
        bool (*customizedLeaveEventHandler) (QEvent*);
        bool (*customizedMouseMoveEventHandler) (QMouseEvent*);
        bool (*customizedMousePressEventHandler) (QMouseEvent*);
        bool (*customizedMouseReleaseEventHandler) (QMouseEvent*);
        static bool defaultHandler(QEvent*) {
            return false;
        }
        static bool defaultHandler(QMouseEvent*) {
            return false;
        }
        void init() {
            customizedEnterEventHandler = defaultHandler;
            customizedLeaveEventHandler = defaultHandler;
            customizedMouseMoveEventHandler = defaultHandler;
            customizedMousePressEventHandler = defaultHandler;
            customizedMouseReleaseEventHandler = defaultHandler;
        }

    public:
        WidgetsWithCustomizedEventHandlers() : QWidget(){
            init();
        }

        WidgetsWithCustomizedEventHandlers(QWidget* parent) : QWidget(parent){
            init();
        }
        WidgetsWithCustomizedEventHandlers(const WidgetsWithCustomizedEventHandlers& copy)
          //  : QWidget(copy)
        {
            setParent(copy.parentWidget());
            customizedEnterEventHandler = copy.customizedEnterEventHandler;
            customizedLeaveEventHandler = copy.customizedLeaveEventHandler;
            customizedMouseMoveEventHandler = copy.customizedMouseMoveEventHandler;
            customizedMousePressEventHandler = copy.customizedMousePressEventHandler;
            customizedMouseReleaseEventHandler = copy.customizedMouseReleaseEventHandler;
        }

        void paintEvent(QPaintEvent* event) {
            QPainter painter(this);
            painter.translate(0,0);
            render(&painter);
        }
        void RegisterEnterEventHandler(bool (*customEventHandler) (QEvent*)) {
            customizedEnterEventHandler = customEventHandler;
        }
        void RegisterLeaveEventHandler(bool (*customEventHandler) (QEvent*)) {
            customizedLeaveEventHandler = customEventHandler;
        }
        void RegisterMouseMoveEvent(bool (*customEventHandler) (QMouseEvent*)) {
            customizedMouseMoveEventHandler = customEventHandler;
        }
        void RegisterMousePressEvent(bool (*customEventHandler) (QMouseEvent*)) {
            customizedMousePressEventHandler = customEventHandler;
        }
        void RegisterMouseReleaseEvent(bool (*customEventHandler) (QMouseEvent*)) {
            customizedMouseReleaseEventHandler = customEventHandler;
        }


        virtual void enterEvent(QEvent* event) {
            if(customizedEnterEventHandler(event)) {

            }
            else {
                QWidget::enterEvent(event);
            }
        }
        virtual void leaveEvent(QEvent* event) {
            if(customizedLeaveEventHandler(event)) {

            }
            else {
                QWidget::leaveEvent(event);
            }
        }
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(customizedMouseMoveEventHandler(event)) {

            }
            else {
                QWidget::mouseMoveEvent(event);
            }
        }
        virtual void mousePressEvent(QMouseEvent* event) {
            if(customizedMousePressEventHandler(event)) {

            }
            else {
                QWidget::mousePressEvent(event);
            }
        }
        virtual void mouseReleaseEvent(QMouseEvent* event) {
            if(customizedMouseReleaseEventHandler(event)) {

            }
            else {
                QWidget::mouseReleaseEvent(event);
            }
        }
};

#endif // WIDGETSWITHCUSTOMIZEDEVENTHANDLERS_H
