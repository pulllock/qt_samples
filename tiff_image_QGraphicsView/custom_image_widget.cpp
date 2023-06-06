#include "custom_image_widget.h"

CustomImageWidget::CustomImageWidget(QPixmap *pixmap) {
    m_pixmap = *pixmap;
    m_currentScaleValue = 0;
    m_scaleDefault = 0;
    m_dragging = false;
    setAcceptDrops(true);
}

QRectF CustomImageWidget::boundingRect() const {
    return QRectF(-m_pixmap.width() / 2, -m_pixmap.height() / 2, m_pixmap.width(), m_pixmap.height());
}

void CustomImageWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(-m_pixmap.width() / 2, -m_pixmap.height() / 2, m_pixmap);
}

void CustomImageWidget::wheelEvent(QGraphicsSceneWheelEvent *event) {
   // 最大能放大到原始图片的100倍
   int max_scale_value = 100;
   if (event->delta() > 0 && m_currentScaleValue >= max_scale_value) {
      return;
   }

   // 缩小到图片自适应大小之后，就不能继续缩小了
   else if (event->delta() < 0 && m_currentScaleValue <= m_scaleDefault) {
       // 重置图片大小和位置，自适应控件大小
       resetToDefault();
   }

   else {
       qreal originScal = m_currentScaleValue;
       // 鼠标滚轮向前滚动，放大
       if (event->delta() > 0) {
           // 每次放大10%
           m_currentScaleValue *= 1.1;
       }
       // 鼠标滚轮向后滚动，缩小
       else {
           // 每次缩小10%
           m_currentScaleValue *= 0.9;
       }

       // 缩放
       setScale(m_currentScaleValue);

       if (event->delta() > 0) {
           // 使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
           moveBy(-event->pos().x() * originScal * 0.1, -event->pos().y() * originScal * 0.1);
       }

       else {
           // 使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
           moveBy(event->pos().x() * originScal * 0.1, event->pos().y() * originScal * 0.1);
       }
   }
}

void CustomImageWidget::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // 鼠标左键按下
    if (event->button() == Qt::LeftButton) {
        // 获取当前鼠标在图片中的坐标
        m_startDraggPosition = event->pos();
        // 记录正在拖动图片
        m_dragging = true;
    }
    // 鼠标右键按下
    else {
        // 重置大小
        resetToDefault();
    }
}

void CustomImageWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_dragging) {
        QPointF point = (event->pos() - m_startDraggPosition) * m_currentScaleValue;
        moveBy(point.x(), point.y());
    }
}

void CustomImageWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    // 鼠标左键抬起，不再进行拖动
    m_dragging = false;
}

void CustomImageWidget::setQGraphicsViewWidthAndHeight(int width, int height) {
    int pixmapWidth = m_pixmap.width();
    int pixmapHeight = m_pixmap.height();

    qreal scaleWidth = width * 1.0 / pixmapWidth;
    qreal scaleHeight = height * 1.0 / pixmapHeight;

    if (scaleWidth > scaleHeight) {
        m_scaleDefault = scaleHeight;
    } else {
        m_scaleDefault = scaleWidth;
    }

    setScale(m_scaleDefault);
    m_currentScaleValue = m_scaleDefault;
}

void CustomImageWidget::resetToDefault() {
    // 设置为初始的自适应比例
    m_currentScaleValue = m_scaleDefault;
    setScale(m_currentScaleValue);
    setPos(0, 0);
}
