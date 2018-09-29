#include "appsearchline.h"
#include "iconhelper.h"
AppSearchLine::AppSearchLine(QWidget *parent)
:QLineEdit(parent)
{
    mainLayout = new QHBoxLayout;
    searchBtn = new QPushButton;
    searchBtn->setFixedSize(13,13);
    searchBtn->setCursor(Qt::PointingHandCursor);
    searchBtn->setFlat(true);
    mainLayout->addWidget(searchBtn);
    mainLayout->addStretch();
    //mainLayout->setContentsMargins(8,8,8,8);
    mainLayout->setContentsMargins(8,0,0,0);
    setTextMargins(13+8+2,0,0,0);
    setContentsMargins(0,0,0,0);
    setLayout(mainLayout);
    
}

void AppSearchLine::InitStyle(QString test, QChar qChar, int fontSize)
{
    searchBtn->setToolTip(test);
    setPlaceholderText(test);
    IconHelper::Instance()->SetIcon(searchBtn, qChar, 13);
    //setStyleSheet("");
}
