cmake_minimum_required(VERSION 3.16)
project(face_comparison VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS 
    Core
    Gui
    Widgets
)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

add_executable(face_comparison
    ${PROJECT_SOURCES}
)

target_link_libraries(face_comparison PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Copy Python script to build directory
configure_file(${CMAKE_SOURCE_DIR}/face_embedding_processor.py
               ${CMAKE_BINARY_DIR}/face_embedding_processor.py
               COPYONLY)