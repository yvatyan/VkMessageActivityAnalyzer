#ifndef QTWIDGET_H
#define QTWIDGET_H

#include <QWidget>
#include <QPainter>

class QtWidget : public QWidget {
Q_OBJECT
    public:
        QtWidget(QWidget* parent = nullptr, bool autoFill = true) : QWidget(parent) {
            setAutoFillBackground(autoFill);
        }
        virtual void paintEvent(QPaintEvent* event) {
            //QPainter painter(this);
            //painter.translate(0, 0);
            //render(&painter);
            QWidget::paintEvent(event);
        }
};

#endif // QTWIDGET_H
