#include "VkMessageAnalyzer.h"

VkMessageAnalyzer::VkMessageAnalyzer(QSize window_size, QMainWindow *parent)
    : QMainWindow(parent)
    , ui(this, window_size, RESIZE_BORDER_SIZE, MOVE_BORDER_HEIGHT)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_PaintOnScreen);
}
