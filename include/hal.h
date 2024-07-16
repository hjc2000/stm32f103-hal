/* 此头文件作为 hal 库对外的接口。
 *
 * 不管是哪个型号的单片机的 hal 库，都要手动创建一个这个头文件，用来帮助导入 hal 库
 * 中的头文件。这样，hal-wrapper 只要包含一个 hal.h 就够了，不用为不同型号的单片机
 * 的 hal 库包含不同的头文件。型号导致的的头文件名称差异就交给本文件来处理。
 */

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include "stm32f1xx_hal.h"
#include <core_cm3.h>
#include <stm32f103xe.h>
#include <stm32f1xx_hal_cortex.h>
#include <stm32f1xx_hal_def.h>
#include <stm32f1xx_hal_rcc.h>
#include <stm32f1xx_hal_rcc_ex.h>
#include <stm32f1xx_hal_uart.h>
#include <stm32f1xx_ll_fsmc.h>

#ifdef __cplusplus
}
#endif // __cplusplus
