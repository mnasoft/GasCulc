project(GasCulc)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(GasCulc_SRCS gas.cpp GasCulc.cpp main.cpp)
qt4_automoc(${GasCulc_SRCS})
add_executable(GasCulc ${GasCulc_SRCS})
target_link_libraries(GasCulc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS GasCulc RUNTIME DESTINATION bin)
