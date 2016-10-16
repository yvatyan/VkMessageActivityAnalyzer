#ifndef MOVEWIDGETSCOLLECTION_H
#define MOVEWIDGETSCOLLECTION_H

#include "WidgetsWithCustomizedEventHandlers.h"
#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QMainWindow>

class MoveWidgetsCollection : public QObject{
Q_OBJECT
    private:
        WidgetsWithCustomizedEventHandlers* moveBorder;

        void init();
        MoveWidgetsCollection();
        MoveWidgetsCollection(const MoveWidgetsCollection&){}
        MoveWidgetsCollection& operator=(const MoveWidgetsCollection&){}

        void enterEventHandler(QEvent* event);
        void leaveEventHandler(QEvent* event);
        void mouseMoveEventHandler(QMouseEvent* event);
        void mousePressEventHandler(QMouseEvent* event);
    public:
        static MoveWidgetsCollection& GetInstance() {
            static MoveWidgetsCollection instance;
            return instance;
        }

        void Configure(QPoint offset, QSize size);
        void SetMainWindow(QMainWindow* win);
    signals:
        void windowMoved();
};

#endif // MOVEWIDGETSCOLLECTION_H
