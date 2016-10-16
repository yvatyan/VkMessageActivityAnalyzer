#ifndef VKMESSAGEANALYZERGUI_H
#define VKMESSAGEANALYZERGUI_H

#include <QMainWindow>

#include "Utilities.h"
#include "BaseWidgetsLayer.h"
#include "ItemWidgetsLayer.h"
#include "ControlWidgetsLayer.h"

class VkMessageAnalyzerGui {
    private:
        BaseWidgetsLayer base;
        ItemWidgetsLayer items;
        ControlWidgetsLayer controls;
    public:
        VkMessageAnalyzerGui(QMainWindow* main_class,
                             QSize initial_size,
                             BorderSize resize_border,
                             int movement_border_height);
};

#endif // VKMESSAGEANALYZERGUI_H
