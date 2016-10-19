#ifndef UTILITIES_H
#define UTILITIES_H

#include <QSize>
#include <QPoint>

struct WindowParameters {
    WindowParameters() {
        windowSize = QSize(-1, -1);
        windowUpperCorner = QPoint(-1, -1);
    }

    WindowParameters(QSize size, QPoint point) {
        windowSize = size;
        windowUpperCorner = point;
    }

    QSize windowSize;
    QPoint windowUpperCorner;
};

class BorderSize {
    private:
        short outer_width;
        short inner_width;
    public:
        BorderSize() {
            outer_width = 0;
            inner_width = 0;
        }
        BorderSize(short inner_w, short outer_w) {
            outer_width = outer_w;
            inner_width = inner_w;
        }
        BorderSize(const BorderSize& copy) {
            outer_width = copy.outer_width;
            inner_width = copy.inner_width;
        }
        short OuterWidth() const {
            return outer_width;
        }
        short InnerWidth() const {
            return inner_width;
        }
        short TotalWidth() const {
            return inner_width + outer_width;
        }
};

class WindowInfo {
    private:
        WindowParameters winInfo;

        WindowInfo() : winInfo(){}
        WindowInfo(const WindowInfo&) {}
        WindowInfo& operator=(const WindowInfo&) {}
    public:
        static WindowInfo& GetInstance() {
            static WindowInfo instance;
            return instance;
        }
        void Set(WindowParameters winParams) {
            winInfo = winParams;
        }
        void SetUpperCorner(QPoint point) {
            winInfo.windowUpperCorner = point;
        }
        void SetSize(QSize size) {
            winInfo.windowSize = size;
        }
        WindowParameters Get() const {
            return winInfo;
        }
};

#endif // UTILITIES_H
