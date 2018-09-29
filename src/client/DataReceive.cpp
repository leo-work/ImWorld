#include "DataReceive.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
DataReceive::DataReceive(QObject *parent):QObject(parent)
{
    dataRecvWS = Q_NULLPTR;
    connectStatus = false;
    m_timer = new QTimer();
}

DataReceive::~DataReceive(){
    
}

/**
 * @breaf 创建WebSocket连接
 */
void DataReceive::createDataRecvWS(){
    if(dataRecvWS == Q_NULLPTR){
        dataRecvWS = new QWebSocket();
        qDebug()<<"create websocket!";
        QObject::connect(dataRecvWS,SIGNAL(disconnected()),this, SLOT(onDisConnected()),Qt::AutoConnection);
    QObject::connect(dataRecvWS,SIGNAL(binaryMessageReceived(QByteArray)),this,SLOT(onMessageReceived(QByteArray)),Qt::AutoConnection);
        
   QObject::connect(dataRecvWS,SIGNAL(textMessageReceived(QString)),this,SLOT(onStrMessageReceived(QString)),Qt::AutoConnection);
        QObject::connect(dataRecvWS,SIGNAL(connected()),this,SLOT(onConnected()),Qt::AutoConnection);
        QObject::connect(m_timer,SIGNAL(timeout()),this,SLOT(reconnect()),Qt::AutoConnection);
        dataRecvWS->open(QUrl(SERVERURL));
    }
}

/**
 * @breaf 判断连接状态
 * @note  当连接成功后，触发该函数
 */
void DataReceive::onConnected(){
    qDebug()<<"DataReveive websocket is already connect!";
    connectStatus = true;
    m_timer->stop();
    qDebug()<<"Address："<<dataRecvWS->peerAddress();
    
    
}
void DataReceive::onStrMessageReceived(QString message){
  //  qDebug()<<message;
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(message.toUtf8(), &jsonError);  // 转化为 JSON 文档
    int cmd = 0;
    int success = 0;
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (doucment.isObject()) {  // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象
            if (object.contains("cmd")) {
                cmd = object.value("cmd").toInt();
            }
            if (object.contains("success")) {
                success = object.value("success").toInt();
                if(success == 0){
                    if (object.contains("error")) {
                        QJsonValue value = object.value("error");
                        if (value.isObject()) {  // Page 的 value 是对象
                            QJsonObject obj = value.toObject();
                            if (obj.contains("cmd")) {
                                int error_cmd = obj.value("cmd").toInt();
                            }
                            if (obj.contains("message")) {
                                QJsonValue value = obj.value("message");
                                if (value.isString()) {
                                    QString error_message = value.toString();
                                    qDebug() << "error_message : " << error_message;
                                }
                            }
                        }
                    }
                    // 发送失败的信号
                }
            }
            if (object.contains("data")) {
                QJsonValue value = object.value("data");
                if(value.Array){
                    QJsonArray array = value.toArray();
                    
                    messageParse(cmd, array);
                }
            }
            
        }
    }
}
/**
 * @breaf 数据处理函数
 * @param msg，数据信息
 * @note  当收到服务端发送的数据时，触发该函数
 */
void DataReceive::onMessageReceived(QByteArray msg){
    qDebug()<<"----------------data-----------------";
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(msg, &jsonError);  // 转化为 JSON 文档
    int cmd = 0;
    int success = 0;
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (doucment.isObject()) {  // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象
            if (object.contains("cmd")) {
                cmd = object.value("cmd").toInt();
            }
            if (object.contains("success")) {
                success = object.value("success").toInt();
                if(success == 0){
                    if (object.contains("error")) {
                        QJsonValue value = object.value("error");
                        if (value.isObject()) {  // Page 的 value 是对象
                            QJsonObject obj = value.toObject();
                            if (obj.contains("cmd")) {
                                int error_cmd = obj.value("cmd").toInt();
                            }
                            if (obj.contains("message")) {
                                QJsonValue value = obj.value("message");
                                if (value.isString()) {
                                    QString error_message = value.toString();
                                    qDebug() << "error_message : " << error_message;
                                }
                            }
                        }
                    }
                    // 发送失败的信号
                }
            }
            if (object.contains("data")) {
                QJsonValue value = object.value("data");
                if(value.Array){
                    QJsonArray array = value.toArray();
                    messageParse(cmd, array);
                }
            }
          
        }
    }
    
}

