#ifndef APPSEARCHLINE_H
#define APPSEARCHLINE_H

#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
class AppSearchLine : public QLineEdit
{
    Q_OBJECT
public:
    AppSearchLine(QWidget *parent = 0);
    QHBoxLayout *mainLayout;
    QPushButton *searchBtn;
    
    void InitStyle(QString test, QChar qChar, int fontSize);
};

#endif // APPSEARCHLINE_H


