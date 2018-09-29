//
//  CRoundLabel.hpp
//  IMWorld
//
//  Created by leo on 2018/9/19.
//

#ifndef CRoundLabel_h
#define CRoundLabel_h

#include <stdio.h>
#include <QLabel>
#include <QPainter>
class CRoundLabel:public QLabel
{
    Q_OBJECT
public:
    CRoundLabel(QWidget* parent=0);
    void setImageHead(const QString & imagePath);
signals:
    void sigClick();
protected:
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
private:
    bool m_bTransLayer; //透明层
};
#endif /* CRoundLabel_hpp */
