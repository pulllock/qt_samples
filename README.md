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
  - Base class：QMainWindow是主窗口类，主窗口具有主菜单栏、工具栏、状态栏
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

# 数据类型定义

- qint8：signed char，1字节
- qint16：signed short，2字节
- qint32：signed int，4字节
- qint64：long long int，8字节
- qlonglong：long long int，8字节
- quint8：unsigned char，1字节
- quint16：unsigned short，2字节
- quint32：unsigned int，4字节
- quint64：unsigned long long int，8字节
- qulonglong：unsigned long long int，8字节
- uchar：unsigned char，1字节
- ushort：unsigned short，2字节
- uint：unsigned int，4字节
- ulong：unsigned long 8字节
- qreal：double，8字节，默认是8字节double类型浮点数，如果Qt使用-qreal float进行配置，就是4字节float类型的浮点数
- qfloat16：2字节，表示16位的浮点数，需要包含头文件`<QFloat16>`

# 容器类

- 顺序容器
- 关联容器

## 顺序容器类

- QList，以数组列表的形式实现
- QLinkedList，是链式列表
- QVector，提供动态数组的功能
- QStack，提供类似于堆栈的后入先出操作的容器类
- QQueue，提供类似于队列先入先出操作的容器类

## 关联容器类

- `QMap<Key, T>`：提供一个字典，一个键映射到一个值
- QMultiMap，支持一个键关联多个值
- QHash，基于散列表来实现字典功能的模板类
- QMultiHash，支持一个键关联多个值
- QSet，基于散列表的集合模板类

## 容器类的迭代

- Java类型迭代器
- STL类型的迭代器

### foreach关键字

`foreach(variable, container)`

# Qt类库的模块

- Qt基本模块（Qt Essential）：提供了Qt在所有平台上的基本功能
  - Qt Core：核心非图形类
  - Qt GUI：设计GUI界面的基础类，包括OpenGL
  - Qt Multimedia：音频，视频，摄像头和广播功能的类
  - Qt Multimedia Widgets：实现多媒体功能的界面组件类
  - Qt Network：网络编程
  - Qt QML：使用QML和JavaScript语言的类
  - Qt Quick：用于构建具有定制用户界面的动态应用程序的声明框架
  - Qt Quick Controls：创建桌面样式用户界面，基于Qt Quick的用户界面控件
  - Qt Quick Dialogs：用于Qt Quick的系统对话框类型
  - Qt Quick Layouts：用于Qt Quick 2界面元素的布局项
  - Qt SQL：用于数据库操作
  - Qt Test：用于进行单测的类
  - Qt Widgets：用于构建GUI界面的C++图形组件类
- Qt附加模块（Qt Add-Ons）：实现一些特定功能的提供附加价值的模块，这些模块可能只在某些开发平台上有或者只能用于某些操作系统或者为了向后兼容
  - Active Qt：用于开发使用ActiveX和COM的Windows应用程序
  - Qt 3D：支持2D和3D渲染，提供用于开发近实时仿真系统的功能
  - Qt Android Extras：提供安卓平台相关的API
  - Qt Bluetooth：提供访问蓝牙硬件的功能
  - Qt Concurrent：提供一些类，无需使用底层的线程控制就可以编写多线程程序
  - Qt D-Bus：使进程间通过D-Bus协议通信
  - Qt Gamepad：Qt应用程序支持游戏手柄硬件的使用
  - Qt Image Formats：支持附加图片格式的插件，包括：TIFF、MNG、TGA、WBMP
  - Qt Mac Extras：提供macOS平台相关的API
  - Qt NFC：提供访问NFC硬件的功能
  - Qt Positioning：通过GPS、WiFi等定位
  - Qt Print Support：用于打印控制
  - Qt Purchasing：应用内购买功能
  - Qt Sensors：访问传感器硬件的功能，以识别运动和手势
  - Qt Serial Bus：访问串行工业总线的功能，目前只支持CAN和Modbus协议
  - Qt SVG：提供显示SVG图片文件的类
  - Qt WebChannel：用于实现服务器端（QML或C++应用程序）与客户端（HTML/JavaScript或QML应用程序）之间的P2P通信
  - Qt WebEngine：在应用程序中嵌入网页内容
  - Qt WebSockets：提供兼容RFC 6455的WebSocket通信
  - Qt Windows Extras：提供Windows平台相关的API
  - Qt XML：该模块不再维护，使用Qt Core中的QXmlStreamReader和QXmlStreamWriter
  - Qt XML Patterns：提供对XPath，XQuery，XSLT和XML等的支持
  - Qt Charts：用于数据显示的二维图表组件
  - Qt Data Visualization：用于3D数据可视化显示的界面组件
  - Qt Virtual Keyboard：实现不同输入法的虚拟键盘框架
- 增值模块（Value-Add Modules）：单独发布的提供额外价值的模块或工具
  - Qt for Device Creation：嵌入式设备应用程序开发工具
  - Qt Quick Compiler：编译.qml源文件生成二进制应用程序的编译器
- 技术预览模块（Technology Preview Modules）：一些处于开发阶段，但是可以作为技术预览使用的模块
  - Qt Network Authorization：基于OAuth协议，为应用程序提供网络账号验证的功能
  - Qt Speech：提供文字转语音功能支持
  - Qt Remote Objects：进程间或设备间通信，共享QObject的API
- Qt工具（Qt Tools）：帮助应用程序开发的一些工具，在所有支持的平台上都可以使用
  - Qt Designer：用于扩展Qt Designer的类
  - Qt Help：在应用程序中集成在线文档的类，实现类似于Qt Assistant的功能
  - Qt UI Tools：操作Qt Designer生成窗体的类
