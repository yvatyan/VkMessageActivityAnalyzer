#ifndef DISPLACEBORDERSCOLLECTION_H
#define DISPLACEBORDERSCOLLECTION_H

#include "QtWidget.h"
#include "Utilities.h"
#include <QEvent>
#include <QMouseEvent>

class DisplaceBorder : public QtWidget {
Q_OBJECT
    protected:
        bool MLBpressed;
        QPoint pressedPoint;
    public:
        DisplaceBorder(QWidget* parent = nullptr) : QtWidget(parent){ MLBpressed = false; }
        virtual void mousePressEvent(QMouseEvent* event) {
            MLBpressed = true;
            pressedPoint = event->globalPos();
            QtWidget::mousePressEvent(event);
        }
        virtual void mouseReleaseEvent(QMouseEvent* event) {
            MLBpressed = false;
            WindowParameters winParams = WindowInfo::GetInstance().Get();
            int x = winParams.windowUpperCorner.x() - (pressedPoint.x() - event->globalX());
            int y = winParams.windowUpperCorner.y() - (pressedPoint.y() - event->globalY());
            WindowInfo::GetInstance().SetUpperCorner(QPoint(x, y));
            QtWidget::mouseReleaseEvent(event);
        }
        virtual void enterEvent(QEvent* event) {
            setCursor(Qt::SizeAllCursor);
            QtWidget::enterEvent(event);
        }
        virtual void leaveEvent(QEvent* event) {
            setCursor(Qt::ArrowCursor);
            QtWidget::leaveEvent(event);
        }
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                int x = winParams.windowUpperCorner.x() - (pressedPoint.x() - event->globalX());
                int y = winParams.windowUpperCorner.y() - (pressedPoint.y() - event->globalY());
                emit windowMoved(QPoint(x, y));
            }
            QtWidget::mouseMoveEvent(event);
        }
    signals:
        void windowMoved(QPoint& upperCorner);
};

#endif // DISPLACEBORDERSCOLLECTION_H
