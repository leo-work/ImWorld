//
//  80308431?utm_source=copy.hpp
//  IMWorld
//
//  Created by leo on 2018/9/21.
//


#ifndef DATARECEIVE_H
#define DATARECEIVE_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <QTimer>
#include "iconhelper.h"
#define SERVERURL "ws://127.0.0.1:9001"
struct UserData{
    long user_id;
    QString nickname;
    QString imagePath;
};
class DataReceive : public QObject
{
    Q_OBJECT
public:
    DataReceive(QObject *parent=0);
    ~DataReceive();
    void createDataRecvWS();    /*-<创建websocket连接 */

    long sendChartData(const QByteArray &data);
private:
    QWebSocket *dataRecvWS;     /*-<websocket类 */
    bool connectStatus;         /*-<websocket连接状态，连接成功：true；断开：false */
    QTimer *m_timer;            /*-<周期重连Timer */
    
    void messageParse(int cmd, const QJsonArray &array);
private slots:
    void onConnected();                         /*-<socket建立成功后，触发该函数 */
    void onMessageReceived(QByteArray message); /*-<收到Sev端的数据时，触发该函数 */
    void onStrMessageReceived(QString message);

    void onDisConnected();                      /*-<socket连接断开后，触发该函数 */
    void reconnect();                           /*-<周期重连函数 */
    
public slots:
    void sendLoginRequest(QString account, QString password);
signals:
    void loginSuccess(UserData userData);
    void friendsSuccess(UserData userData, QString message);
   // long sendFriendsRequest(const QString &account);
public:
    long sendFriendsRequest(const int &account);
    long sendOtherUserMessage(const int &userid, const int &otherid, const QString &message);
};

#endif // DATARECEIVE_H


