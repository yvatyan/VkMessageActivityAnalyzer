#ifndef VKMESSAGEANALYZER_H
#define VKMESSAGEANALYZER_H

#include "VkMessageAnalyzerCore.h"
#include "VkMessageAnalyzerGui.h"

class VkMessageAnalyzer : public QMainWindow {
Q_OBJECT
    private:
        const BorderSize RESIZE_BORDER_SIZE = BorderSize(3, 5);
        const int MOVE_BORDER_HEIGHT = 20;

        VkMessageAnalyzerCore core;
        VkMessageAnalyzerGui  ui;
    public:
        VkMessageAnalyzer(QSize window_size, QMainWindow* parent = nullptr);
};

#endif // VKMESSAGEANALYZER_H
