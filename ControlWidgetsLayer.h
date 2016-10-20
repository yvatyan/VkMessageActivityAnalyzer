#ifndef CONTROLWIDGETSLAYER_H
#define CONTROLWIDGETSLAYER_H

//#define SHOW_WIDGETS_LAYOUT

#include "Utilities.h"
#include "StretchBordersCollection.h"
#include "DisplaceBordersCollection.h"
#include <QMainWindow>
#include <QPushButton>

class ControlWidgetsLayer {
    private:
        /**** Window stretch borders ****/
        SouthBorder* sb;
        NorthBorder* nb;
        WestBorder* wb;
        EastBorder* eb;
        NorthwestBorder* nwb;
        NortheastBorder* neb;
        SoutheastBorder* seb;
        SouthwestBorder* swb;
        DisplaceBorder* mvb;
        /**** Application behavior control ****/
        QPushButton* quitButton;
        QPushButton* fullScreenButton;
        QPushButton* maximizeButton;
        QPushButton* minimizeButton;
        /**** Parameters ****/
        BorderSize border;
        int moveBorderHeight;

        void init(QWidget* parent);
    public:
        ControlWidgetsLayer(QWidget* parent,
                            QSize initial_size,
                            BorderSize rs_border,
                            int move_border_height);
        ~ControlWidgetsLayer();

        void DistributeLayerContents(const WindowParameters winParams);
        void MakeConnections(QMainWindow* main_class);
};

#endif // CONTROLWIDGETSLAYER_H
