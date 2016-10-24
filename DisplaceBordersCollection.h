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
        DisplaceBorder(QWidget* parent = nullptr) : QtWidget(parent, false){ MLBpressed = false; }
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
                if(!WindowInfo::GetInstance().IsAppInFullScreen() && !WindowInfo::GetInstance().IsAppMaximized()) {
                    WindowParameters winParams = WindowInfo::GetInstance().Get();
                    int x = winParams.windowUpperCorner.x() - (pressedPoint.x() - event->globalX());
                    int y = winParams.windowUpperCorner.y() - (pressedPoint.y() - event->globalY());
                    emit windowMoved(QPoint(x, y));
                }
                else {
                    if(WindowInfo::GetInstance().IsAppInFullScreen()) {
                        WindowParameters winParams = WindowInfo::GetInstance().GetFullDropDown();
                        int x = (pressedPoint.x() - winParams.windowSize.width()/2) - (pressedPoint.x() - event->globalX());
                        int y = pressedPoint.y() - event->globalY();
                        WindowInfo::GetInstance().Set(winParams);
                        WindowInfo::GetInstance().SetUpperCorner(QPoint(x, y));
                        WindowInfo::GetInstance().SaveFullDropDown();

                        emit leaveFullScreen();
                    }
                    else {WindowParameters winParams = WindowInfo::GetInstance().GetDropDown();
                        int x = (pressedPoint.x() - winParams.windowSize.width()/2) - (pressedPoint.x() - event->globalX());
                        int y = pressedPoint.y() - event->globalY();
                        WindowInfo::GetInstance().Set(winParams);
                        WindowInfo::GetInstance().SetUpperCorner(QPoint(x, y));
                        WindowInfo::GetInstance().SaveDropDown();

                        emit dropDown();
                    }
                }
            }
            QtWidget::mouseMoveEvent(event);
        }
    signals:
        void windowMoved(QPoint& upperCorner);
        void leaveFullScreen();
        void dropDown();
};

#endif // DISPLACEBORDERSCOLLECTION_H
