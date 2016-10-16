#ifndef CONTROLWIDGETSLAYER_H
#define CONTROLWIDGETSLAYER_H

#define SHOW_WIDGETS_LAYOUT

#include "Utilities.h"
#include "MoveWidgetsCollection.h"
#include "ResizeWidgetsCollection.h"
#include <QPushButton>

class ControlWidgetsLayer {
    private:
        //application size&place control
        static ResizeWidgetsCollection rsBorders;
        static MoveWidgetsCollection mvBorders;
        //application behavior control
        QPushButton* quitButton;
        QPushButton* fullScreenButton;
        QPushButton* maximizeButton;
        QPushButton* minimizeButton;
        // parameters
        BorderSize border;
        int moveBorderHeight;

        void init(QWidget* parent);
    public:
        ControlWidgetsLayer(QWidget* parent,
                            QSize initial_size,
                            BorderSize rs_border,
                            int move_border_height);
        ~ControlWidgetsLayer();

        void DistributeLayerContents(const QSize& layer_new_size, const QPoint& layer_new_offset);
};

#endif // CONTROLWIDGETSLAYER_H
