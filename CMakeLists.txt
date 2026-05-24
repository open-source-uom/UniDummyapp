cmake_minimum_required(VERSION 3.16)

project(WorkshopNotifier VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_add_executable(WorkshopNotifier
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(WorkshopNotifier PRIVATE
    Qt6::Core
    Qt6::Widgets
)

# Windows: no console window
if(WIN32)
    set_target_properties(WorkshopNotifier PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()

install(TARGETS WorkshopNotifier
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
