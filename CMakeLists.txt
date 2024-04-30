cmake_minimum_required(VERSION 3.20)

# 编译，链接选项
# 则需要在任何一个 project 函数的调用之前调用，否则 cmake 会报错，
# 说编译器无法编译测试程序。
if(1)
	string(
		CONCAT C_CXX_FLAGS
		" -Wall -Wextra -Wno-unused-parameter "
		" -mcpu=cortex-m3 -mthumb "
		" -fno-strict-aliasing -ffunction-sections -fdata-sections "
		" --specs=nano.specs "
	)
	set(CMAKE_C_FLAGS ${C_CXX_FLAGS})
	set(CMAKE_CXX_FLAGS ${C_CXX_FLAGS})

	set(CMAKE_ASM_FLAGS "${C_CXX_FLAGS} -x assembler-with-cpp")

	string(
		CONCAT CMAKE_EXE_LINKER_FLAGS
		" -T${CMAKE_SOURCE_DIR}/STM32F103ZETX_FLASH.ld "
		" --specs=nosys.specs "
		" -Wl,-Map=out_map.map "
		" -Wl,--gc-sections "
		" -static "
	)
endif()

set(ProjectName stm32f103-hal)
project(${ProjectName})
set (CMAKE_EXECUTABLE_SUFFIX ".elf")
set (CMAKE_STATIC_LIBRARY_SUFFIX ".a")

enable_language(ASM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

include(${cpp_lib_build_scripts_path}/cmake-module/setup.cmake)

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
