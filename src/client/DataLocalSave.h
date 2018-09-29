//
//  DataLocalSave.hpp
//  IMWorld
//
//  Created by leo on 2018/9/26.
//

#ifndef DataLocalSave_h
#define DataLocalSave_h

#include <mutex>
#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QVariantList>

class DataLocalSave{
    
public:
    ~DataLocalSave();
    static DataLocalSave * getInstance()
    {
        if (m_instance == nullptr)
        {
            std::lock_guard<std::mutex> lgd(m_mt);
            if (m_instance == nullptr)
            {
                m_instance = new DataLocalSave;
            }
        }
        return m_instance;

    }
    static void delInstance()
    {
        std::lock_guard<std::mutex> lgd(m_mt);
        if (m_instance)
        {
            delete m_instance;
            m_instance = nullptr;
        }
    }
    
    bool selectTableData(QSqlQuery &sql_query, QString selectTableSql);
    bool insertTableData(const QString & insertTableSql);
    bool createTable(const QString & createTableSql);
    bool isTable(const QString & tableName);
private:
    DataLocalSave();
    DataLocalSave & operator=(const DataLocalSave & ) = delete;
    DataLocalSave(const DataLocalSave &) = delete;
    static DataLocalSave* m_instance;
    static std::mutex m_mt;
private:
    QSqlDatabase database;
};
#endif /* DataLocalSave_hpp */
