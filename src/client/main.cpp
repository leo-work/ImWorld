#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "myhelper.h"
#include "DataLocalSave.h"

int main(int argc, char *argv[])
{
  
    QApplication a(argc, argv);
    myHelper::SetUTF8Code();
    myHelper::SetStyle("blue");//天蓝色风格
    //DoWork();
    //判断是否有登陆的用户信息 判断是否登陆数据过期
    qDebug()<<DataLocalSave::getInstance()->isTable("rr");
    MainWindow mainWindow;
   // mainWindow.show();
    return a.exec();
}
