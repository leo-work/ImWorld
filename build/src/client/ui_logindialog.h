/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <AppSearchLine.h>
#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *loginTitle_widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *qrCode_label;
    QWidget *login_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    CRoundLabel *loginHead_label;
    QWidget *userInfo_widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    AppSearchLine *account_lineEdit;
    AppSearchLine *password_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *loginSet_widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *autoLogin_checkBox;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *fogetKey_label;
    QLabel *register_label_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(260, 320);
        LoginDialog->setMinimumSize(QSize(260, 320));
        LoginDialog->setMaximumSize(QSize(260, 320));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        loginTitle_widget = new QWidget(LoginDialog);
        loginTitle_widget->setObjectName(QStringLiteral("loginTitle_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginTitle_widget->sizePolicy().hasHeightForWidth());
        loginTitle_widget->setSizePolicy(sizePolicy);
        loginTitle_widget->setMinimumSize(QSize(100, 33));
        horizontalLayout_2 = new QHBoxLayout(loginTitle_widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        qrCode_label = new QLabel(loginTitle_widget);
        qrCode_label->setObjectName(QStringLiteral("qrCode_label"));
        qrCode_label->setMinimumSize(QSize(30, 30));
        qrCode_label->setMaximumSize(QSize(30, 16777215));
        qrCode_label->setLayoutDirection(Qt::LeftToRight);
        qrCode_label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(qrCode_label);


        verticalLayout->addWidget(loginTitle_widget);

        login_widget = new QWidget(LoginDialog);
        login_widget->setObjectName(QStringLiteral("login_widget"));
        verticalLayout_2 = new QVBoxLayout(login_widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(login_widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 120));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginHead_label = new CRoundLabel(widget);
        loginHead_label->setObjectName(QStringLiteral("loginHead_label"));
        loginHead_label->setMinimumSize(QSize(100, 100));
        loginHead_label->setMaximumSize(QSize(100, 100));
        loginHead_label->setMargin(0);

        gridLayout->addWidget(loginHead_label, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget);

        userInfo_widget = new QWidget(login_widget);
        userInfo_widget->setObjectName(QStringLiteral("userInfo_widget"));
        userInfo_widget->setMinimumSize(QSize(0, 90));
        userInfo_widget->setMaximumSize(QSize(260, 16777215));
        gridLayout_2 = new QGridLayout(userInfo_widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        account_lineEdit = new AppSearchLine(userInfo_widget);
        account_lineEdit->setObjectName(QStringLiteral("account_lineEdit"));
        account_lineEdit->setMinimumSize(QSize(180, 30));
        account_lineEdit->setMaximumSize(QSize(180, 30));

        gridLayout_2->addWidget(account_lineEdit, 1, 0, 1, 1);

        password_lineEdit = new AppSearchLine(userInfo_widget);
        password_lineEdit->setObjectName(QStringLiteral("password_lineEdit"));
        password_lineEdit->setMinimumSize(QSize(180, 30));
        password_lineEdit->setMaximumSize(QSize(180, 30));

        gridLayout_2->addWidget(password_lineEdit, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 1);


        verticalLayout_2->addWidget(userInfo_widget);

        loginSet_widget = new QWidget(login_widget);
        loginSet_widget->setObjectName(QStringLiteral("loginSet_widget"));
        loginSet_widget->setMinimumSize(QSize(0, 40));
        loginSet_widget->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(loginSet_widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        autoLogin_checkBox = new QCheckBox(loginSet_widget);
        autoLogin_checkBox->setObjectName(QStringLiteral("autoLogin_checkBox"));
        autoLogin_checkBox->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(autoLogin_checkBox);

        widget_4 = new QWidget(loginSet_widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(150, 0));
        widget_4->setMaximumSize(QSize(150, 16777215));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        fogetKey_label = new QLabel(widget_4);
        fogetKey_label->setObjectName(QStringLiteral("fogetKey_label"));

        horizontalLayout_3->addWidget(fogetKey_label);

        register_label_2 = new QLabel(widget_4);
        register_label_2->setObjectName(QStringLiteral("register_label_2"));

        horizontalLayout_3->addWidget(register_label_2);


        horizontalLayout->addWidget(widget_4);


        verticalLayout_2->addWidget(loginSet_widget);


        verticalLayout->addWidget(login_widget);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", Q_NULLPTR));
        qrCode_label->setText(QApplication::translate("LoginDialog", "1", Q_NULLPTR));
        loginHead_label->setText(QApplication::translate("LoginDialog", "1", Q_NULLPTR));
        autoLogin_checkBox->setText(QApplication::translate("LoginDialog", "\350\207\252\345\212\250\347\231\273\351\231\206", Q_NULLPTR));
        fogetKey_label->setText(QApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", Q_NULLPTR));
        register_label_2->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
