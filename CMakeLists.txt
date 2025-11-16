cmake_minimum_required(VERSION 3.16)

project(qt_NoSelection VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 Widgets 模块
find_package(Qt6 6.2 COMPONENTS Quick Widgets REQUIRED)

qt_add_executable(appqt_NoSelection
    main.cpp
)

qt_add_qml_module(appqt_NoSelection
    URI qt_NoSelection
    VERSION 1.0
    QML_FILES main.qml
    SOURCES main.h
    RESOURCES
)

set_target_properties(appqt_NoSelection PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 链接 Widgets 库
target_link_libraries(appqt_NoSelection
    PRIVATE Qt6::Quick
            Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS appqt_NoSelection
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
