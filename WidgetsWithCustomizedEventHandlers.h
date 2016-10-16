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
    public:
        WidgetsWithCustomizedEventHandlers() : QWidget(){}
        WidgetsWithCustomizedEventHandlers(QWidget* parent) : QWidget(parent){}
        WidgetsWithCustomizedEventHandlers(const WidgetsWithCustomizedEventHandlers& copy)
          //  : QWidget(copy)
        {
            customizedEnterEventHandler = copy.customizedEnterEventHandler;
            customizedLeaveEventHandler = copy.customizedLeaveEventHandler;
            customizedMouseMoveEventHandler = copy.customizedMouseMoveEventHandler;
            customizedMousePressEventHandler = copy.customizedMousePressEventHandler;
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
};

#endif // WIDGETSWITHCUSTOMIZEDEVENTHANDLERS_H
