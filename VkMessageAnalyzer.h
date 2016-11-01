#ifndef VKMESSAGEANALYZER_H
#define VKMESSAGEANALYZER_H

#include "VkMessageAnalyzerCore.h"
#include "VkMessageAnalyzerGui.h"
#include <QApplication>
#include <QDesktopWidget>

class VkMessageAnalyzer : public QMainWindow {
Q_OBJECT
    private:
        const BorderSize RESIZE_BORDER_SIZE = BorderSize(4, 5);
        const QSize MINIMAL_SIZE = QSize(400, 350);
        const int MOVE_BORDER_HEIGHT = 20;

        VkMessageAnalyzerGui  ui;
        VkMessageAnalyzerCore core;       

        bool validParameters(const WindowParameters& params);
    public:
        VkMessageAnalyzer(QPoint initial_point, QSize window_size, QMainWindow* parent = nullptr);
    public slots:
        void Resize(WindowParameters& winPar);
        void Move(QPoint& upperCorner);        
        void QuitApplication();
        void EnterFullScreen();
        void MaximizeApplication();
        void MinimizeApplication();
        void SwitchTab(short tabNum);
        void FollowUrl(const QUrl& url);
        ItemWidgetsLayer* UI_Items();
};

#endif // VKMESSAGEANALYZER_H
