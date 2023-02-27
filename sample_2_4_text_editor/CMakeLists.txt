# 设置cmake最低版本号
cmake_minimum_required(VERSION 3.5)

# 设置工程名
project(sample_2_4_text_editor VERSION 0.1 LANGUAGES CXX)

# 设置自动生成ui.h文件，AUTOUIC打开可以省去QT5_WRAP_UI命令
set(CMAKE_AUTOUIC ON)
# 设置自动生成moc文件，，AUTOMOC打开可以省去QT5_WRAP_CPP命令
set(CMAKE_AUTOMOC ON)
# 可选，设置自动处理.qrc文件
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt5包，需要设置Qt5_HOME环境变量
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        # 添加资源文件
        Resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sample_2_4_text_editor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET sample_2_4_text_editor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(sample_2_4_text_editor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(sample_2_4_text_editor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(sample_2_4_text_editor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(sample_2_4_text_editor PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS sample_2_4_text_editor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sample_2_4_text_editor)
endif()
