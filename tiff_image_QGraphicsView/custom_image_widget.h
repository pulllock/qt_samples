#ifndef CUSTOM_IMAGE_WIDGET_H
#define CUSTOM_IMAGE_WIDGET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class CustomImageWidget:public QGraphicsItem {

public:
    CustomImageWidget(QPixmap *pixmap);
    /**
     * 根据QGraphicsView的长宽和图片的实际长宽来设置QGraphicsView的宽度和高度，按照比例来使图片缩放到适合QGraphicsView控件的大小
     * @brief setQGraphicsViewWidthAndHeight
     * @param wight
     * @param height
     */
    void setQGraphicsViewWidthAndHeight(int wight, int height);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    /**
     * 鼠标滚轮事件
     * @brief wheelEvent
     * @param event
     */
    void wheelEvent(QGraphicsSceneWheelEvent *event);

    /**
     * 重置图片到默认的自适应状态
     * @brief resetToDefault
     */
    void resetToDefault();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QPixmap m_pixmap;
    // 默认的缩放值
    qreal m_scaleDefault;
    // 当前的缩放值
    qreal m_currentScaleValue;

    // 图片是否正在被拖动
    bool m_dragging;
    // 图片被拖动的开始位置
    QPointF m_startDraggPosition;
};

#endif // CUSTOM_IMAGE_WIDGET_H
