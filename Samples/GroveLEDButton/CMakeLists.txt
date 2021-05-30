cmake_minimum_required(VERSION 3.10)

project(grove-led-button C)

azsphere_configure_tools(TOOLS_REVISION "21.04")
azsphere_configure_api(TARGET_API_SET "9")

add_compile_options(-DNETWORKING_STRUCTS_VERSION=1)
add_compile_options(-DWIFICONFIG_STRUCTS_VERSION=1)
add_compile_options(-DUART_STRUCTS_VERSION=1)
add_compile_options(-DSPI_STRUCTS_VERSION=1)

# Libraries
add_subdirectory(../../MT3620_Grove_Shield_Library lib/MT3620_Grove_Shield_Library)

# Executable
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} applibs pthread gcc_s c MT3620_Grove_Shield_Library)

azsphere_target_add_image_package(${PROJECT_NAME})
