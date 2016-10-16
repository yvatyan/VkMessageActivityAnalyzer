#ifndef UTILITIES_H
#define UTILITIES_H

#include <QSize>
#include <QPoint>

struct WindowParameters {
    QSize windowSize;
    QPoint windowUpperCorner;
};

class BorderSize {
    private:
        short outer_width;
        short inner_width;
    public:
        BorderSize(short inner_w, short outer_w) {
            outer_width = outer_w;
            inner_width = inner_w;
        }
        BorderSize(const BorderSize& copy) {
            outer_width = copy.outer_width;
            outer_width = copy.outer_width;
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

#endif // UTILITIES_H
