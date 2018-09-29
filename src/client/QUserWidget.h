//
//  QUserWiget.hpp
//  IMWorld
//
//  Created by leo on 2018/9/19.
//

#ifndef QUserWiget_h
#define QUserWiget_h

#include <stdio.h>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include "CRoundLabel.h"



class QUserWidget : public QWidget
{
public:
    explicit QUserWidget(QWidget *parent = nullptr);
    QHBoxLayout * qHBoxLayout_;
    QLabel * closeLabel_;
    CRoundLabel * headLabel_;
    QWidget * useInfoWidget;
    QLabel * nicknameLabel_;
    QLabel * lastMessageLabel_;
    QVBoxLayout * qVBoxLayout_;
    long user_id;
    QString nickname;
    QString imagePath;
public:
    void AddContents(long userid, const QString &nickname, const QString & lastMessage, const QString &imagePath);
    void UpdateLastMessage(QString lastMessage);
};
#endif /* QUserWiget_hpp */
