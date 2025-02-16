cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(rp2040-bitdoglab-project)

pico_sdk_init()

add_executable(main
    src/main.c
    src/joystick.c
    src/display.c
    src/pwm_control.c
    lib/ssd1306.c
)

target_include_directories(main PRIVATE include lib)

target_link_libraries(main pico_stdlib hardware_adc hardware_pwm hardware_i2c)

pico_add_extra_outputs(main)
