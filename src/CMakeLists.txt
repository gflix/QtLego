configure_file(common/Config.hpp.in common/Config.hpp)

# list of source files which are compiled either for the release binary or for linking against the unittests
set(
    LIBRARY_SOURCE_FILES
    models/GenericLeMessage.cpp
    models/GenericLeMessageHubAttachedIo.cpp
    models/GenericLeMessageHubProperties.cpp
    models/HubProperty.cpp
    models/HubPropertyOperation.cpp
    models/IoType.cpp
    models/LeMessageHubAttachedIo.cpp
    models/LeMessageHubDetachedIo.cpp
    models/LeMessageHubPropertiesUpdateAdvertisingName.cpp
    models/LeMessageHubPropertiesUpdateBatteryLevel.cpp
    models/LeMessageHubPropertiesUpdateButton.cpp
    models/LeMessageHubPropertiesUpdateSystemType.cpp
    models/QBluetoothAddresses.cpp
    models/QBluetoothDeviceInfos.cpp
    models/RgbLightColor.cpp
    models/SystemType.cpp
    protocols/GenericLeMessage.cpp
    protocols/GenericLeMessageHubAttachedIo.cpp
    protocols/GenericLeMessageHubProperties.cpp
    protocols/HubProperty.cpp
    protocols/HubPropertyOperation.cpp
    protocols/IoType.cpp
    protocols/LeMessageHubAttachedIo.cpp
    protocols/LeMessageHubDetachedIo.cpp
    protocols/LeMessageHubPropertiesUpdateAdvertisingName.cpp
    protocols/LeMessageHubPropertiesUpdateBatteryLevel.cpp
    protocols/LeMessageHubPropertiesUpdateButton.cpp
    protocols/LeMessageHubPropertiesUpdateSystemType.cpp
    protocols/RgbLightColor.cpp
    protocols/SystemType.cpp
    utils/Converter.cpp
    utils/EnumMapper.cpp
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
    controllers/BluetoothController.cpp
    controllers/BluetoothDiscoveryController.cpp
    models/lists/BluetoothDeviceList.cpp
    models/lists/RgbLightColorList.cpp
    forms/AttachedIoRgbLight.cpp
    forms/DeviceSelection.cpp
    forms/GeneralInformation.cpp
    forms/GenericChildDialog.cpp
    forms/MainWindow.cpp
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

add_library(
    testable
    EXCLUDE_FROM_ALL
    STATIC
    ${LIBRARY_SOURCE_FILES}
)

target_include_directories(
    testable
    PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_BINARY_DIR}/src
)

target_compile_options(
    testable
    PRIVATE
    -O2 -g -fprofile-arcs -ftest-coverage -coverage
)

target_link_libraries(
    testable
    Qt5::Widgets
    Qt5::Bluetooth
    Threads::Threads
)