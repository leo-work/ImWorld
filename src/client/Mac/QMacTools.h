//
//  QMacTools.hpp
//  IMWorld
//
//  Created by Leo on 2018/9/11.
//

#ifndef QMacTools_hpp
#define QMacTools_hpp
#include <stdio.h>
#include <QMainWindow>


namespace QMacTools {
   // void windowDidResize(NSNotification *aNotification);
    void InitWindow(WId w);
    void InitLoginWindow(WId w);
    void CreateCocoaContianerForWindow(WId w, bool fullScreen);
};

#endif /* QMacTools_hpp */
