#ifndef STRETCHBORDERSCOLLECTION_H
#define STRETCHBORDERSCOLLECTION_H

#include "QtWidget.h"
#include "Utilities.h"
#include <QEvent>
#include <QMouseEvent>

class StretchBorder : public QtWidget {
Q_OBJECT
    protected:
        bool MLBpressed;
    public:
        StretchBorder(QWidget* parent = nullptr) : QtWidget(parent, false){ MLBpressed = false; }
        virtual void mousePressEvent(QMouseEvent* event) {
            MLBpressed = true;
            QtWidget::mousePressEvent(event);
        }
        virtual void mouseReleaseEvent(QMouseEvent* event) {
            MLBpressed = false;
            QtWidget::mouseReleaseEvent(event);
        }
    signals:
        void windowResized(WindowParameters& winPar);
};

class HorizontalBorder : public StretchBorder {
    public:
        HorizontalBorder(QWidget* parent = nullptr) : StretchBorder(parent){}
        virtual void enterEvent(QEvent* event) {
            setCursor(Qt::SizeVerCursor);
            StretchBorder::enterEvent(event);
        }
        virtual void leaveEvent(QEvent* event) {
            setCursor(Qt::ArrowCursor);
            StretchBorder::leaveEvent(event);
        }
};

class VerticalBorder : public StretchBorder {
    public:
        VerticalBorder(QWidget* parent = nullptr) : StretchBorder(parent){}
        virtual void enterEvent(QEvent* event) {
            setCursor(Qt::SizeHorCursor);
            StretchBorder::enterEvent(event);
        }
        virtual void leaveEvent(QEvent* event) {
            setCursor(Qt::ArrowCursor);
            StretchBorder::leaveEvent(event);
        }
};

class LeftDiagonalBorder : public StretchBorder {
    public:
        LeftDiagonalBorder(QWidget* parent = nullptr) : StretchBorder(parent){}
        virtual void enterEvent(QEvent* event) {
            setCursor(Qt::SizeFDiagCursor);
            StretchBorder::enterEvent(event);
        }
        virtual void leaveEvent(QEvent* event) {
            setCursor(Qt::ArrowCursor);
            StretchBorder::leaveEvent(event);
        }
};

class RightDiagonalBorder : public StretchBorder {
    public:
        RightDiagonalBorder(QWidget* parent = nullptr) : StretchBorder(parent){}
        virtual void enterEvent(QEvent* event) {
            setCursor(Qt::SizeBDiagCursor);
            StretchBorder::enterEvent(event);
        }
        virtual void leaveEvent(QEvent* event) {
            setCursor(Qt::ArrowCursor);
            StretchBorder::leaveEvent(event);
        }
};

class NorthBorder : public HorizontalBorder {
    public:
        NorthBorder(QWidget* parent = nullptr) : HorizontalBorder(parent){}
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                winParams.windowSize = QSize(winParams.windowSize.width(),
                                             winParams.windowSize.height() - event->windowPos().y());
                winParams.windowUpperCorner = QPoint(winParams.windowUpperCorner.x(), event->globalY());
                emit windowResized(winParams);
            }
            HorizontalBorder::mouseMoveEvent(event);
        }
};

class SouthBorder : public HorizontalBorder {
    public:
        SouthBorder(QWidget* parent = nullptr) : HorizontalBorder(parent){}
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                winParams.windowSize = QSize(winParams.windowSize.width(), event->windowPos().y());
                emit windowResized(winParams);
            }
            HorizontalBorder::mouseMoveEvent(event);
        }
};

class WestBorder : public VerticalBorder {
    public:
        WestBorder(QWidget* parent = nullptr) : VerticalBorder(parent){}
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                winParams.windowSize = QSize(winParams.windowSize.width() - event->windowPos().x(),
                                             winParams.windowSize.height());
                winParams.windowUpperCorner = QPoint(event->globalX(),
                                                     winParams.windowUpperCorner.y());
                emit windowResized(winParams);
            }
            VerticalBorder::mouseMoveEvent(event);
        }
};

class EastBorder : public VerticalBorder {
    public:
        EastBorder(QWidget* parent = nullptr) : VerticalBorder(parent){}
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                winParams.windowSize = QSize(event->windowPos().x(),
                                             winParams.windowSize.height());
                winParams.windowUpperCorner = QPoint(winParams.windowUpperCorner.x(),
                                                     winParams.windowUpperCorner.y());
                emit windowResized(winParams);
            }
            VerticalBorder::mouseMoveEvent(event);
        }
};

class NorthwestBorder : public LeftDiagonalBorder {
    public:
        NorthwestBorder(QWidget* parent = nullptr) : LeftDiagonalBorder(parent){}
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                winParams.windowSize = QSize(winParams.windowSize.width() - event->windowPos().x(),
                                             winParams.windowSize.height() - event->windowPos().y());
                winParams.windowUpperCorner = QPoint(event->globalX(),
                                                     event->globalY());
                emit windowResized(winParams);
            }
            LeftDiagonalBorder::mouseMoveEvent(event);
        }
};

class SoutheastBorder : public LeftDiagonalBorder {
    public:
        SoutheastBorder(QWidget* parent = nullptr) : LeftDiagonalBorder(parent){}
        virtual void mouseMoveEvent(QMouseEvent* event) {
            if(MLBpressed) {
                WindowParameters winParams = WindowInfo::GetInstance().Get();
                winParams.windowSize = QSize(event->windowPos().x(),
                                             event->windowPos().y());
                winParams.windowUpperCorner = QPoint(winParams.windowUpperCorner.x(),
                                                     winParams.windowUpperCorner.y());
                emit windowResized(winParams);
            }
            LeftDiagonalBorder::mouseMoveEvent(event);
        }
};

class NortheastBorder : public RightDiagonalBorder {
public:
    NortheastBorder(QWidget* parent = nullptr) : RightDiagonalBorder(parent){}
    virtual void mouseMoveEvent(QMouseEvent* event) {
        if(MLBpressed) {
            WindowParameters winParams = WindowInfo::GetInstance().Get();
            winParams.windowSize = QSize(event->windowPos().x(),
                                         winParams.windowSize.height() - event->windowPos().y());
            winParams.windowUpperCorner = QPoint(winParams.windowUpperCorner.x(), event->globalY());
            emit windowResized(winParams);
        }
        RightDiagonalBorder::mouseMoveEvent(event);
    }
};

class SouthwestBorder : public RightDiagonalBorder {
public:
    SouthwestBorder(QWidget* parent = nullptr) : RightDiagonalBorder(parent){}
    virtual void mouseMoveEvent(QMouseEvent* event) {
        if(MLBpressed) {
            WindowParameters winParams = WindowInfo::GetInstance().Get();
            winParams.windowSize = QSize(winParams.windowSize.width() - event->windowPos().x(),
                                         event->windowPos().y());
            winParams.windowUpperCorner = QPoint(event->globalX(),
                                                 winParams.windowUpperCorner.y());
            emit windowResized(winParams);
        }
        RightDiagonalBorder::mouseMoveEvent(event);
    }
};

#endif // STRETCHBORDERSCOLLECTION_H
