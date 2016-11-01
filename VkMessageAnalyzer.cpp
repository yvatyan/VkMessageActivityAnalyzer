#include "VkMessageAnalyzer.h"

VkMessageAnalyzer::VkMessageAnalyzer(QPoint initial_point, QSize window_size, QMainWindow *parent)
    : QMainWindow(parent)
    , ui(this, initial_point, window_size, RESIZE_BORDER_SIZE, MOVE_BORDER_HEIGHT)
    , core(this, 1)
{
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
void VkMessageAnalyzer::QuitApplication() {
    QApplication::quit();
}
void VkMessageAnalyzer::EnterFullScreen() {
    setWindowState(this->windowState() ^ Qt::WindowFullScreen);
    if (!WindowInfo::GetInstance().IsAppInFullScreen()) {
        WindowInfo::GetInstance().SetAppFullScreenState(true);
        WindowInfo::GetInstance().SaveFullDropDown();
        int screenActualHeight = QApplication::desktop()->screenGeometry().height();
        int screenActualWidth = QApplication::desktop()->screenGeometry().width();
        //ui.DisableResize();
        ui.DistributeLayerContents(WindowParameters(QSize(screenActualWidth, screenActualHeight),
                                                       QPoint(0, 0)));
    }
    else {
        WindowInfo::GetInstance().SetAppFullScreenState(false);
        //ui.EnableResize();
        ui.DistributeLayerContents(WindowInfo::GetInstance().GetFullDropDown());
    }
}
void VkMessageAnalyzer::MaximizeApplication() {
    if (!WindowInfo::GetInstance().IsAppMaximized()) {
        WindowInfo::GetInstance().SetAppMaximizedState(true);
        if(WindowInfo::GetInstance().IsAppInFullScreen()) {
            WindowInfo::GetInstance().SetAppFullScreenState(false);
            WindowInfo::GetInstance().Set(WindowInfo::GetInstance().GetFullDropDown());
        }
        WindowInfo::GetInstance().SaveDropDown();
        int desktopActualHeight = QApplication::desktop()->availableGeometry().height();
        int desktopActualWidth = QApplication::desktop()->availableGeometry().width();
        //ui.DisableResize();
        ui.DistributeLayerContents(WindowParameters(QSize(desktopActualWidth, desktopActualHeight),
                                                       QPoint(0, 0)));
    }
    else {
        WindowInfo::GetInstance().SetAppMaximizedState(false);
        //ui.EnableResize();
        ui.DistributeLayerContents(WindowInfo::GetInstance().GetDropDown());
    }
}
void VkMessageAnalyzer::MinimizeApplication() {
    setWindowState((this->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
}
void VkMessageAnalyzer::SwitchTab(short tabNum) {
    ui.SwitchTab(tabNum);
}
void VkMessageAnalyzer::FollowUrl(const QUrl& url) {
    ui.ItemLayer()->Browser()->LoadPage(url.toString());
}
ItemWidgetsLayer* VkMessageAnalyzer::UI_Items() {
    return ui.ItemLayer();
}

