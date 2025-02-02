cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(BitDogLab_Project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(bitdoglab_interruption
    src/main.c
    src/ws2812.c
)

target_include_directories(bitdoglab_interruption PRIVATE src)
target_link_libraries(bitdoglab_interruption pico_stdlib hardware_gpio)

pico_add_extra_outputs(bitdoglab_interruption)
