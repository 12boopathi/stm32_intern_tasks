/*
 * 7seg.c
 *
 *  Created on: Apr 15, 2023
 *      Author: chaman
 */


#include"stm32f4xx.h"
#include"7seg.h"
#include"7seg_cfg.h"



volatile static uint8_t gau8_SevGegPattern[10][7] =
{
  /* a  b  c  d  e  f  g  */
	{0, 0, 0, 0, 0, 0, 1},     /* Zero */
	{1, 0, 0, 1, 1, 1, 1},     /* One */
	{0, 0, 1, 0, 0, 1, 0},     /* Two */
	{0, 0, 0, 0, 1, 1, 0},     /* Three */
	{1, 0, 0, 1, 1, 0, 0},     /* Four */
	{0, 1, 0, 0, 1, 0, 0},     /* Five */
	{0, 1, 0, 0, 0, 0, 0},     /* Six */
	{0, 0, 0, 1, 1, 1, 1},     /* Seven */
	{0, 0, 0, 0, 0, 0, 0},     /* Eight */
	{0, 0, 0, 0, 1, 0, 0}      /* Nine */
};



void SEVEN_SEG_Init()
{
		uint8_t i = 0;
		GPIO_InitTypeDef GPIO_InitStruct = {0};

		/*--------[ Configure The 7-Segments GPIO Pins ]-------*/
		for(i=0; i<7; i++)
		{
			if(SEVEN_SEG_CfgParam.SEG_GPIO[i] == GPIOA)
		    {
		        __HAL_RCC_GPIOA_CLK_ENABLE();
			}
			else if(SEVEN_SEG_CfgParam.SEG_GPIO[i] == GPIOB)
			{
				__HAL_RCC_GPIOB_CLK_ENABLE();
			}
			else if(SEVEN_SEG_CfgParam.SEG_GPIO[i] == GPIOC)
			{
				__HAL_RCC_GPIOC_CLK_ENABLE();
			}
			else if(SEVEN_SEG_CfgParam.SEG_GPIO[i] == GPIOD)
			{
				__HAL_RCC_GPIOD_CLK_ENABLE();
			}
			else if(SEVEN_SEG_CfgParam.SEG_GPIO[i] == GPIOE)
			{
				__HAL_RCC_GPIOE_CLK_ENABLE();
			}
			GPIO_InitStruct.Pin = SEVEN_SEG_CfgParam.SEG_PIN[i];
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
			HAL_GPIO_Init(SEVEN_SEG_CfgParam.SEG_GPIO[i], &GPIO_InitStruct);
		}

}



void SEVEN_SEG_Main(uint16_t counter)
{
	uint8_t j = 0;
	uint8_t Digit_Value = 0;

	while(counter<=9)
	{
	for(j=0; j<7; j++)
	{
		if(gau8_SevGegPattern[Digit_Value][j] == 1)
		{
			HAL_GPIO_WritePin(SEVEN_SEG_CfgParam.SEG_GPIO[j], SEVEN_SEG_CfgParam.SEG_PIN[j], 1);
		}
		else
		{
			HAL_GPIO_WritePin(SEVEN_SEG_CfgParam.SEG_GPIO[j], SEVEN_SEG_CfgParam.SEG_PIN[j], 0);
		}
	}
	}
}




