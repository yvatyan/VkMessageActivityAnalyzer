#include "VkMessageAnalyzerGui.h"

VkMessageAnalyzerGui::VkMessageAnalyzerGui(QMainWindow* main_class,
                                           QSize initial_size,
                                           BorderSize resize_border,
                                           int movement_border_height)
    : base(main_class, initial_size)
    , items(base.GetCentralWidget(), resize_border.InnerWidth())
    , controls(base.GetCentralWidget(), initial_size, resize_border, movement_border_height)
{
}
