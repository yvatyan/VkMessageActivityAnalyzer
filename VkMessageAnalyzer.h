#ifndef VKMESSAGEANALYZER_H
#define VKMESSAGEANALYZER_H

#include "VkMessageAnalyzerCore.h"
#include "VkMessageAnalyzerGui.h"

class VkMessageAnalyzer : public QMainWindow {
Q_OBJECT
    private:
        const BorderSize RESIZE_BORDER_SIZE = BorderSize(3, 5);
        const QSize MINIMAL_SIZE = QSize(400, 250);
        const int MOVE_BORDER_HEIGHT = 20;

        VkMessageAnalyzerCore core;
        VkMessageAnalyzerGui  ui;

        bool validParameters(const WindowParameters& params);
    public:
        VkMessageAnalyzer(QPoint initial_point, QSize window_size, QMainWindow* parent = nullptr);
    public slots:
        void Resize(WindowParameters& winPar);
        void Move(QPoint& upperCorner);
};

#endif // VKMESSAGEANALYZER_H
