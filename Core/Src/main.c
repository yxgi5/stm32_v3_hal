/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <bsp.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define EXAMPLE_NAME  "V3-Uart"
#define EXAMPLE_DATE  "2019-07-16"
#define DEMO_VER    "1.0"
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void PrintfLogo(void);
static void PrintfHelp(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  bsp_Init();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  BEEP_Start(50, 50, 5);
  /* USER CODE END 2 */

  /* 进入主程序循环体 */
  while (1)
  {
    /* USER CODE END WHILE */
      HAL_Delay(500);
      bsp_LedOn(LED1);
      HAL_Delay(500);
      bsp_LedOff(LED1);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
/*
*********************************************************************************************************
* 函 数 名: PrintfHelp
* 功能说明: 打印操作提示
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
static void PrintfHelp(void)
{
  printf("操作提示:\r\n");
  printf("1. 启动一个自动重装软件定时器，每100ms翻转一次LED1和LED2\r\n");
  printf("2. 再启动一个自动重装软件定时器，每500ms翻转一次LED3和LED4\r\n");
}

/*
*********************************************************************************************************
* 函 数 名: PrintfLogo
* 功能说明: 打印例程名称和例程发布日期, 接上串口线后，打开PC机的超级终端软件可以观察结果
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
static void PrintfLogo(void)
{
  printf("*************************************************************\n\r");

  /* 检测CPU ID */
  {
    uint32_t CPU_Sn0, CPU_Sn1, CPU_Sn2;

    CPU_Sn0 = *(__IO uint32_t*)(0x1FFFF7E8);
    CPU_Sn1 = *(__IO uint32_t*)(0x1FFFF7E8 + 4);
    CPU_Sn2 = *(__IO uint32_t*)(0x1FFFF7E8 + 8);

    printf("\r\nCPU : STM32F103ZE, 主频: %dMHz\r\n", SystemCoreClock / 1000000);
    printf("UID = %08X %08X %08X\n\r", CPU_Sn2, CPU_Sn1, CPU_Sn0);
  }

  printf("\n\r");
  printf("*************************************************************\n\r");
  printf("* 例程名称   : %s\r\n", EXAMPLE_NAME);  /* 打印例程名称 */
  printf("* 例程版本   : %s\r\n", DEMO_VER);    /* 打印例程版本 */
  printf("* 发布日期   : %s\r\n", EXAMPLE_DATE);  /* 打印例程日期 */

  /* 打印ST的HAL库版本 */
  printf("* HAL库版本  : V1.3.0 (STM32H7xx HAL Driver)\r\n");
  printf("* \r\n"); /* 打印一行空格 */
  printf("* QQ    : 1295744630 \r\n");
  printf("* 旺旺  : armfly\r\n");
  printf("* Email : armfly@qq.com \r\n");
  printf("* 微信公众号: armfly_com \r\n");
  printf("* 淘宝店: armfly.taobao.com\r\n");
  printf("* Copyright www.armfly.com 安富莱电子\r\n");
  printf("*************************************************************\n\r");
}

/* USER CODE END 4 */

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
