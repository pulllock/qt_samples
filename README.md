# qt_samples
QT samples

# Qt功能模块

- MinGW（Minimalist GUN for Windows），Windows平台上使用的GUN工具集导入库的集合
- UWP是Windows 10中Universal Windows Platform的简称，UWP编译模块
- MSVC，Windows平台上的MSVC编译器模块
- Android平台模块
- Sources是Qt源码
- Qt Charts是二维图表模块，可绘制柱状图，饼图，曲线图等
- Qt Data Visualization是三维图表模块，可绘制散点的三维空间分布、三维曲面等
- Tools是工具软件
  - Qt Creator用于Qt开发的IDE
  - MinGW是MinGW编译工具链

# 工具软件

- Assistant是Qt帮助文件程序
- Designer是可视化的界面设计程序
- Linguist是编辑语言资源文件的程序

# 可创建的应用程序的模板

- Qt Widgets Application支持桌面平台的有图形用户界面的应用程序，GUI设计完全基于C++，采用Qt提供的一套C++类库
  - Base class：QmainWindow是主窗口类，主窗口具有主菜单栏、工具栏、状态栏
  - Base class：QWidget是所有具有可视界面类的基类，QWidget创建的界面对各种界面组建都可以支持
  - Base class：QDialog是对话框类，可建立一个基于对话框的界面
- Qt Console Application控制台应用程序，无GUI界面
- Qt Quick Application创建可部署的Qt Quick 2应用程序，Qt Quick是Qt支持的一套GUI开发架构，界面设计采用QML语言，程序架构采用C++，可设计非常炫酷的用户界面，一般用于移动设备或嵌入式设备上无边框的应用程序设计
- Qt Quick Controls 2 Application创建基于Qt Quick Controls 2组件的可部署的Qt Quick 2应用程序
- Qt Canvas 3D Application创建Qt Canvas 3D QML项目，基于QML语言的界面设计，支持3D画布

# 项目结构

- Header Files是项目内的所有头文件`.h`
- Source Files是项目内所有的C++源文件`.cpp`
- `.ui`文件是界面文件，是文本文件，使用XML语言描述界面的组成
