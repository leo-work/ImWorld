/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <AppSearchLine.h>
#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *Title_widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    AppSearchLine *Search_lineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    CRoundLabel *label_8;
    QWidget *IM_widget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_12;
    QGridLayout *gridLayout;
    QListWidget *listWidget_3;
    QWidget *widget_13;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_11;
    QLabel *label_7;
    QListWidget *listWidget;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_10;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(877, 600);
        MainWindow->setMinimumSize(QSize(877, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Title_widget = new QWidget(centralWidget);
        Title_widget->setObjectName(QStringLiteral("Title_widget"));
        Title_widget->setMaximumSize(QSize(16777215, 54));
        horizontalLayout = new QHBoxLayout(Title_widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_3 = new QWidget(Title_widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(60, 0));
        widget_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(Title_widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(131, 40));
        widget_4->setMaximumSize(QSize(131, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Search_lineEdit = new AppSearchLine(widget_4);
        Search_lineEdit->setObjectName(QStringLiteral("Search_lineEdit"));
        Search_lineEdit->setMinimumSize(QSize(130, 0));
        Search_lineEdit->setMaximumSize(QSize(130, 16777215));

        verticalLayout_2->addWidget(Search_lineEdit);


        horizontalLayout->addWidget(widget_4);

        widget = new QWidget(Title_widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(250, 48));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(160, 40));
        widget_5->setMaximumSize(QSize(220, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(40, 40));
        label_2->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(40, 40));
        label_3->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(label_3);


        horizontalLayout_2->addWidget(widget_5);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(Title_widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(200, 48));
        widget_2->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        label_8 = new CRoundLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(35, 35));
        label_8->setMaximumSize(QSize(35, 35));

        horizontalLayout_6->addWidget(label_8);


        horizontalLayout->addWidget(widget_2);


        verticalLayout->addWidget(Title_widget);

        IM_widget = new QWidget(centralWidget);
        IM_widget->setObjectName(QStringLiteral("IM_widget"));
        IM_widget->setMinimumSize(QSize(0, 0));
        IM_widget->setMaximumSize(QSize(16777215, 16777215));
        IM_widget->setSizeIncrement(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(IM_widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_12 = new QWidget(IM_widget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(210, 0));
        widget_12->setMaximumSize(QSize(210, 16777215));
        gridLayout = new QGridLayout(widget_12);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_3 = new QListWidget(widget_12);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));

        gridLayout->addWidget(listWidget_3, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(widget_12);

        widget_13 = new QWidget(IM_widget);
        widget_13->setObjectName(QStringLiteral("widget_13"));

        horizontalLayout_4->addWidget(widget_13);

        widget_6 = new QWidget(IM_widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 0));
        widget_6->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_11 = new QWidget(widget_7);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(0, 45));
        widget_11->setMaximumSize(QSize(16777215, 45));
        label_7 = new QLabel(widget_11);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 0, 60, 40));
        label_7->setMinimumSize(QSize(0, 40));

        verticalLayout_5->addWidget(widget_11);

        listWidget = new QListWidget(widget_7);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_5->addWidget(listWidget);


        verticalLayout_3->addWidget(widget_7);

        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 180));
        widget_8->setMaximumSize(QSize(16777215, 180));
        verticalLayout_4 = new QVBoxLayout(widget_8);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 50));
        widget_9->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_5 = new QHBoxLayout(widget_9);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(30, 0, 0, 0);
        label_4 = new QLabel(widget_9);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(40, 40));
        label_4->setMaximumSize(QSize(40, 40));

        horizontalLayout_5->addWidget(label_4);

        label_5 = new QLabel(widget_9);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(40, 40));
        label_5->setMaximumSize(QSize(40, 40));

        horizontalLayout_5->addWidget(label_5);

        label_6 = new QLabel(widget_9);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(40, 40));
        label_6->setMaximumSize(QSize(40, 40));

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(16777038, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(widget_9);

        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        gridLayout_2 = new QGridLayout(widget_10);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget_10);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout_4->addWidget(widget_10);


        verticalLayout_3->addWidget(widget_8);


        horizontalLayout_4->addWidget(widget_6);


        verticalLayout->addWidget(IM_widget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\347\240\224\345\217\221-\351\237\251\345\274\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
