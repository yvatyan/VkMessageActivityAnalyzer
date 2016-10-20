#include "VkMessageAnalyzer.h"

VkMessageAnalyzer::VkMessageAnalyzer(QPoint initial_point, QSize window_size, QMainWindow *parent)
    : QMainWindow(parent)
    , ui(this, initial_point, window_size, RESIZE_BORDER_SIZE, MOVE_BORDER_HEIGHT)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground);
    //setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_PaintOnScreen);
    setObjectName("VkMessageAnalyzer");
}
bool VkMessageAnalyzer::validParameters(const WindowParameters& params) {
    if(MINIMAL_SIZE.width() > params.windowSize.width() ||
       MINIMAL_SIZE.height() > params.windowSize.height())
    {
        return false;
    }
    return true;
}
void VkMessageAnalyzer::Resize(WindowParameters& winPar) {
    if(validParameters(winPar)) {
        ui.DistributeLayerContents(winPar);
    }
    else {
        WindowInfo::GetInstance().SetSize(MINIMAL_SIZE);
    }
}
void VkMessageAnalyzer::Move(QPoint& upperCorner) {
    this->move(upperCorner);
}
