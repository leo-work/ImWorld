//
//  CRoundLabel.cpp
//  IMWorld
//
//  Created by leo on 2018/9/19.
//

#include "CRoundLabel.h"
CRoundLabel::CRoundLabel(QWidget *parent):QLabel(parent)
{
    m_bTransLayer = false;
}
void CRoundLabel::paintEvent(QPaintEvent *e)
{
    if(NULL != pixmap())
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        QPainterPath path;
        int round = qMin(width(), height());
        path.addEllipse(0, 0, round, round);
        painter.setClipPath(path);
        painter.drawPixmap(-1, -1, width()+2, height()+2, *pixmap());
        if(m_bTransLayer)
        {
            //鼠标在label上，加载透明图片
           // QPixmap pixMap("/Users/leo/LEO/IM/IMWorld/image/checkbox_unchecked.png");
            //painter.drawPixmap(-1, -1, width()+2, height()+2, pixMap);
        }
    }
    else
    {
        QLabel::paintEvent(e);
    }
}
void CRoundLabel::enterEvent(QEvent *event)
{
    m_bTransLayer = true;
    update();//刷新label
}
void CRoundLabel::leaveEvent(QEvent *event)
{
    m_bTransLayer = false;
    update();//刷新label
}
void CRoundLabel::mousePressEvent(QMouseEvent *ev)
{   //鼠标单击消息
   emit sigClick();
}

void CRoundLabel::setImageHead(const QString & imagePath){
    QPixmap pixMap(imagePath);
    this->setPixmap(pixMap);//初始化一个默认图片,可按需要调用这个接口改变label的图片
    this->setGeometry(10, 10, 80, 80);
}
