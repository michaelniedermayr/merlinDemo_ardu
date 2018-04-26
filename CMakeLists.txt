cmake_minimum_required(VERSION 3.9)
project(demo_ardu)

set(CMAKE_CXX_STANDARD 11)

################################
# MERLIN LIBRARIES
################################
# BASIC LIBRARIES
file(GLOB_RECURSE BASIC_LIBRARIES
        libraries/Builder/*.*
        libraries/FiltersAndPipesManager/*.*
        libraries/Schedulable/*.*
        libraries/Scheduler/*.*
        libraries/Timer/*.*)

# ACTION LIBRARIES
file(GLOB_RECURSE ACTION_LIBRARIES
        libraries/Action_demoMerlin/*.*
        libraries/Action_heartbeat/*.*)

# FILTER LIBRARIES
file(GLOB_RECURSE FILTER_LIBRARIES
        libraries/Filter/*.*
        libraries/Filter_motionDetection_ins/*.*
        libraries/Filter_tiltingAngle/*.*)

# INDICATOR LIBRARIES
file(GLOB_RECURSE INDICATOR_LIBRARIES
        libraries/Indicator_led/*.*)

# LOGGING LIBRARIES
file(GLOB_RECURSE LOGGING_LIBRARIES
        libraries/Loggable/*.*
        libraries/Logger/*.*
        libraries/Logger_dummy/*.*
        libraries/LoggingManager/*.*)

# MANAGER LIBRARIES
file(GLOB_RECURSE MANAGER_LIBRARIES
        libraries/FilterManagerOutput_merlinDemo/*.*
        libraries/RemoteManagerOutput_merlinDemo/*.*)

# MATH LIBRARIES
file(GLOB_RECURSE MATH_LIBRARIES
        libraries/Math_basic/*.*
        libraries/Math_vector3f/*.*
        libraries/Math_lowPassFilter1/*.*
        libraries/Math_medianFilter/*.*)

# REMOTE LIBRARIES
file(GLOB_RECURSE REMOTE_LIBRARIES
        libraries/Remote_serialCmds/*.*
        libraries/Remote_serialCmdsDecoder_demoMerlin/*.*)

# SERIAL LIBRARIES
file(GLOB_RECURSE SERIAL_LIBRARIES
        libraries/Serial_basicCommunication/*.*)

# SENSOR LIBRARIES
file(GLOB_RECURSE SENSOR_LIBRARIES
        libraries/Sensor_ins/*.*)

################################
# HARDWARE
################################
file(GLOB_RECURSE HARDWARE_LIBRARIES
        libraries/Hardware_gpioOut/Hardware_gpioOut.h
        libraries/Hardware_gpioOut/Hardware_gpioOut_dummy.h
        libraries/Hardware_inertialSensor/*.*
        libraries/Hardware_timer/Hardware_timer.h
        libraries/Hardware_spi/Hardware_spi.h
        libraries/Hardware_uart/Hardware_uart.h
        libraries/Hardware_uart/Hardware_uart_dummy.h
        libraries/Hardware_usbSerial/Hardware_usbSerial.h)

# SIMULATOR
file(GLOB_RECURSE HARDWARE_SIM_LIBRARIES
        libraries/Hardware_timer/Hardware_timer_sim.h
        libraries/Hardware_uart/Hardware_uart_sim.h)

# ARDU
file(GLOB_RECURSE HARDWARE_ARDU_LIBRARIES
        libraries/Hardware_gpioOut/Hardware_gpioOut_ardu.h
        libraries/Hardware_spi/Hardware_spi_ardu.h
        libraries/Hardware_timer/Hardware_timer_ardu.h
        libraries/Hardware_uart/Hardware_uart_ardu.h
        libraries/Hardware_usbSerial/Hardware_usbSerial_ardu.h)

# STM32
file(GLOB_RECURSE HARDWARE_STM32_LIBRARIES
        libraries/Hardware_gpioOut/Hardware_gpioOut_stm32.h
        libraries/Hardware_stm32_hal/Hardware_stm32_hal.h
        libraries/Hardware_timer/Hardware_timer_stm32f0.h
        libraries/Hardware_uart/Hardware_uart_stm32.*)

################################
# BUILDER
################################
file(GLOB_RECURSE BUILDER_LIBRARIES
        libraries/Builder_demoMerlin/Builder_demoMerlin.*)

file(GLOB_RECURSE BUILDER_ARDU_LIBRARIES
        libraries/Builder_demoMerlin/Builder_demoMerlin_ardu.h)


file(GLOB_RECURSE MERLIN_LIBRARIES
        ${ACTION_LIBRARIES}
        ${BASIC_LIBRARIES}
        ${BUILDER_LIBRARIES}
        ${FILTER_LIBRARIES}
        ${HARDWARE_LIBRARIES}
        ${INDICATOR_LIBRARIES}
        ${LOGGING_LIBRARIES}
        ${MANAGER_LIBRARIES}
        ${MATH_LIBRARIES}
        ${REMOTE_LIBRARIES}
        ${SENSOR_LIBRARIES}
        ${SERIAL_LIBRARIES})

# tell cmake to look for headers in all libraries-directories -> this way we can include every library with <class-name.h> (arduino-compatible)
file(GLOB ALL_LIBRARY_DIRECTORIES libraries libraries/*)
message(STATUS "All libraries: " ${ALL_LIBRARY_DIRECTORIES} )
include_directories(${ALL_LIBRARY_DIRECTORIES})

################################
# EXECUTABLE
################################
add_executable(demo_ardu Simulator/main.cpp
        ${MERLIN_LIBRARIES}
        ${HARDWARE_ARDU_LIBRARIES}
        ${BUILDER_ARDU_LIBRARIES})
