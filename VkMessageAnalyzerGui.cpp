#include "VkMessageAnalyzerGui.h"
#include "VkMessageAnalyzer.h"

VkMessageAnalyzerGui::VkMessageAnalyzerGui(QMainWindow* main_class,
                                           QPoint initial_point,
                                           QSize initial_size,
                                           BorderSize resize_border,
                                           int movement_border_height)
    : base(main_class, initial_point, initial_size)
    , items(base.GetCentralWidget(), resize_border.InnerWidth())
    , controls(main_class, initial_size, resize_border, movement_border_height)
{
    DistributeLayerContents(WindowParameters(initial_size, initial_point));
    controls.MakeConnections(main_class);
}
void VkMessageAnalyzerGui::DistributeLayerContents(const WindowParameters winParams) {
    WindowInfo::GetInstance().Set(winParams);

    base.DistributeLayerContents(winParams);
    items.DistributeLayerContents(winParams);
    controls.DistributeLayerContents(winParams);
}
