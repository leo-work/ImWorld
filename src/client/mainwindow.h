#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAudio>//一下这五个是QT处理音频的库
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>
#include <QListWidgetItem>
#include <QPoint>
#include "qnchatmessage.h"
#include "DataReceive.h"
#include "logindialog.h"
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitStyle();
    void SendChatData();
    void dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time, QNChatMessage::User_Type type);
    void dealMessageTime(QString curMsgTime);
private:
    void LoadUserList();
public slots:
    void UpdateUserList(long user_id, QString nickname, QString lastMessage);
    void ShowMenu(const QPoint& pos);
    
    void loginSuccess(UserData userData);
    void friendsSuccess(UserData userData, QString message);
    
    void getCurWidget();
private:
    Ui::MainWindow *ui;
    
    bool isFullScreen = false;
    UserData MyUserData;
    UserData OtherUserData;
    bool m_dragging; // 是否正在拖动
    QPoint m_startPosition; // 拖动开始前的鼠标位置
    QPoint m_framePosition; // 窗体的原始位置
    DataReceive dataReceive_;
    
    LoginDialog loginDialog;
    
protected:
    void resizeEvent(QResizeEvent* size);
    bool eventFilter(QObject *obj, QEvent *e);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    
    /*功能:窗体的整体拖动*/
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    
    
};

#endif // MAINWINDOW_H
