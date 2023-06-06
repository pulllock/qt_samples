# 第一行必须是最低版本要求
cmake_minimum_required(VERSION 3.5)

# 如果CMake版本低于3.12，则CMake将被设置为当前版本
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# 设置项目
# 第一个参数cmake_test项目名字
# 第二个参数VERSION 1.0是版本号
# 第三个参数LANGUAGES CXX是语言，语言可以是：C,CXX,Fortran,ASM,CUDA(CMake 3.8+),CSharp(3.8+),SWIFT(CMake 3.15+ experimental)
# 在CMake 3.9中还可以通过DESCRIPTION "xxxx"来添加项目描述
project(cmake_test VERSION 0.1 LANGUAGES CXX)

message(STATUS "This is Binary dir: " ${cmake_test_BINARY_DIR})
message(STATUS "This is Binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "This is Source dir: " ${cmake_test_SOURCE_DIR})
message(STATUS "This is Source dir: " ${PROJECT_SOURCE_DIR})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(cmake_test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET cmake_test APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(cmake_test SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(cmake_test
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(cmake_test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(cmake_test PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS cmake_test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(cmake_test)
endif()
