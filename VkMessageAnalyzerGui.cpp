#include "VkMessageAnalyzerGui.h"
#include "VkMessageAnalyzer.h"

#include <QDebug>

VkMessageAnalyzerGui::VkMessageAnalyzerGui(QMainWindow* main_class,
                                           QPoint initial_point,
                                           QSize initial_size,
                                           BorderSize resize_border,
                                           int movement_border_height)
    : base(main_class, initial_point, initial_size)
    , items(base.GetCentralWidget(), resize_border.OuterWidth())
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
void VkMessageAnalyzerGui::SwitchTab(short tabNum) {
    items.SwitchTab(tabNum);
}
ItemWidgetsLayer* VkMessageAnalyzerGui::ItemLayer() {
    return &items;
}
