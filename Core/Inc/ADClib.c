/*
 * ADClib.c
 *
 *  Created on: Mar 16, 2021
 *      Author: Marco
 */
#include "main.h"

void ADC_Pin_Config(int Port){
	switch(Port){
	case 0:
		GPIOA->MODER &= 0xFFFFFFF0;
		GPIOA->MODER |= 0x00000003;
		GPIOA->ASCR &= 0xFFFFFFFE;
		GPIOA->ASCR |= 0x00000001;
		break;
	case 1:
		GPIOA->MODER &= 0xFFFFFFF0;
		GPIOA->MODER |= 0x0000000C;
		GPIOA->ASCR &= 0xFFFFFFFD;
		GPIOA->ASCR |= 0x00000002;
		break;
	default:
		break;
	}
}
int AnalogRead(ADC_HandleTypeDef hadc1){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	int Data = HAL_ADC_GetValue(&hadc1);
	return Data;
}
