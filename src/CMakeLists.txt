configure_file(common/Config.hpp.in common/Config.hpp)

# list of source files which are compiled either for the release binary or for linking against the unittests
set(
    LIBRARY_SOURCE_FILES
    controllers/BluetoothDiscoveryController.cpp
)

# compile static library from the following source files
add_library(
    libqt-lego STATIC
    ${LIBRARY_SOURCE_FILES}
)

# add the root of this source tree to the include path
target_include_directories(
    libqt-lego
    PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_BINARY_DIR}/src
)

# compile and link dependencies (both include paths and linker options are derived from this)
target_link_libraries(
    libqt-lego
    Qt5::Widgets
    Qt5::Bluetooth
    Threads::Threads
)

# build main executable
add_executable(
    qt-lego
    QtLego.cpp
    forms/MainWindow.cpp
    forms/MainWindow.ui
)

# add the root of this source tree to the include path
target_include_directories(
    qt-lego
    PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_BINARY_DIR}/src
)

# link binary against other libraries
target_link_libraries(
    qt-lego
    libqt-lego
)

install(
    TARGETS
    qt-lego
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
