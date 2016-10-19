#ifndef QTWIDGET_H
#define QTWIDGET_H

#include <QWidget>
#include <QPainter>

class QtWidget : public QWidget {
Q_OBJECT
    public:
        QtWidget(QWidget* parent = nullptr) : QWidget(parent) {
            setAutoFillBackground(true);
        }
        virtual void paintEvent(QPaintEvent* event) {
            //QPainter painter(this);
            //painter.translate(0, 0);
            //render(&painter);
            QWidget::paintEvent(event);
        }
};

#endif // QTWIDGET_H
