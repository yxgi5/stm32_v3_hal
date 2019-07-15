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

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
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
  uint8_t ucKeyCode;    /* 按键代码 */

  bsp_Init();

//  PrintfLogo(); /* 打印例程名称和版本等信息 */
//  PrintfHelp(); /* 打印操作提示 */

  bsp_StartAutoTimer(0, 100); /* 启动1个100ms的自动重装的定时器，软件定时器0 */
  bsp_StartAutoTimer(1, 100); /* 启动1个100ms的自动重装的定时器，软件定时器1 */

  /* 进入主程序循环体 */
  while (1)
  {
    bsp_Idle();   /* 这个函数在bsp.c文件。用户可以修改这个函数实现CPU休眠和喂狗 */

    /* 判断软件定时器0是否超时 */
    if (bsp_CheckTimer(0))
    {
      /* 每隔100ms 进来一次 */
      bsp_LedToggle(1);
    }

    /* 判断软件定时器1超时 */
    if (bsp_CheckTimer(1))
    {
      /* 每隔100ms 进来一次 */
      bsp_LedToggle(2);
    }

    /* 判断软件定时器2是否超时 */
    if (bsp_CheckTimer(2))
    {
      /* 单次模式，按下K1按键后，定时1秒进入 */
      bsp_LedToggle(3);
    }

    /* 判断软件定时器3是否超时 */
    if (bsp_CheckTimer(3))
    {
      /* 单次模式，按下K2按键后，定时2秒进入 */
      bsp_LedToggle(4);
    }


//    /* 按键滤波和检测由后台systick中断服务程序实现，我们只需要调用bsp_GetKey读取键值即可。 */
//    ucKeyCode = bsp_GetKey(); /* 读取键值, 无键按下时返回 KEY_NONE = 0 */
//    if (ucKeyCode != KEY_NONE)
//    {
//      switch (ucKeyCode)
//      {
//        case KEY_DOWN_K1:     /* K1键按下，启动软件定时2，单次模式，定时0.5时间 */
//          printf("K1键按下\r\n");
//          bsp_StartTimer(2, 500);
//          break;
//
//        case KEY_DOWN_K2:     /* K2键按下，启动软件定时3，单次模式，定时1s时间  */
//          printf("K2键按下\r\n");
//          bsp_StartTimer(3, 1000);
//          break;
//
//        default:
//          /* 其它的键值不处理 */
//          break;
//      }
//
//    }
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
