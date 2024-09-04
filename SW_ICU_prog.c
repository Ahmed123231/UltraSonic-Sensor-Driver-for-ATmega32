/*
 * SW_ICU_prog.c
 *
 * Created: 6/25/2024 10:44:29 PM
 *  Author: ahmed
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "EXTI_interface.h"
#include "TIMER1_reg.h"


u32 on_ticks=0;
u32 Tov_ticks=0;

/******* Function to enable SW Input Capture Unit ********/

void SW_ICU(void){
	
	static u8 count=0;
	count++;
	if(count==1){
		TCNT1_REG=0x00;
		EXTI_voidInit(INT_0,FALLING_EDGE);
		
		
	}
	else if (count==2){
		on_ticks=TCNT1_REG;
		EXTI_voidInit(INT_0,RISING_EDGE);
	}
	else if (count==3){
		Tov_ticks=TCNT1_REG;
		count=0;
		TCNT1_REG=0x00;
		
		
	}
	
}
