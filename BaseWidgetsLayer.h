#ifndef BASEWIDGETSLAYER_H
#define BASEWIDGETSLAYER_H

#include "WidgetsWithCustomizedEventHandlers.h"
#include <QMainWindow>
#include <QFrame>

#define SHOW_WIDGETS_LAYOUT

class BaseWidgetsLayer {
    private:
        WidgetsWithCustomizedEventHandlers* centralWidget;
        const QPoint INITIAL_POINT = QPoint(100, 100);

        void init(QMainWindow* main_class);
    public:
        BaseWidgetsLayer(QMainWindow* main_class, QSize initial_size);

        void DistributeLayerContents(const QSize& layer_new_size, const QPoint& layer_new_offset);
        QWidget* GetCentralWidget() const;
};

#endif // BASEWIDGETSLAYER_H
