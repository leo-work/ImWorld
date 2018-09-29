//
//  DataLocalSave.cpp
//  IMWorld
//
//  Created by leo on 2018/9/26.
//

#include "DataLocalSave.h"

DataLocalSave * DataLocalSave::m_instance = nullptr;
std::mutex DataLocalSave::m_mt;

DataLocalSave::DataLocalSave(){
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("CashSystem.db");
    if(database.open())
    {
         qDebug()<<"Database Opened";
    }
}
DataLocalSave::~DataLocalSave(){
    database.close();
    // QFile::remove("CashSystem.db");
}



bool DataLocalSave::isTable(const QString & tableName){
    QSqlQuery sql_query;
    QString show_sql = QString("select name from sqlite_master where name = '%1'").arg(tableName);
    sql_query.prepare(show_sql); //创建表
    if(!sql_query.exec()) //查看创建表是否成功
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    return sql_query.next();
}

bool DataLocalSave::createTable(const QString & createTableSql){
    QSqlQuery sql_query;
    sql_query.prepare(createTableSql);  //创建表
    if(!sql_query.exec())           //查看创建表是否成功
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    return true;
}
bool DataLocalSave::insertTableData(const QString &insertTableSql){
    QSqlQuery sql_query;
    sql_query.prepare(insertTableSql);  //创建表
    if(!sql_query.exec())           //查看创建表是否成功
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    return true;
}

bool DataLocalSave::selectTableData(QSqlQuery &sql_query, QString selectTableSql){
    sql_query.prepare(selectTableSql);  //创建表
    if(!sql_query.exec())           //查看创建表是否成功
    {
        qDebug()<<sql_query.lastError();
        return false;
    }
    return true;
}

