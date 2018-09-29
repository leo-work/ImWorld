#设置cmake版本号
cmake_minimum_required(VERSION 3.4.0)
 

SET(CMAKE_PREFIX_PATH /home/nhk/Software/Qt5.10.1/5.10.1/gcc_64/lib/cmake)
#设置工程名称
PROJECT(IMWorld CXX) 
#编译机器限定（按需）
SET(ENV{Platform} x64) 

 #设置C++编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Wall ")

#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
 
#设置自动生成moc文件，一定要设置
set(CMAKE_AUTOMOC ON) 
 
#查找需要的Qt库文件，最好每一个库都要写，Qt也会根据依赖关系自动添加
find_package(Qt5Widgets)  
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Multimedia)
find_package(Qt5WebSockets)

#find_library(_Multimedia_LIBRARY Qt5Multimedia)

INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/include
  /usr/local/Cellar/ffmpeg/3.4.2/include
  /usr/local/include
  /Users/leo/anaconda3/include/qt
  /usr/include
)
LINK_DIRECTORIES(
  ${PROJECT_BINARY_DIR}/lib
  /usr/local/Cellar/ffmpeg/3.4.2/lib
  /Users/leo/anaconda3/lib
  /usr/local/lib
  /use/lib64
) 

# 设置可执行文件目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置库文件目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 添加源文件目录
ADD_SUBDIRECTORY(src/client)