//
//  QUserWiget.cpp
//  IMWorld
//
//  Created by leo on 2018/9/19.
//

#include "QUserWidget.h"
#include "iconhelper.h"


QUserWidget::QUserWidget(QWidget *parent) : QWidget(parent)
{
    qHBoxLayout_ = new QHBoxLayout();
    qHBoxLayout_->setContentsMargins(0, 5, 0, 5);
    closeLabel_ = new QLabel("");
    closeLabel_->setMinimumSize(10, 10);
    closeLabel_->setMaximumSize(10, 10);
    closeLabel_->setScaledContents(true);   //自动和文本一样的高度
    headLabel_ = new CRoundLabel;
    headLabel_->setMinimumSize(40, 40);
    headLabel_->setMaximumSize(40, 40);
    headLabel_->setScaledContents(true);
    qHBoxLayout_->addWidget(closeLabel_);
    qHBoxLayout_->addWidget(headLabel_);
    useInfoWidget = new QWidget();
    qVBoxLayout_ = new QVBoxLayout();
    qVBoxLayout_->setContentsMargins(0, 3, 0, 7);
    nicknameLabel_ = new QLabel("9");
    lastMessageLabel_ = new QLabel("10");
    useInfoWidget->setMinimumSize(this->width()-50, 50);
    useInfoWidget->setMaximumSize(this->width()-50, 50);
    nicknameLabel_->setMinimumSize(this->width()-50, 20);
   // nicknameLabel_->setMaximumSize(10, 50);
    lastMessageLabel_->setMinimumSize(this->width()-50, 20);
    //lastMessageLabel_->setMaximumSize(10, 50);
    qVBoxLayout_->addWidget(nicknameLabel_);
    qVBoxLayout_->addWidget(lastMessageLabel_);
    useInfoWidget->setLayout(qVBoxLayout_);
    qHBoxLayout_->addWidget(useInfoWidget);
    this->setLayout(qHBoxLayout_);
}

void QUserWidget::AddContents(long userid,const QString &nickname, const QString & lastMessage, const QString &imagePath){
    //IconHelper::Instance()->SetIcon(closeLabel_, QChar(0xf00d), 10);
    //closeLabel_->hide();
    headLabel_->setImageHead(imagePath);
    nicknameLabel_->setText(nickname);
    lastMessageLabel_->setText(lastMessage);
    this->imagePath = imagePath;
    this->user_id = userid;
    this->nickname = nickname;
}

void QUserWidget::UpdateLastMessage(QString lastMessage){
    lastMessageLabel_->setText(lastMessage);
    //
}