void DataReceive::messageParse(int cmd, const QJsonArray &array){
    qDebug()<<"---array---" << array;
   
    switch (cmd) {
        case 100001:
            if(!array.empty()){
                if(array[0].isObject()){
                    UserData myUserData;
                    QJsonObject object = array[0].toObject();
                    if (object.contains("userid")) {
                        
                        myUserData.user_id = object.value("userid").toInt();
                    }
                    if (object.contains("image")) {
                        myUserData.imagePath = QString("%1%2.jpg").arg(HEADPATH).arg(object.value("image").toInt());
                     
                    }
                    if (object.contains("nickname")) {
                        QJsonValue value = object.value("nickname");
                        if (value.isString()) {
                            myUserData.nickname = value.toString();
                        }
                    }
                    emit loginSuccess(myUserData);
                    qDebug()<<"success .."<<myUserData.user_id;
                }
            }
            break;
        case 100002:
            for (int index = 0; index < array.size(); index++) {
                if(array[index].isObject()){
                    UserData userData;
                    QJsonObject object = array[index].toObject();
                    if (object.contains("userid")) {
                        
                        userData.user_id = object.value("userid").toInt();
                    }
                    if (object.contains("image")) {
                        userData.imagePath = QString("%1%2.jpg").arg(HEADPATH).arg(object.value("image").toInt());
                        
                    }
                    if (object.contains("nickname")) {
                        QJsonValue value = object.value("nickname");
                        if (value.isString()) {
                            userData.nickname = value.toString();
                        }
                    }
                    emit friendsSuccess(userData, QString("%1 is a boy!").arg(userData.nickname));
                }
            }
            break;
        case 100004:
            
            break;
            
        default:
            break;
    }
}

/**
 * @breaf 连接断开
 * @note  当连接断开时，触发该函数
 */
void DataReceive::onDisConnected(){
    qDebug()<<"DataReceive websocket is disconnected!!!";
    connectStatus = false;
    m_timer->start(3000);/*-<当连接失败时，触发重连计时器，设置计数周期为3秒 */
}

/**
 * @breaf 周期重连函数
 * @note  连接建立成功时，调用该函数
 */
void DataReceive::reconnect(){
    qDebug()<<"try to reconnect!";
    dataRecvWS->abort();
    dataRecvWS->open(QUrl(SERVERURL));
}


long DataReceive::sendChartData(const QByteArray &data){
    return dataRecvWS->sendBinaryMessage(data);
}
void DataReceive::sendLoginRequest(QString account, QString password){
    // 构建 JSON 对象
    QJsonObject jsonObject;
    jsonObject.insert("userid", account.toInt());
    jsonObject.insert("password", password);
    jsonObject.insert("cmd", 100001);

    // 构建 JSON 文档
    QJsonDocument jsonDocument;
    jsonDocument.setObject(jsonObject);
    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Compact);
    long req = sendChartData(byteArray);
    QString msg(byteArray);
    qDebug()<<"sendLoginRequest----"<<msg;
}

long DataReceive::sendFriendsRequest(const int &userid){
    // 构建 JSON 对象
    QJsonObject jsonObject;
    jsonObject.insert("userid", userid);
    jsonObject.insert("cmd", 100002);
    
    // 构建 JSON 文档
    QJsonDocument jsonDocument;
    jsonDocument.setObject(jsonObject);
    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Compact);
   // long req = sendChartData(byteArray);
    //QString msg(byteArray);
    return sendChartData(byteArray);
}
long DataReceive::sendOtherUserMessage(const int &userid, const int &otherid, const QString &message){
    QJsonObject jsonObject;
    jsonObject.insert("userid", userid);
    jsonObject.insert("cmd", 100003);
    jsonObject.insert("message", message);
    // 构建 JSON 文档
    QJsonDocument jsonDocument;
    jsonDocument.setObject(jsonObject);
    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Compact);
    // long req = sendChartData(byteArray);
    //QString msg(byteArray);
    return sendChartData(byteArray);
}
