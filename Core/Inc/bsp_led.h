/**
  ******************************************************************************
  * @file    bsp_led.h
  * @author  Andreas Zhang
  * @version V1.0
  * @date    05-June-2019
  * @brief   BSP led driver header.
  ******************************************************************************
*/
#ifndef __BSP_LED_H
#define __BSP_LED_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"


typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3
} Led_TypeDef;

/*
    4 user LEDs：(low on，high off)
    LED1     : PF6
    LED2     : PF7
    LED3     : PF8
    LED4     : PF9
*/

#define LEDn  4

#define GPIO_PORT_LED1  GPIOF
#define GPIO_PIN_LED1 GPIO_PIN_6

#define GPIO_PORT_LED2  GPIOF
#define GPIO_PIN_LED2 GPIO_PIN_7

#define GPIO_PORT_LED3  GPIOF
#define GPIO_PIN_LED3 GPIO_PIN_8

#define GPIO_PORT_LED4  GPIOF
#define GPIO_PIN_LED4 GPIO_PIN_9

#define GPIO_CLK_ENABLE_LED1()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define GPIO_CLK_DISABLE_LED1()          __HAL_RCC_GPIOF_CLK_DISABLE()

#define GPIO_CLK_ENABLE_LED2()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define GPIO_CLK_DISABLE_LED2()          __HAL_RCC_GPIOF_CLK_DISABLE()

#define GPIO_CLK_ENABLE_LED3()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define GPIO_CLK_DISABLE_LED3()          __HAL_RCC_GPIOF_CLK_DISABLE()

#define GPIO_CLK_ENABLE_LED4()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define GPIO_CLK_DISABLE_LED4()          __HAL_RCC_GPIOF_CLK_DISABLE()


#define ALL_LED_GPIO_CLK_ENABLE() { \
  __HAL_RCC_GPIOF_CLK_ENABLE(); \
};

#define GPIO_CLK_ENABLE_LEDx(__INDEX__) do{if((__INDEX__) == 0) GPIO_CLK_ENABLE_LED1(); else \
                                         if((__INDEX__) == 1) GPIO_CLK_ENABLE_LED2(); else \
                                         if((__INDEX__) == 2) GPIO_CLK_ENABLE_LED3(); else \
                                         if((__INDEX__) == 3) GPIO_CLK_ENABLE_LED4(); \
                                         }while(0)

#define GPIO_CLK_DISABLE_LEDx(__INDEX__) do{if((__INDEX__) == 0) GPIO_CLK_DISABLE_LED1(); else \
                                          if((__INDEX__) == 1) GPIO_CLK_DISABLE_LED2(); else \
                                          if((__INDEX__) == 2) GPIO_CLK_DISABLE_LED3(); else \
                                          if((__INDEX__) == 3) GPIO_CLK_DISABLE_LED4(); \
                                          }while(0)


void bsp_InitLed(void);
void bsp_LedOn(Led_TypeDef _no);
void bsp_LedOff(Led_TypeDef _no);
void bsp_LedToggle(Led_TypeDef _no);
uint8_t bsp_IsLedOn(Led_TypeDef _no);

#endif // __BSP_LED_H

