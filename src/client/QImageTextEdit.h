//
//  QImageTextEdit.hpp
//  IMWorld
//
//  Created by leo on 2018/9/25.
//

#ifndef QImageTextEdit_hpp
#define QImageTextEdit_hpp

#include <stdio.h>
#include <QTextEdit>
#include <QMimeData>
#include <QFile>
#include <QFileInfo>
#include <QImageReader>
class QImageTextEdit : public QTextEdit
{
public:
    bool canInsertFromMimeData(const QMimeData* source)const;
    void insertFromMimeData(const QMimeData* source);
    
private:
    void dropImage(const QUrl& url, const QImage& image);
    void dropTextFile(const QUrl& url);
};
#endif /* QImageTextEdit_hpp */
