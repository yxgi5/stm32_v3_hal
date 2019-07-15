/*
 * bsp.c
 *
 *  Created on: Jun 10, 2019
 *      Author: andy
 */

#include "bsp.h"


static void SystemClock_Config(void);
//static void MPU_Config(void);
void Error_Handler(char *file, uint32_t line);

void bsp_Init(void)
{
//  MPU_Config();
  HAL_Init();
  SystemClock_Config();
#if Enable_EventRecorder == 1
  /* 初始化EventRecorder并开启 */
  EventRecorderInitialize(EventRecordAll, 1U);
  EventRecorderStart();
#endif

//  bsp_InitKey();      /* 按键初始化，要放在滴答定时器之前，因为按钮检测是通过滴答定时器扫描 */
  bsp_InitTimer();    /* 初始化滴答定时器 */
//  bsp_InitUart();   /* 初始化串口 */
  bsp_InitLed();      /* 初始化LED */
//  bsp_InitI2C2();
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_MUL                        = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler(__FILE__, __LINE__);
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler(__FILE__, __LINE__);
  }
}

/*
*********************************************************************************************************
* 函 数 名: Error_Handler
* 形    参: file : 源代码文件名称。关键字 __FILE__ 表示源代码文件名。
*       line ：代码行号。关键字 __LINE__ 表示源代码行号
* 返 回 值: 无
*   Error_Handler(__FILE__, __LINE__);
*********************************************************************************************************
*/
void Error_Handler(char *file, uint32_t line)
{
  /*
    用户可以添加自己的代码报告源代码文件名和代码行号，比如将错误文件和行号打印到串口
    printf("Wrong parameters value: file %s on line %d\r\n", file, line)
  */

  /* 这是一个死循环，断言失败时程序会在此处死机，以便于用户查错 */
  if (line == 0)
  {
    return;
  }

  while(1)
  {
  }
}

///*
//*********************************************************************************************************
//* 函 数 名: MPU_Config
//* 功能说明: 配置MPU
//* 形    参: 无
//* 返 回 值: 无
//*********************************************************************************************************
//*/
//static void MPU_Config( void )
//{
//  MPU_Region_InitTypeDef MPU_InitStruct;
//
//  /* 禁止 MPU */
//  HAL_MPU_Disable();
//
////  /* 配置AXI SRAM的MPU属性为Write back, Read allocate，Write allocate */
////  MPU_InitStruct.Enable           = MPU_REGION_ENABLE;
////  MPU_InitStruct.BaseAddress      = 0x24000000;
////  MPU_InitStruct.Size             = MPU_REGION_SIZE_512KB;
////  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
////  MPU_InitStruct.IsBufferable     = MPU_ACCESS_BUFFERABLE;
////  MPU_InitStruct.IsCacheable      = MPU_ACCESS_CACHEABLE;
////  MPU_InitStruct.IsShareable      = MPU_ACCESS_NOT_SHAREABLE;
////  MPU_InitStruct.Number           = MPU_REGION_NUMBER0;
////  MPU_InitStruct.TypeExtField     = MPU_TEX_LEVEL1;
////  MPU_InitStruct.SubRegionDisable = 0x00;
////  MPU_InitStruct.DisableExec      = MPU_INSTRUCTION_ACCESS_ENABLE;
//
//  HAL_MPU_ConfigRegion(&MPU_InitStruct);
//
//
////  /* 配置FMC扩展IO的MPU属性为Device或者Strongly Ordered */
////  MPU_InitStruct.Enable           = MPU_REGION_ENABLE;
////  MPU_InitStruct.BaseAddress      = 0x60000000;
////  MPU_InitStruct.Size             = ARM_MPU_REGION_SIZE_64KB;
////  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
////  MPU_InitStruct.IsBufferable     = MPU_ACCESS_BUFFERABLE;
////  MPU_InitStruct.IsCacheable      = MPU_ACCESS_NOT_CACHEABLE; /* 不能用MPU_ACCESS_CACHEABLE，会出现2次CS、WE信号 */
////  MPU_InitStruct.IsShareable      = MPU_ACCESS_NOT_SHAREABLE;
////  MPU_InitStruct.Number           = MPU_REGION_NUMBER1;
////  MPU_InitStruct.TypeExtField     = MPU_TEX_LEVEL0;
////  MPU_InitStruct.SubRegionDisable = 0x00;
////  MPU_InitStruct.DisableExec      = MPU_INSTRUCTION_ACCESS_ENABLE;
//
//  HAL_MPU_ConfigRegion(&MPU_InitStruct);
//
//  /*使能 MPU */
//  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
//}

/*
*********************************************************************************************************
* 函 数 名: bsp_RunPer10ms
* 功能说明: 该函数每隔10ms被Systick中断调用1次。详见 bsp_timer.c的定时中断服务程序。一些处理时间要求不严格的
*     任务可以放在此函数。比如：按键扫描、蜂鸣器鸣叫控制等。
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void bsp_RunPer10ms(void)
{
//  bsp_KeyScan10ms();
}

/*
*********************************************************************************************************
* 函 数 名: bsp_RunPer1ms
* 功能说明: 该函数每隔1ms被Systick中断调用1次。详见 bsp_timer.c的定时中断服务程序。一些需要周期性处理的事务
*      可以放在此函数。比如：触摸坐标扫描。
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void bsp_RunPer1ms(void)
{

}

/*
*********************************************************************************************************
* 函 数 名: bsp_Idle
* 功能说明: 空闲时执行的函数。一般主程序在for和while循环程序体中需要插入 CPU_IDLE() 宏来调用本函数。
*      本函数缺省为空操作。用户可以添加喂狗、设置CPU进入休眠模式的功能。
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void bsp_Idle(void)
{
  /* --- 喂狗 */

  /* --- 让CPU进入休眠，由Systick定时中断唤醒或者其他中断唤醒 */

  /* 例如 emWin 图形库，可以插入图形库需要的轮询函数 */
  //GUI_Exec();

  /* 例如 uIP 协议，可以插入uip轮询函数 */
  //TOUCH_CapScan();
}

/*
*********************************************************************************************************
* 函 数 名: HAL_Delay
* 功能说明: 重定向毫秒延迟函数。替换HAL中的函数。因为HAL中的缺省函数依赖于Systick中断，如果在USB、SD卡
*             中断中有延迟函数，则会锁死。也可以通过函数HAL_NVIC_SetPriority提升Systick中断
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
/* 当前例子使用stm32f4xx_hal.c默认方式实现，未使用下面重定向的函数 */
#if 0
void HAL_Delay(uint32_t Delay)
{
  bsp_DelayUS(Delay * 1000);
}
#endif
