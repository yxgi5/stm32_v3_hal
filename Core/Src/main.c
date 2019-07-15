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
  bsp_Init();

//  GPIO_InitTypeDef  gpio_initstruct;
//  __HAL_RCC_GPIOF_CLK_ENABLE();
//  /* Configure the GPIO_LED pin */
//  gpio_initstruct.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
//  gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;
//  gpio_initstruct.Pull = GPIO_PULLUP;
//  gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH;
//
//  HAL_GPIO_Init(GPIOF, &gpio_initstruct);
//
//  /* By default, turn off LED */
//  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);

  while (1)
  {
//    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
////    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
//    /* Insert delay 100 ms */
    bsp_LedToggle(LED1);
    HAL_Delay(100);
//    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
//    /* Insert delay 100 ms */
    bsp_LedToggle(LED2);
    HAL_Delay(100);
//    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8);
//    /* Insert delay 100 ms */
    bsp_LedToggle(LED3);
    HAL_Delay(100);
//    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
//    /* Insert delay 100 ms */
    bsp_LedToggle(LED4);
    HAL_Delay(100);
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
