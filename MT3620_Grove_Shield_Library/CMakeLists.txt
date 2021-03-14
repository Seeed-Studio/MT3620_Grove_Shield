CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
PROJECT(MT3620_Grove_Shield_Library C)

################################################################################
# Source groups
################################################################################
set(Common
    src/Common/Delay.c
)
source_group("Common" FILES ${Common})

set(HAL
    src/HAL/GroveI2C.c
    src/HAL/GroveShield.c
    src/HAL/GroveUART.c
)
source_group("HAL" FILES ${HAL})

set(Sensors
    src/Sensors/Grove4DigitDisplay.c
    src/Sensors/GroveAD7992.c
    src/Sensors/GroveLEDButton.c
    src/Sensors/GroveLightSensor.c
    src/Sensors/GroveOledDisplay96x96.c
    src/Sensors/GroveRelay.c
    src/Sensors/GroveRotaryAngleSensor.c
    src/Sensors/GroveTempHumiBaroBME280.c
    src/Sensors/GroveTempHumiSHT31.c
)
source_group("Sensors" FILES ${Sensors})

set(ALL_FILES
    ${no_group_source_files}
    ${Common}
    ${HAL}
    ${Sensors}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

set(ROOT_NAMESPACE MT3620_Grove_Shield_Library)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "AzureSphere"
)

target_link_libraries (${PROJECT_NAME} applibs pthread gcc_s c)
