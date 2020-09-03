cmake_minimum_required(VERSION 3.10.2)

# set project name and version
file(STRINGS ".version" VERSION_FILE)
project(qt-lego VERSION ${VERSION_FILE} LANGUAGES CXX)

# require compiler features
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOUIC_OPTIONS "-n" "--tr" "_gettext_qt")

# require external packages
find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Qt5 5.5 COMPONENTS Widgets Bluetooth REQUIRED)

# import directory names used on GNU systems
include(GNUInstallDirs)

# import CMakeLists.txt from subdirectories
add_subdirectory(src)
