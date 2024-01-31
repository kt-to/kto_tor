cmake_minimum_required(VERSION 3.25)
project(kto_tor)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(kto_tor main.cpp bigInt.h bigInt_fun.cpp bigInt_ope.cpp fraction.h fraction_fun.cpp fraction_ope.cpp ktMainWindow.h ktMainWinow.cpp ktMainWinowOtherFun.cpp)

target_link_libraries(kto_tor PRIVATE Qt6::Widgets)

set( CMAKE_AUTOMOC ON )

