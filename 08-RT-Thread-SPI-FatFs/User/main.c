/**
  *********************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   RT-Thread 3.0 + STM32 工程模版
  *********************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  **********************************************************************
  */ 
 
/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/ 
#include "board.h"
#include "rtthread.h"


/*
*************************************************************************
*                               变量
*************************************************************************
*/

/* 定义线程控制块 */
static rt_thread_t led1_thread = RT_NULL;
static rt_thread_t test_thread = RT_NULL;
/*
*************************************************************************
*                             函数声明
*************************************************************************
*/
static void led1_thread_entry(void* parameter);
static void test_thread_entry(void* parameter);

/*
*************************************************************************
*                             main 函数
*************************************************************************
*/
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
    /* 
	 * 开发板硬件初始化，RTT系统初始化已经在main函数之前完成，
	 * 即在component.c文件中的rtthread_startup()函数中完成了。
	 * 所以在main函数中，只需要创建线程和启动线程即可。
	 */
	
	led1_thread =                          /* 线程控制块指针 */
    rt_thread_create( "led1",              /* 线程名字 */
                      led1_thread_entry,   /* 线程入口函数 */
                      RT_NULL,             /* 线程入口函数参数 */
                      1024,                 /* 线程栈大小 */
                      2,                   /* 线程的优先级 */
                      20);                 /* 线程时间片 */
                   
    /* 启动线程，开启调度 */
   if (led1_thread != RT_NULL)
        rt_thread_startup(led1_thread);
    else
        return -1;
		
	test_thread =                          /* 线程控制块指针 */
    rt_thread_create( "test",              /* 线程名字 */
                      test_thread_entry,   /* 线程入口函数 */
                      RT_NULL,             /* 线程入口函数参数 */
                      1024,                 /* 线程栈大小 */
                      3,                   /* 线程的优先级 */
                      20);                 /* 线程时间片 */
                   
    /* 启动线程，开启调度 */
   if (test_thread != RT_NULL)
        rt_thread_startup(test_thread);
    else
        return -1;
}

/*
*************************************************************************
*                             线程定义
*************************************************************************
*/

static void led1_thread_entry(void* parameter)
{	
	/* 文件系统初始化 */
	FileSystem_Init();
	while (1)
	{
		rt_kprintf("*******************led1_thread inter running******************\n");
		/* 文件系统读写测试 */
		FileSystem_Test();
		rt_kprintf("*******************led1_thread exti running******************\n");
		LED1_ON;
		//rt_kprintf("led1_thread running,LED1_ON\r\n");
		rt_thread_delay(1000);   /* 延时500个tick */
		
		
//		LED1_OFF;    
//		rt_kprintf("led1_thread running,LED1_OFF\r\n");		
//		rt_thread_delay(500);   /* 延时500个tick */		 		
		
//		rt_kprintf("led1_thread running\r\n");

//		rt_kprintf("led1_thread running over!\r\n");
	}
}

static void test_thread_entry(void* parameter)
{	
//	/* 文件系统初始化 */
//	FileSystem_Init();
	while (1)
	{
		rt_kprintf("*******************test_thread inter running******************\n");
		/* 文件系统读写测试 */
		FileSystem_Test();
		rt_kprintf("*******************test_thread exti running******************\n");
		rt_thread_delay(1000);   /* 延时500个tick */		 		

	}
}


/********************************END OF FILE****************************/
