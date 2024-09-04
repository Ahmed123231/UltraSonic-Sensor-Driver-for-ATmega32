/*
 * UltraSonic_prog.c
 *
 * Created: 7/3/2024 9:32:36 AM
 *  Author: ahmed
 */ 


#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "INT_Vector.h"
#include "UltraSonic_config.h"
#include "GI_interface.h"
#include "TIMER1_interface.h"
#include "TIMER1_reg.h"
#include "SW_ICU_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>



//volatile static u32 on_ticks=0;
//volatile static u32 Tov_ticks=0;

volatile u16 distance=0;

/********** Function to Inzialize UltraSonic Sensor ***********/

void UltraSonic_voidInit(void){
	
	DIO_voidSetPinDir(TRIG_PORT,TRIG_PIN,OUTPUT);
	DIO_voidSetPinDir(ECHO_PORT,ECHO_PIN,INPUT);
	GI_voidEnable();
	
	EXTI_voidInit(INT_0,RISING_EDGE);
	EXTI_voidINT0Enable();
	EXTI_SetCallBack(INT_0,SW_ICU);
	TIMER1_voidInitTimerWithINTEnable(OVF_MODE);
	
}

void UltraSonic_SendPulse(void){
	
	
	DIO_voidSetPinVal(TRIG_PORT,TRIG_PIN,HIGH);
	_delay_us(10);
	DIO_voidSetPinVal(TRIG_PORT,TRIG_PIN,LOW);
	
	_delay_ms(50);
	
}



u8 UltraSonic_u8GetDistance(u16 on_ticks){
	
	u8 Distance=0;
	f32 Time=0;
	Time=on_ticks*0.0625;		// No prescaler and FCPU in 16MHZ ticktime=1/FCPU -->tick time in microseconds
	Distance=(Time*346.0)/20000;		// Distance in centimeter assuming Sound speed is 343 m/s
	
	return Distance;
	
}