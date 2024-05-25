cmake_minimum_required(VERSION 3.20)
include(${cpp_lib_build_scripts_path}/cmake-module/setup.cmake)

set(ProjectName stm32f103-hal)
project(${ProjectName})
set (CMAKE_EXECUTABLE_SUFFIX ".elf")
set (CMAKE_STATIC_LIBRARY_SUFFIX ".a")

enable_language(ASM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

add_library(${ProjectName} STATIC)

target_compile_definitions(
	${ProjectName} PUBLIC
	USE_HAL_DRIVER=1
	STM32F103xE=1
	STM32F10X_HD=1
	ARM_MATH_CM3
	ARM_MATH_MATRIX_CHECK
	ARM_MATH_ROUNDING
	UNALIGNED_SUPPORT_DISABLE
)

target_import_src(${ProjectName})
