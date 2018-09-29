#include "logindialog.h"
#include "ui_logindialog.h"
#include "myHelper.h"
#include "iconhelper.h"
#include "Mac/QMacTools.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
 
    ui->setupUi(this);
    this->InitStyle();
    connect(ui->account_lineEdit, SIGNAL(returnPressed()), this, SLOT(sendLoginRequest()));
    connect(ui->password_lineEdit, SIGNAL(returnPressed()), this, SLOT(sendLoginRequest()));
   
}


LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::sendLoginRequest(){
    emit sendLoginRequest(ui->account_lineEdit->text(),ui->password_lineEdit->text());
}

void LoginDialog::InitStyle()
{
     QMacTools::InitLoginWindow(this->winId());
     QString imagePath = QString("%1%2").arg(HEADPATH).arg("15.jpeg");
     ui->loginHead_label->setImageHead(imagePath);
     ui->account_lineEdit->InitStyle("账户", QChar(0xf007), 24);
     ui->password_lineEdit->InitStyle("密码", QChar(0xf023), 24);
     ui->password_lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
     IconHelper::Instance()->SetIcon(ui->qrCode_label, QChar(0xf075), 18);
    
}
