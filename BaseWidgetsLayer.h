#ifndef BASEWIDGETSLAYER_H
#define BASEWIDGETSLAYER_H

#include "QtWidget.h"
#include "Utilities.h"
#include <QMainWindow>
#include <QFrame>

#define SHOW_WIDGETS_LAYOUT

class BaseWidgetsLayer {
    private:
        QtWidget* centralWidget;

        void init(QMainWindow* main_class);
    public:
        BaseWidgetsLayer(QMainWindow* main_class, QPoint initial_point, QSize initial_size);

        void DistributeLayerContents(const WindowParameters winParams);
        QWidget* GetCentralWidget() const;
};

#endif // BASEWIDGETSLAYER_H
