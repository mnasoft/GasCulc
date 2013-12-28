project(GasCulc)
cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#find_package(Qt4 REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(GasCulc_SRCS agas.cpp component.cpp gas.cpp GasCulc.cpp main.cpp)
#qt4_automoc(${GasCulc_SRCS})

add_executable(GasCulc ${GasCulc_SRCS})
qt5_use_modules(GasCulc Widgets Gui Core Test)


target_link_libraries(GasCulc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS GasCulc RUNTIME DESTINATION bin)
