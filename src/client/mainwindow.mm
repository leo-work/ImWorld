#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <queue>
#include <stdio.h>
#include <unistd.h>
#include "Mac/QMacTools.h"
#include <QMimeData>
#include <QFile>
#include <QFileInfo>
#include <QImageReader>
#include "iconhelper.h"
#include "QUserWidget.h"
#include <QScrollBar>
#include <QMenu>
#include <QDateTime>
#include <QKeyEvent>
#include <QTextDocumentFragment>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->InitStyle();
    this->hide();
    loginDialog.show();
    connect(ui->listWidget_3, SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(ShowMenu(const QPoint&)));
    connect(ui->listWidget_3, SIGNAL(itemSelectionChanged()),this,SLOT(getCurWidget()));//重要的槽连接，检测是否有item改变

    connect(&dataReceive_, SIGNAL(loginSuccess(UserData)), this, SLOT(loginSuccess(UserData)));
    connect(&dataReceive_, SIGNAL(friendsSuccess(UserData, QString)), this, SLOT(friendsSuccess(UserData, QString)));
    connect(&loginDialog, SIGNAL(sendLoginRequest(QString, QString)), &dataReceive_, SLOT(sendLoginRequest(QString, QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitStyle(){
    m_dragging = false;
   // MyUserData.user_id = 88888888;
   // MyUserData.nickname = "谦谦君子";
    //MyUserData.imagePath = QString("%1%2").arg(HEADPATH).arg("15.jpeg");
    ui->Search_lineEdit->InitStyle("搜索", QChar(0xf002), 12);
    IconHelper::Instance()->SetIcon(ui->label, QChar(0xf075), 24);
    IconHelper::Instance()->SetIcon(ui->label_2, QChar(0xf007), 24);
    IconHelper::Instance()->SetIcon(ui->label_3, QChar(0xf009), 24);
    IconHelper::Instance()->SetIcon(ui->label_6, QChar(0xf017), 24);
    IconHelper::Instance()->SetIcon(ui->label_4, QChar(0xf119), 24);
    IconHelper::Instance()->SetIcon(ui->label_5, QChar(0xf03d), 24);
  
    ui->listWidget->setFrameShape(QListWidget::VLine);
    QMacTools::InitWindow(this->winId());
    QMacTools::CreateCocoaContianerForWindow(this->winId(), isFullScreen);
    ui->centralWidget->installEventFilter(this);
    ui->textEdit->installEventFilter(this);
    ui->listWidget_3->setMouseTracking(true);
    ui->listWidget_3->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    dataReceive_.createDataRecvWS();
    ui->widget_6->hide();
    ui->widget_13->show();
    ui->textEdit->setAcceptDrops(false);
    this->setAcceptDrops(true);
}

void MainWindow::loginSuccess(UserData  userData){
    this->MyUserData = userData;
    ui->label_8->setImageHead(MyUserData.imagePath);
    loginDialog.hide();
    
    dataReceive_.sendFriendsRequest(this->MyUserData.user_id);
  //  this->LoadUserList();
    this->show();
    
    
}

void MainWindow::getCurWidget(){
    QListWidgetItem *item = ui->listWidget_3->currentItem();
    QUserWidget * qUserWidget = (QUserWidget *)ui->listWidget_3->itemWidget(item);
    OtherUserData.user_id = qUserWidget->user_id;
    OtherUserData.nickname = qUserWidget->nickname;
    OtherUserData.imagePath = qUserWidget->imagePath;
    ui->label_7->setText(OtherUserData.nickname);
    ui->widget_13->hide();
    ui->listWidget->clear();
    ui->widget_6->show();
}

void MainWindow::friendsSuccess(UserData userData, QString message){
    QListWidgetItem *item = new QListWidgetItem();
    QSize size = item->sizeHint();
    item->setSizeHint(QSize(size.width(),60));
    ui->listWidget_3->addItem(item);
    QUserWidget * qUserWidget = new QUserWidget();
    qUserWidget->setSizeIncrement(size.width(),40);
    qUserWidget->AddContents(userData.user_id, userData.nickname, message, userData.imagePath);
    ui->listWidget_3->setItemWidget(item,qUserWidget);
}


void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent* event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
    {
        return;
    }
    qDebug()<<urls;
    
   // QString imageData = QString("\"<img< span=\"\" style=\"word-wrap: break-word;\"> src='%1'\"");
    QList<QUrl>::iterator it;
    for(it = urls.begin(); it != urls.end(); it++)
    {
        QUrl url = *it;
        QFileInfo fileInfo(it->toLocalFile());
        if(fileInfo.isFile())
        {
            QString imageData = QString("<img src='%1'>").arg(fileInfo.filePath());
            qDebug()<<imageData;
            ui->textEdit->append(imageData);
            QTextDocumentFragment fragment;
            fragment = QTextDocumentFragment::fromHtml(imageData);
            ui->textEdit->textCursor().insertFragment(fragment);
            ui->textEdit->setVisible(true);
            //ui->listWidget->addItem(fileInfo.filePath());
        }
    }
}
void MainWindow::resizeEvent(QResizeEvent* size){
    
    Q_UNUSED(size);
    for(int i = 0; i < ui->listWidget->count(); i++) {
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(ui->listWidget->item(i));
        QListWidgetItem* item = ui->listWidget->item(i);
        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
    }
    QMacTools::InitWindow(this->winId());
    if(this->windowState()==Qt::WindowFullScreen)
    {
        if(!isFullScreen){
            isFullScreen = true;
            QMacTools::CreateCocoaContianerForWindow(this->winId(), isFullScreen);
            return;
        }
        isFullScreen = false;
    }
    QMacTools::CreateCocoaContianerForWindow(this->winId(), isFullScreen);
}


void MainWindow::LoadUserList(){
    OtherUserData.imagePath = QString("%1%2").arg(HEADPATH).arg("3.jpg");
    for (int i = 0; i < 13; i++) {
       
    }
}

void MainWindow::UpdateUserList(long user_id, QString nickname, QString lastMessage){
    
}

void MainWindow::ShowMenu(const QPoint& pos){
    if(!((ui->listWidget_3->selectionModel()->selectedIndexes()).empty()))
    {
    
        QMenu *cmenu = new QMenu(ui->listWidget_3);
        QAction *upSortAction = cmenu->addAction("置顶");
        QAction *delSortAction = cmenu->addAction("删除");
       // connect(ascendSortAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu1()));
       // connect(descendSortAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu2()));
//connect(filterAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu3()));
       // connect(reshowAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu4()));
        cmenu->exec(QCursor::pos());//在当前鼠标位置显示
        //cmenu->exec(pos)是在viewport显示
        
        //把选中的清楚
        //ui->listWidget_3->selectionModel()->clear();
    }
}

void MainWindow::SendChatData()
{
    QString msg = ui->textEdit->toPlainText();
    qDebug()<<msg;
    ui->textEdit->setPlainText("");
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    
    bool isSending = false; // 发送中
    //if(ui->listWidget->count()%2) {
//        if(isSending) {
//            dealMessageTime(time);
//
//            QNChatMessage* messageW = new QNChatMessage(ui->listWidget);
//            QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
//            dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
//        } else {
            bool isOver = true;
            for(int i = ui->listWidget->count() - 1; i > 0; i--) {
                QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(ui->listWidget->item(i));
                if(messageW->text() == msg) {
                    isOver = false;
                    messageW->setTextSuccess();
                }
            }
            if(isOver) {
                dealMessageTime(time);
                
                QNChatMessage* messageW = new QNChatMessage(ui->listWidget);
                QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
                dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
                messageW->setTextSuccess();
            }
       // }
//    } else {
//        if(msg != "") {
//            dealMessageTime(time);
//
//            QNChatMessage* messageW = new QNChatMessage(ui->listWidget);
//            QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
//            dealMessage(messageW, item, msg, time, QNChatMessage::User_She);
//        }
//    }
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    //listWidget
   
}


void MainWindow::dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time,  QNChatMessage::User_Type type)
{
    messageW->setFixedWidth(ui->listWidget->width());
    QSize size = messageW->fontRect(text);
    qDebug()<<size;
    item->setSizeHint(QSize(size.width()+5, size.height()+15));
    messageW->setText(text, time, QSize(size.width()+5, size.height()+15), type, OtherUserData.imagePath,MyUserData.imagePath);
    ui->listWidget->setItemWidget(item, messageW);
}

void MainWindow::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(ui->listWidget->count() > 0) {
        QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
        //        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        QNChatMessage* messageTime = new QNChatMessage(ui->listWidget);
        QListWidgetItem* itemTime = new QListWidgetItem(ui->listWidget);
        
        QSize size = QSize(ui->listWidget->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time,OtherUserData.imagePath,MyUserData.imagePath);
        ui->listWidget->setItemWidget(itemTime, messageTime);
    }
}
bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    //Q_ASSERT(obj == ui->textEdit);
    //Q_ASSERT(obj == inputTextEdit);
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *event = static_cast<QKeyEvent*>(e);
        if (event->key() == Qt::Key_Return && (event->modifiers() & Qt::ControlModifier))
        {
            SendChatData(); //发送消息的槽
            return true;
        }
    }
    return false;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 只响应左键
    if (event->button() == Qt::LeftButton)
    {
        m_dragging = true;
        m_startPosition = event->globalPos();
        m_framePosition = frameGeometry().topLeft();
    }
    
    QWidget::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // 只响应左键
    if (event->buttons() & Qt::LeftButton)
    {
        if(m_dragging)
        {
            // delta 相对偏移量,
            QPoint delta = event->globalPos() - m_startPosition;
            // 新位置：窗体原始位置  + 偏移量
            move(m_framePosition + delta);
        }
    }
    
    QWidget::mouseMoveEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
    // 结束dragging
    m_dragging = false;
    QWidget::mouseReleaseEvent(event);
}


