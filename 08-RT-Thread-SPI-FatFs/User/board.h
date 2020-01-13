#ifndef __BOARD_H__
#define __BOARD_H__

/*
*************************************************************************
*                             ������ͷ�ļ�
*************************************************************************
*/
#include <rthw.h>
#include <rtthread.h>

/* STM32 �̼���ͷ�ļ� */
#include "stm32f10x.h"

/* ������Ӳ��bspͷ�ļ� */
#include "bsp_led.h"
#include "bsp_usart.h"
#include "./flash/bsp_spi_flash.h"
#include "ff.h"
#include "FatFs_test.h"


/*
*************************************************************************
*                               ��������
*************************************************************************
*/
void rt_hw_board_init(void);
void SysTick_Handler(void);
	

#endif /* __BOARD_H__ */